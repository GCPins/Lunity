#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class Instabreak : public Cheat
{
public:
	Instabreak();
	void onGmTick(GameMode* gm);
	void onLoop();
	void onTick();
	void onEnable();
	void onDisable();
	void onKey(ulong key);
};

