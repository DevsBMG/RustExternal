#pragma once
#include "../../../menu/includes.h"
class c_command_list
{ public:
	declare_member(systems::c_string*, Name, 0x10);
	declare_member(bool, AllowRunFromServer, 0x58);
public:
	static auto instance() -> systems::c_array<c_command_list*>* { return m_vm.get()->read_chain< systems::c_array<c_command_list*>*>(m_vm.get()->game_assembly, { var::m_ConsoleSystem_Index_c, 0xB8, 0x10 }); }
};