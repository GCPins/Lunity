#pragma once
#include "../Cheat.h"

class AirAcceleration : public Cheat {
public:
	AirAcceleration();
	void onGmTick(GameMode* gm);
};