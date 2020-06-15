#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class Triggerbot : public Cheat
{
public:
	Triggerbot();
	void onGmTick(GameMode* gm);
};