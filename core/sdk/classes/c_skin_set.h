#pragma once
#include "../../../menu/includes.h"
class c_skin_set
{ public:
	declare_member(std::uintptr_t, HeadMaterial, SkinSet::HeadMaterial);
	declare_member(std::uintptr_t, BodyMaterial, SkinSet::BodyMaterial);
	declare_member(std::uintptr_t, EyeMaterial, SkinSet::EyeMaterial);
};