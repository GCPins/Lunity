#pragma once
#include "../BigHead.h"
#include "Cheat.h"
#include "Cheats/AirJump.h"
#include "Cheats/TpTest.h"
#include "Cheats/SwingTest.h"
#include "Cheats/TabGUI.h"

class CheatManager {
public:
	static std::vector<Cheat*> getCheats();
	static void loadCheats();
	static void tickCheats();
	static void distroKeyPress(ulong key);
};