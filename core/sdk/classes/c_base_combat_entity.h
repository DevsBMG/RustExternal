#pragma once
#include "../../../menu/includes.h"

class c_base_combat_entity : public c_base_entity
{ public:
	declare_member(float, _health,  BaseCombatEntity::_health);
	declare_member(float, deathTime, BaseCombatEntity::deathTime);
	declare_member(float, _maxHealth, BaseCombatEntity::_maxHealth);
	declare_member(float, startHealth, BaseCombatEntity::startHealth);
public:
	declare_member(systems::lifestate, lifestate, BaseCombatEntity::lifestate);
};