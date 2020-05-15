#pragma once
#include "../BigHead.h"
#include "Cheat.h"
#include "Cheats/AirJump.h"
#include "Cheats/TpTest.h"

static std::vector<Cheat*> cheats = std::vector<Cheat*>();

static void loadCheats() {
	//Load cheats here
	cheats.push_back(new AirJump());
	cheats.push_back(new TpTest());
}
static void tickCheats() {
	for (uint i = 0; i < cheats.size(); i++) {
		cheats[i]->onLoop();
	}
}
