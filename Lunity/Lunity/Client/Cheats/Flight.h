#pragma once
#include "../Cheat.h"

class Flight : public Cheat {
public:
	Flight();
	void onGmTick(GameMode* GM);
	void onDisable();
};