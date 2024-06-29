#pragma once
#include "../../../menu/includes.h"
class c_tod_night
{
public:
	declare_member(float, LightIntensity, 0x48);
	declare_member(float, ShadowStrength, 0x4C);
	declare_member(float, AmbientMultiplier, 0x50);
	declare_member(float, ReflectionMultiplier, 0x54);
public:
	declare_member(c_gradient*, SkyColor, 0x28);
};