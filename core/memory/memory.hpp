#pragma once
#include "../../menu/includes.h"
#include "driver/driver.hpp"
namespace utils
{
	auto is_weapon(std::wstring shortname) -> bool
	{
		if (shortname.find(skCrypt(L"rifle")) != std::wstring::npos
			|| shortname.find(skCrypt(L"pistol")) != std::wstring::npos
			|| shortname.find(skCrypt(L"bow")) != std::wstring::npos
			|| shortname.find(skCrypt(L"lmg")) != std::wstring::npos
			|| shortname.find(skCrypt(L"hmlmg")) != std::wstring::npos
			|| shortname.find(skCrypt(L"shotgun")) != std::wstring::npos
			|| shortname.find(skCrypt(L"smg")) != std::wstring::npos
			|| shortname.find(skCrypt(L"minigun")) != std::wstring::npos
			|| shortname.find(skCrypt(L"multiplegrenadelauncher")) != std::wstring::npos)
		{
			return true;
		}

		return false;
	}

	auto is_prefab_weapon(std::wstring shortname) -> bool
	{
		if (shortname.find(skCrypt(L"rifle")) != std::wstring::npos
			|| shortname.find(skCrypt(L"pistol")) != std::wstring::npos
			|| shortname.find(skCrypt(L"bow")) != std::wstring::npos
			|| shortname.find(skCrypt(L"lmg")) != std::wstring::npos
			|| shortname.find(skCrypt(L"hmlmg")) != std::wstring::npos
			|| shortname.find(skCrypt(L"shotgun")) != std::wstring::npos
			|| shortname.find(skCrypt(L"smg")) != std::wstring::npos
			|| shortname.find(skCrypt(L"minigun")) != std::wstring::npos
			|| shortname.find(skCrypt(L"multiplegrenadelauncher")) != std::wstring::npos
			|| shortname.find(skCrypt(L"rocket")) != std::wstring::npos)
		{
			return true;
		}

		return false;
	}

	auto to_string(std::wstring wstr) -> std::string
	{
		return std::string(wstr.begin(), wstr.end());
	}

	auto to_wstring(std::string str) -> std::wstring
	{
		return std::wstring(str.begin(), str.end());
	}

	auto to_str(std::wstring wstr) -> std::string
	{
		if (wstr.empty())
			return skCrypt("").decrypt();

		static auto encoded_table = std::unordered_map<std::wstring, std::string>{ };
		if (encoded_table.find(wstr) == encoded_table.end())
		{
			const auto size = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), 0, 0, 0, 0);
			auto str = std::string(size, 0);

			if (WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &str[0], size, 0, 0) != size)
				return std::string(wstr.begin(), wstr.end());

			encoded_table.emplace(wstr, str);
			return str;
		}

		return encoded_table[wstr];
	}

	template <typename T>
	auto get_module(std::uint32_t pid, const wchar_t* name) -> T
	{
		const auto handle = OpenProcess(PROCESS_QUERY_INFORMATION, 0, pid);

		auto current = 0ull;
		auto mbi = MEMORY_BASIC_INFORMATION();

		while (VirtualQueryEx(handle, reinterpret_cast<void*>(current), &mbi, sizeof(MEMORY_BASIC_INFORMATION)))
		{
			if (mbi.Type == MEM_MAPPED || mbi.Type == MEM_IMAGE)
			{
				const auto buffer = malloc(1024);
				auto bytes = std::size_t();

				const static auto ntdll = GetModuleHandle(skCrypt("ntdll"));
				const static auto nt_query_virtual_memory_fn = reinterpret_cast<
					NTSTATUS(__stdcall*)(HANDLE, void*, std::int32_t, void*, std::size_t, std::size_t*)> (
						GetProcAddress(ntdll, skCrypt("NtQueryVirtualMemory")));

				if (nt_query_virtual_memory_fn(handle, mbi.BaseAddress, 2, buffer, 1024, &bytes) != 0 ||
					!wcsstr(static_cast<UNICODE_STRING*>(buffer)->Buffer, name) ||
					wcsstr(static_cast<UNICODE_STRING*>(buffer)->Buffer, skCrypt(L".mui")))
				{
					free(buffer);
					goto skip;
				}

				free(buffer);
				CloseHandle(handle);

				return reinterpret_cast<T>(mbi.BaseAddress);
			}

		skip:
			current = reinterpret_cast<std::uintptr_t>(mbi.BaseAddress) + mbi.RegionSize;
		}

		CloseHandle(handle);
		return 0ull;
	}

	auto find_cave(std::int32_t pid, std::int32_t min_address = 0, std::int32_t start_size = 0) -> std::pair<std::uintptr_t, std::size_t>
	{
		const auto handle = OpenProcess(PROCESS_QUERY_LIMITED_INFORMATION, 0, pid);
		auto code_cave = std::pair<std::uintptr_t, std::size_t>{ 0ull, start_size };

		auto mbi = MEMORY_BASIC_INFORMATION();
		auto current = 0ull;

		while (VirtualQueryEx(handle, (void*)current, &mbi, sizeof(mbi)))
		{
			current = reinterpret_cast<uintptr_t>(mbi.BaseAddress) + mbi.RegionSize;
			if (mbi.AllocationProtect == PAGE_EXECUTE_READWRITE
				&& mbi.State == MEM_COMMIT
				&& mbi.Type == MEM_PRIVATE
				&& reinterpret_cast<uintptr_t>(mbi.BaseAddress) > min_address)
			{
				if (std::get<1>(code_cave) < mbi.RegionSize)
					code_cave = { reinterpret_cast<std::uintptr_t>(mbi.BaseAddress), mbi.RegionSize };
			}
		}

		CloseHandle(handle);
		return code_cave;
	}

	auto random_string(int len) -> std::string
	{
		srand(time(NULL));
		std::string str = skCrypt("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz").decrypt();
		std::string newstr;
		int pos;
		while (newstr.size() != len)
		{
			pos = ((rand() % (str.size() - 1)));
			newstr += str.substr(pos, 1);
		}
		return newstr;
	}

	template <typename t = float>
	auto bound(t current, t min, t max) -> t
	{
		if (current < min)
		{
			return min;
		}
		else if (current > max)
		{
			return max;
		}

		return current;
	}
}