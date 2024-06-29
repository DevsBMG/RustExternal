#pragma once
#include "../../../menu/includes.h"
class c_weapon_view_model
{
public:
	declare_member(c_weapon_bob*, get_bob, BaseViewModel::bob);
	declare_member(c_weapon_sway*, get_sway, BaseViewModel::sway);
	declare_member(c_weapon_lower*, get_lower, BaseViewModel::lower);
	declare_member(c_weapon_punch*, get_punch, BaseViewModel::punch);
	declare_member(std::uintptr_t, animator, BaseViewModel::animator);
public:
	declare_member(std::uintptr_t, model, BaseViewModel::model);
	declare_member(c_weapon_view_model*, ActiveModels, BaseViewModel::ActiveModels);
	declare_member(bool, useViewModelCamera, BaseViewModel::useViewModelCamera);
};