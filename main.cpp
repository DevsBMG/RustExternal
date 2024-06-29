#include "menu/includes.h"
bool focus_window = false;
void render_menu()
{
	static auto next_frame = std::chrono::steady_clock::now();
	std::this_thread::sleep_until(next_frame);
	next_frame += std::chrono::milliseconds(1000 / 165);

	if (GetAsyncKeyState(VK_INSERT) & 1) {
		if ((GetTickCount64() - last_tick) > 1000) {
			config.show_menu = !config.show_menu;
			last_tick = GetTickCount64();
		}
	}

	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImGui::GetIO().MouseDrawCursor = config.show_menu;

	const auto draw = ImGui::GetBackgroundDrawList();
	{
		esp::draw_entities(draw);
	}

	if (config.show_menu)
	{
		input_handler();
		ImGui::SetNextWindowSize(ImVec2(687, 572));
		ImGui::PushFont(verdana);
		ImGui::Begin(skCrypt("codeine.wtf"), 0, ImGuiWindowFlags_NoDecoration);
		{
			auto draw = ImGui::GetWindowDrawList();
			ImVec2 pos = ImGui::GetWindowPos();
			ImVec2 size = ImGui::GetWindowSize();

			{//style
				draw->AddRectFilledMultiColor(ImVec2(pos.x, pos.y + 30), ImVec2(pos.x + size.x, pos.y + size.y), ImColor(31, 30, 33), ImColor(32, 31, 33), ImColor(33, 30, 32), ImColor(33, 27, 30));
				draw->AddRectFilledMultiColor(ImVec2(pos.x, pos.y), ImVec2(pos.x + size.x, pos.y + 35), ImColor(23, 22, 25), ImColor(25, 24, 26), ImColor(33, 33, 37), ImColor(37, 35, 40));
				draw->AddLine(ImVec2(pos.x, pos.y + 35), ImVec2(pos.x + size.x, pos.y + 35), ImColor(70, 66, 68, 160), 1.0f);
				draw->AddText(verdana, 16, ImVec2(pos.x + 8, pos.y + 10), ImColor(255, 255, 255), skCrypt("codeine.wtf"));
				draw->AddRectFilledMultiColor(ImVec2(pos.x, pos.y + 36), ImVec2(pos.x + size.x, pos.y + 66), ImColor(23, 22, 25), ImColor(33, 33, 37), ImColor(33, 33, 37), ImColor(37, 35, 40));
				draw->AddLine(ImVec2(pos.x, pos.y + 66), ImVec2(pos.x + size.x, pos.y + 66), ImColor(70, 66, 68, 160), 0.5f);
				draw->AddRect(ImVec2(pos.x + 1, pos.y + 1), ImVec2(pos.x + size.x - 1, pos.y + size.y - 1), ImColor(50, 50, 50), 0, 0, 1.0f);
			}
			if (config.b_fov_picker)
				Controls::ColorPicker(skCrypt("FOV COLOR"), &config.b_fov_picker, config.fov_color);

			if (config.b_crosshair_picker)
				Controls::ColorPicker(skCrypt("CROSSHAIR COLOR"), &config.b_crosshair_picker, config.crosshair_color);

			if (config.b_box_picker)
				Controls::ColorPicker(skCrypt("BOX COLOR"), &config.b_box_picker, config.box_color);

			if (config.b_outline_picker)
				Controls::ColorPicker(skCrypt("BOX OUTLINE COLOR"), &config.b_outline_picker, config.outline_color);

			if (config.b_fill_picker)
				Controls::ColorPicker(skCrypt("FILLED COLOR"), &config.b_fill_picker, config.fill_color);

			if (config.b_health_percent_picker)
				Controls::ColorPicker(skCrypt("HEALTH PERCENT COLOR"), &config.b_health_percent_picker, config.health_percent_color);

			if (config.b_health_outline_picker)
				Controls::ColorPicker(skCrypt("HEALTH OUTLINE COLOR"), &config.b_health_outline_picker, config.health_outline_color);

			if (config.b_skeleton_picker)
				Controls::ColorPicker(skCrypt("SKELETON COLOR"), &config.b_skeleton_picker, config.skeleton_color);

			if (config.b_lines_picker)
				Controls::ColorPicker(skCrypt("SNAPLINE COLOR"), &config.b_lines_picker, config.line_color);

			if (config.b_name_picker)
				Controls::ColorPicker(skCrypt("NAME TEXT COLOR"), &config.b_name_picker, config.name_color);

			if (config.b_distance_picker)
				Controls::ColorPicker(skCrypt("DISTANCE TEXT COLOR"), &config.b_distance_picker, config.distance_color);


			{//tabs
				ImGui::SetCursorPos(ImVec2(4, 38));
				if (Controls::RadioButton(skCrypt("AIMBOT"), ImVec2(70, 26), config.selected_tab == 0)) { config.selected_tab = 0; config.transition_loaded = true; config.transition_alpha = 1.0f; }

				ImGui::SetCursorPos(ImVec2(90, 38));
				if (Controls::RadioButton(skCrypt("PLAYER VISUAL"), ImVec2(100, 26), config.selected_tab == 1)) { config.selected_tab = 1; config.transition_loaded = true; config.transition_alpha = 1.0f; }

				ImGui::SetCursorPos(ImVec2(205, 38));
				if (Controls::RadioButton(skCrypt("ITEM VISUAL"), ImVec2(100, 26), config.selected_tab == 2)) { config.selected_tab = 2; config.transition_loaded = true; config.transition_alpha = 1.0f; }

				ImGui::SetCursorPos(ImVec2(325, 38));
				if (Controls::RadioButton(skCrypt("WORLD VISUAL"), ImVec2(100, 26), config.selected_tab == 3)) { config.selected_tab = 3; config.transition_loaded = true; config.transition_alpha = 1.0f; }

				ImGui::SetCursorPos(ImVec2(450, 38));
				if (Controls::RadioButton(skCrypt("MISCELLANEOUS"), ImVec2(100, 26), config.selected_tab == 4)) { config.selected_tab = 4; config.transition_loaded = true; config.transition_alpha = 1.0f; }

				ImGui::SetCursorPos(ImVec2(570, 38));
				if (Controls::RadioButton(skCrypt("CONFIG"), ImVec2(70, 26), config.selected_tab == 5)) { config.selected_tab = 5; config.transition_loaded = true; config.transition_alpha = 1.0f; }
			}

			if (config.selected_tab == 0)
			{
				ImGui::SetCursorPos(ImVec2(16, 105));
				Controls::GroupBox(skCrypt("AIM"), ImColor(140, 140, 140), ImVec2(320, 450));
				{
					{// Toggle 1
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 146), ImColor(140, 140, 140), skCrypt("ENABLE"));

						ImGui::SetCursorPos(ImVec2(170, 145));
						Controls::Toggle(skCrypt("ENABLE"), &config.b_aimbot, ImVec2(20, 20));
					}

					{// Toggle 2
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 176), ImColor(140, 140, 140), skCrypt("ON KEY PRESS"));

						ImGui::SetCursorPos(ImVec2(170, 175));
						Controls::Toggle(skCrypt("ON KEY PRESS"), &config.b_on_key, ImVec2(20, 20));

						ImGui::SetCursorPos(ImVec2(205, 175));
						Controls::HotkeyButton(config.aimkey, Controls::ChangeKey, config.aim_status);
					}

					{// Toggle 3
						
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 206), ImColor(140, 140, 140), skCrypt("AIM TYPE"));

						ImGui::SetCursorPos(ImVec2(170, 205));
						Controls::ItemSelector(skCrypt("AIM TYPE"), config.AimType.data(), static_cast<int>(config.AimType.size()), config.aim, ImVec2(150, 20));
					}

					{// Toggle 4
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 236), ImColor(140, 140, 140), "AIM BONE");

						ImGui::SetCursorPos(ImVec2(170, 235));
						Controls::ItemSelector(skCrypt("AIM BONE"), config.bones.data(), static_cast<int>(config.bones.size()), config.aimbone, ImVec2(150, 20));
					}
				}

				ImGui::SetCursorPos(ImVec2(350, 105));
				Controls::GroupBox(skCrypt("SETTINGS"), ImColor(140, 140, 140), ImVec2(320, 218));
				{
					{// Toggle 1
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 146), ImColor(140, 140, 140), skCrypt("FIELD OF VIEW"));

						ImGui::SetCursorPos(ImVec2(504, 145));
						ImGui::SetNextItemWidth(150);
						ImGui::SliderFloat(skCrypt("##FIELD OF VIEW"), &config.aim_fov, 1.f, 750.f);
					}

					{// Toggle 2
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 176), ImColor(140, 140, 140), skCrypt("AIM SMOOTH"));

						ImGui::SetCursorPos(ImVec2(504, 175));
						ImGui::SetNextItemWidth(150);
						ImGui::SliderFloat(skCrypt("##AIM SMOOTH"), &config.aim_smooth, 2.f, 10.f);
					}
				}

				ImGui::SetCursorPos(ImVec2(350, 337));
				Controls::GroupBox(skCrypt("MISC"), ImColor(140, 140, 140), ImVec2(320, 218));
				{
					{// Toggle 1
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 379), ImColor(140, 140, 140), skCrypt("DRAW FOV CIRCLE"));

						ImGui::SetCursorPos(ImVec2(504, 378));
						Controls::Toggle(skCrypt("DRAW FOV CIRCLE"), &config.b_draw_fov, ImVec2(20, 20));

						ImGui::SetCursorPos(ImVec2(574, 378));
						if (Controls::Button(skCrypt("FOV COLOR"), ImVec2(80, 20))) {
							config.b_fov_picker = true;
						}
					}

					{// Toggle 2
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 409), ImColor(140, 140, 140), skCrypt("DRAW CROSSHAIR"));

						ImGui::SetCursorPos(ImVec2(504, 407));
						Controls::Toggle(skCrypt("DRAW CROSSHAIR"), &config.b_draw_crosshair, ImVec2(20, 20));

						ImGui::SetCursorPos(ImVec2(574, 407));
						if (Controls::Button(skCrypt("C COLOR"), ImVec2(80, 20))) {
							config.b_crosshair_picker = true;
						}
					}

					{// Toggle 3
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 439), ImColor(140, 140, 140), skCrypt("CROSSHAIR SIZE"));

						ImGui::SetCursorPos(ImVec2(504, 438));
						ImGui::SetNextItemWidth(150);
						ImGui::SliderInt(skCrypt("##CROSSHAIR SIZE"), &config.crosshair_size, 1, 25, 0, 0);
					}
				}
			}
			else if (config.selected_tab == 1)
			{
				ImGui::SetCursorPos(ImVec2(16, 105));
				Controls::GroupBox(skCrypt("VISUAL"), ImColor(140, 140, 140), ImVec2(320, 450));
				{
					draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 146), ImColor(140, 140, 140), skCrypt("BOX"));

					ImGui::SetCursorPos(ImVec2(170, 145));
					Controls::Toggle(skCrypt("BOX"), &config.b_box, ImVec2(20, 20));

					ImGui::SetCursorPos(ImVec2(205, 145));
					if (Controls::Button(skCrypt("B COLOR"), ImVec2(80, 20))) {
						config.b_box_picker = true;
					}

					draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 176), ImColor(140, 140, 140), skCrypt("BOX TYPE"));

					ImGui::SetCursorPos(ImVec2(170, 175));
					Controls::ItemSelector(skCrypt("BOX TYPE"), config.box_types.data(), static_cast<int>(config.box_types.size()), config.box_type, ImVec2(150, 20));

					draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 206), ImColor(140, 140, 140), skCrypt("BOX OUTLINE"));

					ImGui::SetCursorPos(ImVec2(170, 205));
					Controls::Toggle(skCrypt("BOX OUTLINE"), &config.b_outline, ImVec2(20, 20));

					ImGui::SetCursorPos(ImVec2(205, 205));
					if (Controls::Button(skCrypt("B O COLOR"), ImVec2(80, 20))) {
						config.b_outline_picker = true;
					}

					draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 236), ImColor(140, 140, 140), skCrypt("FILLED"));

					ImGui::SetCursorPos(ImVec2(170, 235));
					Controls::Toggle(skCrypt("FILLED"), &config.b_fill, ImVec2(20, 20));

					ImGui::SetCursorPos(ImVec2(205, 235));
					if (Controls::Button(skCrypt("F COLOR"), ImVec2(80, 20))) {
						config.b_fill_picker = true;
					}

					draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 266), ImColor(140, 140, 140), skCrypt("HEALTH BAR"));

					ImGui::SetCursorPos(ImVec2(170, 265));
					Controls::Toggle(skCrypt("HEALTH BAR"), &config.b_health, ImVec2(20, 20));

					ImGui::SetCursorPos(ImVec2(205, 265));
					if (Controls::Button(skCrypt("H O COLOR"), ImVec2(80, 20))) {
						config.b_health_outline_picker = true;
					}

					draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 296), ImColor(140, 140, 140), skCrypt("HEALTH PERCENT"));

					ImGui::SetCursorPos(ImVec2(170, 295));
					Controls::Toggle(skCrypt("HEALTH PERCENT"), &config.b_health_percent, ImVec2(20, 20));

					ImGui::SetCursorPos(ImVec2(205, 295));
					if (Controls::Button(skCrypt("H P COLOR"), ImVec2(80, 20))) {
						config.b_health_percent_picker = true;
					}

					draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 326), ImColor(140, 140, 140), skCrypt("SKELETON"));
					ImGui::SetCursorPos(ImVec2(170, 325));
					Controls::Toggle(skCrypt("SKELETON"), &config.b_skeleton, ImVec2(20, 20));

					ImGui::SetCursorPos(ImVec2(205, 325));
					if (Controls::Button(skCrypt("S COLOR"), ImVec2(80, 20))) {
						config.b_skeleton_picker = true;
					}

					draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 356), ImColor(140, 140, 140), skCrypt("SNAP LINE"));

					ImGui::SetCursorPos(ImVec2(170, 355));
					Controls::Toggle(skCrypt("SNAP LINE"), &config.b_lines, ImVec2(20, 20));

					ImGui::SetCursorPos(ImVec2(205, 355));
					if (Controls::Button(skCrypt("L COLOR"), ImVec2(80, 20))) {
						config.b_lines_picker = true;
					}


					draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 386), ImColor(140, 140, 140), skCrypt("LINE POS"));

					ImGui::SetCursorPos(ImVec2(170, 385));
					Controls::ItemSelector(skCrypt("LINE POS"), config.line_types.data(), static_cast<int>(config.line_types.size()), config.line_type, ImVec2(150, 20));

					draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 416), ImColor(140, 140, 140), skCrypt("NAME TEXT"));

					ImGui::SetCursorPos(ImVec2(170, 415));
					Controls::Toggle(skCrypt("NAME TEXT"), &config.b_name, ImVec2(20, 20));

					ImGui::SetCursorPos(ImVec2(205, 415));
					if (Controls::Button(skCrypt("N COLOR"), ImVec2(80, 20))) {
						config.b_name_picker = true;
					}

					draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 446), ImColor(140, 140, 140), skCrypt("DISTANCE TEXT"));

					ImGui::SetCursorPos(ImVec2(170, 445));
					Controls::Toggle(skCrypt("DISTANCE TEXT"), &config.b_distance, ImVec2(20, 20));

					ImGui::SetCursorPos(ImVec2(205, 445));
					if (Controls::Button(skCrypt("D COLOR"), ImVec2(80, 20))) {
						config.b_distance_picker = true;
					}

					draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 476), ImColor(140, 140, 140), skCrypt("RENDER DISTANCE"));

					ImGui::SetCursorPos(ImVec2(170, 475));
					ImGui::SetNextItemWidth(150);
					ImGui::SliderFloat(skCrypt("##DISTANCE"), &config.render_distance, 0.f, 500.f);


				}

				ImGui::SetCursorPos(ImVec2(350, 105));
				Controls::GroupBox(skCrypt("SETTINGS"), ImColor(140, 140, 140), ImVec2(320, 132));
				{
					{// Toggle 1
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 146), ImColor(140, 140, 140), skCrypt("VIS CHECK"));

						ImGui::SetCursorPos(ImVec2(504, 145));
						Controls::Toggle(skCrypt("RENDER ONLY"), &config.b_visible_only, ImVec2(20, 20));
					}

					{// Toggle 2
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 176), ImColor(140, 140, 140), skCrypt("RENDER KNOCKED"));

						ImGui::SetCursorPos(ImVec2(504, 175));
						ImGui::SetNextItemWidth(150);
						Controls::Toggle(skCrypt("RENDER KNOCKED"), &config.b_render_knocked, ImVec2(20, 20));
					}

					{// Toggle 3
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 206), ImColor(140, 140, 140), skCrypt("RENDER SLEEPER"));

						ImGui::SetCursorPos(ImVec2(504, 205));
						Controls::Toggle(skCrypt("RENDER SLEEPER"), &config.b_render_sleeper, ImVec2(20, 20));
					}
				}

				ImGui::SetCursorPos(ImVec2(350, 252));
				Controls::GroupBox(skCrypt("Chams"), ImColor(140, 140, 140), ImVec2(320, 302));
				{
					{// Toggle 1
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 306), ImColor(140, 140, 140), skCrypt("HAND & GUN"));

						ImGui::SetCursorPos(ImVec2(504, 305));
						Controls::ItemSelector(skCrypt("HANDGUN"), config.chams_b.data(), static_cast<int>(config.chams_b.size()), chams_hands, ImVec2(150, 20));

					}
					{// Toggle 2
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 336), ImColor(140, 140, 140), skCrypt("PLAYER"));

						ImGui::SetCursorPos(ImVec2(504, 335));
						Controls::ItemSelector(skCrypt("PLAYERCHAMS"), config.Hand_cham_b.data(), static_cast<int>(config.Hand_cham_b.size()), chams, ImVec2(150, 20));
					}
				}
			}
			else if (config.selected_tab == 2)
			{
				ImGui::SetCursorPos(ImVec2(16, 105));
				Controls::GroupBox(skCrypt("ITEMS"), ImColor(140, 140, 140), ImVec2(320, 450));
				{
					{// Toggle 1
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 144), ImColor(140, 140, 140), skCrypt("SUPPLYDROP"));

						ImGui::SetCursorPos(ImVec2(170, 143));
						Controls::Toggle(skCrypt("SUPPLYDROP"), &config.b_supply, ImVec2(20, 20));
					}
					{// Toggle 2
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 174), ImColor(140, 140, 140), skCrypt("DROPITEM"));

						ImGui::SetCursorPos(ImVec2(170, 173));
						Controls::Toggle(skCrypt("DROPITEM"), &config.b_dropitem, ImVec2(20, 20));
					}
					{// Toggle 3
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 204), ImColor(140, 140, 140), skCrypt("BED"));

						ImGui::SetCursorPos(ImVec2(170, 203));
						Controls::Toggle(skCrypt("BED"), &config.b_bed, ImVec2(20, 20));
					}
					{// Toggle 4
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 234), ImColor(140, 140, 140), skCrypt("FLAMETURRET"));

						ImGui::SetCursorPos(ImVec2(170, 233));
						Controls::Toggle(skCrypt("FLAMETURRET"), &config.b_flameturret, ImVec2(20, 20));
					}
					{// Toggle 5
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 264), ImColor(140, 140, 140), skCrypt("SAMSITE"));

						ImGui::SetCursorPos(ImVec2(170, 263));
						Controls::Toggle(skCrypt("SAMSITE"), &config.b_samsite, ImVec2(20, 20));
					}
					{// Toggle 6
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 294), ImColor(140, 140, 140), skCrypt("GUNTRAP"));

						ImGui::SetCursorPos(ImVec2(170, 293));
						Controls::Toggle(skCrypt("GUNTRAP"), &config.b_guntrap, ImVec2(20, 20));
					}
					{// Toggle 7
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 324), ImColor(140, 140, 140), skCrypt("BEARTRAP"));

						ImGui::SetCursorPos(ImVec2(170, 323));
						Controls::Toggle(skCrypt("BEARTRAP"), &config.b_beartrap, ImVec2(20, 20));
					}
					{// Toggle 8
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 354), ImColor(140, 140, 140), skCrypt("LANDMINE"));

						ImGui::SetCursorPos(ImVec2(170, 353));
						Controls::Toggle(skCrypt("LANDMINE"), &config.b_landmine, ImVec2(20, 20));
					}
					{// Toggle 9
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 384), ImColor(140, 140, 140), skCrypt("AUTOTURRET"));

						ImGui::SetCursorPos(ImVec2(170, 383));
						Controls::Toggle(skCrypt("AUTOTURRET"), &config.b_autoturret, ImVec2(20, 20));
					}
					{// Toggle 10
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 414), ImColor(140, 140, 140), skCrypt("HORSE"));

						ImGui::SetCursorPos(ImVec2(170, 413));
						Controls::Toggle(skCrypt("HORSE"), &config.b_ridablehorse, ImVec2(20, 20));
					}
					{// Toggle 11
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 444), ImColor(140, 140, 140), skCrypt("BOAT"));

						ImGui::SetCursorPos(ImVec2(170, 443));
						Controls::Toggle(skCrypt("BOAT"), &config.b_tugboat, ImVec2(20, 20));
					}
					{// Toggle 12
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 474), ImColor(140, 140, 140), skCrypt("SCRAPHELICOPTER"));

						ImGui::SetCursorPos(ImVec2(170, 473));
						Controls::Toggle(skCrypt("SCRAPHELICOPTER"), &config.b_scraptransporthelicopter, ImVec2(20, 20));
					}
					{// Toggle 13
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 504), ImColor(140, 140, 140), skCrypt("MINICOPTER"));

						ImGui::SetCursorPos(ImVec2(170, 503));
						Controls::Toggle(skCrypt("MINICOPTER"), &config.b_minicopter, ImVec2(20, 20));
					}
					{// Toggle 14
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 534), ImColor(140, 140, 140), skCrypt("BACKPACK"));

						ImGui::SetCursorPos(ImVec2(170, 533));
						Controls::Toggle(skCrypt("BACKPACK"), &config.b_backpack, ImVec2(20, 20));
					}
				}

				ImGui::SetCursorPos(ImVec2(350, 105));
				Controls::GroupBox(skCrypt("ORE"), ImColor(140, 140, 140), ImVec2(320, 132));
				{
					{// Toggle 1
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 146), ImColor(140, 140, 140), skCrypt("STONE"));
						ImGui::SetCursorPos(ImVec2(504, 145));
						Controls::Toggle(skCrypt("STONE"), &config.b_stone, ImVec2(20, 20));
					}

					{// Toggle 2
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 176), ImColor(140, 140, 140), skCrypt("METAL"));

						ImGui::SetCursorPos(ImVec2(504, 175));
						Controls::Toggle(skCrypt("METAL"), &config.b_metal, ImVec2(20, 20));
					}
					{// Toggle 3
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 206), ImColor(140, 140, 140), skCrypt("SULFER"));

						ImGui::SetCursorPos(ImVec2(504, 205));
						Controls::Toggle(skCrypt("SULFER"), &config.b_sulfur, ImVec2(20, 20));
					}
				}

				ImGui::SetCursorPos(ImVec2(350, 252));
				Controls::GroupBox(skCrypt("OTHER"), ImColor(140, 140, 140), ImVec2(320, 302));
				{
					{// Toggle 1
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 306), ImColor(140, 140, 140), skCrypt("HEMP"));

						ImGui::SetCursorPos(ImVec2(504, 305));
						Controls::Toggle(skCrypt("HEMP"), &config.b_hemp, ImVec2(20, 20));

					}
					{// Toggle 2
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 336), ImColor(140, 140, 140), skCrypt("WOOD"));

						ImGui::SetCursorPos(ImVec2(504, 335));
						Controls::Toggle(skCrypt("WOOD"), &config.b_wood, ImVec2(20, 20));
					}
					{// Toggle 3
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 366), ImColor(140, 140, 140), skCrypt("FOOD"));

						ImGui::SetCursorPos(ImVec2(504, 365));
						Controls::Toggle(skCrypt("FOOD"), &config.b_food, ImVec2(20, 20));
					}
					{// Toggle 4
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 396), ImColor(140, 140, 140), skCrypt("DISTANCE"));
						ImGui::SetCursorPos(ImVec2(504, 395));
						ImGui::SetNextItemWidth(150);
						ImGui::SliderFloat(skCrypt("##DISTANCE"), &config.render_items, 0.f, 500.f);
					}
				}
			}
			else if (config.selected_tab == 3)
			{
				ImGui::SetCursorPos(ImVec2(16, 105));
				Controls::GroupBox(skCrypt("WORLD VISUAL"), ImColor(140, 140, 140), ImVec2(320, 450));
				{
					{// Toggle 1
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 144), ImColor(140, 140, 140), skCrypt("BRIGHT-NIGHT"));

						ImGui::SetCursorPos(ImVec2(170, 143));
						Controls::Toggle(skCrypt("BRIGHT-NIGHT"), &config.b_bright_night, ImVec2(20, 20));
					}
				}

				ImGui::SetCursorPos(ImVec2(350, 105));
				Controls::GroupBox(skCrypt("SKY VISUAL"), ImColor(140, 140, 140), ImVec2(320, 132));
				{

				}

				ImGui::SetCursorPos(ImVec2(350, 252));
				Controls::GroupBox(skCrypt("GROUND VISAL"), ImColor(140, 140, 140), ImVec2(320, 302));
				{

				}
			}
			else if (config.selected_tab == 4)
			{
				ImGui::SetCursorPos(ImVec2(16, 105));
				Controls::GroupBox(skCrypt("MISCELLANEOUS"), ImColor(140, 140, 140), ImVec2(320, 450));
				{
					{// Toggle 1
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 144), ImColor(140, 140, 140), skCrypt("NO-RECOIL"));

						ImGui::SetCursorPos(ImVec2(170, 143));
						Controls::Toggle(skCrypt("NO-RECOIL"), &config.b_norecoli, ImVec2(20, 20));
					}
					{// Toggle 2
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 174), ImColor(140, 140, 140), skCrypt("NO-SPREAD"));

						ImGui::SetCursorPos(ImVec2(170, 173));
						Controls::Toggle(skCrypt("NO-SPREAD"), &config.b_nospread, ImVec2(20, 20));
					}
					{// Toggle 3
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 204), ImColor(140, 140, 140), skCrypt("NO-SWAY"));

						ImGui::SetCursorPos(ImVec2(170, 203));
						Controls::Toggle(skCrypt("NO-SWAY"), &config.b_nosway, ImVec2(20, 20));
					}
					{// Toggle 4
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 234), ImColor(140, 140, 140), skCrypt("EOKA"));

						ImGui::SetCursorPos(ImVec2(170, 233));
						Controls::Toggle(skCrypt("EOKA"), &config.b_eoka, ImVec2(20, 20));
					}
					{// Toggle 5
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 264), ImColor(140, 140, 140), skCrypt("AUTOMATIC"));

						ImGui::SetCursorPos(ImVec2(170, 263));
						Controls::Toggle(skCrypt("AUTOMATIC"), &config.b_automatic, ImVec2(20, 20));
					}
					{// Toggle 5
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 294), ImColor(140, 140, 140), skCrypt("BIG-BULLET"));

						ImGui::SetCursorPos(ImVec2(170, 293));
						Controls::Toggle(skCrypt("BIG-BULLET"), &config.b_thiccbullet, ImVec2(20, 20));
					}
					{// Toggle 5
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 324), ImColor(140, 140, 140), skCrypt("RELOAD-BAR"));

						ImGui::SetCursorPos(ImVec2(170, 323));
						Controls::Toggle(skCrypt("RELOAD-BAR"), &config.b_reload_bar, ImVec2(20, 20));
					}
					{// Toggle 6
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 354), ImColor(140, 140, 140), skCrypt("SPUDER-MAN"));

						ImGui::SetCursorPos(ImVec2(170, 353));
						Controls::Toggle(skCrypt("SPUDER-MAN"), &config.b_spyderman, ImVec2(20, 20));
					}
					{// Toggle 7
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 384), ImColor(140, 140, 140), skCrypt("ZOOM"));

						ImGui::SetCursorPos(ImVec2(170, 383));
						Controls::HotkeyButton1(config.Zoomkey, Controls::ChangeKey1, config.Zoom_status);
					}
					{// Toggle 8
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 414), ImColor(140, 140, 140), skCrypt("ZOOMS"));

						ImGui::SetCursorPos(ImVec2(170, 413));
						ImGui::SetNextItemWidth(150);
						ImGui::SliderFloat(skCrypt("##ZOOMSER"), &config.Zoom_float, 0.f, 90.f);
					}
					{// Toggle 9
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 444), ImColor(140, 140, 140), skCrypt("FOV"));

						ImGui::SetCursorPos(ImVec2(170, 443));
						ImGui::SetNextItemWidth(150);
						ImGui::SliderFloat(skCrypt("##FOVV"), &config.ZoomFOV_float, 60.f, 135.f);
					}
					{// Toggle 10
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 474), ImColor(140, 140, 140), skCrypt("ADMIN-FLAGS"));

						ImGui::SetCursorPos(ImVec2(170, 473));
						Controls::Toggle(skCrypt("ADMIN"), &config.b_adminflags, ImVec2(20, 20));
					}
					{// Toggle 11
						draw->AddText(verdana, 16, ImVec2(pos.x + 30, pos.y + 504), ImColor(140, 140, 140), skCrypt("ALWAYS-SHOOT"));

						ImGui::SetCursorPos(ImVec2(170, 503));
						Controls::Toggle(skCrypt("ALWAYS-SHOOT"), &config.b_alwaysshoot, ImVec2(20, 20));
					}
				}

				ImGui::SetCursorPos(ImVec2(350, 105));
				Controls::GroupBox(skCrypt("EXPLOITS"), ImColor(140, 140, 140), ImVec2(320, 132));
				{
					{// Toggle 1
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 146), ImColor(140, 140, 140), skCrypt("INF-JUMP"));
						ImGui::SetCursorPos(ImVec2(504, 145));

						Controls::Toggle(skCrypt("INF-JUMP"), &config.b_infjump, ImVec2(20, 20));
					}
					{// Toggle 2
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 176), ImColor(140, 140, 140), skCrypt("NO-ANIMATION"));
						ImGui::SetCursorPos(ImVec2(504, 175));
						Controls::Toggle(skCrypt("NO-ANIMATION"), &config.b_noanaimation, ImVec2(20, 20));
					}
					{// Toggle 2
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 206), ImColor(140, 140, 140), skCrypt("OMNI-SPRINT"));
						ImGui::SetCursorPos(ImVec2(504, 205));

						Controls::Toggle(skCrypt("OMNI-SPRINT"), &config.b_fastsprint, ImVec2(20, 20)); 
					}
				}

				ImGui::SetCursorPos(ImVec2(350, 252));
				Controls::GroupBox(skCrypt("LOCAL"), ImColor(140, 140, 140), ImVec2(320, 302));
				{
					{// Toggle 1
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 306), ImColor(140, 140, 140), skCrypt("INSTA-KILL"));

						ImGui::SetCursorPos(ImVec2(504, 305));
						Controls::Toggle(skCrypt("INSTA-KILL"), &config.b_instakill, ImVec2(20, 20));

					}
					{// Toggle 2
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 336), ImColor(140, 140, 140), skCrypt("SPIN-BOT"));

						ImGui::SetCursorPos(ImVec2(504, 335));
						Controls::Toggle(skCrypt("SPIN-BOT"), &config.b_spingbot, ImVec2(20, 20));
					}
					{// Toggle 3
						draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 366), ImColor(140, 140, 140), skCrypt("FLY-HACK"));

						ImGui::SetCursorPos(ImVec2(504, 365));
						Controls::HotkeyButton2(config.FLYkey, Controls::ChangeKe2, config.FLY_status);
					}
				}
			}
			else if (config.selected_tab == 5)
			{
				draw->AddText(verdana, 16, ImVec2(pos.x + 17, pos.y + 77), ImColor(140, 140, 140), skCrypt("SELECTED CONFIG: "));

				std::string selectedName = config_.GetSelectedName();

				std::transform(selectedName.begin(), selectedName.end(), selectedName.begin(),
					[](unsigned char c) { return std::toupper(c); });

				size_t found = selectedName.find(skCrypt(".JSON"));
				if (found != std::string::npos) {
					selectedName = selectedName.substr(0, found);
				}

				draw->AddText(verdana, 16, ImVec2(pos.x + 137, pos.y + 77), ImColor(140, 140, 140), selectedName.c_str());

				ImGui::SetCursorPos(ImVec2(16, 105));
				Controls::GroupBox(skCrypt("CONFIG VIEWER"), ImColor(140, 140, 140), ImVec2(320, 450));
				{
					ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 0.f);
					ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.f / 255.f, 0.f / 255.f, 0.f / 255.f, 0.f / 255.f));

					ImGui::SetCursorPos(ImVec2(19, 140));
					ImGui::BeginListBox(skCrypt("##config_box"), ImVec2(314, 414));
					{
						for (size_t i = 0; i < config_.Size(); ++i)
						{
							const bool isSelected = (config_.Selected() == i);

							if (ImGui::Selectable(config_[i], isSelected))
								config_.Selected() = i;

							if (isSelected)
								ImGui::SetItemDefaultFocus();
						}
					}
					ImGui::EndListBox();

					ImGui::PopStyleVar(1); ImGui::PopStyleColor();
				}

				ImGui::SetCursorPos(ImVec2(350, 105));
				Controls::GroupBox(skCrypt("CONFIGURATION SETTINGS"), ImColor(140, 140, 140), ImVec2(320, 222));
				{
					draw->AddText(verdana, 16, ImVec2(pos.x + 364, pos.y + 146), ImColor(140, 140, 140), skCrypt("CONFIG NAME"));

					ImGui::SetCursorPos(ImVec2(504, 145));
					ImGui::SetNextItemWidth(150);
					ImGui::InputText(skCrypt("##name"), config_.nameBuffer, IM_ARRAYSIZE(config_.nameBuffer), ImGuiInputTextFlags_CharsNoBlank);

					ImGui::SetCursorPos(ImVec2(364, 175));
					if (Controls::Button(skCrypt("CREATE CONFIG"), ImVec2(290, 20))) {
						config_.Create();
					}

					ImGui::SetCursorPos(ImVec2(364, 205));
					if (Controls::Button(skCrypt("DELETE CONFIG"), ImVec2(290, 20))) {
						config_.Delete();
					}

					ImGui::SetCursorPos(ImVec2(364, 235));
					if (Controls::Button(skCrypt("REFRESH ALL CONFIGS"), ImVec2(290, 20))) {
						config_.Refresh();
					}

					ImGui::SetCursorPos(ImVec2(364, 265));
					if (Controls::Button(skCrypt("LOAD CONFIG"), ImVec2(290, 20))) {
						config_.Load();
					}

					ImGui::SetCursorPos(ImVec2(364, 295));
					if (Controls::Button(skCrypt("SAVE CONFIG"), ImVec2(290, 20))) {
						config_.Save();
					}
				}
			}
		}

		ImGui::PopFont();
		ImGui::End();

		click_though(false);
	}
	else
	{
		click_though(true);
	}
	ImGui::EndFrame();

	direct_x9_interface::p_device->SetRenderState(D3DRS_ZENABLE, false);
	direct_x9_interface::p_device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	direct_x9_interface::p_device->SetRenderState(D3DRS_SCISSORTESTENABLE, false);

	direct_x9_interface::p_device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1.0f, 0);
	if (direct_x9_interface::p_device->BeginScene() >= 0) {
		ImGui::Render();
		ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
		direct_x9_interface::p_device->EndScene();
	}

	HRESULT result = direct_x9_interface::p_device->Present(NULL, NULL, NULL, NULL);
	if (result == D3DERR_DEVICELOST && direct_x9_interface::p_device->TestCooperativeLevel() == D3DERR_DEVICENOTRESET) {
		ImGui_ImplDX9_InvalidateDeviceObjects();
		direct_x9_interface::p_device->Reset(&direct_x9_interface::p_params);
		ImGui_ImplDX9_CreateDeviceObjects();
	}
}

DWORD get_process_id(const char* process_name) {
	DWORD process_id = 0;
	HANDLE snapshot_handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (snapshot_handle != INVALID_HANDLE_VALUE) {
		PROCESSENTRY32 process_entry;
		process_entry.dwSize = sizeof(PROCESSENTRY32);
		if (Process32First(snapshot_handle, &process_entry)) {
			do {
				if (!_stricmp(process_entry.szExeFile, process_name)) {
					process_id = process_entry.th32ProcessID;
					break;
				}
			} while (Process32Next(snapshot_handle, &process_entry));
		}
		CloseHandle(snapshot_handle);
	}
	return process_id;
}

int main()
{
	m_vm.get()->setup(e(L"RustClient.exe"));
	std::srand(std::time(nullptr));
	//enity loop
	std::thread([&]()
		{
			while (true)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				if (entity_loop::initialize())
					entity_loop::get_list();
				else
					entity_loop::clear();
			}
		}
	).detach();
	////aimbot
	std::thread([&]()
		{
			while (true)
			{
				if (!config.b_aimbot)
					std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				else
					std::this_thread::sleep_for(std::chrono::milliseconds(2));
				aimbot::aimbot_loop();
			}
		}
	).detach();
	////fast_features
	std::thread([&]()
		{
			while (true)
			{
				if (!config.b_fastsprint && !config.b_spingbot && !config.b_bright_night)
					std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				features::fast_features();
			}
		}
	).detach();
	////misc_features
	std::thread([&]()
		{
			while (true)
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(3));
				features::misc_features();
			}
		}
	).detach();

	while (focus_window == false)
	{
		DWORD ForegroundWindowProcessID;
		GetWindowThreadProcessId(GetForegroundWindow(), &ForegroundWindowProcessID);
		if (get_process_id(e("RustClient.exe")) == ForegroundWindowProcessID)
		{
			vars.game_hwnd = GetForegroundWindow();
			RECT TempRect;
			GetWindowRect(vars.game_hwnd, &TempRect);
			vars.screen_width = TempRect.right - TempRect.left;
			vars.screen_height = TempRect.bottom - TempRect.top;
			vars.screen_left = TempRect.left;
			vars.screen_right = TempRect.right;
			vars.screen_top = TempRect.top;
			vars.screen_bottom = TempRect.bottom;
			focus_window = true;
		}
	}

	overlay_window::app = "codeine.wtf";
	overlay_window::name = "codeine.wtf";

	setup_window();
	init_directx();

	ImGuiIO& io = ImGui::GetIO();
	verdana = io.Fonts->AddFontDefault();
	verdana = io.Fonts->AddFontFromFileTTF(e("C:\\Windows\\Fonts\\comicbd.ttf"), 16.0f);
	visuals = io.Fonts->AddFontFromFileTTF(skCrypt("C:\\Windows\\Fonts\\Montserrat-Regular.ttf"), 10.0f);
	io.Fonts->Build();

	while (true) main_loop();
}
