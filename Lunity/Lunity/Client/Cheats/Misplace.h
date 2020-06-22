#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
#include "../Hooks/GamemodeHook.h"

class Misplace : public Cheat
{
public:
	Misplace();
	void onLoop();
	void onTick();
	void onEnable();
	void onDisable();
	void onGmTick(GameMode* GM);
};