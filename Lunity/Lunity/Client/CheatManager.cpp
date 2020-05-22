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
	/* Combat */
	cheats.push_back(new Killaura());
	cheats.push_back(new Triggerbot());
	cheats.push_back(new Hitbox());

	/* Movement */
	cheats.push_back(new Jetpack());
	cheats.push_back(new AirJump());
	cheats.push_back(new AutoSprint());
	cheats.push_back(new NoSlowDown());
	cheats.push_back(new BunnyHop());
	cheats.push_back(new NoWeb());

	/* Player */
	cheats.push_back(new Scaffold());
	cheats.push_back(new Nuker());
	cheats.push_back(new Velocity());
	cheats.push_back(new Instabreak());
	cheats.push_back(new ClickTP());

	/* Visuals */
	cheats.push_back(new TabGUI());
	cheats.push_back(new ModuleList());

	/* Other */
	cheats.push_back(new Uninject());
	cheats.push_back(new PacketLogger());

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

void CheatManager::gmTickCheats(GameMode* gm)
{
	//logHex("Cheat vec size", getCheats().size());
	for (uint i = 0; i < cheats.size(); i++) {
		cheats[i]->onGmLoop(gm);
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

void CheatManager::distroButtonPress(ulong key)
{
	for (uint i = 0; i < cheats.size(); i++) {
		cheats[i]->onMouseButton(key);
	}
}

void CheatManager::distroMouseMove()
{
	for (uint i = 0; i < cheats.size(); i++) {
		cheats[i]->onMouseMove();
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

void CheatManager::onPacket(void* Packet)
{
	for (uint i = 0; i < cheats.size(); i++) {
		cheats[i]->onPacket(Packet);
	}
}
