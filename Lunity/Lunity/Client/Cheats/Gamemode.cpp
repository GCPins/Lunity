#include "pch.h"
#include "Gamemode.h"

int savedGamemode;

Gamemode::Gamemode() :Cheat::Cheat("Gamemode", "Player")
{

}

void Gamemode::onEnable() {
	Cheat::onEnable();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			savedGamemode = LunMem::getClientInstance()->LocalPlayer->currentGamemode;
		}
	}
}

void Gamemode::onGmTick(GameMode* gm)
{
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LunMem::getClientInstance()->LocalPlayer->setPlayerGameType(1);
		}
	}
}

void Gamemode::onDisable() {
	Cheat::onDisable();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LunMem::getClientInstance()->LocalPlayer->setPlayerGameType(savedGamemode);
		}
	}
}