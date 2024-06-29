#pragma once
#include <string>
#include <locale>
#include <codecvt>
#include "../../../menu/includes.h"

namespace systems
{

	template <typename t = float>
	auto bound(t current, t min, t max) -> t
	{
		if (current < min)
		{
			return min;
		}
		else if (current > max)
		{
			return max;
		}

		return current;
	}

	//struct
	struct unity_str { char buffer[128]; };
	struct box { geo::vec2_t pos; geo::vec2_t size; };
	struct dynamic_array { std::uint64_t base; std::uint64_t mem_id; std::uint64_t sz; std::uint64_t cap; };

	//classes
	class c_string
	{
	public:
		auto buffer() -> std::wstring { if (!this) return std::wstring(); auto local = reinterpret_cast<std::uintptr_t>(this); wchar_t buffer[65]; m_vm.get()->read_physical((local + 0x14), (std::uint8_t*)&buffer, 64); buffer[64] = '\0'; return std::wstring(buffer); }
	};

	template <typename t>
	class c_list
	{
	public:
		auto size() -> std::uint32_t { return m_vm.get()->read<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this) + 0x10); }
		auto get(std::uint32_t idx) -> t { return m_vm.get()->read_chain<t>(reinterpret_cast<std::uintptr_t>(this), { 0x18, 0x20ull + (idx * 0x08ull) }); }
	};

	template <typename t>
	class c_list_dictionary
	{
	public:
		auto size() -> std::uint32_t { return m_vm.get()->read< std::uint32_t >(reinterpret_cast<std::uintptr_t>(this) + 0x18ull); }
		auto get(std::uint32_t idx) -> t { const auto base = m_vm.get()->read< std::uint64_t >(reinterpret_cast<std::uintptr_t>(this) + 0x10ull); if (!base) return 0; return m_vm.get()->read< t >(base + 0x20ull + (static_cast<std::uint32_t>(idx) * 0x08ull)); }
	};

	template <typename t>
	class c_array
	{
	public:
		auto size() -> std::uint32_t { return m_vm.get()->read<std::uint32_t>(reinterpret_cast<std::uintptr_t>(this) + 0x18); }
		template <typename c = std::uint32_t>
		auto get(c idx) -> t { return m_vm.get()->read<t>(reinterpret_cast<std::uintptr_t>(this) + 0x20ull + (static_cast<std::uint32_t>(idx) * 0x8ull)); }
	};

	class bounds
	{
	public:
		float left, right, top, bottom;
		bounds(float left, float right, float top, float bottom) : left(left), right(right), top(top), bottom(bottom) { }
		bounds() : left(FLT_MAX), right(FLT_MIN), top(FLT_MAX), bottom(FLT_MIN) { }
	};

	class c_color
	{
	public:
		float r, g, b, a;
		c_color() { r = g = b = a = 0.00f; }
		c_color(float _r, float _g, float _b, float _a) { this->r = _r; this->g = _g; this->b = _b; this->a = _a; }
		c_color(std::uint32_t color) { this->a = (color >> 24) & 0xff; this->r = (color >> 16) & 0xff; this->g = (color >> 8) & 0xff; this->b = (color & 0xff); }
		static auto from_hsb(float flHue, float flSaturation, float flBrightness) -> c_color
		{
			const float h = std::fmodf(flHue, 1.0f) / (60.0f / 360.0f);
			const int i = static_cast<int>(h);
			const float f = h - static_cast<float>(i);
			const float p = flBrightness * (1.0f - flSaturation);
			const float q = flBrightness * (1.0f - flSaturation * f);
			const float t = flBrightness * (1.0f - flSaturation * (1.0f - f));
			float r = 0.0f, g = 0.0f, b = 0.0f;
			switch (i)
			{
			case 0: r = flBrightness, g = t, b = p; break;
			case 1: r = q, g = flBrightness, b = p; break;
			case 2: r = p, g = flBrightness, b = t; break;
			case 3: r = p, g = q, b = flBrightness; break;
			case 4: r = t, g = p, b = flBrightness; break;
			default: r = flBrightness, g = p, b = q; break;
			}
			return c_color(r, g, b, 255);
		}
		auto random_color(int iTick) -> void { this->r = sin(3.f * iTick + 0.f) * 127 + 128; this->g = sin(3.f * iTick + 0.f) * 127 + 128; this->b = sin(3.f * iTick + 0.f) * 127 + 128; }
		static auto transparent() -> c_color { return { 0.f, 0.f, 0.f, 0.f }; }
		static auto black(float alpha = 1.f) -> c_color { return { 0.f, 0.f, 0.f, alpha }; }
		static auto white(float alpha = 1.f) -> c_color { return { 1.f, 1.f, 1.f, alpha }; }
		static auto red(float alpha = 1.f) -> c_color { return { 1.f, 0.f, 0.f, alpha }; }
		static auto green(float alpha = 1.f) -> c_color { return { 0.f, 1.f, 0.f, alpha }; }
		static auto blue(float alpha = 1.f) -> c_color { return { 0.f, 0.f, 1.f, alpha }; }
		static auto yellow(float alpha = 1.f) -> c_color { return { 1.f, 1.f, 0.f, alpha }; }
		static auto orange(float alpha = 1.f) -> c_color { return { 1.f, 0.5f, 0.f, alpha }; }
		static auto cyan(float alpha = 1.f) -> c_color { return { 0.f, 0.5f, 1.f, alpha }; }
		static auto rose(float alpha = 1.f) -> c_color { return { 252.f / 255.f, 3.f / 255.f, 98.f / 255.f, alpha }; }
		static auto turquoise(float alpha = 1.f) -> c_color { return { 0.f, 1.f, 1.f, alpha }; }
	};

	enum class lifestate : std::uint32_t { alive = 0, dead = 1, };
	enum class item_rarity : std::uint32_t { none = 0, common = 1, uncommon = 2, rare = 3, very_rare = 4, };
	enum class category : std::uint32_t { shirt = 0, jacket = 1, hat = 2, mask = 3, footwear = 4, pants = 5, weapon = 6, misc = 7, deployable = 9, gloves = 10 };
	enum class engine_layers : std::uint32_t { terrain = 8388608, world = 65536, ragdolls = 512, construction = 2097152, construction_socket = 4194304, craters = 1, game_trace = 16384, trigger = 262144, vehicles_detailed = 8192, rain_fall = 1101070337, deploy = 1235288065, default_deploy_volume_check = 537001984, build_line_of_sight_check = 2097152, projectile_line_of_sight_check = 2162688, projectile_line_of_sight_check_terrain = 10551296, meele_line_of_sight_check = 2162688, eye_line_of_sight_check = 2162688, entity_line_of_sight_check = 1218519041, player_buildings = 18874624, planner_placement = 161546496, solid = 1218652417, vis_culling = 10551297, altitude_check = 1218511105, hab_ground_effect = 1218511105, ai_line_of_sight = 1218519297, dismount_check = 1486946561, ai_placement = 278986753, wheel_ray = 1235321089, };
	enum class model_flags : std::uint32_t { ducked = 1, jumped = 2, on_ground = 4, sleeping = 8, sprinting = 16, on_ladder = 32, flying = 64, aiming = 128, prone = 256, mounted = 512, relaxed = 1024, on_phone = 2048, crawling = 4096, head_look = 16384 };
	enum class item_category : std::uint32_t { weapon = 0, construction = 1, items = 2, resources = 3, attire = 4, tool = 5, medical = 6, food = 7, ammunition = 8, traps = 9, misc = 10, all = 11, common = 12, component = 13, search = 14, favourite = 15, electrical = 16, fun = 17 };
	enum class base_entity_signal : std::uint32_t { attack, alt_attack, dry_fire, reload, deploy, flinch_head, flinch_chest, flinch_stomach, flinch_rear_head, flinch_rear_torso, _throw, relax, gesture, phys_impact, eat, startled, admire };
	enum class player_flags : std::uint32_t { none = 0, unused1 = 1, unused2 = 2, isadmin = 4, receivingsnapshot = 8, sleeping = 16, spectating = 32, wounded = 64, isdeveloper = 128, connected = 256, thirdpersonviewmode = 1024, eyesviewmode = 2048, chatmute = 4096, nosprint = 8192, aiming = 16384, displaysash = 32768, relaxed = 65536, safezone = 131072, serverfall = 262144, incapacitated = 524288, workbench1 = 1048576, workbench2 = 2097152, workbench3 = 4194304, };
	enum class layer : std::uint32_t { default_layer = 0, transparentfx = 1, ignore_raycast = 2, reserved1 = 3, water = 4, ui = 5, reserved2 = 6, reserved3 = 7, deployed = 8, ragdoll = 9, invisible = 10, ai = 11, player_movement = 12, vehicle_detailed = 13, game_trace = 14, vehicle_world = 15, world = 16, player_server = 17, trigger = 18, harvestable = 19, physics_projectile = 20, construction = 21, construction_socket = 22, terrain = 23, transparent = 24, clutter = 25, debris = 26, vehicle_large = 27, prevent_movement = 28, prevent_building = 29, tree = 30, unused = 31, };
	enum class player_bones : std::uint32_t { l_hip = 1, l_knee, l_foot, l_toe, l_ankle_scale, pelvis, penis, GenitalCensor, GenitalCensor_LOD0, Inner_LOD0, GenitalCensor_LOD1, GenitalCensor_LOD2, r_hip, r_knee, r_foot, r_toe, r_ankle_scale, spine1, spine1_scale, spine2, spine3, spine4, l_clavicle, l_upperarm, l_forearm, l_hand, l_index1, l_index2, l_index3, l_little1, l_little2, l_little3, l_middle1, l_middle2, l_middle3, l_prop, l_ring1, l_ring2, l_ring3, l_thumb1, l_thumb2, l_thumb3, IKtarget_righthand_min, IKtarget_righthand_max, l_ulna, neck, head, jaw, eye_transform, l_eye, l_Eyelid, r_eye, r_Eyelid, r_clavicle, r_upperarm, r_forearm, r_hand, r_index1, r_index2, r_index3, r_little1, r_little2, r_little3, r_middle1, r_middle2, r_middle3, r_prop, r_ring1, r_ring2, r_ring3, r_thumb1, r_thumb2, r_thumb3, IKtarget_lefthand_min, IKtarget_lefthand_max, r_ulna, l_breast, r_breast, BoobCensor, BreastCensor_LOD0, BreastCensor_LOD1, BreastCensor_LOD2, collision, displacement };
	//player_bones
	std::array<player_bones, 16> v_bones = { player_bones::head, player_bones::r_foot, player_bones::l_foot, player_bones::pelvis, player_bones::r_hand, player_bones::l_hand, player_bones::l_knee, player_bones::l_hip, player_bones::r_knee, player_bones::r_hip, player_bones::l_clavicle, player_bones::l_upperarm, player_bones::l_forearm , player_bones::r_clavicle, player_bones::r_upperarm, player_bones::r_forearm, };
}