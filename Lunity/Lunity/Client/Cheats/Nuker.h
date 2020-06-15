#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class Nuker : public Cheat
{
public:
	Nuker();
	void onGmTick(GameMode* gm);
};

