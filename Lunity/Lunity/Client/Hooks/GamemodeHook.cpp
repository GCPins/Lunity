#include "pch.h"
#include "GamemodeHook.h"
#include <MinHook.h>
#include "../CheatManager.h"

typedef int (WINAPI* GamemodeTick)(GameMode* gm);
GamemodeTick original;

static GameMode* thisGm = nullptr;
int hookCallback(GameMode* gm) {
	thisGm = gm;
	int retval = original(gm);
	CheatManager::gmTickCheats(gm);
	return retval;
}

GameMode* GamemodeHook::getLastGm()
{
	return thisGm;
}

void GamemodeHook::installHook()
{
	log("installing gamemode hook...");
	void* toGmHook = (void*)(LunMem::getBaseModule() + 0x14FEA00);
	logHex("ToHook", (ulong)toGmHook);
	bool installSuccess = false;
	if (MH_CreateHook(toGmHook, &hookCallback, reinterpret_cast<LPVOID*>(&original)) == MH_OK) {
		log("Gamemode Hook successfully created!");
		if (MH_EnableHook(toGmHook) == MH_OK) {
			installSuccess = true;
			log("render hook installed");
		}
	}
	if (!installSuccess) {
		log("Failed to hook gamemode!");
	}
}

void GamemodeHook::uninstallHook()
{
	void* toGmHook = (void*)(LunMem::getBaseModule() + 0x14FEA00);
	MH_DisableHook(toGmHook);
}
