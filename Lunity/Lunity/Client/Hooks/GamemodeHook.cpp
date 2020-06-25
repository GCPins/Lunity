#include "pch.h"
#include "GamemodeHook.h"
#include <MinHook.h>
#include "../CheatManager.h"

typedef int (__thiscall* GamemodeTick)(GameMode* gm);
GamemodeTick gmOriginal;
GamemodeTick smOriginal;

static GameMode* thisGm = nullptr;
int gmHookCallback(GameMode* gm) {
	thisGm = gm;
	int retval = gmOriginal(gm);
	if ((ulong)gm->Player == (ulong)LunMem::getClientInstance()->LocalPlayer) {
		CheatManager::gmTickCheats(gm);
	}
	return retval;
}

int smHookCallback(GameMode* gm) {
	thisGm = gm;
	int retval = smOriginal(gm);
	if ((ulong)gm->Player == (ulong)LunMem::getClientInstance()->LocalPlayer) {
		CheatManager::gmTickCheats(gm);
	}
	return retval;
}

GameMode* GamemodeHook::getLastGm()
{
	return thisGm;
}

void GamemodeHook::installHook()
{
	Logger::log("installing gamemode hook...");
	void* toGmHook = (void*)(LunMem::getBaseModule() + 0x15D6570);
	Logger::logHex("ToHook", (ulong)toGmHook);
	bool installSuccess = false;
	if (MH_CreateHook(toGmHook, &gmHookCallback, reinterpret_cast<LPVOID*>(&gmOriginal)) == MH_OK) {
		Logger::log("Gamemode Hook successfully created!");
		if (MH_EnableHook(toGmHook) == MH_OK) {
			installSuccess = true;
			Logger::log("gamemode hook installed");
		}
	}
	if (!installSuccess) {
		Logger::log("Failed to hook gamemode!");
	}

	Logger::log("installing survivalmode hook...");
	void* toSmHook = (void*)(LunMem::getBaseModule() + 0x15D6B00);
	Logger::logHex("ToHook", (ulong)toSmHook);
	bool smInstallSuccess = false;
	if (MH_CreateHook(toSmHook, &smHookCallback, reinterpret_cast<LPVOID*>(&smOriginal)) == MH_OK) {
		Logger::log("survivalmode Hook successfully created!");
		if (MH_EnableHook(toSmHook) == MH_OK) {
			smInstallSuccess = true;
			Logger::log("survivalmode hook installed");
		}
	}
	if (!smInstallSuccess) {
		Logger::log("Failed to hook survivalmode!");
	}
}

void GamemodeHook::uninstallHook()
{
	void* toGmHook = (void*)(LunMem::getBaseModule() + 0x15D6570);
	MH_DisableHook(toGmHook);
	void* toSmHook = (void*)(LunMem::getBaseModule() + 0x15D6B00);
	MH_DisableHook(toSmHook);
}
