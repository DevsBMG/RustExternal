#pragma once
#include "../../../menu/includes.h"

class c_base_movement
{
public:
    declare_member(bool, flying, PlayerWalkMovement::flying);
    declare_member(bool, adminCheat, BaseMovement::adminCheat);
    declare_member(bool, jumping, PlayerWalkMovement::jumping);
    declare_member(bool, grounded, PlayerWalkMovement::grounded);
    declare_member(bool, swimming, PlayerWalkMovement::swimming);
    declare_member(float, landTime, PlayerWalkMovement::landTime);
    declare_member(float, jumpTime, PlayerWalkMovement::jumpTime);
    declare_member(float, groundTime, PlayerWalkMovement::groundTime);
    declare_member(std::uintptr_t, ladder, PlayerWalkMovement::ladder);
    declare_member(float, groundAngle, PlayerWalkMovement::groundAngle);
    declare_member(float, maxVelocity, PlayerWalkMovement::maxVelocity);
    declare_member(std::uintptr_t, capsule, PlayerWalkMovement::capsule);
    declare_member(float, capsuleHeight, PlayerWalkMovement::capsuleHeight);
    declare_member(float, capsuleCenter, PlayerWalkMovement::capsuleCenter);
    declare_member(float, groundAngleNew, PlayerWalkMovement::groundAngleNew);
    declare_member(bool, Duckingk__BackingField, BaseMovement::Duckingk__BackingField);
    declare_member(float, Runningk__BackingField, BaseMovement::Runningk__BackingField);
    declare_member(float, Groundedk__BackingField, BaseMovement::Groundedk__BackingField);
    declare_member(float, capsuleHeightDucked, PlayerWalkMovement::capsuleHeightDucked);
    declare_member(float, capsuleCenterDucked, PlayerWalkMovement::capsuleCenterDucked);
    declare_member(geo::vec3_t, TargetMovementk__BackingField, BaseMovement::TargetMovementk__BackingField);
public:
    auto is_flying() -> bool
    {
        auto grounded = this->grounded();
        auto climbing = ((this->ladder() == 0) ? false : true);
        auto swimming = this->swimming();

        return (!grounded && !climbing && !swimming);
    }
};