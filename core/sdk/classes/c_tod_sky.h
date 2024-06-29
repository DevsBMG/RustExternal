#pragma once
#include "../../../menu/includes.h"
class c_tod_sky
{
public:
	declare_member(c_tod_day*, Day, TOD_Sky::Day);
	declare_member(c_tod_night*, Night, TOD_Sky::Night);
	declare_member(c_tod_stars*, Stars, TOD_Sky::Stars);
	declare_member(c_tod_components*, Components, 0xA8);
	declare_member(systems::c_list<std::uintptr_t>*, get_instances, 0x00);
public:
	static auto instance() -> c_tod_sky*
	{
		return m_vm.get()->read_chain<c_tod_sky*>(m_vm.get()->game_assembly, { var::m_TOD_Sky_c, 0xB8, 0x0, 0x10, 0x20 });
	}
};