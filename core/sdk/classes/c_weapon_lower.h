#pragma once
#include "../../../menu/includes.h"
class c_weapon_lower
{
public:
	declare_member(bool, shouldLower, ViewmodelLower::shouldLower);
	declare_member(bool, lowerOnSprint, ViewmodelLower::lowerOnSprint);
	declare_member(bool, lowerWhenCantAttack, ViewmodelLower::lowerWhenCantAttack);
public:
	auto set_loweranim(bool enabled) -> void
	{
		this->set_shouldLower(enabled);
		this->set_lowerOnSprint(enabled);
		this->set_lowerWhenCantAttack(enabled);
	}
};