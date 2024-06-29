#pragma once
#include "../../../menu/includes.h"
class c_item_definition
{ public:
	declare_member(systems::item_category, category, ItemDefinition::category);
	declare_member(systems::item_rarity, rarity, ItemDefinition::rarity);
	declare_member(systems::c_string*, shortname, ItemDefinition::shortname);
	declare_member(systems::c_string*, displayName, ItemDefinition::displayName);

	auto realName() -> systems::c_string*
	{
		return m_vm.get()->read<systems::c_string*>(reinterpret_cast<std::uintptr_t>(this->displayName()) + 0x18);
	}
};