#pragma once
#include "../../menu/includes.h"
#include "../memory/estr.h"
namespace aimbot
{
	c_base_player* m_target;
	geo::vec3_t m_predicted;
	float bullet_speed{ FLT_MAX },
		bullet_gravity{ FLT_MAX },
		bullet_drag{ FLT_MAX }, closest_distance{ FLT_MAX };
	namespace prediction
	{
		namespace helpers
		{
			struct
			{
				geo::vec3_t* velocities = new geo::vec3_t[32];
				int current_velocity_record = {};
				int current_velocity_index = {};
				geo::vec3_t velocity_angle = geo::vec3_t{ 0.f, 0.f, 0.f };
			} inline prediction_data;

			auto lerp(float default_val, float target, float alpha) -> float
			{
				return default_val + alpha * (target - default_val);
			}

			auto line_cirlce_intersection(geo::vec3_t center, float radius, geo::vec3_t raystart, geo::vec3_t rayend) -> bool
			{
				geo::vec2_t p(raystart.x, raystart.z);
				geo::vec2_t q(rayend.x, rayend.z);

				float a = q.y - p.y;
				float b = p.x - q.x;
				float c = (a * (p.x) + b * (p.y)) * -1.f;

				float x = center.x;
				float y = center.z;

				float c_x = (b * ((b * x) - (a * y)) - a * c) / (std::pow(a, 2) + std::pow(b, 2));
				float c_y = (a * ((-b * x) + (a * y)) - (b * c)) / (std::pow(a, 2) + std::pow(b, 2));

				geo::vec2_t closestpoint(c_x, c_y);

				float distance = p.distance(q);

				if (p.distance(closestpoint) > distance || q.distance(closestpoint) > distance)
					return false;

				if (radius > closestpoint.distance(geo::vec2_t(center.x, center.z)))
				{
					geo::vec2_t p(raystart.x, raystart.y);
					geo::vec2_t q(rayend.x, rayend.y);

					float a = q.y - p.y;
					float b = p.x - q.x;
					float c = (a * (p.x) + b * (p.y)) * -1.f;

					float x = center.x;
					float y = center.y;

					float c_x = (b * ((b * x) - (a * y)) - a * c) / (std::pow(a, 2) + std::pow(b, 2));
					float c_y = (a * ((-b * x) + (a * y)) - (b * c)) / (std::pow(a, 2) + std::pow(b, 2));

					geo::vec2_t closestpoint(c_x, c_y);
					if (radius > closestpoint.distance(geo::vec2_t(center.x, center.y))) return true;
					else return false;
				}

				return false;
			}

			auto get_lerp(geo::vec3_t center, geo::vec3_t firstposition, geo::vec3_t lastposition) -> float
			{
				geo::vec3_t center2d = center; geo::vec3_t first2d = firstposition; geo::vec3_t last2d = lastposition;
				center2d.y = 0.f; first2d.y = 0.f; last2d.y = 0.f;
				float distancefromfirst = (center2d - first2d).length();
				float distancefromlast = (center2d - last2d).length();
				float totaldistance = (last2d - first2d).length();
				if (totaldistance == 0)return 0.5;
				else
				{
					float percentfromfirst = distancefromfirst / totaldistance;
					float percentfromlast = distancefromlast / totaldistance;
					float lerpvalue = percentfromfirst / (percentfromfirst + percentfromlast);
					return lerpvalue;
				}
			}

			double lastTime;
			double currentTime;
			double deltaTime;
			geo::vec3_t targetCurrentPosition;
			geo::vec3_t targetPreviousPosition;

			auto simulate_movement(c_base_player* ply) -> geo::vec3_t
			{
				static bool set_data = true;
				static c_base_player* lastTarget;
				if (lastTarget != ply) {
					targetCurrentPosition = geo::vec3_t::zero();
					targetPreviousPosition = geo::vec3_t::zero();
					prediction_data.current_velocity_record = 0;
					prediction_data.current_velocity_index = 0;
				}
				int records = 3;
				auto velocity = ply->playerModel()->newVelocity();
				if (velocity.is_empty()) { velocity = ply->playerModel()->newVelocity(); }
				prediction_data.velocities[prediction_data.current_velocity_index++] = velocity;
				if (prediction_data.current_velocity_index >= records)prediction_data.current_velocity_index = 0.0f;
				prediction_data.current_velocity_record++;
				if (prediction_data.current_velocity_record >= 0.0f)prediction_data.current_velocity_record = records;
				int current_records = prediction_data.current_velocity_record;
				geo::vec3_t velocity_sums{};
				for (int j = 0; j < current_records; j++)velocity_sums += prediction_data.velocities[j];
				prediction_data.velocity_angle = velocity_sums / (float)current_records;
				set_data = !set_data;
				lastTarget = ply;
				return prediction_data.velocity_angle;
			}

			auto get_trajectory(geo::vec3_t target_pos, geo::vec3_t initial_pos, geo::vec3_t player_velocity, float velocity, float drag, float gravity_multi, float intial_distance) -> geo::vec3_t
			{
				bool sim_finished = false;
				static int maximumsims = 30;

				float pitch_offset = 0;
				geo::vec3_t target_position = target_pos;

				for (int i = 0; i < maximumsims; i++)
				{
					target_position.y += pitch_offset;

					geo::vec3_t angle = target_position - initial_pos;

					geo::vec3_t calc_velocity = angle.normalized() * velocity;

					geo::vec3_t proectile_pos = initial_pos;
					geo::vec3_t previous_pos = geo::vec3_t();

					const float step_size = 0.03125f;
					for (float projectiletime = 0.f; projectiletime < 8.f; projectiletime += step_size)
					{
						previous_pos = proectile_pos;
						proectile_pos = proectile_pos + (calc_velocity * step_size);

						calc_velocity.y -= 9.81f * gravity_multi * step_size;
						calc_velocity -= calc_velocity * drag * step_size;

						if (line_cirlce_intersection(target_pos, 0.025f, previous_pos, proectile_pos))
						{
							sim_finished = true;
							break;
						}
						else if (initial_pos.distance(target_pos) < initial_pos.distance(proectile_pos))
						{
							geo::vec3_t calculated_pos = geo::vec3_t(target_pos.x, lerp(proectile_pos.y, previous_pos.y, get_lerp(target_position, proectile_pos, previous_pos)), target_pos.z);
							pitch_offset = target_pos.y - calculated_pos.y;
							break;
						}
					}
					if (sim_finished)
						break;
				}
				auto time = (intial_distance / velocity);

				player_velocity.x *= 0.75f * time;
				player_velocity.y *= 0.75f * time;
				player_velocity.z *= 0.75f * time;

				target_position.x += player_velocity.x;
				target_position.y += player_velocity.y;
				target_position.z += player_velocity.z;

				if (core.player->modelState()->has_flag(systems::model_flags::ducked)) target_position.y -= 0.4725f;

				return target_position;
			}
		}
	}

	auto get_weapon_info(c_magazine* magazine, float velocity_scale) -> void
	{
		auto ammo_name = magazine->shortname()->buffer();
		if (ammo_name.find(skCrypt(L"ammo.rifle.incendiary")) != std::wstring::npos)
		{
			bullet_speed = 225.00f;
			if (velocity_scale)
				bullet_speed *= velocity_scale;
			bullet_gravity = 1.00f;
			bullet_drag = 0.60f;
		}
		else if (ammo_name.find(skCrypt(L"ammo.rifle.explosive")) != std::wstring::npos)
		{
			bullet_speed = 225.00f;
			if (velocity_scale)
				bullet_speed *= velocity_scale;
			bullet_gravity = 1.25f;
			bullet_drag = 0.60f;
		}
		else if (ammo_name.find(skCrypt(L"ammo.pistol.fire")) != std::wstring::npos)
		{
			bullet_speed = 225.00f;
			if (velocity_scale)
				bullet_speed *= velocity_scale;
			bullet_gravity = 1.00f;
			bullet_drag = 0.70f;
		}
		else if (ammo_name.find(skCrypt(L"arrow.fire")) != std::wstring::npos)
		{
			bullet_speed = 40.00f;
			bullet_gravity = 1.00f;
			bullet_drag = 0.01f;
		}
		else
		{
			const auto item_mod_projectile = get_component(m_vm.get()->read_chain<std::uintptr_t>(reinterpret_cast<std::uintptr_t>(magazine), { 0x20, 0x10, 0x30 }), skCrypt("ItemModProjectile"));
			if (item_mod_projectile)
			{
				const auto projectile = reinterpret_cast<c_projectile*>(get_component(m_vm.get()->read_chain<std::uintptr_t>(item_mod_projectile, { 0x20, 0x18, 0x10 }), skCrypt("Projectile")));
				if (projectile)
				{
					bullet_speed = m_vm.get()->read<float>(item_mod_projectile + 0x3C); // projectileVelocity
					if (velocity_scale)
						bullet_speed *= velocity_scale;
					bullet_gravity = projectile->gravityModifier();
					bullet_drag = projectile->drag();
				}
			}
		}
	}

	auto aimbot_loop() -> void
	{
		if (!core.camera || !core.player)
			return;

		float closest = FLT_MAX;

		const auto projectile = core.player->get_projectile();
		if (!projectile)
			return;

		const auto held_entity = projectile->heldEntity();
		if (!held_entity)
			return;

		const auto item_definition = projectile->info();
		if (!item_definition)
			return;

		const auto is_weapon = utils::is_weapon(item_definition->shortname()->buffer());
		if (!is_weapon)
			return;

		const auto player_eyes = core.player->eyes();
		if (!player_eyes)
			return;

		auto localplayerpos = core.camera->position();
		if (localplayerpos.is_empty())
			return;

		auto m_matrix = core.camera->view_matrix();

		auto target_player = std::tuple<c_base_player*, geo::vec3_t, float>(nullptr, geo::vec3_t{ 0.00f, 0.00f, 0.00f }, FLT_MAX);
		for (const auto& entity : core.player_list)
		{
			if (entity->lifestate() != systems::lifestate::alive)
				continue;

			const auto player_model = entity->playerModel();
			if (!player_model)
				continue;

			const auto model = entity->model();
			if (!model)
				continue;

			const auto bone_transform = model->boneTransforms();
			if (!bone_transform)
				continue;

			systems::player_bones target_boner;
			int bones = 1;
			switch (config.aimbone) 
			{
			case 0:
				bones = 1 + rand() % 79;
				if (bones == 5 || bones == 8 || bones == 9 || bones == 10 || bones == 11 || bones == 12 || bones == 17 || bones == 19 || bones == 43 || bones == 44 || bones == 49 || bones == 74 || bones == 75 || bones >= 79 || bones == 47 || bones == 48) {
					bones = (int)systems::player_bones::spine2;
				}
				target_boner = (systems::player_bones)bones;
				break;
			case 1:
				bones = 1 + rand() % 79;
				if (bones == 5 || bones == 8 || bones == 9 || bones == 10 || bones == 11 || bones == 12 || bones == 17 || bones == 19 || bones == 43 || bones == 44 || bones == 49 || bones == 74 || bones == 75 || bones >= 79) {
					bones = (int)systems::player_bones::spine2;
				}
				target_boner = (systems::player_bones)bones;
				break;
			case 2:
				target_boner = systems::player_bones::head;
				break;
			}
			auto bone_pos = bone_transform->get(target_boner)->get_position();
			if (bone_pos.is_empty())
				continue;

			if (core.camera->calculate_fov(m_matrix, bone_pos) >= config.aim_fov)
				continue;

			auto distance = localplayerpos.distance(bone_pos);
			if (!distance)
				continue;

			auto point = core.camera->world_to_screen_point(m_matrix, bone_pos);
			if (point.is_empty())
				continue;

			auto length = std::sqrt(std::pow((vars.screen_width / 2.00f) - point.x, 2.00f) + std::pow((vars.screen_height / 2.00f) - point.y, 2.00f));

			if (length < closest)
			{
				closest = length;
				target_player = { entity, bone_pos, distance };
			}
		}

		auto& [instance, position, distance_2d] = target_player;
		if (!instance)
		{
			aimbot::m_target = nullptr;
			aimbot::m_predicted = geo::vec3_t{ 0.00f, 0.00f, 0.00f };
			return;
		}
		else aimbot::m_target = instance;

		if (is_weapon)
		{
			static auto lasttick = std::chrono::steady_clock::now();
			auto now = std::chrono::steady_clock::now();
			if (std::chrono::duration_cast<std::chrono::milliseconds>(now - lasttick).count() > 1)
			{
				aimbot::get_weapon_info(held_entity->primaryMagazine(), held_entity->projectileVelocityScale());
				lasttick = now;
			}

			position = aimbot::prediction::helpers::get_trajectory
			(
				position,
				localplayerpos,
				aimbot::prediction::helpers::simulate_movement(instance) * 0.75f,
				bullet_speed,
				bullet_drag,
				bullet_gravity,
				distance_2d
			);
		}
		else
		{
			aimbot::m_target = nullptr;
			aimbot::m_predicted = geo::vec3_t{ 0.00f, 0.00f, 0.00f };
		}
		aimbot::m_predicted = position;

		auto new_angles = geo::normalize(geo::unity_calculate_angle(localplayerpos, aimbot::m_predicted));
		if (std::isnan(new_angles.x) && std::isnan(new_angles.y))
			return;

		if (config.b_aimbot) 
		{
			if (config.aim == 0)
			{
				const auto local_input = core.player->input();
				if (!local_input)
					return;

				auto current_angles = local_input->bodyAngles();
				auto delta = (new_angles - current_angles).clamped();
				if (GetAsyncKeyState(config.aimkey))
				{
					local_input->set_bodyAngles(current_angles + (delta / (2.50f / 2.00f)));
				}
			}
			else if (config.aim == 1) 
			{
				if (GetAsyncKeyState(config.aimkey))
				{
					player_eyes->set_bodyRotationk__BackingField(geo::to_quaternion(new_angles));
				}
			}
		}
	}
}