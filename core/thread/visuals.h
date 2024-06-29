#pragma once
#include "../../menu/includes.h"

auto get_rust_installation() -> std::string
{
	LONG   lResult;
	HKEY   hKey;
	char   value[64];
	DWORD  value_length = 64;
	DWORD  dwType = REG_SZ;

	lResult = RegOpenKey(HKEY_LOCAL_MACHINE, TEXT(skCrypt("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\Steam App 252490")), &hKey);
	RegQueryValueExA(hKey, skCrypt("InstallLocation"), NULL, &dwType, (LPBYTE)&value, &value_length);

	RegCloseKey(hKey);

	return value;
}

auto texture_bundle_path = get_rust_installation() + (std::string)skCrypt("\\Bundles\\items\\");

class c_texture_cache
{
private:
	std::unordered_map<std::string, IDirect3DTexture9*> texture_cache{};

	auto create_texture(LPDIRECT3DDEVICE9 device, std::string name) -> IDirect3DTexture9*
	{
		auto image_path = texture_bundle_path + name; // todo: make path dynamic
		auto* tex = LPDIRECT3DTEXTURE9();

		if (D3DXCreateTextureFromFileA(device, image_path.c_str(), &tex) != D3D_OK)
			return nullptr;

		return tex;
	}
public:
	auto get_texture(std::string item_name) -> IDirect3DTexture9*
	{
		if (texture_cache.find(item_name) != texture_cache.end())
			return texture_cache[item_name];

		auto texture = create_texture(direct_x9_interface::p_device, item_name + (std::string)skCrypt(".png"));
		if (!texture)
			return nullptr;

		texture_cache.emplace(item_name, texture);
		return texture;
	}

}; inline c_texture_cache texture_cache;


namespace esp
{
	auto draw_entities(ImDrawList* draw) -> void
	{
		ImVec2 pos = ImGui::GetWindowPos();
		ImVec2 size = ImGui::GetWindowSize();
		if (!core.player || !core.camera)
			return;

		auto v_matrix = core.camera->view_matrix();

		auto local_position = core.camera->position();

		geo::vec2_t screen_center = { (float)vars.screen_width / 2.00f, (float)vars.screen_height / 2.00f };
		if (config.b_draw_fov)
		{// fov cercle
			ImU32 color = IM_COL32(int(config.fov_color[0] * 255), int(config.fov_color[1] * 255), int(config.fov_color[2] * 255), int(config.fov_color[3] * 255));
			draw->AddCircle({ screen_center.x, screen_center.y }, config.aim_fov, color, 150 , 1.0f);
		}

		if (config.b_draw_crosshair) 
		{
			ImU32 color = IM_COL32(int(config.crosshair_color[0] * 255), int(config.crosshair_color[1] * 255), int(config.crosshair_color[2] * 255), int(config.crosshair_color[3] * 255));
			render::DrawCrosshair(draw, vars.screen_width / 2, vars.screen_height / 2, config.crosshair_size, color);
		}

		const auto projectile = core.player->get_projectile();
		if (projectile)
		{
			if (utils::is_weapon(projectile->shortname()))
			{
				const auto held = projectile->heldEntity();
				if (held)
				{
					if (config.b_reload_bar)
					{
						if (held->isReloading() && geo::reload_indicator.m_reload_time > 0.00f && geo::reload_indicator.m_reload_duration > 0.00f)
						{
							const auto current = geo::reload_indicator.m_reload_duration - geo::reload_indicator.m_reload_time;
							const auto max = geo::reload_indicator.m_reload_duration;
							const auto color = render::get_health_color(current / max);
							geo::vec2_t size = { 360.00f, 6.00f };
							geo::vec2_t position = { screen_center.x, screen_center.y + 16.00f };
							draw->AddRectFilled(
								{ position.x - (size.x / 2.00f), position.y },
								{ position.x - (size.x / 2.00f) + size.x, position.y + size.y + 1.00f },
								ImColor(0, 0, 0, (int)255.00f),
								0.00f
							);
							draw->AddRectFilled(
								{ position.x - ((size.x - 1.00f) / 2.00f), position.y + 1.00f },
								{ position.x - ((size.x - 1.00f) / 2.00f) + utils::bound((current * (size.x - 2.00f) / max) + 1.00f, 0.00f, (size.x - 2.00f)), position.y + size.y },
								ImColor((int)color.x, (int)color.y, (int)color.z, (int)255.00f),
								0.00f
							);
							render::add_text(draw, { screen_center.x - 3.00f, screen_center.y + 12.00f }, geo::vec4_t{ 255, 255, 255, 255 }, std::to_string(static_cast<std::int32_t>(geo::reload_indicator.m_reload_time / 1000.00f)));
						}
					}
				}
			}
		}

		if (local_position.is_empty())
			return;
		{
			for (const auto& entity : core.player_list)
			{
				const auto player_model = entity->playerModel();
				if (!player_model)
					continue;

				const auto model = entity->model();
				if (!model)
					continue;

				const auto bone_transform = model->boneTransforms();
				if (!bone_transform)
					continue;

				auto position = player_model->position();
				if (position.is_empty())
					continue;

				const auto display_name = entity->_displayName();
				if (!display_name)
					continue;

				auto distance = position.distance(_pos);

				auto base_pos = core.camera->world_to_screen_point(v_matrix, position);
				auto head_pos = core.camera->world_to_screen_point(v_matrix, bone_transform->get(systems::player_bones::head)->get_position());
				auto feet_pos = core.camera->world_to_screen_point(v_matrix, bone_transform->get(systems::player_bones::r_foot)->get_position());
				auto standing_pos = core.camera->world_to_screen_point(v_matrix, position + geo::vec3_t{ 0.00f, 1.90f, 0.00f });
				if (base_pos.is_empty() || head_pos.is_empty() || standing_pos.is_empty())
					continue;

				const auto box_width = (base_pos.y - standing_pos.y) * 0.45f;
				const auto box_height = (base_pos.y - head_pos.y) * 1.15f;
				const auto box = systems::box{ { base_pos.x - box_width * 0.50f, base_pos.y - box_height  }, { box_width, box_height } };

				if (config.b_box)
				{
					if (config.box_type == 0) 
					{
						if (config.b_visible_only)
						{
							if (entity->isVisible())
							{
								render::rect(draw, geo::vec2_t{ box.pos.x, box.pos.y }, box.size, ImColor(0, 94, 255), ImColor(0, 94, 255), 1, false);
							}
							else
							{
								render::rect(draw, geo::vec2_t{ box.pos.x, box.pos.y }, box.size, ImColor(255, 0, 25), ImColor(255, 0, 25) , 1 , false);
							}
						}
						else 
						{
							ImU32 color = IM_COL32(int(config.box_color[0] * 255), int(config.box_color[1] * 255), int(config.box_color[2] * 255), int(config.box_color[3] * 255));
							ImU32 color_outline = IM_COL32(int(config.outline_color[0] * 255), int(config.outline_color[1] * 255), int(config.outline_color[2] * 255), int(config.outline_color[3] * 255));
							render::rect(draw, geo::vec2_t{ box.pos.x, box.pos.y }, box.size, color, color_outline, 1, config.b_outline);
						}
					}
					else if (config.box_type == 1) 
					{
						if (config.b_visible_only)
						{
							if (entity->isVisible())
							{
								render::DrawCornerBox(draw, box.pos.x, box.pos.y, box.size.x, box.size.y, ImColor(0, 94, 255), ImColor(0, 94, 255));
							}
							else {
								render::DrawCornerBox(draw, box.pos.x, box.pos.y, box.size.x, box.size.y, ImColor(255, 0, 25), ImColor(255, 0, 25));
							}
						}
						else {
							ImU32 color = IM_COL32(int(config.box_color[0] * 255), int(config.box_color[1] * 255), int(config.box_color[2] * 255), int(config.box_color[3] * 255));
							ImU32 color_outline = IM_COL32(int(config.outline_color[0] * 255), int(config.outline_color[1] * 255), int(config.outline_color[2] * 255), int(config.outline_color[3] * 255));
							render::DrawCornerBox(draw, box.pos.x, box.pos.y, box.size.x, box.size.y, color, color_outline);
						}
					}
				}
				if (config.b_fill)
				{
					ImU32 fill_color = IM_COL32(int(config.fill_color[0] * 255), int(config.fill_color[1] * 255), int(config.fill_color[2] * 255), int(config.fill_color[3] * 255));
					render::filled_rect(draw, geo::vec2_t{ box.pos.x, box.pos.y }, box.size, fill_color);
				}
				if (config.b_health)
				{
					ImU32 color = IM_COL32(int(config.health_outline_color[0] * 255), int(config.health_outline_color[1] * 255), int(config.health_outline_color[2] * 255), int(config.health_outline_color[3] * 255));
					const auto health = entity->_health();
					const auto max_health = float(entity->playerModel()->IsNpck__BackingField() ? 150.00f : 100.00f);
					float healthBarPosX = box.pos.x + box.size.x + 5.0f;
					float healthBarPosY = box.pos.y;
					float healthBarHeight = box.size.y * (health / max_health);
					draw->AddRectFilled(ImVec2(healthBarPosX, healthBarPosY),ImVec2(healthBarPosX + 3.0f, healthBarPosY + box.size.y),ImColor(20, 20, 20));
					draw->AddRectFilled(ImVec2(healthBarPosX, healthBarPosY + box.size.y - healthBarHeight),ImVec2(healthBarPosX + 3.0f, healthBarPosY + box.size.y),color);
				}
				if (config.b_health_percent)
				{
					ImU32 color = IM_COL32(int(config.health_percent_color[0] * 255), int(config.health_percent_color[1] * 255), int(config.health_percent_color[2] * 255), int(config.health_percent_color[3] * 255));
					const auto health = entity->_health();
					const auto max_health = float(entity->playerModel()->IsNpck__BackingField() ? 150.00f : 100.00f);
					float healthBarPosX = box.pos.x + box.size.x + 5.0f;
					float healthBarPosY = box.pos.y;
					float healthBarHeight = box.size.y * (health / max_health);
					char buffer[32];
					snprintf(buffer, sizeof(buffer), skCrypt("%.0f"), health);
					ImVec2 textSize = ImGui::CalcTextSize(buffer);
					ImVec2 textPos = ImVec2(healthBarPosX + 5.0f, healthBarPosY + box.size.y - healthBarHeight - textSize.y / 2.0f);
					render::draw_text(draw,textPos, buffer, color);
				}
				if (config.b_skeleton)
				{
					ImU32 color = IM_COL32(int(config.skeleton_color[0] * 255), int(config.skeleton_color[1] * 255), int(config.skeleton_color[2] * 255), int(config.skeleton_color[3] * 255));
					auto head = core.camera->world_to_screen_point(v_matrix, bone_transform->get(systems::player_bones::head)->get_position());
					if (head.is_empty()) continue;

					auto neck = core.camera->world_to_screen_point(v_matrix, bone_transform->get(systems::player_bones::neck)->get_position());
					if (neck.is_empty()) continue;

					auto r_upperarm = core.camera->world_to_screen_point(v_matrix, bone_transform->get(systems::player_bones::r_upperarm)->get_position());
					if (r_upperarm.is_empty()) continue;

					auto r_hand = core.camera->world_to_screen_point(v_matrix, bone_transform->get(systems::player_bones::r_hand)->get_position());
					if (r_hand.is_empty()) continue;

					auto l_upperarm = core.camera->world_to_screen_point(v_matrix, bone_transform->get(systems::player_bones::l_upperarm)->get_position());
					if (l_upperarm.is_empty()) continue;

					auto l_forearm = core.camera->world_to_screen_point(v_matrix, bone_transform->get(systems::player_bones::l_forearm)->get_position());
					if (l_forearm.is_empty()) continue;

					auto r_forearm = core.camera->world_to_screen_point(v_matrix, bone_transform->get(systems::player_bones::r_forearm)->get_position());
					if (r_forearm.is_empty()) continue;

					auto l_hand = core.camera->world_to_screen_point(v_matrix, bone_transform->get(systems::player_bones::l_hand)->get_position());
					if (l_hand.is_empty()) continue;

					auto spine = core.camera->world_to_screen_point(v_matrix, bone_transform->get(systems::player_bones::spine1)->get_position());
					if (spine.is_empty()) continue;

					auto r_hip = core.camera->world_to_screen_point(v_matrix, bone_transform->get(systems::player_bones::r_hip)->get_position());
					if (r_hip.is_empty()) continue;

					auto r_knee = core.camera->world_to_screen_point(v_matrix, bone_transform->get(systems::player_bones::r_knee)->get_position());
					if (r_knee.is_empty()) continue;

					auto r_foot = core.camera->world_to_screen_point(v_matrix, bone_transform->get(systems::player_bones::r_foot)->get_position());
					if (r_foot.is_empty()) continue;

					auto l_hip = core.camera->world_to_screen_point(v_matrix, bone_transform->get(systems::player_bones::l_hip)->get_position());
					if (l_hip.is_empty()) continue;

					auto l_knee = core.camera->world_to_screen_point(v_matrix, bone_transform->get(systems::player_bones::l_knee)->get_position());
					if (l_knee.is_empty()) continue;

					auto l_foot = core.camera->world_to_screen_point(v_matrix, bone_transform->get(systems::player_bones::l_foot)->get_position());
					if (l_foot.is_empty()) continue;

					render::draw_line(draw,head, neck, color, 1, false); // head

					render::draw_line(draw, neck, r_upperarm, color, 1, false); render::draw_line(draw, neck, l_upperarm, color, 1, false);//shoulders

					render::draw_line(draw, r_upperarm, r_forearm, color, 1, false); render::draw_line(draw, l_upperarm, l_forearm, color, 1, false);//bicep

					render::draw_line(draw, r_forearm, r_hand, color, 1, false); render::draw_line(draw, l_forearm, l_hand, color, 1, false);//forearm

					render::draw_line(draw, neck, spine, color, 1, false);//back

					render::draw_line(draw, spine, r_hip, color, 1, false);	render::draw_line(draw, spine, l_hip, color, 1, false);//hip flexors

					render::draw_line(draw, r_hip, r_knee, color, 1, false); render::draw_line(draw, l_hip, l_knee, color, 1, false);//thigh

					render::draw_line(draw, r_knee, r_foot, color, 1, false); render::draw_line(draw, l_knee, l_foot, color, 1, false);//shin
				}

				if (config.b_lines)
				{
					if (config.line_type == 0)
					{
						auto head = core.camera->world_to_screen_point(v_matrix, bone_transform->get(systems::player_bones::head)->get_position());
						ImU32 color = IM_COL32(int(config.line_color[0] * 255), int(config.line_color[1] * 255), int(config.line_color[2] * 255), int(config.line_color[3] * 255));
						render::DrawSnapLine(draw, head, color, 1);
					}
					if (config.line_type == 1)
					{
						auto head = core.camera->world_to_screen_point(v_matrix, bone_transform->get(systems::player_bones::penis)->get_position());
						ImU32 color = IM_COL32(int(config.line_color[0] * 255), int(config.line_color[1] * 255), int(config.line_color[2] * 255), int(config.line_color[3] * 255));
						render::DrawSnapLine(draw, head, color, 1);
					}
				}

				if (config.b_name) 
				{
					ImU32 color = IM_COL32(int(config.name_color[0] * 255), int(config.name_color[1] * 255), int(config.name_color[2] * 255), int(config.name_color[3] * 255));
					auto display_name = entity->_displayName()->buffer();
					auto name = std::string(display_name.begin(), display_name.end());
					if (name.empty()) continue;

					const float fontSize = 1.0f;
					float textWidth = ImGui::CalcTextSize(name.c_str()).x;
					float textHeight = ImGui::CalcTextSize(name.c_str()).y;
					float centerX = box.pos.x + box.size.x * 0.8f; 
					float centerY = box.pos.y - box.size.y * 0.f;
					float distanceFactor = 1.0f / distance;
					float xPos = centerX - textWidth * distanceFactor;
					float yPos = centerY - textHeight * 0.5f;

					render::draw_text(draw, geo::vec2_t{ xPos, yPos }, name, color, true, true);
				}

				if (config.b_distance)
				{
					ImU32 color = IM_COL32(int(config.distance_color[0] * 255), int(config.distance_color[1] * 255), int(config.distance_color[2] * 255), int(config.distance_color[3] * 255));
					auto distance_string = std::to_string((int)distance) + (std::string)skCrypt("M");
					if (distance_string.empty()) continue;

					const float fontSize = 1.0f;
					float textWidth = ImGui::CalcTextSize(distance_string.c_str()).x;
					float textHeight = ImGui::CalcTextSize(distance_string.c_str()).y;
					float centerX = box.pos.x + box.size.x * 0.5f;
					float centerY = box.pos.y + box.size.y + 10.0f;
					float distanceFactor = 1.0f / distance;
					float xPos = centerX - textWidth * distanceFactor;
					float yPos = centerY - textHeight * 0.5f;

					render::draw_text(draw, geo::vec2_t{ xPos, yPos }, distance_string, color, true, true);
				}
			}

			for (const auto& [position, color, name] : core.prefab_list)
			{
				const auto _pos = core.camera->world_to_screen_point(v_matrix, position);
				if (_pos.x == 0.00f)
					continue;

				const auto distance = local_position.distance(position);
				if (!distance)
					continue;

				auto distance_string = std::to_string((int)distance) + (std::string)skCrypt("M");
				if (distance_string.empty()) continue;

				const auto display_name = std::get<0>(name) + " " + distance_string;
				if (display_name.empty())
					continue;

				render::draw_text2(draw, _pos, display_name, color, distance);
			}
		}
	}
}