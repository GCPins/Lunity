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
	MultiPlayerLevel* Level = LunMem::getClientInstance()->LocalPlayer->MultiPlayerLevel;
	uintptr_t startAddr = (uintptr_t)(Level + 0x40);
	uintptr_t endAddr = (uintptr_t)(Level + 0x48);

	for (uintptr_t currEnt = startAddr; currEnt < endAddr; currEnt += 0x8) {
		LocalPlayer* Entity = (LocalPlayer*)currEnt;
		Entity->setSize((float)6, (float)6);
	}
	Sleep(10);
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
