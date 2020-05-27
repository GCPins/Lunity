#include "pch.h"
#include "Gamemode.h"

Gamemode::Gamemode() :Cheat::Cheat("Gamemode", "Player")
{

}

void Gamemode::onTick()
{
	Cheat::onTick();
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
			LunMem::getClientInstance()->LocalPlayer->setPlayerGameType(0);
		}
	}
}