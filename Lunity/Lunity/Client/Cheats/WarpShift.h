#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
#include "../Hooks/KeyHook.h"

class WarpShift : public Cheat
{
public:
	WarpShift();
	void onEnable();
	void onGmTick(GameMode* gm);
};

