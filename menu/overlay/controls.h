#pragma once
#include <map>

static const char* keyNames[] =
{
"UK",
"LMB",
"RMB",
"CANCEL",
"MB",
"XB1",
"XB2",
"UK",
"BACK",
"TAB",
"UK",
"UK",
"CLEAR",
"RETURN",
"UK",
"UK",
"SHIFT",
"CONTROL",
"MENU",
"PAUSE",
"CAP",
"KANA",
"UK",
"JUNJA",
"FINAL",
"KANJI",
"UK",
"ESCAPE",
"CONVERT",
"NONCOVERT",
"ACCEPT",
"MODECHANGE",
"SPACE",
"PRIOR",
"NEXT",
"END",
"HOME",
"LEFT",
"UP",
"RIGHT",
"DOWN",
"SELECT",
"PRINT",
"EXECUTE",
"SNAPSHOT",
"INSERT",
"DELETE",
"HELP",
"0",
"1",
"2",
"3",
"4",
"5",
"6",
"7",
"8",
"9",
"UK",
"UK",
"UK",
"UK",
"UK",
"UK",
"UK",
"A",
"B",
"C",
"D",
"E",
"F",
"G",
"H",
"I",
"J",
"K",
"L",
"M",
"N",
"O",
"P",
"Q",
"R",
"S",
"T",
"U",
"V",
"W",
"X",
"W",
"Z",
"LWIN",
"RWIN",
"APPS",
"UK",
"SLEEP",
"NUM0",
"NUM1",
"NUM2",
"NUM3",
"NUM4",
"NUM5",
"NUM6",
"NUM7",
"NUM8",
"NUM9",
"MULTIPLY",
"ADD",
"SEPERATOR",
"SUBTRACT",
"DECIMAL",
"DIVIDE",
"F1",
"F2",
"F3",
"F4",
"F5",
"F6",
"F7",
"F8",
"F9",
"F10",
"F11",
"F12",
"F13",
"F14",
"F15",
"F16",
"F17",
"F18",
"F19",
"F20",
"F21",
"F22",
"F23",
"F24",
"UK",
"UK",
"UK",
"UK",
"UK",
"UK",
"UK",
"UK",
"NUM LOCK",
"SCROLL",
"VK_OEM_NEC_EQUAL",
"VK_OEM_FJ_MASSHOU",
"VK_OEM_FJ_TOUROKU",
"VK_OEM_FJ_LOYA",
"VK_OEM_FJ_ROYA",
"UK",
"UK",
"UK",
"UK",
"UK",
"UK",
"UK",
"UK",
"UK",
"LSHIFT",
"RSHIFT",
"LCONTROL",
"RCONTROL",
"LMENU",
"RMENU"
};

namespace Controls
{
    bool RadioButton(const char* label, const ImVec2& size_arg, const bool selected)
    {
        ImGuiWindow* window = ImGui::GetCurrentWindow();
        if (window->SkipItems)
            return false;

        ImGuiContext& g = *GImGui;
        const ImGuiStyle& style = g.Style;
        const ImGuiID id = window->GetID(label);

        ImVec2 pos = window->DC.CursorPos;
        ImVec2 size = ImGui::CalcItemSize(size_arg, 0.0f, 0.0f);
        const ImRect bb(pos, { pos.x + size.x, pos.y + size.y });

        ImGui::ItemSize(size, style.FramePadding.y);
        if (!ImGui::ItemAdd(bb, id))
            return false;

        bool hovered, held;
        bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, NULL);

        static std::map<ImGuiID, float> alphaMap;
        const float fadeDuration = 0.5f;

        float& alpha = alphaMap[id];

        if (pressed) {
            alpha = 0.70f;
        }
        else if (hovered) {
            alpha = 0.50f;
        }
        else if (!held && alpha < 1.0f)
        {
            alpha += g.IO.DeltaTime / fadeDuration;
            alpha = ImClamp(alpha, 0.0f, 1.0f);
        }

        ImU32 colors[] = {
            ImGui::ColorConvertFloat4ToU32(ImColor(23, 22, 25, static_cast<int>(alpha * 255))),
            ImGui::ColorConvertFloat4ToU32(ImColor(25, 24, 26, static_cast<int>(alpha * 255))),
            ImGui::ColorConvertFloat4ToU32(ImColor(33, 33, 37, static_cast<int>(alpha * 255))),
            ImGui::ColorConvertFloat4ToU32(ImColor(37, 35, 40, static_cast<int>(alpha * 255)))
        };

        window->DrawList->AddRectFilledMultiColor(bb.Min, bb.Max, colors[0], colors[1], colors[2], colors[3]);

        if (selected) {
            ImVec4 borderColor = ImVec4(50 / 255.0f, 50 / 255.0f, 50 / 255.0f, alpha);
            ImU32 borderCol = ImGui::ColorConvertFloat4ToU32(borderColor);

            ImVec4 borderColor2 = ImVec4(0 / 255.0f, 0 / 255.0f, 0 / 255.0f, alpha);
            ImU32 borderCol2 = ImGui::ColorConvertFloat4ToU32(borderColor2);

            float rounding = style.FrameRounding;
            float borderThickness = 1.0f;

            ImVec2 outerBorderMin = ImVec2(bb.Min.x - borderThickness, bb.Min.y - borderThickness);
            ImVec2 outerBorderMax = ImVec2(bb.Max.x + borderThickness, bb.Max.y + borderThickness);

            window->DrawList->AddRect(outerBorderMin, outerBorderMax, borderCol2, rounding, 0, borderThickness);

            window->DrawList->AddRect(bb.Min, bb.Max, borderCol, rounding, 0, borderThickness);
        }

        ImVec2 textSize = ImGui::CalcTextSize(label, NULL, true);
        ImVec2 textPos = ImVec2(bb.Min.x + (size.x - textSize.x) * 0.5f, bb.Min.y + (size.y - textSize.y) * 0.5f);
        window->DrawList->AddText(textPos, ImColor(235, 235, 235, static_cast<int>(alpha * 255)), label);

        return pressed;
    }

    bool Toggle(const char* label, bool* v, const ImVec2& size)
    {
        ImGuiWindow* window = ImGui::GetCurrentWindow();
        if (window->SkipItems)
            return false;

        ImGuiContext& g = *GImGui;
        const ImGuiStyle& style = g.Style;
        const ImGuiID id = window->GetID(label);
        const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

        float height = size.y;
        const ImVec2 pos = window->DC.CursorPos;

        float width = size.x;
        float radius = height * 0.5f;

        const ImRect total_bb(pos, ImVec2(pos.x + width, pos.y + height));

        const ImRect button_bb(pos, ImVec2(pos.x + width, pos.y + height));

        ImGui::ItemSize(total_bb, style.FramePadding.y);
        if (!ImGui::ItemAdd(button_bb, id))
            return false;

        float last_active_id_timer = g.LastActiveIdTimer;

        bool hovered, held;
        bool pressed = ImGui::ButtonBehavior(total_bb, id, &hovered, &held);
        if (pressed)
        {
            *v = !(*v);
            ImGui::MarkItemEdited(id);
            g.LastActiveIdTimer = 0.f;
        }

        if (g.LastActiveIdTimer == 0.f && g.LastActiveId == id && !pressed)
            g.LastActiveIdTimer = last_active_id_timer;

        float t = *v ? 1.0f : 0.0f;

        if (g.LastActiveId == id)
        {
            float t_anim = ImSaturate(g.LastActiveIdTimer / 0.16f);
            t = *v ? (t_anim) : (1.0f - t_anim);
        }

        const ImRect frame_bb(pos, ImVec2(pos.x + width, pos.y + height));

        ImVec4 borderColor = ImVec4(50 / 255.0f, 50 / 255.0f, 50 / 255.0f, 1.0f);
        ImU32 borderCol = ImGui::ColorConvertFloat4ToU32(borderColor);

        ImVec4 borderColor2 = ImVec4(0 / 255.0f, 0 / 255.0f, 0 / 255.0f, 1.0f);
        ImU32 borderCol2 = ImGui::ColorConvertFloat4ToU32(borderColor2);

        float rounding = 0.0f;
        float borderThickness = 1.0f;

        ImVec2 outerBorderMin = ImVec2(frame_bb.Min.x - borderThickness, frame_bb.Min.y - borderThickness);
        ImVec2 outerBorderMax = ImVec2(frame_bb.Max.x + borderThickness, frame_bb.Max.y + borderThickness);

        window->DrawList->AddRect(outerBorderMin, outerBorderMax, borderCol2, rounding, 0, borderThickness);

        window->DrawList->AddRect(frame_bb.Min, frame_bb.Max, borderCol, rounding, 0, borderThickness);

        if (*v)
        {
            ImU32 colors[] = {
                ImGui::ColorConvertFloat4ToU32(ImColor(23, 22, 25, 255)),
                ImGui::ColorConvertFloat4ToU32(ImColor(25, 24, 26, 255)),
                ImGui::ColorConvertFloat4ToU32(ImColor(0, 0, 0, 120)),
                ImGui::ColorConvertFloat4ToU32(ImColor(37, 35, 40, 255))
            };

            ImVec2 innerMin = ImVec2(pos.x + 2, pos.y + 2);
            ImVec2 innerMax = ImVec2(pos.x + width - 2, pos.y + height - 2);

            window->DrawList->AddRectFilledMultiColor(innerMin, innerMax, colors[0], colors[1], colors[2], colors[3]);
        }

        return pressed;
    }

    bool Button(const char* label, const ImVec2& size_arg)
    {
        ImGuiWindow* window = ImGui::GetCurrentWindow();
        if (window->SkipItems)
            return false;

        ImGuiContext& g = *GImGui;
        const ImGuiStyle& style = g.Style;
        const ImGuiID id = window->GetID(label);

        ImVec2 pos = window->DC.CursorPos;
        ImVec2 size = ImGui::CalcItemSize(size_arg, 0.0f, 0.0f);
        const ImRect bb(pos, { pos.x + size.x, pos.y + size.y });

        ImGui::ItemSize(size, style.FramePadding.y);
        if (!ImGui::ItemAdd(bb, id))
            return false;

        bool hovered, held;
        bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, NULL);

        static std::map<ImGuiID, float> alphaMap;
        const float fadeDuration = 0.5f;

        float& alpha = alphaMap[id];

        if (pressed) {
            alpha = 0.70f;
        }
        else if (hovered) {
            alpha = 0.50f;
        }
        else if (!held && alpha < 1.0f)
        {
            alpha += g.IO.DeltaTime / fadeDuration;
            alpha = ImClamp(alpha, 0.0f, 1.0f);
        }

        ImU32 colors[] = {
            ImGui::ColorConvertFloat4ToU32(ImColor(23, 22, 25, static_cast<int>(alpha * 255))),
            ImGui::ColorConvertFloat4ToU32(ImColor(25, 24, 26, static_cast<int>(alpha * 255))),
            ImGui::ColorConvertFloat4ToU32(ImColor(33, 33, 37, static_cast<int>(alpha * 255))),
            ImGui::ColorConvertFloat4ToU32(ImColor(37, 35, 40, static_cast<int>(alpha * 255)))
        };

        window->DrawList->AddRectFilledMultiColor(bb.Min, bb.Max, colors[0], colors[1], colors[2], colors[3]);

        ImVec4 borderColor = ImVec4(50 / 255.0f, 50 / 255.0f, 50 / 255.0f, alpha);
        ImU32 borderCol = ImGui::ColorConvertFloat4ToU32(borderColor);

        ImVec4 borderColor2 = ImVec4(0 / 255.0f, 0 / 255.0f, 0 / 255.0f, alpha);
        ImU32 borderCol2 = ImGui::ColorConvertFloat4ToU32(borderColor2);

        float rounding = style.FrameRounding;
        float borderThickness = 1.0f;

        ImVec2 outerBorderMin = ImVec2(bb.Min.x - borderThickness, bb.Min.y - borderThickness);
        ImVec2 outerBorderMax = ImVec2(bb.Max.x + borderThickness, bb.Max.y + borderThickness);

        window->DrawList->AddRect(outerBorderMin, outerBorderMax, borderCol2, rounding, 0, borderThickness);

        window->DrawList->AddRect(bb.Min, bb.Max, borderCol, rounding, 0, borderThickness);

        ImVec2 textSize = ImGui::CalcTextSize(label, NULL, true);
        ImVec2 textPos = ImVec2(bb.Min.x + (size.x - textSize.x) * 0.5f, bb.Min.y + (size.y - textSize.y) * 0.5f);
        window->DrawList->AddText(textPos, ImColor(140, 140, 140), label);

        return pressed;
    }

    bool ButtonEx(const char* label, const ImVec2& size_arg, const ImVec2& pos)
    {
        ImGuiWindow* window = ImGui::GetCurrentWindow();
        if (window->SkipItems)
            return false;

        ImGuiContext& g = *GImGui;
        const ImGuiStyle& style = g.Style;
        const ImGuiID id = window->GetID(label);

        ImVec2 size = ImGui::CalcItemSize(size_arg, 0.0f, 0.0f);
        const ImRect bb(pos, { pos.x + size.x, pos.y + size.y });

        ImGui::ItemSize(size, style.FramePadding.y);
        if (!ImGui::ItemAdd(bb, id))
            return false;

        bool hovered, held;
        bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, NULL);

        static std::map<ImGuiID, float> alphaMap;
        const float fadeDuration = 0.5f;

        float& alpha = alphaMap[id];

        if (pressed) {
            alpha = 0.70f;
        }
        else if (hovered) {
            alpha = 0.50f;
        }
        else if (!held && alpha < 1.0f)
        {
            alpha += g.IO.DeltaTime / fadeDuration;
            alpha = ImClamp(alpha, 0.0f, 1.0f);
        }

        ImU32 colors[] = {
            ImGui::ColorConvertFloat4ToU32(ImColor(23, 22, 25, static_cast<int>(alpha * 255))),
            ImGui::ColorConvertFloat4ToU32(ImColor(25, 24, 26, static_cast<int>(alpha * 255))),
            ImGui::ColorConvertFloat4ToU32(ImColor(33, 33, 37, static_cast<int>(alpha * 255))),
            ImGui::ColorConvertFloat4ToU32(ImColor(37, 35, 40, static_cast<int>(alpha * 255)))
        };

        window->DrawList->AddRectFilledMultiColor(bb.Min, bb.Max, colors[0], colors[1], colors[2], colors[3]);

        ImVec4 borderColor = ImVec4(50 / 255.0f, 50 / 255.0f, 50 / 255.0f, alpha);
        ImU32 borderCol = ImGui::ColorConvertFloat4ToU32(borderColor);

        ImVec4 borderColor2 = ImVec4(0 / 255.0f, 0 / 255.0f, 0 / 255.0f, alpha);
        ImU32 borderCol2 = ImGui::ColorConvertFloat4ToU32(borderColor2);

        float rounding = style.FrameRounding;
        float borderThickness = 1.0f;

        ImVec2 outerBorderMin = ImVec2(bb.Min.x - borderThickness, bb.Min.y - borderThickness);
        ImVec2 outerBorderMax = ImVec2(bb.Max.x + borderThickness, bb.Max.y + borderThickness);

        window->DrawList->AddRect(outerBorderMin, outerBorderMax, borderCol2, rounding, 0, borderThickness);

        window->DrawList->AddRect(bb.Min, bb.Max, borderCol, rounding, 0, borderThickness);

        ImVec2 textSize = ImGui::CalcTextSize(label, NULL, true);
        ImVec2 textPos = ImVec2(bb.Min.x + (size.x - textSize.x) * 0.5f, bb.Min.y + (size.y - textSize.y) * 0.5f);
        window->DrawList->AddText(textPos, ImColor(140, 140, 140), label);

        return pressed;
    }

    static bool Items_ArrayGetter(void* data, int idx, const char** out_text)
    {
        const char* const* items = (const char* const*)data;
        if (out_text)
            *out_text = items[idx];
        return true;
    }

    void ChangeKey(void* blank)
    {
        config.aim_status = 1;
        while (true)
        {
            for (int i = 0; i < 0x87; i++)
            {
                if (GetKeyState(i) & 0x8000)
                {
                    config.aimkey = i;
                    config.aim_status = 0;
                    return;
                }
            }
        }
    }
    void ChangeKey1(void* blank)
    {
        config.Zoom_status = 1;
        while (true)
        {
            for (int i = 0; i < 0x87; i++)
            {
                if (GetKeyState(i) & 0x8000)
                {
                    config.Zoomkey = i;
                    config.Zoom_status = 0;
                    return;
                }
            }
        }
    }
    void ChangeKe2(void* blank)
    {
        config.FLY_status = 1;
        while (true)
        {
            for (int i = 0; i < 0x87; i++)
            {
                if (GetKeyState(i) & 0x8000)
                {
                    config.FLYkey = i;
                    config.FLY_status = 0;
                    return;
                }
            }
        }
    }

    void HotkeyButton(int aimkey, void* changekey, int status)
    {
        const char* preview_value = NULL;
        if (aimkey >= 0 && aimkey < IM_ARRAYSIZE(keyNames))
            Items_ArrayGetter(keyNames, aimkey, &preview_value);
        std::string aimkeys;
        std::string zoomkeys;
        std::string flykeys;
        if (preview_value == NULL) 
        {
            aimkeys = ("");
            zoomkeys = ("");
            flykeys = ("");
        }
        else
        {
            aimkeys = preview_value;
            zoomkeys = preview_value;
            flykeys = preview_value;
        }

        if (status == 1)
        {
            flykeys = ("");
            zoomkeys = ("");
            aimkeys = ("");
        }   
         
        if (Button(aimkeys.c_str(), ImVec2(80, 20)))
        {
            if (status == 0)
            {
                CreateThread(0, 0, (LPTHREAD_START_ROUTINE)changekey, nullptr, 0, nullptr);
            }
        }
    }
    void HotkeyButton1(int zoom, void* changekey, int status)
    {
        const char* preview_value = NULL;
        if (zoom >= 0 && zoom < IM_ARRAYSIZE(keyNames))
            Items_ArrayGetter(keyNames, zoom, &preview_value);
        std::string zoomkeys;
        if (preview_value == NULL)
        {
            zoomkeys = ("");
        }
        else
        {
            zoomkeys = preview_value;
        }

        if (status == 1)
        {
            zoomkeys = ("");
        }

        if (Button(zoomkeys.c_str(), ImVec2(80, 20)))
        {
            if (status == 0)
            {
                CreateThread(0, 0, (LPTHREAD_START_ROUTINE)changekey, nullptr, 0, nullptr);
            }
        }
    }
    void HotkeyButton2(int fly, void* changekey, int status)
    {
        const char* preview_value = NULL;
        if (fly >= 0 && fly < IM_ARRAYSIZE(keyNames))
            Items_ArrayGetter(keyNames, fly, &preview_value);
        std::string flykeys;
        if (preview_value == NULL)
        {
            flykeys = ("");
        }
        else
        {
            flykeys = preview_value;
        }

        if (status == 1)
        {
            flykeys = ("");
        }

        if (Button(flykeys.c_str(), ImVec2(80, 20)))
        {
            if (status == 0)
            {
                CreateThread(0, 0, (LPTHREAD_START_ROUTINE)changekey, nullptr, 0, nullptr);
            }
        }
    }

    void ItemSelector(const char* label, const char* const* items, int num_items, int& current_item, const ImVec2& size) {
        ImGuiWindow* window = ImGui::GetCurrentWindow();
        if (window->SkipItems)
            return;

        ImGuiContext& g = *GImGui;
        const ImGuiStyle& style = g.Style;

        const ImVec2 button_size = ImVec2(20, 20);
        const float spacing = 5.0f;
        const ImVec2 rect_size = ImVec2(size.x - button_size.x * 2 - spacing * 4, size.y);
        const ImVec2 total_bb_min = window->DC.CursorPos;
        const ImVec2 total_bb_max(total_bb_min.x + size.x, total_bb_min.y + size.y);

        static std::map<ImGuiID, float> alphaMap;

        if (!alphaMap.count(window->ID))
            alphaMap[window->ID] = 1.0f;

        ImGui::PushID(label);

        ImVec2 left_button_pos = ImVec2(total_bb_min.x, total_bb_min.y + (size.y - button_size.y) * 0.5f);
        ImVec2 right_button_pos = ImVec2(total_bb_max.x - button_size.x, total_bb_min.y + (size.y - button_size.y) * 0.5f);

        ImGui::PushID(0);
        if (ButtonEx("-", button_size, left_button_pos)) {
            current_item = ImMax(current_item - 1, 0);
            alphaMap[window->ID] = 0.5f;
        }
        ImGui::PopID();

        ImGui::SameLine(left_button_pos.x + button_size.x + spacing);

        const ImVec2 rect_pos(total_bb_min.x + button_size.x + spacing * 2, total_bb_min.y);
        const ImVec2 text_center(rect_pos.x + (rect_size.x - ImGui::CalcTextSize(items[current_item]).x) * 0.5f, rect_pos.y + (rect_size.y - ImGui::GetTextLineHeight()) * 0.5f);

        ImU32 colors[] = {
            ImGui::ColorConvertFloat4ToU32(ImColor(23, 22, 25, static_cast<int>(alphaMap[window->ID] * 255))),
            ImGui::ColorConvertFloat4ToU32(ImColor(25, 24, 26, static_cast<int>(alphaMap[window->ID] * 255))),
            ImGui::ColorConvertFloat4ToU32(ImColor(33, 33, 37, static_cast<int>(alphaMap[window->ID] * 255))),
            ImGui::ColorConvertFloat4ToU32(ImColor(37, 35, 40, static_cast<int>(alphaMap[window->ID] * 255)))
        };

        ImVec2 outerBorderMin = ImVec2(rect_pos.x - 1, rect_pos.y - 1); // Adjusted position for outer border
        ImVec2 outerBorderMax = ImVec2(rect_pos.x + rect_size.x + 1, rect_pos.y + rect_size.y + 1); // Adjusted size for outer border

        window->DrawList->AddRect(outerBorderMin, outerBorderMax, IM_COL32(0, 0, 0, 255), 0.0f, 0, 1.0f);
        window->DrawList->AddRectFilledMultiColor(rect_pos, ImVec2(rect_pos.x + rect_size.x, rect_pos.y + rect_size.y), colors[0], colors[1], colors[2], colors[3]);
        window->DrawList->AddRect(rect_pos, ImVec2(rect_pos.x + rect_size.x, rect_pos.y + rect_size.y), IM_COL32(50, 50, 50, 255));

        window->DrawList->AddText(text_center, ImGui::ColorConvertFloat4ToU32(ImGui::GetStyleColorVec4(ImGuiCol_Text)), items[current_item]);

        ImGui::PushID(1);
        if (ButtonEx("+", button_size, right_button_pos)) {
            current_item = ImMin(current_item + 1, num_items - 1);
            alphaMap[window->ID] = 0.5f;
        }
        ImGui::PopID();

        ImGui::PopID();
    }

    void ColorPreview(const char* label, ImColor col, const ImVec2& size_arg)
    {
        ImGuiWindow* window = ImGui::GetCurrentWindow();
        if (window->SkipItems)
            return;

        const ImGuiStyle& style = ImGui::GetStyle();
        const ImGuiID id = window->GetID(label);

        ImVec2 pos = window->DC.CursorPos;
        ImVec2 size = ImGui::CalcItemSize(size_arg, 0.0f, 0.0f);
        const ImRect bb(pos, ImVec2(pos.x + size.x, pos.y + size.y));

        ImGui::ItemSize(size, style.FramePadding.y);
        if (!ImGui::ItemAdd(bb, id))
            return;

        ImVec2 outerBorderMin = ImVec2(bb.Min.x - 1.f, bb.Min.y - 1.f);
        ImVec2 outerBorderMax = ImVec2(bb.Max.x + 1.f, bb.Max.y + 1.f);

        window->DrawList->AddRect(outerBorderMin, outerBorderMax, ImColor(0, 0, 0, 255), 0, 0, 1.f);
        window->DrawList->AddRect(bb.Min, bb.Max, ImColor(50, 50, 50, 160), 0.f, 0, 1.f);

        ImVec2 innerMin = ImVec2(bb.Min.x + 3, bb.Min.y + 3);
        ImVec2 innerMax = ImVec2(bb.Max.x - 3, bb.Max.y - 3);
        window->DrawList->AddRectFilled(innerMin, innerMax, col);
    }

    void GroupBox(const char* label, ImColor col, const ImVec2& size_arg) {
        ImGuiWindow* window = ImGui::GetCurrentWindow();
        if (window->SkipItems)
            return;
        ImVec2 min = window->DC.CursorPos;
        ImVec2 max = ImVec2(min.x + size_arg.x, min.y + size_arg.y);

        ImVec2 top_rect_min = min;
        ImVec2 top_rect_max = ImVec2(max.x, min.y + 30);
        window->DrawList->AddRectFilledMultiColor(top_rect_min, top_rect_max, ImColor(37, 35, 40), ImColor(33, 33, 37), ImColor(25, 24, 26), ImColor(23, 22, 25));
        
        window->DrawList->AddRect(min, max, ImColor(0, 0, 0), 0, 0, 0.5f);
        window->DrawList->AddRect(ImVec2(min.x + 1, min.y + 1), ImVec2(max.x - 1, max.y - 1), ImColor(50, 50, 50, 160), 0, 0, 1.0f);

        window->DrawList->AddLine(ImVec2(min.x + 1, min.y + 30), ImVec2(max.x - 1, min.y + 30), ImColor(0, 0, 0), 0.5f);

        ImVec2 textSize = ImGui::CalcTextSize(label, NULL, true);
        ImVec2 textPos = ImVec2(min.x + 10, min.y + 7);
        window->DrawList->AddText(textPos, col, label);
    }

    void ColorPicker(const char* popupName, bool* isOpen, float* color)
    {
        ImGui::OpenPopup(popupName);
        ImGui::SetNextWindowSize(ImVec2(200, 190));

        ImGui::PushStyleColor(ImGuiCol_Border, ImVec4(0.0f / 255.f, 0.0f / 255.f, 0.0f / 255.f, 0.0f / 255.f));

        if (ImGui::BeginPopupModal(popupName, isOpen, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize))
        {
            ImGui::SetCursorPos(ImVec2(1, 1));
            GroupBox(popupName, ImColor(140, 140, 140), ImVec2(198, 188));

            ImGui::SetCursorPos(ImVec2(173, 5.5));
            if (Button("X", ImVec2(20, 20))) {
                *isOpen = false;
                ImGui::CloseCurrentPopup();
            }

            ImGui::SetCursorPos(ImVec2(10, 39));
            ColorPreview(popupName, ImColor(color[0], color[1], color[2], color[3]), ImVec2(180, 20));

            ImGui::SetCursorPos(ImVec2(10, 69)); ImGui::SetNextItemWidth(180);
            ImGui::SliderFloat("##R", &color[0], 0.0f, 1.0f, "R: %.2f");

            ImGui::SetCursorPos(ImVec2(10, 99)); ImGui::SetNextItemWidth(180);
            ImGui::SliderFloat("##G", &color[1], 0.0f, 1.0f, "G: %.2f");

            ImGui::SetCursorPos(ImVec2(10, 129)); ImGui::SetNextItemWidth(180);
            ImGui::SliderFloat("##B", &color[2], 0.0f, 1.0f, "B: %.2f");

            ImGui::SetCursorPos(ImVec2(10, 159)); ImGui::SetNextItemWidth(180);
            ImGui::SliderFloat("##A", &color[3], 0.0f, 1.0f, "A: %.2f");
        }
        ImGui::PopStyleColor();
        ImGui::EndPopup();
    }
}