#pragma once
#include "../../../menu/includes.h"

class c_hit_test
{
public:
	declare_member(bool, DidHit, HitTest::DidHit);
public:
	declare_member(c_base_entity*, HitEntity, HitTest::HitEntity);
	declare_member(c_transform*, HitTransform, HitTest::HitTransform);
};