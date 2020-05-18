#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class TpAura : public Cheat
{
public:
	TpAura();
	void onLoop();
	void onTick();
	void onGmTick(GameMode* gm);
	void onEnable();
	void onDisable();
	void onKey(ulong key);
};

