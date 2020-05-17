#include "pch.h"
#include "Hitbox.h"
#include "../Hooks/KeyHook.h"

Hitbox::Hitbox() :Cheat::Cheat("Hitbox", "Combat")
{
	//keyBind = 0x4b;
}

void Hitbox::onLoop()
{
	Cheat::onLoop();
}

void Hitbox::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			MultiPlayerLevel* Level = LunMem::getClientInstance()->LocalPlayer->MultiPlayerLevel;
			uintptr_t startAddr = (uintptr_t)Level->playerListBegin;
			uintptr_t endAddr = (uintptr_t)Level->playerListEnd;

			for (uintptr_t currEnt = startAddr; currEnt < endAddr; currEnt += 0x8) {
				if (currEnt == startAddr) continue;
				Actor* Entity = (Actor*)currEnt;
				Entity->setSize(5, 2);
			}
		}
	}
}

void Hitbox::onEnable()
{
	Cheat::onEnable();
}

void Hitbox::onDisable()
{
	Cheat::onDisable();
}

void Hitbox::onKey(ulong key) {
}
