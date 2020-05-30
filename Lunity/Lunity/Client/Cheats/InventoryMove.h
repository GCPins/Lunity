#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"

class InventoryMove : public Cheat
{
public:
	InventoryMove();
	void onTick();
};

