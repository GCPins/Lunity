#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
#include "../Hooks/GamemodeHook.h"

class Fastfall : public Cheat
{
public:
	Fastfall();
	void onLoop();
	void onTick();
	void onEnable();
	void onDisable();
	void onGmTick(GameMode* GM);
};