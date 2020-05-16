#pragma once
#include "../BigHead.h"
#include "Cheat.h"
#include "Cheats/AirJump.h"
#include "Cheats/TpTest.h"
#include "Cheats/SwingTest.h"
#include "Cheats/TabGUI.h"

class CheatManager {
public:
	static vector<Cheat*> getCheats();
	static vector<string> getCategories();
	static void loadCheats();
	static void tickCheats();
	static void distroKeyPress(ulong key);
	static void onPreRender();
	static void onPostRender();
};