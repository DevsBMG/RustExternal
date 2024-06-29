#pragma once
#include "../../../menu/includes.h"

class c_convar_admin
{ public:
	declare_member(float, adminTime, Admin::admintime);
public:
	static auto instance() -> c_convar_admin* { return m_vm.get()->read_chain<c_convar_admin*>(m_vm.get()->game_assembly, { var::m_ConVar_Admin_c, 0xB8 }); }
};