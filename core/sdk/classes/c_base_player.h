#pragma once
#include "../../../menu/includes.h"

class c_base_player : public c_base_combat_entity
{ public:
	declare_member(std::uint32_t, userID, BasePlayer::userID);
	declare_member(std::uint32_t, currentTeam, BasePlayer::currentTeam);
	declare_member(float, lastSentTickTime, BasePlayer::lastSentTickTime);
	declare_member(std::uint32_t, clActiveItem, BasePlayer::clActiveItem);
	declare_member(bool, needsClothesRebuild, BasePlayer::needsClothesRebuild);
	declare_member(systems::c_string*, _displayName, BasePlayer::_displayName);
	declare_member(float, clothingWaterSpeedBonus, BasePlayer::clothingWaterSpeedBonus);
	declare_member(float, clothingMoveSpeedReduction, BasePlayer::clothingMoveSpeedReduction);
	declare_member(c_option*, __menuOption_Menu_AssistPlayer, BasePlayer::__menuOption_Menu_AssistPlayer);
public:
	declare_member(c_player_eyes*, eyes, BasePlayer::eyes);
	declare_member(c_player_belt*, Belt, BasePlayer::Belt);
	declare_member(c_player_input*, input, BasePlayer::input);
	declare_member(c_projectile*, worldItem, WorldItem::item);
	declare_member(c_base_mountable*, mounted, BasePlayer::mounted);
	declare_member(c_base_movement*, movement, BasePlayer::movement);
	declare_member(c_model_state*, modelState, BasePlayer::modelState);
	declare_member(c_base_collision*, collision, BasePlayer::collision);
	declare_member(c_player_inventory*, inventory, BasePlayer::inventory);
	declare_member(c_player_model*, playerModel, BasePlayer::playerModel);
	declare_member(c_player_tick*, lastSentTick, BasePlayer::lastSentTick);
	declare_member(c_rigid_body*, playerRigidbody, BasePlayer::playerRigidbody);//Rigidbody
	declare_member(systems::player_flags, playerFlags, BasePlayer::playerFlags);
	declare_member(c_capsule_collider*, playerCollider, BasePlayer::playerCollider);
public:
	auto has_flag(systems::player_flags player_flag) -> bool
	{
		return (std::uint32_t)this->playerFlags() & (std::uint32_t)player_flag;
	}

	auto is_teammate(c_base_player* local) -> bool
	{
		const auto local_team = local->currentTeam();
		const auto player_team = this->currentTeam();
		const auto team = (local_team == player_team && local_team && player_team);
		return team;
	}

	auto is_dead() -> bool
	{
		if (this->lifestate() == systems::lifestate::alive) return false;
		else return true;
	}

	auto get_speed(c_model_state* model_state, float running, float ducking) -> float
	{
		float num = 1.f;
		num -= this->clothingMoveSpeedReduction();

		if (model_state->is_swimming())
		{
			num += this->clothingWaterSpeedBonus();
		}

		return geo::lerp_vector({ geo::lerp_vector({ 2.8f, 5.5f, running }), 1.7f, ducking }) * num;
	}
public:
	auto get_item() -> c_item*
	{
		const auto active_uid = this->clActiveItem();
		if (!active_uid)
			return nullptr;

		const auto inventory = this->inventory();
		if (!inventory)
			return nullptr;

		const auto inv_belt = inventory->containerBelt();
		if (!inv_belt)
			return nullptr;

		const auto item_list = inv_belt->itemList();
		if (!item_list)
			return nullptr;

		for (std::uint32_t idx{ 0 }; idx < item_list->size(); idx++)
		{
			const auto item = item_list->get_item(idx);
			if (!item)
				continue;

			if (active_uid == item->uid())
				return item;
		}
		return nullptr;
	}
	auto get_projectile() -> c_projectile*
	{
		const auto active_uid = this->clActiveItem();
		if (!active_uid)
			return nullptr;

		const auto inventory = this->inventory();
		if (!inventory)
			return nullptr;

		const auto inv_belt = inventory->containerBelt();
		if (!inv_belt)
			return nullptr;

		const auto item_list = inv_belt->itemList();
		if (!item_list)
			return nullptr;

		for (std::uint32_t idx{ 0 }; idx < item_list->size(); idx++)
		{
			const auto item = item_list->get_item(idx);
			if (!item)
				continue;

			if (active_uid == item->uid())
				return reinterpret_cast<c_projectile*>(item);
		}
		return nullptr;
	}

	static auto instance() -> c_base_player* { return m_vm.get()->read_chain<c_base_player*>(m_vm.get()->game_assembly, { var::m_LocalPlayer_c, 0xB8, 0x0, 0x10, 0x28 }); }
};