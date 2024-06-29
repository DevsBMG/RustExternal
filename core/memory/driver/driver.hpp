#pragma once
#include <vector>
#include <Windows.h>
#include <functional>
#include <string>
#include <iostream>
#include <chrono>
#include <tlhelp32.h>
#include <winternl.h>
#include "../skcrypt.h"
#define DEVICE_NAME "\\\\.\\\HarddiskVolumeDevice27"
#define code_r CTL_CODE(FILE_DEVICE_UNKNOWN, 0x245, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define code_ba CTL_CODE(FILE_DEVICE_UNKNOWN, 0x246, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define code_gma CTL_CODE(FILE_DEVICE_UNKNOWN, 0x249, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define code_security 0x55aa556

namespace ioctl_interface
{
	typedef struct _cmd_invoke
	{
		std::int32_t security;
		std::int32_t process_id;
		std::uintptr_t address;
		void* buffer;
		size_t size;
		BOOLEAN write;
		BOOLEAN read;
	} cmd_invoke, * pcmd_invoke;

	typedef struct _base_invoke
	{
		std::int32_t security;
		std::int32_t process_id;
		std::uintptr_t* address;
	} base_invoke, * pbase_invoke;

	typedef struct _module_invoke
	{
		std::int32_t security;
		std::int32_t process_id;
		std::uintptr_t* address;
	} module_invoke, * pmodule_invoke;

	class c_interface
	{

		std::int32_t m_pid;
		HANDLE m_driver_handle;

	public:

		[[nodiscard]] const std::uint32_t get_process_pid(const std::wstring& proc_name);
		[[nodiscard]] bool setup(const std::wstring proc_name);
		[[nodiscard]] std::uintptr_t get_image_base(const std::int32_t proc_id);
		[[nodiscard]] std::uintptr_t get_base_module(const wchar_t* module_name);

		[[nodiscard]] void read_physical(std::uintptr_t address, void* buffer, size_t size);
		[[nodiscard]] void write_physical(std::uintptr_t address, void* buffer, size_t size);

		[[nodiscard]] auto is_valid(uintptr_t pointer) -> bool {
			return (pointer && pointer > 0xFFFFFF && pointer < 0x7FFFFFFFFFFF && pointer != NULL);
		}

		template <class t>
		[[nodiscard]] auto read(const uintptr_t address) -> t {
			t response{ };

			read_physical(
				address,
				&response,
				sizeof(t)
			);

			return response;
		}

		auto is_valid_pointer(std::uintptr_t pointer) -> bool
		{
			return (pointer && pointer > 0xFFFFFF && pointer < 0x7FFFFFFFFFFF);
		}

		template <typename t>
		[[nodiscard]] auto write(const uintptr_t address, t value) -> t {
			write_physical(address, &value, sizeof(t));
			return value;
		}

		template<typename t>
		[[nodiscard]] auto read_chain(const std::uint64_t& Address, std::vector<std::uint64_t> Offsets) -> t
		{
			std::uint64_t Value = Address;

			for (int i = 0; i < Offsets.size() - 1; i++)
			{
				const std::uint64_t& Offset = Offsets[i];

				Value = this->read<std::uint64_t>(Value + Offset);
			}

			return this->read<t>(Value + Offsets[Offsets.size() - 1]);
		};

		[[nodiscard]] auto read_string(std::uintptr_t Address) -> std::string
		{
			char buffer[128];
			this->read_physical(Address, (std::uint8_t*)&buffer, sizeof(buffer));
			return std::string(buffer, strlen(buffer));
		};
		auto read_wstring(std::uintptr_t Address) -> std::wstring
		{
			wchar_t buffer[128];
			this->read_physical(Address, (std::uint8_t*)&buffer, sizeof(buffer));
			return std::wstring(buffer, wcslen(buffer));
		}

	public:

		std::uintptr_t m_image;
		std::uint64_t game_assembly;
		std::uint64_t unity_player;
	};

} inline auto m_vm = std::make_shared<ioctl_interface::c_interface>();