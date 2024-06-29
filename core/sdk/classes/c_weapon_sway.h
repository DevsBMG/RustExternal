#pragma once
#include "../../../menu/includes.h"
class c_weapon_sway
{
public:
	declare_member(float, positionalSwaySpeed, ViewmodelSway::positionalSwaySpeed);
	declare_member(float, positionalSwayAmount, ViewmodelSway::positionalSwayAmount);
public:
	auto set_swayanim(float n) -> void
	{
		this->set_positionalSwaySpeed(n);
		this->set_positionalSwayAmount(n);
	}
};