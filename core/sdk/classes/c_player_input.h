#pragma once
#include "../../../menu/includes.h"
class c_player_input
{
public:
	declare_member(geo::vec2_t, bodyAngles, PlayerInput::bodyAngles);
public:
	declare_member(c_input_state*, state, PlayerInput::state);
public:
};