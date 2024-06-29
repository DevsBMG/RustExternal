#pragma once
#include "../../../menu/includes.h"

class c_magazine
{ public:
	declare_member(c_item_definition*, definition, ItemDefinition::itemid);
public:
	declare_member(int, capacity, Magazine::capacity);
	declare_member(int, contents, Magazine::contents);
	auto shortname() -> systems::c_string* { return m_vm.get()->read_chain<systems::c_string*>(reinterpret_cast<std::uintptr_t>(this), { 0x10, 0x20 }); }
};