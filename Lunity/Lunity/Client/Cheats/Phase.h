#pragma once
#include "../Cheat.h"

class Phase : public Cheat {
public:
	Phase();
	void onGmTick(GameMode* GM);
	void onDisable();
};