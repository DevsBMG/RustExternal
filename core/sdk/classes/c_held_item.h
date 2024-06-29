#pragma once
#include "../../../menu/includes.h"

class c_held_item : public c_base_entity
{ public:
    declare_member(float, arrowBack, BowWeapon::arrowBack);
    declare_member(float, aimSway, BaseProjectile::aimSway);
    declare_member(float, aimCone, BaseProjectile::aimCone);
    declare_member(bool, attackReady, BowWeapon::attackReady);
    declare_member(bool, automatic, BaseProjectile::automatic);
    declare_member(float, strikes, FlintStrikeWeapon::strikes);
    declare_member(float, repeatDelay, AttackEntity::repeatDelay);
    declare_member(float, hipAimCone, BaseProjectile::hipAimCone);
    declare_member(float, reloadTime, BaseProjectile::reloadTime);
    declare_member(bool, isReloading, BaseProjectile::isReloading);
    declare_member(int, currentBurst, BaseProjectile::currentBurst);
    declare_member(float, aimSwaySpeed, BaseProjectile::aimSwaySpeed);
    declare_member(bool, isBurstWeapon, BaseProjectile::isBurstWeapon);
    declare_member(float, stancePenalty, BaseProjectile::stancePenalty);
    declare_member(float, nextReloadTime, BaseProjectile::nextReloadTime);
    declare_member(float, aimconePenalty, BaseProjectile::aimconePenalty);
    declare_member(float, hipAimConeScale, BaseProjectile::hipAimConeScale);
    declare_member(float, hipAimConeOffset, BaseProjectile::hipAimConeOffset);
    declare_member(float, successFraction, FlintStrikeWeapon::successFraction);
    declare_member(float, aimConePenaltyMax, BaseProjectile::aimConePenaltyMax);
    declare_member(float, sightAimConeScale, BaseProjectile::sightAimConeScale);
    declare_member(bool, canChangeFireModes, BaseProjectile::canChangeFireModes);
    declare_member(float, sightAimConeOffset, BaseProjectile::sightAimConeOffset);
    declare_member(float, stancePenaltyScale, BaseProjectile::stancePenaltyScale);
    declare_member(float, stringBonusDamage, CompoundBowWeapon::stringBonusDamage);
    declare_member(bool, _didSparkThisFrame, FlintStrikeWeapon::_didSparkThisFrame);
    declare_member(float, aimconePenaltyPerShot, BaseProjectile::aimconePenaltyPerShot);
    declare_member(float, stringHoldDurationMax, CompoundBowWeapon::stringHoldDurationMax);
    declare_member(float, projectileVelocityScale, BaseProjectile::projectileVelocityScale);
    declare_member(float, movementPenaltyRampUpTime, CompoundBowWeapon::movementPenaltyRampUpTime);
public:
    declare_member(c_view_model*, viewModel, 0x1A0);
    declare_member(c_recoil_properties*, recoil, BaseProjectile::recoil);
    declare_member(c_magazine*, primaryMagazine, BaseProjectile::primaryMagazine);
public:
    auto created_projectiles(void (*each)(std::uintptr_t)) -> void
    {
        const auto list = m_vm.get()->read<std::uintptr_t>(reinterpret_cast<std::uintptr_t>(this) + BaseProjectile::createdProjectiles);
        if (!list) return;

        const auto key = m_vm.get()->read<std::uintptr_t>(list + 0x10);
        if (!key) return;

        const auto size = m_vm.get()->read<int>(list + 0x18);
        if (!size) return;

        for (int i = 0; i < size; ++i)
        {
            const auto projectile = m_vm.get()->read<std::uintptr_t>(key + 0x20 + (i * 0x8));
            if (!projectile) continue;

            each(projectile);
        }
    }
};
