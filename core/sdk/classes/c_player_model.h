#pragma once
#include "../../../menu/includes.h"

class c_player_model
{
public:
	declare_member(bool, visible, PlayerModel::visible);
	declare_member(int, skinType, PlayerModel::skinType);
	declare_member(geo::vec3_t, velocity, PlayerModel::velocity);
	declare_member(geo::vec3_t, position, PlayerModel::position);
	declare_member(bool, isLocalPlayer, PlayerModel::isLocalPlayer);
	declare_member(geo::vec3_t, newVelocity, PlayerModel::newVelocity);
	declare_member(bool, IsNpck__BackingField, PlayerModel::IsNpck__BackingField);
public:
	declare_member(c_skinned_multi_mesh*, _multiMesh, PlayerModel::_multiMesh);
	declare_member(c_skinset_collection*, MaleSkin, PlayerModel::MaleSkin);
	declare_member(c_skinset_collection*, FemaleSkin, PlayerModel::FemaleSkin);
public:
};