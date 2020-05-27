#include "pch.h"
#include "Gamemode.h"

Gamemode::Gamemode() :Cheat::Cheat("Gamemode", "Player")
{

}

void Gamemode::onTick()
{
	Cheat::onTick();
	LunMem::getClientInstance()->LocalPlayer->setPlayerGameType(1);
}

void Gamemode::onDisable() {
	Cheat::onDisable();
	LunMem::getClientInstance()->LocalPlayer->setPlayerGameType(0);
}