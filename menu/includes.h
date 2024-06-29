#pragma once
int chams = 0;
int chams_hands = 0;
int gun_chams = 0;
//window 
#include <windows.h>
#include <tlhelp32.h>
#include <Psapi.h>
#include <cstdint>
#include <string>
#include <thread>
#include <vector>
#include <random>
#include <winioctl.h>
#include <cstddef>
#include <winternl.h>
#include <d3dx9.h>
#include <d3d9.h>
#include <dwmapi.h>
#include "../core/memory/skcrypt.h"
//dx9
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")
#pragma comment(lib, "dwmapi.lib")

//imgui
#include "../external/imgui/imgui.h"
#include "../external/imgui/imgui_internal.h"
#include "../external/imgui/imgui_impl_dx9.h"
#include "../external/imgui/imgui_impl_win32.h"
//config
#include "../core/utils/singleton.h"
#include "../core/sdk/vars/game.h"
#include "config/config.h"
//overlay
#include "overlay/setup.h"
#include "overlay/overlay.h"
#include "overlay/controls.h"
//math
#include "../core/sdk/system/math.hpp"
//memory
#include "../core/memory/memory.hpp"
//offsets
#include "../core/sdk/system/offsets.h"
using namespace offsets;
//systems
#include "../core/sdk/system/systems.h"
//il2cpp header
#define declare_member(type, name, shift)														\
	auto name ( ) -> type																		\
	{																							\
		return m_vm.get()->read<type>( reinterpret_cast<std::uintptr_t>( this ) + shift );			\
	}																							\
																								\
	auto set_##name( type name ) -> void														\
	{																							\
		m_vm.get()->write<type>( reinterpret_cast< std::uintptr_t >( this ) + shift, name );			\
	}	
//classes
#include "../core/sdk/classes/c_option.h"
#include "../core/sdk/classes/c_gradient.h"
#include "../core/sdk/classes/c_command_list.h"
#include "../core/sdk/classes/c_rigid_body.h"
#include "../core/sdk/classes/c_player_belt.h"
#include "../core/sdk/classes/c_capsule_collider.h"
#include "../core/sdk/classes/c_player_eyes.h"
#include "../core/sdk/classes/c_player_tick.h"
#include "../core/sdk/classes/c_base_mountable.h"
#include "../core/sdk/classes/c_model_state.h"
#include "../core/sdk/classes/c_base_collision.h"
#include "../core/sdk/classes/c_base_movement.h"
#include "../core/sdk/classes/c_input_message.h"
#include "../core/sdk/classes/c_input_state.h"
#include "../core/sdk/classes/c_player_input.h"
#include "../core/sdk/classes/c_skinned_multi_mesh.h"
#include "../core/sdk/classes/c_skin_set.h"
#include "../core/sdk/classes/c_skinset_collection.h"
#include "../core/sdk/classes/c_player_model.h"
#include "../core/sdk/classes/c_convar_graphics.h"
#include "../core/sdk/classes/c_convar_admin.h"
#include "../core/sdk/classes/c_convar_client.h"
#include "../core/sdk/classes/c_transform.h"
#include "../core/sdk/classes/c_model.h"
#include "../core/sdk/classes/c_flashbang_overlay.h"
#include "../core/sdk/classes/c_base_entity.h"
#include "../core/sdk/classes/c_base_networkable.h"
#include "../core/sdk/classes/c_base_combat_entity.h"
#include "../core/sdk/classes/c_recoil_properties.h"
#include "../core/sdk/classes/c_item_definition.h"
#include "../core/sdk/classes/c_tod_scattering.h"
#include "../core/sdk/classes/c_tod_components.h"
#include "../core/sdk/classes/c_tod_day.h"
#include "../core/sdk/classes/c_tod_night.h"
#include "../core/sdk/classes/c_tod_stars.h"
#include "../core/sdk/classes/c_tod_sky.h"
#include "../core/sdk/classes/c_skin_type.h"
#include "../core/sdk/classes/c_groups.h"
#include "../core/sdk/classes/c_skinnable.h"
#include "../core/sdk/classes/c_magazine.h"
#include "../core/sdk/classes/c_item_projectile_mod.h"
#include "../core/sdk/classes/c_weapon_bob.h"
#include "../core/sdk/classes/c_weapon_sway.h"
#include "../core/sdk/classes/c_weapon_punch.h"
#include "../core/sdk/classes/c_weapon_lower.h"
#include "../core/sdk/classes/c_weapon_view_model.h"
#include "../core/sdk/classes/c_view_model.h"
#include "../core/sdk/classes/c_held_item.h"
#include "../core/sdk/classes/c_item.h"
#include "../core/sdk/classes/c_item_list.h"
#include "../core/sdk/classes/c_item_container.h"
#include "../core/sdk/classes/c_player_inventory.h"
#include "../core/sdk/classes/c_hit_test.h"
#include "../core/sdk/classes/c_projectile.h"
#include "../core/sdk/classes/c_base_player.h"
#include "../core/sdk/classes/c_camera.h"
#include "../core/sdk/classes/c_object_class.h"
#include "../core/sdk/classes/c_object.h"
#include "../core/sdk/classes/c_ItemIcon.h"
#include "../core/sdk/classes/c_unity.h"

#include "../core/draw/drawing.h"
#include "../core/thread/entityloop/entityloop.h"
#include "../core/thread/aimbot.h"
#include "../core/thread/localplayer.h"
#include "../core/thread/visuals.h"