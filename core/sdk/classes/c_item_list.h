#pragma once
#include "../../../menu/includes.h"
class c_item_list
{ public:
    declare_member(int, size, Item::info);
    auto get_item(int id) -> c_item*
    {
        auto items_list = m_vm.get()->read< std::uintptr_t >(reinterpret_cast<std::uintptr_t>(this) + 0x10);
        return m_vm.get()->read< c_item* >(items_list + 0x20 + (id * 0x8));
    }
};