#pragma once
#include "../../../menu/includes.h"
class c_weapon_bob
{
public:
	declare_member(float, bobSpeedRun, ViewmodelBob::bobSpeedRun);
	declare_member(float, bobSpeedWalk, ViewmodelBob::bobSpeedWalk);
	declare_member(float, bobAmountRun, ViewmodelBob::bobAmountRun);
	declare_member(float, bobAmountWalk, ViewmodelBob::bobAmountWalk);
	declare_member(float, leftOffsetRun, ViewmodelBob::leftOffsetRun);
public:
	auto set_bobanim(float n) -> void
	{
		this->set_bobSpeedRun(n);
		this->set_bobSpeedWalk(n);
		this->set_bobAmountRun(n);
		this->set_bobAmountWalk(n);
		this->set_leftOffsetRun(n);
	}
};