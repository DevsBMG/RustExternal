#pragma once
#include "../../../menu/includes.h"
class c_itemicon
{
public:
	static auto instance() -> c_itemicon* { return m_vm.get()->read_chain<c_itemicon*>(m_vm.get()->game_assembly, { var::m_ItemIcon_c, 0xB8}); }
	declare_member(systems::c_list_dictionary<float>*, size, 0x0);
	declare_member(float, containerLootStartTimes, 0x0);
};