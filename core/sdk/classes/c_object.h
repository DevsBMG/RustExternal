#pragma once
#include "../../../menu/includes.h"

class c_object : public c_base_player
{ public:
	declare_member(c_object_class*, object_class, 0x30);
public:
	auto class_name() -> std::string
	{
		const auto entity = reinterpret_cast<std::uintptr_t>(this);
		if (!entity) return std::string();
		return m_vm.get()->read_string(entity + 0x10);
	}
public:
	auto get_instance() -> c_base_player*
	{
		return m_vm.get()->read<c_base_player*>(reinterpret_cast<std::uintptr_t>(this) + 0x28);
	}
};