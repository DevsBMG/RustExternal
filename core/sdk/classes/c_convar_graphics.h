#pragma once
#include "../../../menu/includes.h"

class c_convar_graphics
{ public:
	declare_member(float, _fov, Graphics::_fov);
	declare_member(float, viewModelCamera, Graphics::viewModelCamera);
public:
	static auto instance() -> c_convar_graphics* { return m_vm.get()->read_chain<c_convar_graphics*>(m_vm.get()->game_assembly, { var::m_ConVar_Graphics_c, 0xB8 }); }
};