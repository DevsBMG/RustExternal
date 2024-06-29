#pragma once
#include "../../../menu/includes.h"
class c_weapon_punch
{
public:
	declare_member(float, punchDuration, ViewmodelPunch::punchDuration);
	declare_member(float, punchMagnitude, ViewmodelPunch::punchMagnitude);
public:
	auto set_punchanim(float n) -> void
	{
		this->set_punchDuration(n);
		this->set_punchMagnitude(n);
	}
};