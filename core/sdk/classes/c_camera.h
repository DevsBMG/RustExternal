#pragma once
#include "../../../menu/includes.h"

class c_camera
{ public:
	declare_member(geo::m_matrix, view_matrix, 0x30C);
	declare_member(geo::vec3_t, velocity, 0x420);
	declare_member(geo::vec3_t, position, 0x454);
public:
	static auto instance() -> c_camera* { return m_vm.get()->read_chain<c_camera*>(m_vm.get()->game_assembly, { var::m_MainCamera_c, 0xb8, 0x00, 0x10 }); }
	auto world_to_screen(geo::m_matrix vmatrix, geo::vec3_t position, geo::vec2_t* screen) -> bool
	{
		const auto w = geo::vec3_t(vmatrix._14, vmatrix._24, vmatrix._34).dot(position) + vmatrix._44;
		if (w < 0.097f) return false;
		*screen =
		{
			((float)vars.screen_width * 0.50f) * (1.00f + (geo::vec3_t(vmatrix._11, vmatrix._21, vmatrix._31).dot(position) + vmatrix._41) / w),
			((float)vars.screen_height * 0.50f) * (1.00f - (geo::vec3_t(vmatrix._12, vmatrix._22, vmatrix._32).dot(position) + vmatrix._42) / w)
		};
		return true;
	}

	auto world_to_screen_point(geo::m_matrix vmatrix, geo::vec3_t position) -> geo::vec2_t
	{
		const auto w = geo::vec3_t(vmatrix._14, vmatrix._24, vmatrix._34).dot(position) + vmatrix._44;
		if (w < 0.097f) return geo::vec2_t{ 0.00f, 0.00f };
		return
		{
			((float)vars.screen_width * 0.50f) * (1.00f + (geo::vec3_t(vmatrix._11, vmatrix._21, vmatrix._31).dot(position) + vmatrix._41) / w),
			((float)vars.screen_height * 0.50f) * (1.00f - (geo::vec3_t(vmatrix._12, vmatrix._22, vmatrix._32).dot(position) + vmatrix._42) / w)
		};
	}

	auto calculate_fov(geo::m_matrix matrix, geo::vec3_t pos) -> float
	{
		auto screen_pos = this->world_to_screen_point(matrix, pos);
		auto get_2d_dist = [&](const geo::vec2_t& source, const geo::vec2_t& dest) -> float
        { return std::sqrt(std::powf(source.x - dest.x, 2) + std::powf(source.y - dest.y, 2)); };
		return get_2d_dist(geo::vec2_t(vars.screen_width / 2.00f, vars.screen_height / 2.00f), screen_pos);
	}
};