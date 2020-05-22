#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
#include "../Hooks/GamemodeHook.h"

class MineplexYesCheat : public Cheat
{
public:
	MineplexYesCheat();
	void onGmTick(GameMode* gm);
	void onEnable();
	void onDisable();
};

