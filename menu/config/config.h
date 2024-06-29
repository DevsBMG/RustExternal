#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>

#include "json.h"

class Config
{
public:
	void Setup();

	void ExistCheck();
	void Refresh();

	void Create();
	void Delete();

	void Load();
	void Save();

	constexpr size_t Size() const
	{
		return configs.size();
	}

	constexpr size_t& Selected()
	{
		return selected;
	}

	constexpr const char* GetSelectedName() const
	{
		if (configs.empty())
			return "None";
		else
			return configs[selected].c_str();
	}

	const char* operator[](const std::size_t index) const
	{
		return configs[index].c_str();
	}

public:
	char nameBuffer[20];

private:
	const char* baseDir = "C:\\codeine\\configs";
	size_t selected = 0;
	std::vector<std::string> configs{ };
};

void Config::Setup()
{
	ExistCheck();
	Refresh();
}

void Config::ExistCheck()
{
	if (!std::filesystem::exists(baseDir))
	{
		std::filesystem::create_directory(baseDir);
	}
}

void Config::Refresh()
{
	ExistCheck();

	// Flush the config list
	configs.clear();

	for (const auto& dir : std::filesystem::recursive_directory_iterator(baseDir))
	{
		if (!dir.exists() || !dir.is_regular_file())
			continue;

		const auto& path = dir.path();

		if (!path.has_filename() || !path.has_extension())
			continue;

		if (!path.extension().generic_string().ends_with(skCrypt(".json")))
			continue;

		configs.push_back(path.filename().generic_string());
	}
}

void Config::Create()
{
	ExistCheck();

	// Create a string to use *modern* string functions
	auto name = std::string(nameBuffer);

	if (name.empty())
		return;

	if (!name.ends_with(skCrypt(".json")))
		name += std::string(skCrypt(".json"));

	const auto file = std::ofstream(baseDir + std::string(skCrypt("/")) + name);

	Refresh();
}

void Config::Delete()
{
	ExistCheck();

	if (configs.empty())
		return;

	std::filesystem::remove(baseDir + std::string(skCrypt("/")) + GetSelectedName());

	Refresh();
}

void Config::Load() {
	if (GetSelectedName() == nullptr) { return; }
	nlohmann::json j;
	std::ifstream read(baseDir + std::string("/") + GetSelectedName());
	if (!read.is_open()) { return; }
	try 
	{
		read >> j;
		read.close();
		// Menu settings
		config.show_menu = j["menu"]["show_menu"];
		config.selected_tab = j["menu"]["selected_tab"];
		config.transition_alpha = j["menu"]["transition_alpha"];
		config.transition_loaded = j["menu"]["transition_loaded"];
		config.b_background_picker = j["menu"]["b_background_picker"];

		// Aim settings
		config.b_aimbot = j["aim"]["b_aimbot"];
		config.aim = j["aim"]["aim"];
		config.aimkey = j["aim"]["aimkey"];
		config.aim_status = j["aim"]["aim_status"];
		config.aimbone = j["aim"]["aimbone"];
		config.aim_smooth = j["aim"]["aim_smooth"];
		config.aim_fov = j["aim"]["aim_fov"];

		// Visuals settings
		config.b_fov_picker = j["visual"]["b_fov_picker"];
		config.b_crosshair_picker = j["visual"]["b_crosshair_picker"];
		config.b_box_picker = j["visual"]["b_box_picker"];
		config.b_outline_picker = j["visual"]["b_outline_picker"];
		config.b_fill_picker = j["visual"]["b_fill_picker"];
		config.b_health_percent_picker = j["visual"]["b_health_percent_picker"];
		config.b_health_outline_picker = j["visual"]["b_health_outline_picker"];
		config.b_skeleton_picker = j["visual"]["b_skeleton_picker"];
		config.b_lines_picker = j["visual"]["b_lines_picker"];
		config.b_name_picker = j["visual"]["b_name_picker"];
		config.b_distance_picker = j["visual"]["b_distance_picker"];
		config.b_dropped_picker = j["visual"]["b_dropped_picker"];
		config.b_visible = j["visual"]["b_visible"];
		config.b_on_key = j["visual"]["b_on_key"];
		config.b_knocked = j["visual"]["b_knocked"];
		config.b_team = j["visual"]["b_team"];
		config.b_recoil = j["visual"]["b_recoil"];
		config.b_draw_fov = j["visual"]["b_draw_fov"];
		config.b_draw_crosshair = j["visual"]["b_draw_crosshair"];
		config.crosshair_size = j["visual"]["crosshair_size"];
		config.b_box = j["visual"]["b_box"];
		config.b_outline = j["visual"]["b_outline"];
		config.b_fill = j["visual"]["b_fill"];
		config.b_health = j["visual"]["b_health"];
		config.b_health_percent = j["visual"]["b_health_percent"];
		config.b_health_outline = j["visual"]["b_health_outline"];
		config.b_skeleton = j["visual"]["b_skeleton"];
		config.b_lines = j["visual"]["b_lines"];
		config.b_name = j["visual"]["b_name"];
		config.b_distance = j["visual"]["b_distance"];
		config.b_visible_only = j["visual"]["b_visible_only"];
		config.b_render_sleeper = j["visual"]["b_render_sleeper"];
		config.b_render_knocked = j["visual"]["b_render_knocked"];
		config.box_type = j["visual"]["box_type"];
		config.line_type = j["visual"]["line_type"];
		config.render_distance = j["visual"]["render_distance"];
		config.render_items = j["visual"]["render_items"];

		// World settings
		config.b_hemp = j["world"]["b_hemp"];
		config.b_backpack = j["world"]["b_backpack"];
		config.b_supply = j["world"]["b_supply"];
		config.b_dropitem = j["world"]["b_dropitem"];
		config.b_metal = j["world"]["b_metal"];
		config.b_wood = j["world"]["b_wood"];
		config.b_stone = j["world"]["b_stone"];
		config.b_sulfur = j["world"]["b_sulfur"];
		config.b_bed = j["world"]["b_bed"];
		config.b_flameturret = j["world"]["b_flameturret"];
		config.b_samsite = j["world"]["b_samsite"];
		config.b_guntrap = j["world"]["b_guntrap"];
		config.b_beartrap = j["world"]["b_beartrap"];
		config.b_landmine = j["world"]["b_landmine"];
		config.b_autoturret = j["world"]["b_autoturret"];
		config.b_ridablehorse = j["world"]["b_ridablehorse"];
		config.b_tugboat = j["world"]["b_tugboat"];
		config.b_scraptransporthelicopter = j["world"]["b_scraptransporthelicopter"];
		config.b_minicopter = j["world"]["b_minicopter"];
		config.b_food = j["world"]["b_food"];

		// Misc settings
		config.Zoomkey = j["misc"]["Zoomkey"];
		config.Zoom_status = j["misc"]["Zoom_status"];
		config.Zoom_float = j["misc"]["Zoom_float"];
		config.ZoomFOV_float = j["misc"]["ZoomFOV_float"];
		config.FLYkey = j["misc"]["FLYkey"];
		config.FLY_status = j["misc"]["FLY_status"];
		config.b_spyderman = j["misc"]["b_spyderman"];
		config.b_infjump = j["misc"]["b_infjump"];
		config.b_alwaysshoot = j["misc"]["b_alwaysshoot"];
		config.b_noanaimation = j["misc"]["b_noanaimation"];
		config.b_thiccbullet = j["misc"]["b_thiccbullet"];
		config.b_reload_bar = j["misc"]["b_reload_bar"];
		config.b_nosway = j["misc"]["b_nosway"];
		config.b_automatic = j["misc"]["b_automatic"];
		config.b_norecoli = j["misc"]["b_norecoli"];
		config.b_eoka = j["misc"]["b_eoka"];
		config.b_instakill = j["misc"]["b_instakill"];
		config.b_nospread = j["misc"]["b_nospread"];
		config.b_fastsprint = j["misc"]["b_fastsprint"];
		config.b_spingbot = j["misc"]["b_spingbot"];
		config.b_adminflags = j["misc"]["b_adminflags"];
		config.b_shoot_in_debug = j["misc"]["b_shoot_in_debug"];

		// Night settings
		config.b_bright_night = j["night"]["b_bright_night"];
	}
	catch (const std::exception& e) { int wstrSize = MultiByteToWideChar(CP_UTF8, 0, e.what(), -1, nullptr, 0); }
}


void Config::Save() {
	if (GetSelectedName() == nullptr)
		return;

	nlohmann::json j;
	// Menu settings
	j["menu"]["show_menu"] = config.show_menu;
	j["menu"]["selected_tab"] = config.selected_tab;
	j["menu"]["transition_alpha"] = config.transition_alpha;
	j["menu"]["transition_loaded"] = config.transition_loaded;
	j["menu"]["b_background_picker"] = config.b_background_picker;
	j["menu"]["background_color"] = config.background_color;

	// Aim settings
	j["aim"]["b_aimbot"] = config.b_aimbot;
	j["aim"]["aim"] = config.aim;
	j["aim"]["AimType"] = config.AimType;
	j["aim"]["aimkey"] = config.aimkey;
	j["aim"]["aim_status"] = config.aim_status;
	j["aim"]["aimbone"] = config.aimbone;
	j["aim"]["bones"] = config.bones;
	j["aim"]["aim_smooth"] = config.aim_smooth;
	j["aim"]["aim_fov"] = config.aim_fov;

	// Visuals settings
	j["visual"]["b_fov_picker"] = config.b_fov_picker;
	j["visual"]["fov_color"] = config.fov_color;
	j["visual"]["b_crosshair_picker"] = config.b_crosshair_picker;
	j["visual"]["crosshair_color"] = config.crosshair_color;
	j["visual"]["b_box_picker"] = config.b_box_picker;
	j["visual"]["box_color"] = config.box_color;
	j["visual"]["b_outline_picker"] = config.b_outline_picker;
	j["visual"]["outline_color"] = config.outline_color;
	j["visual"]["b_fill_picker"] = config.b_fill_picker;
	j["visual"]["fill_color"] = config.fill_color;
	j["visual"]["b_health_percent_picker"] = config.b_health_percent_picker;
	j["visual"]["health_percent_color"] = config.health_percent_color;
	j["visual"]["b_health_outline_picker"] = config.b_health_outline_picker;
	j["visual"]["health_outline_color"] = config.health_outline_color;
	j["visual"]["b_skeleton_picker"] = config.b_skeleton_picker;
	j["visual"]["skeleton_color"] = config.skeleton_color;
	j["visual"]["b_lines_picker"] = config.b_lines_picker;
	j["visual"]["line_color"] = config.line_color;
	j["visual"]["b_name_picker"] = config.b_name_picker;
	j["visual"]["name_color"] = config.name_color;
	j["visual"]["b_distance_picker"] = config.b_distance_picker;
	j["visual"]["distance_color"] = config.distance_color;
	j["visual"]["b_dropped_picker"] = config.b_dropped_picker;
	j["visual"]["dropped_color"] = config.dropped_color;
	j["visual"]["b_visible"] = config.b_visible;
	j["visual"]["b_on_key"] = config.b_on_key;
	j["visual"]["b_knocked"] = config.b_knocked;
	j["visual"]["b_team"] = config.b_team;
	j["visual"]["b_recoil"] = config.b_recoil;
	j["visual"]["b_draw_fov"] = config.b_draw_fov;
	j["visual"]["b_draw_crosshair"] = config.b_draw_crosshair;
	j["visual"]["crosshair_size"] = config.crosshair_size;
	j["visual"]["b_box"] = config.b_box;
	j["visual"]["b_outline"] = config.b_outline;
	j["visual"]["b_fill"] = config.b_fill;
	j["visual"]["b_health"] = config.b_health;
	j["visual"]["b_health_percent"] = config.b_health_percent;
	j["visual"]["b_health_outline"] = config.b_health_outline;
	j["visual"]["b_skeleton"] = config.b_skeleton;
	j["visual"]["b_lines"] = config.b_lines;
	j["visual"]["b_name"] = config.b_name;
	j["visual"]["b_distance"] = config.b_distance;
	j["visual"]["b_visible_only"] = config.b_visible_only;
	j["visual"]["b_render_sleeper"] = config.b_render_sleeper;
	j["visual"]["b_render_knocked"] = config.b_render_knocked;
	j["visual"]["box_type"] = config.box_type;
	j["visual"]["box_types"] = config.box_types;
	j["visual"]["line_type"] = config.line_type;
	j["visual"]["line_types"] = config.line_types;
	j["visual"]["render_distance"] = config.render_distance;
	j["visual"]["render_items"] = config.render_items;

	// World settings
	j["world"]["b_hemp"] = config.b_hemp;
	j["world"]["b_backpack"] = config.b_backpack;
	j["world"]["b_supply"] = config.b_supply;
	j["world"]["b_dropitem"] = config.b_dropitem;
	j["world"]["b_metal"] = config.b_metal;
	j["world"]["b_wood"] = config.b_wood;
	j["world"]["b_stone"] = config.b_stone;
	j["world"]["b_sulfur"] = config.b_sulfur;
	j["world"]["b_bed"] = config.b_bed;
	j["world"]["b_flameturret"] = config.b_flameturret;
	j["world"]["b_samsite"] = config.b_samsite;
	j["world"]["b_guntrap"] = config.b_guntrap;
	j["world"]["b_beartrap"] = config.b_beartrap;
	j["world"]["b_landmine"] = config.b_landmine;
	j["world"]["b_autoturret"] = config.b_autoturret;
	j["world"]["b_ridablehorse"] = config.b_ridablehorse;
	j["world"]["b_tugboat"] = config.b_tugboat;
	j["world"]["b_scraptransporthelicopter"] = config.b_scraptransporthelicopter;
	j["world"]["b_minicopter"] = config.b_minicopter;
	j["world"]["b_food"] = config.b_food;

	// Misc settings
	j["misc"]["Zoomkey"] = config.Zoomkey;
	j["misc"]["Zoom_status"] = config.Zoom_status;
	j["misc"]["Zoom_float"] = config.Zoom_float;
	j["misc"]["ZoomFOV_float"] = config.ZoomFOV_float;
	j["misc"]["FLYkey"] = config.FLYkey;
	j["misc"]["FLY_status"] = config.FLY_status;
	j["misc"]["b_spyderman"] = config.b_spyderman;
	j["misc"]["b_infjump"] = config.b_infjump;
	j["misc"]["b_alwaysshoot"] = config.b_alwaysshoot;
	j["misc"]["b_noanaimation"] = config.b_noanaimation;
	j["misc"]["b_thiccbullet"] = config.b_thiccbullet;
	j["misc"]["b_reload_bar"] = config.b_reload_bar;
	j["misc"]["b_nosway"] = config.b_nosway;
	j["misc"]["b_automatic"] = config.b_automatic;
	j["misc"]["b_norecoli"] = config.b_norecoli;
	j["misc"]["b_eoka"] = config.b_eoka;
	j["misc"]["b_instakill"] = config.b_instakill;
	j["misc"]["b_nospread"] = config.b_nospread;
	j["misc"]["b_fastsprint"] = config.b_fastsprint;
	j["misc"]["b_spingbot"] = config.b_spingbot;
	j["misc"]["b_adminflags"] = config.b_adminflags;
	j["misc"]["b_shoot_in_debug"] = config.b_shoot_in_debug;

	// Night settings
	j["night"]["b_bright_night"] = config.b_bright_night;

	std::ofstream write(baseDir + std::string(skCrypt("/")) + GetSelectedName());
	write << j.dump(4) << std::endl;
	write.close();
}