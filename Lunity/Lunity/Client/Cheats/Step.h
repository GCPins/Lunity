#pragma once
#include "../Cheat.h"

class Step : public Cheat {
public:
	Step();
	void onGmTick(GameMode* gm);
	void onDisable();
};