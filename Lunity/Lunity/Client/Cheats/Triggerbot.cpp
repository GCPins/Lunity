#include "pch.h"
#include "Triggerbot.h"
#include "../Hooks/GamemodeHook.h"

Triggerbot::Triggerbot() :Cheat::Cheat("Triggerbot", "Combat")
{
	//keyBind = 0x4b;
}

void Triggerbot::onLoop()
{
	Cheat::onLoop();
}

void Triggerbot::onTick()
{
	Cheat::onTick();
}

void Triggerbot::onGmTick(GameMode* gm) {
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* player = LunMem::getClientInstance()->LocalPlayer;
			Actor* lookingAtEnt = LunMem::getClientInstance()->LocalPlayer->MultiPlayerLevel->LookingActor;
			//logHex("Looking", (ulong)lookingAtEnt);
			if (lookingAtEnt != NULL) {
				player->swing();
				//player->attack(lookingAtEnt);
				gm->attack(lookingAtEnt);
			}
		}
	}
}

void Triggerbot::onEnable()
{
	Cheat::onEnable();
}

void Triggerbot::onDisable()
{
	Cheat::onDisable();
}

void Triggerbot::onKey(ulong key) {
}
