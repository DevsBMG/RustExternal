#pragma once
#include "../../../menu/includes.h"
class c_skinnable
{
public:
	declare_member(systems::category, Category, Skinnable::Category);
	declare_member(systems::c_array<c_groups*>*, Groups, Skinnable::Groups);
	declare_member(systems::c_array<c_skinnable*>*, All, Skinnable::All);
public:
	static auto instance() -> c_skinnable* { return m_vm.get()->read_chain<c_skinnable*>(m_vm.get()->game_assembly, { var::m_Skinnable_c, 0xB8 }); }
};