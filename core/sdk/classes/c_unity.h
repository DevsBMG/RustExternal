#pragma once
#include "../../../menu/includes.h"
    std::uint64_t get_component(std::uintptr_t game_object, const char* componenet)
    {
        const auto component_list = m_vm.get()->read<std::uintptr_t>(game_object + 0x30);
        if (!component_list)
            return 0;

        for (std::uint32_t idx{ 0 }; idx < 20; idx++)
        {
            const auto instance = m_vm.get()->read<std::uintptr_t>(component_list + (0x10 * idx + 0x8));
            if (!instance)
                continue;

            const auto component = m_vm.get()->read<std::uintptr_t>(instance + 0x28);
            if (!component)
                continue;

            const auto component_name = m_vm.get()->read<std::uintptr_t>(component + 0x0);
            if (!component_name)
                continue;

            const auto name = m_vm.get()->read_string(m_vm.get()->read<std::uintptr_t>(component_name + 0x10));
            if (strcmp(name.c_str(), componenet) == 0)
                return component;
        }
        return 0;
    }
    void GetComponentsInChildren(std::uintptr_t game_object, std::vector<std::uintptr_t>& renderers, int depth = 0)
    {
        const auto component_list = m_vm.get()->read<std::uint64_t>(game_object + 0x30);
        if (!component_list)
            return;

        const auto component_size = m_vm.get()->read<int>(game_object + 0x40);
        if (!component_size)
            return;

        for (int idx{ 0 }; idx < component_size; ++idx)
        {
            const auto component = m_vm.get()->read<std::uint64_t>(component_list + (0x10 * idx + 0x8));
            if (!component)
                continue;

            const auto component_ptr = m_vm.get()->read<std::uint64_t>(component + 0x28);
            if (!component_ptr)
                continue;

            const auto component_name_ptr = m_vm.get()->read<std::uint64_t>(component_ptr + 0x0);
            if (!component_name_ptr)
                continue;

            const auto component_name = m_vm.get()->read<std::uint64_t>(component_name_ptr + 0x10);
            if (!component_name)
                continue;

            auto name = m_vm.get()->read_string(component_name);

            if (name == ("SkinnedMeshRenderer") || name == ("MeshRenderer"))
                renderers.push_back(component);

            if (name == ("Transform"))
            {
                const auto child_list = m_vm.get()->read<std::uint64_t>(component + 0x70);
                if (!child_list)
                    continue;

                const auto child_size = m_vm.get()->read<int>(component + 0x80);
                if (!child_size)
                    continue;

                for (int i{ 0 }; i < child_size; ++i)
                {
                    const auto child_transform = m_vm.get()->read<std::uint64_t>(child_list + (0x8 * i));
                    if (!child_transform)
                        continue;

                    const auto child_game_object = m_vm.get()->read<std::uint64_t>(child_transform + 0x30);
                    if (!child_game_object)
                        continue;

                    const auto child_object_name = m_vm.get()->read<std::uint64_t>(child_game_object + 0x60);
                    if (!child_object_name)
                        continue;

                    const auto child_name = m_vm.get()->read_string(child_object_name);

                    if (child_name.find(("holosight")) != std::string::npos || child_name.find(("hand")) != std::string::npos)
                        continue;

                    GetComponentsInChildren(child_game_object, renderers, depth + 1);
                }
            }
        }
    }
    void ProcessSkinnedMeshRenderer(uintptr_t renderer)
    {
        if (renderer == 0) return;

        switch (chams_hands)
        {
        case 1:
            config.hand_chams = 0;
            break;
        case 2:
            config.hand_chams = 246724;//plainlight_red
            break;
        case 3:
            config.hand_chams = 1234548;//plainlight_blue_deeper
            break;
        }
        if (chams_hands > 0)
        {
            for (std::uint32_t idx{ 0 }; idx < 2; idx++)
            {
                const auto renderEntry = m_vm.get()->read<uintptr_t>(renderer + 0x20 + (idx * 0x8));
                if (!renderEntry)
                    continue;

                const auto untity_object = m_vm.get()->read<uintptr_t>(renderEntry + 0x10);
                if (!untity_object)
                    continue;

                const auto mat_list = m_vm.get()->read<systems::dynamic_array>(untity_object + 0x148);
                if (mat_list.sz < 1 || mat_list.sz > 5)
                    continue;

                for (std::uint32_t idx{ 0 }; idx < mat_list.sz; idx++)
                    m_vm.get()->write<unsigned int>(mat_list.base + (idx * 0x4), config.hand_chams);
            }
        }
    }