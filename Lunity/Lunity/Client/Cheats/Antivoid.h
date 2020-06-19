#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
#include "../Hooks/GamemodeHook.h"
#include <chrono>

class Antivoid : public Cheat
{
public:
	Antivoid();
	void onLoop();
	void onTick();
	void onEnable();
	void onDisable();
	void onGmTick(GameMode* GM);
};