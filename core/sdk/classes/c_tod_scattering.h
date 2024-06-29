#pragma once
#include "../../../menu/includes.h"
class c_tod_scattering
{
public:
	declare_member(std::uintptr_t, scatteringMaterial, 0x78);
	declare_member(std::uintptr_t, screenClearMaterial, 0x80);
	declare_member(std::uintptr_t, skyMaskMaterial, 0x88);
};