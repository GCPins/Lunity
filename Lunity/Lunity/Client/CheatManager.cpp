#include "pch.h"
#include "CheatManager.h"
#include "../SDK/DrawUtils.h"

vector<Cheat*> cheats;
vector<string> categories;
vector<Cheat*> CheatManager::getCheats()
{
	return cheats;
}

vector<string> CheatManager::getCategories()
{
	return categories;
}

void CheatManager::loadCheats()
{
	cheats = vector<Cheat*>();
	//Load cheats here
	cheats.push_back(new AirJump());
	cheats.push_back(new TpTest());
	cheats.push_back(new SwingTest());
	cheats.push_back(new TabGUI());

	for (uint i = 0; i < cheats.size(); i++) {
		if (find(categories.begin(), categories.end(), cheats[i]->category) == categories.end()) {
			categories.push_back(cheats[i]->category);
		}
	}
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
	//logHex("CM Press", key);
	for (uint i = 0; i < cheats.size(); i++) {
		//log("Distroing");
		//logHex(cheats[i]->name, cheats[i]->keyBind);
		if (cheats[i]->keyBind == key) {
			//log("Keybind match");
			cheats[i]->enabled = !cheats[i]->enabled;
		}
	}
	for (uint i = 0; i < cheats.size(); i++) {
		cheats[i]->onKey(key);
	}
}

void CheatManager::onPreRender()
{
	for (uint i = 0; i < cheats.size(); i++) {
		cheats[i]->onPreRender();
	}
}

void CheatManager::onPostRender()
{
	for (uint i = 0; i < cheats.size(); i++) {
		cheats[i]->onPostRender();
	}
}
