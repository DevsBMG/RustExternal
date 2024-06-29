#pragma once
#include "../../../menu/includes.h"

class c_item_projectile_mod
{
public:
	declare_member(float, projectileSpread, ItemModProjectile::projectileSpread);
	declare_member(float, projectileVelocity, ItemModProjectile::projectileVelocity);
	declare_member(float, projectileVelocitySpread, ItemModProjectile::projectileVelocitySpread);
};