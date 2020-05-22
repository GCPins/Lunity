#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
#include "../Hooks/GamemodeHook.h"

class ShiftWarp : public Cheat
{
public:
	ShiftWarp();
	void onGmTick(GameMode* gm);
	void onEnable();
	void onDisable();
};

