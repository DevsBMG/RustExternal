#pragma once
#include "../../../menu/includes.h"
class c_projectile
{
public:
	declare_member(std::uint32_t, uid, Item::uid);
	declare_member(float, drag, Projectile::drag);
	declare_member(std::uint32_t, amount, Item::amount);
	declare_member(float, thickness, Projectile::thickness);
	declare_member(float, integrity, Projectile::integrity);
	declare_member(float, initialDistance, Projectile::initialDistance);
	declare_member(float, gravityModifier, Projectile::gravityModifier);
public:
	declare_member(c_item_definition*, info, Item::info);
	declare_member(c_held_item*, heldEntity, Item::heldEntity);
	declare_member(c_item_projectile_mod*, mod, Projectile::mod);
	declare_member(c_hit_test*, hitTest, Projectile::hitTest);
public:
	auto shortname() -> std::wstring
	{
		if (!this || !this->heldEntity()) return L"none";
		else
		{
			auto info = m_vm.get()->read<std::uintptr_t>(reinterpret_cast<std::uintptr_t>(this) + Item::info);

			auto display_name = m_vm.get()->read<std::uintptr_t>(info + ItemDefinition::shortname);

			auto wide_name = m_vm.get()->read_wstring(display_name + 0x14);

			return wide_name;
		}
	}

};