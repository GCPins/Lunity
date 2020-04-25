#include "pch.h"
#include "CheatManager.h"

CheatManager::CheatManager()
{
	cheats = vector<Cheat>();
}

void CheatManager::tickCheats()
{
	for (uint i = 0; i < cheats.size(); i++) {
		cheats[i].onLoop();
	}
}
