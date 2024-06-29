#pragma once
#include "../../../menu/includes.h"
class c_skinset_collection
{
public:
	declare_member(systems::c_array<c_skin_set*>*, skinSet, SkinSetCollection::Skins);
};