#pragma once

inline namespace vintage
{
	class variables : public singleton<variables>
	{
	public:
		HWND game_hwnd = NULL;

		int screen_height = NULL;
		int screen_width = NULL;
		int screen_left = NULL;
		int screen_right = NULL;
		int screen_top = NULL;
		int screen_bottom = NULL;

		float screen_center_x = screen_width / 2;
		float screen_center_y = screen_height / 2;
	};

    #define vars vintage::variables::get()
}

inline namespace configuration
{
	class settings : public singleton<settings>
	{
	public:
		///////////////////                MENU                          //////////////////////
		bool show_menu = true;
		int selected_tab = 0;
		float transition_alpha = 1.0f;
		bool transition_loaded = true;
		bool b_background_picker = false;
		float background_color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		/////////////////////////////////////////////////////////////////////////////////////


		///////////////////                Aim                          //////////////////////
		bool b_aimbot = false; int aim = 0; std::vector<const char*> AimType = { "Memory", "Silent" }; int aimkey = 0x12; int aim_status = 0;int aimbone = 0; std::vector<const char*> bones = { "BODY", "NECK", "HEAD" }; float aim_smooth = 2.f; float aim_fov = 50.f;
		/////////////////////////////////////////////////////////////////////////////////////

		///////////////////                Visuals                          //////////////////////
		bool b_fov_picker = false; float fov_color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		bool b_crosshair_picker = false;float crosshair_color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		bool b_box_picker = false; float box_color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		bool b_outline_picker = false; float outline_color[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
		bool b_fill_picker = false; float fill_color[4] = { 37.f / 255.f, 35.f / 255.f, 40.f / 255.f, 0.5f };
		bool b_health_percent_picker = false; float health_percent_color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		bool b_health_outline_picker = false; float health_outline_color[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
		bool b_skeleton_picker = false; float skeleton_color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		bool b_lines_picker = false; float line_color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		bool b_name_picker = false; float name_color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		bool b_distance_picker = false; float distance_color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		bool b_dropped_picker = false; float dropped_color[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
		bool b_visible = false;
		bool b_on_key = false;
		bool b_knocked = false;
		bool b_team = false;
		bool b_recoil = false;
		bool b_draw_fov = false;
		bool b_draw_crosshair = false;
		int crosshair_size = 5;
		bool b_box = false;
		bool b_outline = false;
		bool b_fill = false;
		bool b_health = false;
		bool b_health_percent = false;
		bool b_health_outline = false;
		bool b_skeleton = false;
		bool b_lines = false;
		bool b_name = false;
		bool b_distance = false;
		bool b_visible_only = false;
		bool b_render_sleeper = false;
		bool b_render_knocked = false;
		int box_type = 0;
		std::vector<const char*> box_types = { "2D BOX", "CORNER" };
		int line_type = 0;
		std::vector<const char*> line_types = { "HEAD", "PELVIS" };
		float render_distance = 150.f;
		float render_items = 150.f;

		int hand_chams = 0;
		int chams = 0;
		std::vector<const char*> chams_b = { "NONE" , "PINK", "SUNNY D", "GLOSSY BLUE" };
		std::vector<const char*> Hand_cham_b = {"NONE" , "PINK", "SUNNY D", "GLOSSY BLUE" };

		/////////////////////////////////////////////////////////////////////////////////////
		// 
		///////////////////                World                          //////////////////////
		bool b_hemp = false;
		bool b_backpack = false;
		bool b_supply = false;
		bool b_dropitem = false;
		bool b_metal = false;
		bool b_wood = false;
		bool b_stone = false;
		bool b_sulfur = false;
		bool b_bed = false;
		bool b_flameturret = false;
		bool b_samsite = false;
		bool b_guntrap = false;
		bool b_beartrap = false;
		bool b_landmine = false;
		bool b_autoturret = false;
		bool b_ridablehorse = false;
		bool b_tugboat = false;
		bool b_scraptransporthelicopter = false;
		bool b_minicopter = false;
		bool b_food = false;
		/////////////////////////////////////////////////////////////////////////////////////

		///////////////////                Misc                          //////////////////////
		int Zoomkey = 0x12; int Zoom_status = 0; float Zoom_float = 10;
		float ZoomFOV_float = 90;
		int FLYkey = 0x12; int FLY_status = 0;
		bool b_spyderman = false;
		bool b_infjump = false;
		bool b_alwaysshoot = false;
		bool b_noanaimation = false;
		bool b_thiccbullet = false;
		bool b_reload_bar = false;
		bool b_nosway = false;
		bool b_automatic = false;
		bool b_norecoli = false;
		bool b_eoka = false;
		bool b_instakill = false;
		bool b_nospread = false;
		bool b_fastsprint = false;
		bool b_spingbot = false;
		bool b_adminflags = false;
		bool b_shoot_in_debug = false;
		/////////////////////////////////////////////////////////////////////////////////////

		///////////////////                night                          //////////////////////
		bool b_bright_night = false;
	};

    #define config configuration::settings::get()
}