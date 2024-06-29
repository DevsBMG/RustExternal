#pragma once
#include "../../../menu/includes.h"
class local
{
public:
	//classes
	c_camera* camera;
	c_base_player* player;
	c_tod_sky* sky;
	c_convar_client* convar_client;
	c_convar_graphics* convar_graphics;
	c_itemicon* convar_itemicon;
	//lists
	std::vector< c_base_player*> player_list;
	std::vector<std::tuple<geo::vec3_t, systems::c_color, std::pair<std::string, std::string>>> prefab_list;
} core;

auto _pos = geo::vec3_t{};
auto _players = std::vector<c_base_player*>{ };
auto _prefabs = std::vector<std::tuple<geo::vec3_t, systems::c_color, std::pair<std::string, std::string>>>{};

namespace entity_loop
{
	auto initialize() -> bool
	{
		core.camera = c_camera::instance();
		if (!core.camera)
		{
			return false;
		}
		return true;
	}

	auto clear() -> void
	{
		core.camera = nullptr;
		core.player = nullptr;
		core.player_list.clear();
		core.convar_graphics = nullptr;
	}

	auto get_list() -> void
	{
		const auto base_entity = c_base_networkable::get_base_entity();
		if (!base_entity)
			entity_loop::clear();

		core.convar_graphics = c_convar_graphics::instance();
		if (!core.convar_graphics) return;

		const auto client_entities = base_entity->get_client_entities();
		if (!client_entities)
			entity_loop::clear();

		for (std::uint32_t idx{ 0 }; idx < client_entities->size(); idx++)
		{
			const auto instance = client_entities->get(idx);
			if (!instance)
				continue;

			const auto object = reinterpret_cast<c_object*>(instance->object());
			if (!object)
				continue;

			const auto object_class = object->object_class();
			if (!object_class)
				continue;

			const auto entity = object->get_instance();
			if (!entity)
				continue;

			if (object_class->tag() == 6)
			{
				const auto player_model = entity->playerModel();
				if (!player_model || entity->lifestate() != systems::lifestate::alive)
					continue;

				if (player_model->isLocalPlayer())
				{
					auto position = player_model->position();
					if (position.is_empty())
						continue;

					_pos = position;
					core.player = entity;
					continue;
				}
				if (!config.b_render_knocked)
				{
					if (entity->has_flag(systems::player_flags::wounded))
						continue;
				}
				if (!config.b_render_sleeper) 
				{
					if (entity->has_flag(systems::player_flags::sleeping))
						continue;
				}

				if (player_model->IsNpck__BackingField())
					continue;

				auto position = player_model->position();
				auto distance = position.distance(_pos);
				if (distance > config.render_distance) // max dist
					continue;

				_players.push_back(entity);
			}
			else
			{
				auto class_name = instance->get_name();
				if (class_name.empty())
					continue;

				auto object_name = object_class->get_name();
				if (object_name.empty())
					continue;

				auto object_position = object_class->get_position();
				if (object_position.is_empty())
					continue;

				//ore
				if (config.b_hemp)
					if (strstr(object_name.c_str(), skCrypt("hemp-collectable.prefab")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::green(), {(std::string)skCrypt("HEMP"), (std::string)skCrypt("")} });

				if (config.b_metal)
					if (strstr(object_name.c_str(), skCrypt("metal-ore.prefab")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::orange(), {(std::string)skCrypt("METAL"), (std::string)skCrypt("")} });

				if (config.b_stone)
					if (strstr(object_name.c_str(), skCrypt("stone-ore.prefab")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::white(), {(std::string)skCrypt("STONE"), (std::string)skCrypt("")} });

				if (config.b_sulfur)
					if (strstr(object_name.c_str(), skCrypt("sulfur-ore.prefab")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::yellow(), {(std::string)("SULFUR"), (std::string)("")} });

				if (config.b_sulfur)
					if (strstr(object_name.c_str(), skCrypt("sulfur-collectable.prefab")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::yellow(), {(std::string)skCrypt("SULFUR"), (std::string)("")} });

				if (config.b_stone)
					if (strstr(object_name.c_str(), skCrypt("stone-collectable.prefab")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::white(), {(std::string)skCrypt("STONE"), (std::string)skCrypt("")} });

				if (config.b_wood)
					if (strstr(object_name.c_str(), skCrypt("wood-collectable.prefab")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::rose(), {(std::string)skCrypt("WOOD"), (std::string)skCrypt("")} });

				if (config.b_metal)
					if (strstr(object_name.c_str(), skCrypt("metal-collectable.prefab")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::orange(), {(std::string)skCrypt("METAL"), (std::string)skCrypt("")} });
				//foood
				if (config.b_food)
					if (strstr(object_name.c_str(), skCrypt("black raspberries.item.prefab")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::transparent(), {(std::string)skCrypt("FOOD"), (std::string)skCrypt("")} });

				if (config.b_food)
					if (strstr(object_name.c_str(), skCrypt("blueberries.item.prefab")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::cyan(), {(std::string)skCrypt("FOOD"), (std::string)skCrypt("")} });

				if (config.b_food)
					if (strstr(object_name.c_str(), skCrypt("mushroom-cluster-6.prefab")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::cyan(), {(std::string)skCrypt("FOOD"), (std::string)skCrypt("")} });

				if (config.b_food)
					if (strstr(object_name.c_str(), skCrypt("pumpkin-collectable.prefab")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::cyan(), {(std::string)skCrypt("FOOD"), (std::string)skCrypt("")} });

				if (config.b_food)
					if (strstr(object_name.c_str(), skCrypt("corn-collectable.prefab")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::cyan(), {(std::string)skCrypt("FOOD"), (std::string)skCrypt("")} });

				if (config.b_food)
					if (strstr(object_name.c_str(), skCrypt("berry-white-collectable.prefab")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::cyan(), {(std::string)skCrypt("FOOD"), (std::string)skCrypt("")} });

				if (config.b_food)
					if (strstr(object_name.c_str(), skCrypt("potato-collectable.prefab")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::cyan(), {(std::string)skCrypt("FOOD"), (std::string)skCrypt("")} });
				//drop item
				if (config.b_dropitem)
					if (strstr(object_name.c_str(), skCrypt("item_drop.prefab")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::cyan(), {(std::string)skCrypt("DROPPED"), (std::string)skCrypt("")} });
				if (config.b_supply)
					if (strstr(object_name.c_str(), skCrypt("supply_drop.prefab")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::cyan(), {(std::string)skCrypt("SUPPLY-DROP"), (std::string)skCrypt("")} });
				//backpack
				if (config.b_backpack)
					if (strstr(object_name.c_str(), skCrypt("item_drop_backpack.prefab")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::cyan(), {(std::string)skCrypt("BACK-PACK"), (std::string)skCrypt("")} });
				//vihols
				if (config.b_minicopter)
					if (strstr(object_name.c_str(), skCrypt("minicopter")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::turquoise(), {(std::string)skCrypt("MINI-COPTER"), (std::string)skCrypt("")} });

				if (config.b_scraptransporthelicopter)
					if (strstr(object_name.c_str(), skCrypt("scraptransporthelicopter")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::turquoise(), {(std::string)skCrypt("SCRAP-HELICOPTER"), (std::string)skCrypt("")} });

				if (config.b_tugboat)
					if (strstr(object_name.c_str(), skCrypt("motorrowboat")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::turquoise(), {(std::string)skCrypt("ROW-BOAT"), (std::string)skCrypt("")} });

				if (config.b_tugboat)
					if (strstr(object_name.c_str(), skCrypt("tugboat")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::turquoise(), {(std::string)skCrypt("TUG-BOAT"), (std::string)skCrypt("")} });

				if (config.b_tugboat)
					if (strstr(object_name.c_str(), skCrypt("rhib")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::turquoise(), {(std::string)skCrypt("RHIB"), (std::string)skCrypt("")} });

				if (config.b_ridablehorse)
					if (strstr(object_name.c_str(), skCrypt("ridablehorse")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::turquoise(), {(std::string)skCrypt("HORSE"), (std::string)skCrypt("")} });

				if (config.b_autoturret)
					if (strstr(object_name.c_str(), skCrypt("autoturret")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::turquoise(), {(std::string)skCrypt("AUTOTURRET"), (std::string)skCrypt("")} });

				if (config.b_landmine)
					if (strstr(object_name.c_str(), skCrypt("landmine")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::turquoise(), {(std::string)skCrypt("LANDMINE"), (std::string)skCrypt("")} });

				if (config.b_beartrap)
					if (strstr(object_name.c_str(), skCrypt("beartrap")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::turquoise(), {(std::string)skCrypt("BEAR-TRAP"), (std::string)skCrypt("")} });

				if (config.b_guntrap)
					if (strstr(object_name.c_str(), skCrypt("guntrap")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::turquoise(), {(std::string)skCrypt("GUN-TRAP"), (std::string)skCrypt("")} });

				if (config.b_flameturret)
					if (strstr(object_name.c_str(), skCrypt("flameturret.deployed")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::turquoise(), {(std::string)skCrypt("FLAMETURRET"), (std::string)skCrypt("")} });

				if (config.b_flameturret)
					if (strstr(object_name.c_str(), skCrypt("flameturret_fireball")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::turquoise(), {(std::string)skCrypt("FIRE!!!"), (std::string)skCrypt("")} });

				if (config.b_samsite)
					if (strstr(object_name.c_str(), skCrypt("samsite")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::turquoise(), {(std::string)skCrypt("SAMESITE"), (std::string)skCrypt("")} });

				if (config.b_bed)
					if (strstr(object_name.c_str(), skCrypt("sleepingbag_leather_deployed")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::turquoise(), {(std::string)skCrypt("BED"), (std::string)skCrypt("")} });

				if (config.b_bed)
					if (strstr(object_name.c_str(), skCrypt("bed_deployed")) && _pos.distance(object_position) <= config.render_items)
						_prefabs.push_back({ object_position, systems::c_color::turquoise(), {(std::string)skCrypt("BED"), (std::string)skCrypt("")} });
			}
		}

		core.player_list = _players;
		_players.clear();

		core.prefab_list = _prefabs;
		_prefabs.clear();
	}
}