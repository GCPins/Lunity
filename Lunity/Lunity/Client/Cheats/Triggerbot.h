#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
#include <chrono>

class Triggerbot : public Cheat
{
public:
	Triggerbot();
	void onGmTick(GameMode* gm);
};