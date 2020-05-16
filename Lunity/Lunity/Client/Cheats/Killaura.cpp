#include "pch.h"
#include "Killaura.h"

Killaura::Killaura() :Cheat::Cheat("Killaura", "Combat")
{
	//keyBind = 0x4b;
}

void Killaura::onLoop()
{
	Cheat::onLoop();
}

void Killaura::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL)
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* player = LunMem::getClientInstance()->LocalPlayer;
		}
}

void Killaura::onEnable()
{
	Cheat::onEnable();
}

void Killaura::onDisable()
{
	Cheat::onDisable();
}

void Killaura::onKey(ulong key) {
}
