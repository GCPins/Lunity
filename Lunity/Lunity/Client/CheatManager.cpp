#pragma once
#include "pch.h"
#include "CheatManager.h"
#include "../SDK/DrawUtils.h"
#include "Hooks/NetworkHook.h"

std::chrono::time_point<std::chrono::steady_clock> oldTime = std::chrono::high_resolution_clock::now();

bool CheatManager::cpuLimiter = false;
vector<Cheat*> cheats;
vector<string> categories;
vector<Cheat*> CheatManager::getCheats()
{
	return cheats;
}

vector<Cheat*> CheatManager::getCheatsOfCategory(string category)
{
	vector<Cheat*> returner;
	for (int i = 0; i < cheats.size(); i++) {
		if (cheats[i]->category.compare(category) == 0) {
			returner.push_back(cheats[i]);
		}
	}
	return returner;
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
	cheats.push_back(new Criticals());
	cheats.push_back(new Misplace());

	/* Movement */
	cheats.push_back(new Jetpack());
	cheats.push_back(new AirJump());
	cheats.push_back(new AutoSprint());
	cheats.push_back(new NoSlowDown());
	cheats.push_back(new BunnyHop());
	cheats.push_back(new NoWeb());
	cheats.push_back(new Speed());
	cheats.push_back(new Jesus());
	cheats.push_back(new Glide());
	cheats.push_back(new Step());
	cheats.push_back(new AutoWalk());
	cheats.push_back(new NoWater());
	cheats.push_back(new CCFly());
	cheats.push_back(new WarpShift());
	cheats.push_back(new HiveGlide());
	cheats.push_back(new Longjump());
	cheats.push_back(new LBfly());
	cheats.push_back(new AirAcceleration());
	cheats.push_back(new Antivoid());
	cheats.push_back(new Fastfall());

	/* Player */
	cheats.push_back(new Scaffold());
	cheats.push_back(new Nuker());
	cheats.push_back(new Velocity());
	cheats.push_back(new Instabreak());
	cheats.push_back(new ClickTP());
	cheats.push_back(new Gamemode());
	cheats.push_back(new InventoryMove());
	cheats.push_back(new NoFall());
	cheats.push_back(new Phase());
	cheats.push_back(new Flight());

	/* Visuals */
	cheats.push_back(new TabGUI());
	cheats.push_back(new ModuleList());
	cheats.push_back(new Coords());
	cheats.push_back(new ClickGui());
	cheats.push_back(new Radar());

	/* Other */
	cheats.push_back(new Uninject());
	cheats.push_back(new CPULimiter());
	cheats.push_back(new MineplexBP());
	cheats.push_back(new PacketLogger());
	cheats.push_back(new NoPacket());
	cheats.push_back(new Freecam());
	cheats.push_back(new CCGodMode());
	cheats.push_back(new Profiler());

	cheats.push_back(new TestModule());

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
	if (CheatManager::cpuLimiter) {
		if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - oldTime) >= std::chrono::milliseconds{ 130 }) {
			for (uint i = 0; i < cheats.size(); i++) {
				cheats[i]->onLoop();
			}

			oldTime = std::chrono::high_resolution_clock::now();
		}
	}
	else {
		for (uint i = 0; i < cheats.size(); i++) {
			cheats[i]->onLoop();
		}
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

void CheatManager::onPacket(void* Packet, PacketType type, bool* cancel)
{
	for (uint i = 0; i < cheats.size(); i++) {
		cheats[i]->onPacket(Packet, type, cancel);
	}
}
