#pragma once
#include "../../menu/includes.h"

namespace render
{
	geo::vec4_t ImU32ToVec4(ImU32 color) {
		return geo::vec4_t(
			static_cast<float>((color & 0xFF0000) >> 16) / 255.0f,
			static_cast<float>((color & 0x00FF00) >> 8) / 255.0f,
			static_cast<float>(color & 0x0000FF) / 255.0f, 
			static_cast<float>((color & 0xFF000000) >> 24) / 255.0f );
	}
	auto get_health_color(float factor) -> geo::vec4_t
	{
		auto r = (factor >= 0.50f) ? static_cast<std::uint8_t>(255.00f - 255.00f * (factor - 0.50f) / 0.50f) : 255.00f;
		auto g = (factor >= 0.50f) ? 255.00f : static_cast<std::uint8_t>(255.00f * factor / 0.50f);

		return geo::vec4_t(r, g, 0.00f, 255);
	}
	auto add_text(ImDrawList* draw , geo::vec2_t pos, geo::vec4_t color, std::string str) -> void
	{
		draw->AddText
		(
			{ pos.x, pos.y - 1 },
			ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)),
			str.c_str()
		);

		draw->AddText
		(
			{ pos.x, pos.y + 1 },
			ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)),
			str.c_str()
		);

		draw->AddText
		(
			{ pos.x - 1, pos.y },
			ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)),
			str.c_str()
		);

		draw->AddText
		(
			{ pos.x + 1, pos.y },
			ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)),
			str.c_str()
		);

		draw->AddText
		(
			{ pos.x, pos.y },
			ImColor((int)color.x, (int)color.y, (int)color.z, (int)color.w),
			str.c_str()
		);
	}
	template <typename t = geo::vec3_t>
	auto draw_text(ImDrawList* draw, t position, std::string str, ImU32 color, bool centered = true, bool outline = true) -> void
	{
		auto _str = str.c_str();
		ImVec2 textSize = ImGui::CalcTextSize(_str);
		if (centered)
		{
			position.x -= textSize.x / 2.0f;
			position.y -= textSize.y / 2.0f; 
		}

		if (outline)
		{
			draw->AddText(visuals, ImGui::GetFontSize(), ImVec2(position.x + 1, position.y + 1), IM_COL32_BLACK, _str);
		}

		draw->AddText(visuals, ImGui::GetFontSize(), ImVec2(position.x, position.y), color, _str);
	}
	template <typename t = geo::vec3_t>
	auto draw_text2(ImDrawList* draw, t position, std::string str, systems::c_color color, bool centered = true, bool outline = true) -> void
	{
		const char* _str = str.c_str();
		ImVec2 textSize = ImGui::CalcTextSize(_str);

		if (centered)
		{
			position.x -= textSize.x / 2.0f;
			position.y -= textSize.y / 2.0f;
		}

		ImU32 im_color = IM_COL32(int(color.r * 255), int(color.g * 255), int(color.b * 255), int(color.a * 255));

		if (outline)
		{
			draw->AddText(ImVec2(position.x + 1, position.y + 1), IM_COL32_BLACK, _str);
		}

		draw->AddText(visuals, ImGui::GetFontSize(), ImVec2(position.x, position.y), im_color, _str);
	}
	auto add_circle(ImDrawList* draw, geo::vec2_t pos, float radius, geo::vec4_t color) -> void
	{
		draw->AddCircle
		(
			{ pos.x, pos.y },
			radius,
			ImColor((int)color.x, (int)color.y, (int)color.z, (int)color.w)
		);
	}

	auto add_circle_filled(ImDrawList* draw, geo::vec2_t pos, float radius, geo::vec4_t color) -> void
	{
		draw->AddCircleFilled
		(
			{ pos.x, pos.y },
			radius,
			ImColor((int)color.x, (int)color.y, (int)color.z, (int)color.w)
		);
	}

	auto draw_horizontal_bar(ImDrawList* draw, geo::vec2_t size, geo::vec2_t position, float current, float max, float rounding = 4.00f, float alpha = 255.00f) -> void
	{
		if (current > max)
			current = max;

		auto start = get_health_color(current / max);

		draw->AddRectFilled // background
		(
			{ position.x - (size.x / 2.00f), position.y },
			{ position.x - (size.x / 2.00f) + size.x, position.y + size.y + 1.00f },
			ImColor(0, 0, 0, (int)alpha),
			rounding
		);

		draw->AddRectFilled // colored
		(
			{ position.x - ((size.x - 1.00f) / 2.00f), position.y + 1.00f },
			{ position.x - ((size.x - 1.00f) / 2.00f) + systems::bound((current * (size.x - 2.00f) / max) + 1.00f, 0.00f, (size.x - 2.00f)), position.y + size.y },
			ImColor((int)start.x, (int)start.y, (int)start.z, (int)alpha),
			rounding
		);
	}

	auto draw_vertical_bar(ImDrawList* draw, geo::vec2_t size, geo::vec2_t position, float current, float max, float rounding = 4.00f, float alpha = 255.00f) -> void
	{
		if (current > max)
			current = max;

		auto start = get_health_color(current / max);

		draw->AddRectFilled
		(
			{ position.x, position.y + 1.00f },
			{ position.x + size.x + 1.00f, position.y + size.y - 1.00f },
			ImColor(0, 0, 0, (int)alpha),
			rounding
		);

		draw->AddRectFilled
		(
			{ position.x + 1.00f, position.y },
			{ position.x + size.x, position.y + (current * size.y / max) },
			ImColor((int)start.x, (int)start.y, (int)start.z, (int)alpha),
			rounding
		);
	}
	auto FilledRect(ImDrawList* draw, int x, int y, int w, int h, ImColor color) -> void
	{
		draw->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), color, 0, 0);
	}
	auto filled_rect(ImDrawList* draw, const geo::vec2_t& position, const geo::vec2_t& size, ImU32 color)
	{
		draw->AddRectFilled(
			ImVec2(position.x, position.y),
			ImVec2(position.x + size.x, position.y + size.y),
			color
		);
	}

	template <typename t = geo::vec3_t>
	auto rect(ImDrawList* draw, const t& position, const geo::vec2_t& size, ImU32 color, ImU32 outlineColor, float thickness = 1.00f, bool outline = true)
	{
		if (outline)
		{
			draw->AddRect(
				{ position.x - thickness, position.y - thickness },
				{ position.x + size.x + thickness, position.y + size.y + thickness },
				outlineColor, 0.00f, 0, thickness + 1.00f
			);
		}
		draw->AddRect(
			{ position.x, position.y },
			{ position.x + size.x, position.y + size.y },
			color, 0.00f, 0, thickness
		);
	}

	auto draw_line1(const geo::vec2_t& a, const geo::vec2_t& b, geo::vec4_t color = { 255.00f, 255.00f, 255.00f, 255.00f }, float thickness = 1.00f, bool outline = true)
	{
		auto gui = ImGui::GetBackgroundDrawList();
		if (outline)
		{
			gui->AddLine
			(
				{ a.x, a.y },
				{ b.x, b.y },
				ImColor(0, 0, 0, (int)color.w),
				thickness + 1.00f
			);
		}

		gui->AddLine
		(
			{ a.x, a.y }, { b.x, b.y },
			ImColor((int)color.x, (int)color.y, (int)color.z, (int)color.w),
			thickness
		);
	}
	void draw_line(ImDrawList* draw, const geo::vec2_t& a, const geo::vec2_t& b, ImU32 color, float thickness = 1.00f, bool outline = true)
	{
		draw->AddLine(
			ImVec2(a.x, a.y),
			ImVec2(b.x, b.y),
			color,
			thickness
		);
	}

	auto DrawCornerBox(ImDrawList* draw, int X, int Y, int W, int H, ImU32 inline_color, ImU32 outline_color) -> void
	{
		float lineW = static_cast<float>(W) / 5.0f;
		float lineH = static_cast<float>(H) / 6.0f;
		float lineT = 0.2f;

		if (config.b_outline)
		{
			draw_line(draw, { X - lineT, Y - lineT }, { X + lineW, Y - lineT }, outline_color, static_cast<float>(3.5f));
			draw_line(draw, { X - lineT, Y - lineT }, { X - lineT, Y + lineH }, outline_color, static_cast<float>(3.5f));
			draw_line(draw, { X - lineT, Y + H - lineH }, { X - lineT, Y + H + lineT }, outline_color, static_cast<float>(3.5f));
			draw_line(draw, { X - lineT, Y + H + lineT }, { X + lineW, Y + H + lineT }, outline_color, static_cast<float>(3.5f));
			draw_line(draw, { X + W - lineW, Y - lineT }, { X + W + lineT, Y - lineT }, outline_color, static_cast<float>(3.5f));
			draw_line(draw, { X + W + lineT, Y - lineT }, { X + W + lineT, Y + lineH }, outline_color, static_cast<float>(3.5f));
			draw_line(draw, { X + W + lineT, Y + H - lineH }, { X + W + lineT, Y + H + lineT }, outline_color, static_cast<float>(3.5f));
			draw_line(draw, { X + W - lineW, Y + H + lineT }, { X + W + lineT, Y + H + lineT }, outline_color, static_cast<float>(3.5f));
		}
		float inlineThickness = 0.8f;
		draw_line(draw, { static_cast<float>(X), static_cast<float>(Y) }, { static_cast<float>(X), static_cast<float>(Y) + lineH }, inline_color, inlineThickness);
		draw_line(draw, { static_cast<float>(X), static_cast<float>(Y) }, { static_cast<float>(X) + lineW, static_cast<float>(Y) }, inline_color, inlineThickness);
		draw_line(draw, { static_cast<float>(X) + W - lineW, static_cast<float>(Y) }, { static_cast<float>(X) + W, static_cast<float>(Y) }, inline_color, inlineThickness);
		draw_line(draw, { static_cast<float>(X) + W, static_cast<float>(Y) }, { static_cast<float>(X) + W, static_cast<float>(Y) + lineH }, inline_color, inlineThickness);
		draw_line(draw, { static_cast<float>(X), static_cast<float>(Y) + H - lineH }, { static_cast<float>(X), static_cast<float>(Y) + H }, inline_color, inlineThickness);
		draw_line(draw, { static_cast<float>(X), static_cast<float>(Y) + H }, { static_cast<float>(X) + lineW, static_cast<float>(Y) + H }, inline_color, inlineThickness);
		draw_line(draw, { static_cast<float>(X) + W - lineW, static_cast<float>(Y) + H }, { static_cast<float>(X) + W, static_cast<float>(Y) + H }, inline_color, inlineThickness);
		draw_line(draw, { static_cast<float>(X) + W, static_cast<float>(Y) + H - lineH }, { static_cast<float>(X) + W, static_cast<float>(Y) + H }, inline_color, inlineThickness);
	}
	void DrawCrosshair(ImDrawList* draw, int centerX, int centerY, int size, ImColor color)
	{
		render::FilledRect(draw, centerX - size / 2, centerY - 1, size, 3, color);
		render::FilledRect(draw, centerX - 1, centerY - size / 2, 3, size, color);
	}
	void DrawSnapLine(ImDrawList* draw, const geo::vec2_t& position, ImU32 color, float thickness = 1.0f, bool drawCenter = false)
	{
		ImVec2 screenSize = ImGui::GetIO().DisplaySize;
		float centerX = screenSize.x / 2.0f;
		float centerY = screenSize.y / 2.0f;
		draw_line(draw, position, geo::vec2_t{ centerX, centerY }, color, thickness);
		if (drawCenter)
		{
			float crosshairSize = 10.0f;
			draw_line(draw, geo::vec2_t{ centerX - crosshairSize, centerY }, geo::vec2_t{ centerX + crosshairSize, centerY }, color, thickness);
			draw_line(draw, geo::vec2_t{ centerX, centerY - crosshairSize }, geo::vec2_t{ centerX, centerY + crosshairSize }, color, thickness);
		}
	}
}