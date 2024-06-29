#pragma once
#include "../../../menu/includes.h"
class c_groups
{ public:
	declare_member(c_skin_type*, material, 0x18);
public:
	auto material_value(std::uintptr_t material) -> std::uintptr_t { return m_vm.get()->read<std::uintptr_t>(material + 0x10); }
};