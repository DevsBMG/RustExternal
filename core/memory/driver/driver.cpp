#include "driver.hpp"

#define offsetof(s,m) ((size_t)&reinterpret_cast<const volatile char&>((((s*)0)->m)))

auto ioctl_interface::c_interface::setup(
	const std::wstring proc_name) -> bool {

	if (proc_name.empty())
		return false;

	static bool m_fn_found = false;

	int a_pid = 0;

	while (!m_fn_found) {
		auto found = this->get_process_pid(proc_name.c_str());
		printf(skCrypt("looking for rust\n"));
		if (found)
		{
			printf(skCrypt("found rust!\n"));
			a_pid = found;
			m_fn_found = true;
		}
	}

	printf(skCrypt("proccess id: %i\n"), a_pid);

	auto handle = CreateFile(DEVICE_NAME, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	if (handle == INVALID_HANDLE_VALUE)
		return false;

	this->m_driver_handle = std::move(handle);

	printf(skCrypt("driver handle: %llx\n"), handle);

	auto base_address = this->get_image_base(a_pid);
	if (!base_address)
		return false;

	printf(skCrypt("image base: %llx\n"), base_address);

	this->m_pid = std::move(a_pid);
	this->m_image = std::move(base_address);

	auto gameassembly = this->get_base_module(skCrypt(L"GameAssembly.dll"));
	if (!gameassembly)
		return false;

	printf(skCrypt("game assembly: %llx\n"), gameassembly);

	this->game_assembly = std::move(gameassembly);

	auto unityplayer = this->get_base_module(skCrypt(L"UnityPlayer.dll"));
	if (!unityplayer)
		return false;

	printf(skCrypt("unity player: %llx\n"), unityplayer);

	this->unity_player = std::move(unityplayer);

	return true;
}

auto ioctl_interface::c_interface::get_image_base(
	const std::int32_t proc_id) -> std::uintptr_t {

	std::uintptr_t image_address;
	ioctl_interface::base_invoke arguments = { 0 };

	arguments.security = code_security;
	arguments.process_id = proc_id;
	arguments.address = (ULONGLONG*)&image_address;

	DeviceIoControl(this->m_driver_handle,
		code_ba,
		&arguments,
		sizeof(arguments),
		nullptr,
		NULL, NULL, NULL);

	return image_address;
}

auto ioctl_interface::c_interface::get_base_module(
	const wchar_t* module_name) -> std::uintptr_t
{
	ioctl_interface::module_invoke arguments = { 0 };

	uintptr_t image_address;
	arguments.security = code_security;
	arguments.process_id = this->m_pid;
	arguments.address = &image_address;

	DeviceIoControl(this->m_driver_handle,
		code_gma,
		&arguments,
		sizeof(arguments),
		nullptr,
		NULL, NULL, NULL);

	auto Peb = read<PEB>(image_address);
	auto Ldr = read<PEB_LDR_DATA>(std::uintptr_t(Peb.Ldr));

	LDR_DATA_TABLE_ENTRY* ModuleEntry = nullptr;

	for (LIST_ENTRY* Current = Ldr.InMemoryOrderModuleList.Flink; (unsigned char*)Current != (unsigned char*)Peb.Ldr + offsetof(PEB_LDR_DATA, PEB_LDR_DATA::InMemoryOrderModuleList); Current = (LIST_ENTRY*)ModuleEntry->InMemoryOrderLinks.Flink)
	{
		auto CurrentData = read<LDR_DATA_TABLE_ENTRY>(std::uintptr_t(Current));

		ModuleEntry = CONTAINING_RECORD(&CurrentData, LDR_DATA_TABLE_ENTRY, InMemoryOrderLinks);

		if (ModuleEntry->FullDllName.Buffer)
		{
			wchar_t CompareName[256];

			read_physical(std::uintptr_t(ModuleEntry->FullDllName.Buffer), &CompareName, sizeof(CompareName));

			if (CompareName)
			{
				if (wcsstr(CompareName, module_name))
				{
					return std::uintptr_t(ModuleEntry->DllBase);
				}
			}
		}
	}
}

auto ioctl_interface::c_interface::write_physical(
	std::uintptr_t address,
	void* buffer,
	size_t size) -> void {

	ioctl_interface::cmd_invoke arguments = { 0 };

	arguments.security = code_security;
	arguments.address = (ULONGLONG)address;
	arguments.buffer = buffer;
	arguments.size = size;
	arguments.process_id = this->m_pid;
	arguments.write = TRUE;

	DeviceIoControl(this->m_driver_handle,
		code_r,
		&arguments,
		sizeof(arguments),
		nullptr,
		NULL, NULL, NULL);
}

auto ioctl_interface::c_interface::read_physical(
	std::uintptr_t address,
	void* buffer,
	size_t size) -> void {

	ioctl_interface::cmd_invoke arguments = { 0 };

	arguments.security = code_security;
	arguments.address = address;
	arguments.buffer = buffer;
	arguments.size = size;
	arguments.process_id = this->m_pid;
	arguments.read = TRUE;


	DeviceIoControl(this->m_driver_handle,
		code_r,
		&arguments,
		sizeof(arguments),
		nullptr,
		NULL, NULL, NULL);
}

auto ioctl_interface::c_interface::get_process_pid(
	const std::wstring& proc_name) -> const std::uint32_t {
	PROCESSENTRY32W proc_info;
	proc_info.dwSize = sizeof(proc_info);

	HANDLE proc_snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (proc_snapshot == INVALID_HANDLE_VALUE) {
		return 0;
	}

	Process32FirstW(proc_snapshot, &proc_info);
	if (!wcscmp(proc_info.szExeFile, proc_name.c_str())) {
		CloseHandle(proc_snapshot);
		return proc_info.th32ProcessID;
	}

	while (Process32NextW(proc_snapshot, &proc_info)) {
		if (!wcscmp(proc_info.szExeFile, proc_name.c_str())) {
			CloseHandle(proc_snapshot);
			return proc_info.th32ProcessID;
		}
	}

	CloseHandle(proc_snapshot);
	return 0;
}