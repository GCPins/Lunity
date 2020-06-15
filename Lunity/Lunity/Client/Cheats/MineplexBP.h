#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
#include "../Hooks/GamemodeHook.h"

class MineplexBP : public Cheat
{
public:
	MineplexBP();
	void onGmTick(GameMode* gm);
};

