#pragma once
#include "../../../menu/includes.h"

class c_base_entity
{ public:
	declare_member(std::uintptr_t, object, 0x10);
	declare_member(bool, isVisible, BaseEntity::isVisible);
	declare_member(c_model*, model, BaseEntity::model);
	declare_member(std::uint32_t, skinID, BaseEntity::skinID);
public:
	auto get_name() -> std::string
	{
        const auto unk_0 = m_vm.get()->read<std::uintptr_t>(reinterpret_cast<std::uintptr_t>(this));
        if (!unk_0)
            return "";

        const auto unk_1 = m_vm.get()->read<std::uintptr_t>(unk_0 + 0x10);
        if (!unk_1)
            return "";

        char buffer[32];
        m_vm.get()->read_physical(std::uintptr_t(unk_1), reinterpret_cast<void*>(&buffer), sizeof(buffer));
        return std::string(buffer);
	}
public:
	auto get_client_entities() -> systems::c_list<c_base_entity*>* { return m_vm.get()->read_chain< systems::c_list<c_base_entity*>*>(reinterpret_cast<std::uintptr_t>(this), { 0x10, 0x10, 0x28 }); }
};