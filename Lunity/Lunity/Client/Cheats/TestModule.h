#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
#include "../Hooks/GamemodeHook.h"

class TestModule : public Cheat
{
public:
	TestModule();
	void onLoop();
	void onTick();
	void onEnable();
	void onPostRender();
	void onDisable();
	void onGmTick(GameMode* GM);
};

