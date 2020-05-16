#include "pch.h"
#include "GamemodeHook.h"
#include <MinHook.h>

typedef int (WINAPI* GamemodeTick)(GameMode* gm);
GamemodeTick original;

static GameMode* thisGm = nullptr;
int hookCallback(GameMode* gm) {
	thisGm = gm;
	return original(gm);
}

GameMode* GamemodeHook::getLastGm()
{
	return thisGm;
}

void GamemodeHook::installHook()
{
	log("installing gamemode hook...");
	void* toHook = (void*)(LunMem::getBaseModule() + 0x14FEA00);
	logHex("ToHook", (ulong)toHook);
	bool installSuccess = false;
	if (MH_CreateHook(toHook, &hookCallback, reinterpret_cast<LPVOID*>(&original)) == MH_OK) {
		log("Gamemode Hook successfully created!");
		if (MH_EnableHook(toHook) == MH_OK) {
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
	void* toHook = (void*)(LunMem::getBaseModule() + 0x14FEA00);
	MH_DisableHook(toHook);
}
