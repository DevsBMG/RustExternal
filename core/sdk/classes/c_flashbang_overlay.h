#pragma once
#include "../../../menu/includes.h"

class c_flashbang_overlay
{ public:
	declare_member(c_flashbang_overlay*, Instance, FlashbangOverlay::Instance);
public:
	declare_member(float, flashLength, FlashbangOverlay::flashLength);
public:
	static auto instance() -> c_flashbang_overlay* { return m_vm.get()->read_chain<c_flashbang_overlay*>(m_vm.get()->game_assembly, { var::m_FlashbangOverlay_c, 0xB8 }); }
};