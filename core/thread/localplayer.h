#pragma once
#include "../../menu/includes.h"
namespace features
{
	auto recoil_values(float n1, float n2, float n3, float n4, c_recoil_properties* recoil) -> void
	{
		{
			recoil->set_recoilYawMin(0 * n1); // replace 0.00f for yaw
			recoil->set_recoilYawMax(0 * n1); // replace 0.00f for yaw
			recoil->set_recoilPitchMin(0 * n3); // replace 0.00f for pitch
			recoil->set_recoilPitchMax(0 * n4); // replace 0.00f for pitch
		}
	}
	auto no_recoil(std::wstring itemname, c_recoil_properties* recoil, c_recoil_properties* new_recoil) -> void
	{
		if (itemname == e(L"pistol.nailgun"))  recoil_values(-1.f, 1.f, -3.f, -6.f, recoil);
		else if (itemname == e(L"pistol.python")) recoil_values(-2.f, 2.f, -15.f, -16.f, recoil);
		else if (itemname == e(L"pistol.revolver")) recoil_values(-1.f, 1.f, -3.f, -6.f, recoil);
		else if (itemname == e(L"shotgun.pump")) recoil_values(4.f, 8.f, -10.f, -14.f, recoil);
		else if (itemname == e(L"shotgun.double")) recoil_values(8.f, 15.f, -10.f, -15.f, recoil);
		else if (itemname == e(L"shotgun.spas12")) recoil_values(4.f, 8.f, -10.f, -14.f, recoil);
		else if (itemname == e(L"shotgun.waterpipe")) recoil_values(4.f, 8.f, -10.f, -14.f, recoil);
		else if (itemname == e(L"crossbow")) recoil_values(-3.f, 3.f, -3.f, -6.f, recoil);
		else if (itemname == e(L"rifle.l96")) recoil_values(-2.f, 2.f, -1.f, -1.5f, recoil);
		else if (itemname == e(L"rifle.bolt")) recoil_values(-4.f, 4.f, -2.f, -3.f, recoil);
		else if (itemname == e(L"rifle.bolt")) recoil_values(-4.f, 4.f, -2.f, -3.f, recoil);
		else if (itemname == e(L"pistol.prototype17")) recoil_values(-1.f, 1.f, -2.f, -2.5f, recoil);
		{
			if (itemname == e(L"rifle.ak")) recoil_values(1.5f, 2.5f, -2.5f, -3.5f, new_recoil);
			else if (itemname == e(L"rifle.ak.ice")) recoil_values(1.5f, 2.5f, -2.5f, -3.5f, new_recoil);
			else if (itemname == e(L"rifle.lr300")) recoil_values(-1.f, 1.f, -2.f, -3.f, new_recoil);
			else if (itemname == e(L"lmg.m249")) recoil_values(1.25f, 2.25f, -3.f, -4.f, new_recoil);
			else if (itemname == e(L"rifle.m39")) recoil_values(1.5f, 2.5f, -3.f, -4.f, new_recoil);
			else if (itemname == e(L"rifle.semiauto")) recoil_values(-0.5f, 0.5f, -2.f, -3.f, new_recoil);
			else if (itemname == e(L"hmlmg")) recoil_values(-1.25f, -2.5f, -3.f, -4.f, new_recoil);
			else if (itemname == e(L"minigun.entity")) recoil_values(-1.25f, -2.5f, -3.f, -4.f, new_recoil);
			else if (itemname == e(L"smg.mp5")) recoil_values(-1.f, 1.f, -1.f, -3.f, new_recoil);
			else if (itemname == e(L"smg.thompson")) recoil_values(-1.f, 1.f, -1.5f, -2.f, new_recoil);
			else if (itemname == e(L"smg.2")) recoil_values(-1.f, 1.f, -1.5f, -2.f, new_recoil);
			else if (itemname == e(L"pistol.m92")) recoil_values(-1.f, 1.f, -2.f, -2.5f, new_recoil);
			else if (itemname == e(L"pistol.semiauto")) recoil_values(-1.f, 1.f, -7.f, -8.f, new_recoil);
		}
	}
	auto weapon_repeat_delay(std::wstring weapon_name) -> float
	{
		if (weapon_name == e(L"rifle.ak")) return 0.1333f;
		else if (weapon_name == e(L"rifle.ak.ice")) return 0.1333f;
		else if (weapon_name == e(L"smg.2")) return 0.10f;
		else if (weapon_name == e(L"rifle.lr300")) return 0.12f;
		else if (weapon_name == e(L"lmg.m249")) return 0.12f;
		else if (weapon_name == e(L"rifle.m39")) return 0.20f;
		else if (weapon_name == e(L"pistol.m92")) return 0.15f;
		else if (weapon_name == e(L"smg.mp5")) return 0.10f;
		else if (weapon_name == e(L"pistol.nailgun")) return 0.15f;
		else if (weapon_name == e(L"pistol.revolver")) return 0.175f;
		else if (weapon_name == e(L"pistol.semiauto")) return 0.15f;
		else if (weapon_name == e(L"rifle.semiauto")) return 0.175f;
		else if (weapon_name == e(L"smg.thompson")) return 0.13f;
		else if (weapon_name == e(L"pistol.python")) return 0.15f;
		else if (weapon_name == e(L"hmlmg")) return 0.13f;
		else if (weapon_name == e(L"pistol.prototype17")) return 0.09f;
	}

	auto misc_features() -> void
	{
		if (!core.player || !core.camera)
		{
			entity_loop::clear();
			return;
		}

		const auto player_walk_movement = core.player->movement();
		if (!player_walk_movement)
			return;

		const auto model_state = core.player->modelState();
		if (!model_state) return;

		const auto eyes = core.player->eyes();
		if (!eyes) return;

		if (GetAsyncKeyState(config.Zoomkey))
		{
			core.convar_graphics->set__fov(config.Zoom_float);
		}
		else
		{
			core.convar_graphics->set__fov(config.ZoomFOV_float);
		}

		if (GetAsyncKeyState(config.FLYkey))
		{
			model_state->set_waterLevel(1.10f); // 0.988f
			auto rotation = eyes->bodyRotationk__BackingField();
			auto target_movement = geo::vec3_t(0.00f, 0.039f, 0.00f);
			auto speed = 4.00f;
			if (GetAsyncKeyState(0x57)) target_movement = geo::quaternion_multi(geo::vec3_t::get_forward(), &rotation);
			if (GetAsyncKeyState(0x53)) target_movement = geo::quaternion_multi(geo::vec3_t::get_backward(), &rotation);
			if (GetAsyncKeyState(0x44)) target_movement = geo::quaternion_multi(geo::vec3_t::get_right(), &rotation);
			if (GetAsyncKeyState(0x41)) target_movement = geo::quaternion_multi(geo::vec3_t::get_left(), &rotation);
			if (GetAsyncKeyState(VK_SPACE)) target_movement.y = 1.00f;
			if (GetAsyncKeyState(VK_LCONTROL)) target_movement.y - 1.00f;
			if (GetAsyncKeyState(VK_SHIFT))
			{ speed = 10.00f; }
			player_walk_movement->set_capsuleCenter(0.90f);
			player_walk_movement->set_capsuleHeight(1.80f);
			player_walk_movement->set_TargetMovementk__BackingField(target_movement * speed);
		}

		if (config.b_spyderman)
		{
			player_walk_movement->set_groundAngle(0.00f);
			player_walk_movement->set_groundAngleNew(0.00f);
		}
		if (config.b_infjump)
		{
			if (GetAsyncKeyState(VK_SPACE))
			{
				player_walk_movement->set_jumpTime(0.51f);
				player_walk_movement->set_landTime(0.30f);
				player_walk_movement->set_groundTime(99999.f);
			}
		}
		if (config.b_alwaysshoot)
		{
			auto mounted = core.player->mounted();
			if (mounted) { if (model_state->has_flag(systems::model_flags::mounted)) mounted->set_canWieldItems(true); }
		}

		const auto projectile = core.player->get_projectile();
		if (!projectile) return;

		const auto wide_name = projectile->shortname();
		if (wide_name.empty()) return;

		const auto held = projectile->heldEntity();
		if (!held) return;

		if (utils::is_weapon(projectile->shortname()))
		{
			const auto held_entity = projectile->heldEntity();
			if (!held_entity)
				return;

			const auto view_model = held_entity->viewModel();
			if (!view_model)
				return;

			if (config.b_noanaimation)
			{
				const auto instance = view_model->instance();
				if (!instance)
					return;

				instance->set_animator(0);

				const auto bob = instance->get_bob();
				if (bob)
					bob->set_bobanim(0);

				const auto sway = instance->get_sway();
				if (sway)
					sway->set_swayanim(0);
			}

			auto thickness = [](std::uintptr_t each) -> void
				{
					auto created = reinterpret_cast<c_projectile*>(each);
					if (created)
						created->set_thickness(2.50);
				};

			if (config.b_thiccbullet)
				held->created_projectiles(thickness);

			if (config.b_nosway)
			{
				held->set_aimSway(0.00f);//0.00f
				held->set_aimSwaySpeed(0.00f);//0.00f
			}

			if (config.b_automatic)
			{
				held->set_automatic(true);
			}

			if (config.b_norecoli)
			{
				auto recoil = held->recoil();
				auto new_recoil = recoil->newRecoilOverride();
				if (recoil || new_recoil) no_recoil(wide_name, recoil, new_recoil);
			}

			if (config.b_eoka)
			{
				if (wide_name.find(e(L"eoka")) != std::wstring::npos)
				{
					held->set_strikes(1);
					held->set_successFraction(1.00f);
					held->set__didSparkThisFrame(true);
				}
			}
			if (config.b_nospread)
			{
				held->set_aimCone(-5.00f);//-5.00f
				held->set_hipAimCone(-5.00f);//-5.00f
				held->set_stancePenalty(0.00f);//0.00f
				held->set_aimconePenalty(0.00f);//0.00f
				held->set_aimConePenaltyMax(0.00f);//0.00f
				held->set_stancePenaltyScale(0.00f);//0.00f
				held->set_aimconePenaltyPerShot(0.00f);//0.00f

				auto projectile_mod = [](std::uintptr_t each) -> void
					{
						auto created = reinterpret_cast<c_projectile*>(each);
						auto projectile_mod = created->mod();
						if (projectile_mod)
						{
							projectile_mod->set_projectileSpread(0.00f);
							projectile_mod->set_projectileVelocitySpread(0.00f);
						}
					};

				held->created_projectiles(projectile_mod);
			}
			if (config.b_reload_bar) {
					static auto start = 0ll;
					if (held->isReloading())
					{
						if (!start) start = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
						geo::reload_indicator.m_reload_duration = held->reloadTime() * 1000.00f;
						geo::reload_indicator.m_reload_time = static_cast<std::int32_t>(start + held->reloadTime() * 1000.00f) - std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
					}
					else
					{
						start = 0ll;
						geo::reload_indicator.m_reload_duration = 0.00f;
						geo::reload_indicator.m_reload_time = 0.00f;
					}
			}
			if (config.b_instakill) {
				held->set_repeatDelay(-99999);
				if (GetAsyncKeyState(0x1))
				{
					held->set_currentBurst(1); held->set_isBurstWeapon(true);
				}
			}
		}
	}

	auto fast_features() -> void
	{
		if (!core.player || !core.camera)
		{
			entity_loop::clear();
			return;
		}

		const auto input = core.player->input();
		if (!input)
			return;

		const auto state = input->state();
		if (!state)
			return;

		const auto current = state->current();
		if (!current)
			return;

		const auto player_walk_movement = core.player->movement();
		if (!player_walk_movement)
			return;
		const auto sky = core.sky->instance();
		if (!sky)
			return;

		const auto night = sky->Night();
		if (!night)
			return;

		const auto stars = sky->Stars();
		if (!stars)
			return;

		if (config.b_fastsprint)
			player_walk_movement->set_Runningk__BackingField(1.00f);

		float randomFloat = geo::random_float(0.00f, 10000.00f);
		if (config.b_spingbot)
			current->set_aimAngles(geo::vec3_t{ 89.00f, randomFloat, 0.00f });
	}

}