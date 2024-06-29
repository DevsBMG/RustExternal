#pragma once
#include "../../../menu/includes.h"
class c_item
{ public:
    declare_member(c_weapon_view_model*, instance, ViewModel::instance);//	public BaseViewModel instance; // 0x30
    declare_member(c_held_item*, heldEntity, Item::heldEntity);
    declare_member(c_view_model*, viewModel, HeldEntity::viewModelk__BackingField);
    declare_member(int, amount, Item::amount);//	public int amount; // 0x2C
    declare_member(int, uid, Item::uid);//	public ItemId uid; // 0x20

    auto get_name() -> std::string
    {
        auto item_info = m_vm.get()->read<std::uintptr_t>(reinterpret_cast<std::uintptr_t>(this) + Item::info); // public ItemDefinition info; // 
        auto shortname = m_vm.get()->read<std::uintptr_t>(item_info + ItemDefinition::shortname); // public string shortname; // 
        auto name = m_vm.get()->read_wstring(shortname + 0x14); // rust string // 0x14 //	private char _firstChar; // 0x14
        auto output = std::string(name.begin(), name.end());
        return output;
    }
};