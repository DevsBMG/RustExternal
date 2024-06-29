#pragma once
#include "../../../menu/includes.h"

class c_convar_client
{
public:
	declare_member(float, camlerp, Client::camlerp);
	declare_member(float, _camspeed, Client::_camspeed);
	declare_member(float, camlookspeed, Client::camlookspeed);
public:
	static auto instance() -> c_convar_client*{return m_vm.get()->read_chain<c_convar_client*>(m_vm.get()->game_assembly, { var::m_ConVar_Client_c, 0xB8 });}
};