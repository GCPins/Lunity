#pragma once
#include "../BigHead.h"
#include "Cheat.h"
#include "Cheats/Killaura.h"
#include "Cheats/Triggerbot.h"
#include "Cheats/Hitbox.h"
#include "Cheats/AirJump.h"
#include "Cheats//AutoSprint.h"
#include "Cheats/TabGUI.h"
#include "Cheats/Uninject.h"

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