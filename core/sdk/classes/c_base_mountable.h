#pragma once
#include "../../../menu/includes.h"

class c_base_mountable
{
public:
	declare_member(bool, canWieldItems, BaseMountable::canWieldItems);
	declare_member(bool, ignoreVehicleParent, BaseMountable::ignoreVehicleParent);
public:
};