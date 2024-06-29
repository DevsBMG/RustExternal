#pragma once
#include "../../../menu/includes.h"
class c_model_state
{ public:
	declare_member(float, waterLevel, ModelState::waterLevel);
public:
	declare_member(systems::model_flags, flags, ModelState::flags);
public:
	auto is_swimming() -> bool { return this->waterLevel() >= 0.65f; }
	auto has_flag(systems::model_flags model_flag) -> bool { return (std::uint32_t)this->flags() & (std::uint32_t)model_flag; }
};