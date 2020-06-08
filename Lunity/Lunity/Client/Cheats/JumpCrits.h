#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class JumpCrits : public Cheat
{
public:
	JumpCrits();
	void onLoop();
	void onTick();
	void onGmTick(GameMode* gm);
	void onEnable();
	void onDisable();
	void onKey(ulong key);
};