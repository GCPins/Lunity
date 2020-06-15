#pragma once
#include "../../BigHead.h"
#include "../Cheat.h"
class AutoSprint : public Cheat
{
public:
	AutoSprint();
	void onGmTick(GameMode* gm);
};

