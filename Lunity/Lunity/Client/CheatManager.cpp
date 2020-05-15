#include "pch.h"
#include "CheatManager.h"
#include "../SDK/DrawUtils.h"

std::vector<Cheat*> cheats;
std::vector<Cheat*> CheatManager::getCheats()
{
	return cheats;
}

void CheatManager::loadCheats()
{
	cheats = std::vector<Cheat*>();
	//Load cheats here
	cheats.push_back(new AirJump());
	cheats.push_back(new TpTest());
	cheats.push_back(new SwingTest());
	cheats.push_back(new TabGUI());
	//logHex("Cheat vec size", getCheats().size());
}

void CheatManager::tickCheats()
{
	//logHex("Cheat vec size", getCheats().size());
	for (uint i = 0; i < cheats.size(); i++) {
		cheats[i]->onLoop();
	}
}

void CheatManager::distroKeyPress(ulong key)
{
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