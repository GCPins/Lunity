#pragma once
#include "../BigHead.h"
#include "Cheat.h"
#include "Cheats/AirJump.h"
#include "Cheats/TpTest.h"
#include "Cheats/SwingTest.h"

static std::vector<Cheat*> cheats = std::vector<Cheat*>();

static void loadCheats() {
	//Load cheats here
	cheats.push_back(new AirJump());
	cheats.push_back(new TpTest());
	cheats.push_back(new SwingTest());
}
static void tickCheats() {
	for (uint i = 0; i < cheats.size(); i++) {
		cheats[i]->onLoop();
	}
}
static void distroKeyPress(ulong key) {
	logHex("CM Press", key);
	for (uint i = 0; i < cheats.size(); i++) {
		log("Distroing");
		logHex(cheats[i]->name, cheats[i]->keyBind);
		if (cheats[i]->keyBind == key) {
			log("Keybind match");
			cheats[i]->enabled = !cheats[i]->enabled;
		}
	}
	for (uint i = 0; i < cheats.size(); i++) {
		cheats[i]->onKey(key);
	}
}
