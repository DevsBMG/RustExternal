#pragma once
#include "../../../menu/includes.h"

class c_base_networkable
{ public:
	static auto get_base_entity() -> c_base_entity* { return m_vm.get()->read_chain<c_base_entity*>(m_vm.get()->game_assembly, { var::m_System_Collections_Generic_List_BaseGameMode__c, 0xB8 }); }
};