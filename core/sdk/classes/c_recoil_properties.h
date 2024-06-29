#pragma once
#include "../../../menu/includes.h"
class c_recoil_properties
{ public:
	declare_member(float, recoilYawMin, RecoilProperties::recoilYawMin);
	declare_member(float, recoilYawMax, RecoilProperties::recoilYawMax);
	declare_member(float, recoilPitchMin, RecoilProperties::recoilPitchMin);
	declare_member(float, recoilPitchMax, RecoilProperties::recoilPitchMax);
public:
	declare_member(c_recoil_properties*, newRecoilOverride, RecoilProperties::newRecoilOverride);
public:
};