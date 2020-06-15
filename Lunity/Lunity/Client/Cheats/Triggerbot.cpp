#include "pch.h"
#include "Triggerbot.h"
#include "../Hooks/GamemodeHook.h"

Triggerbot::Triggerbot() :Cheat::Cheat("Triggerbot", "Combat")
{

}

void Triggerbot::onGmTick(GameMode* gm) {
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* player = LunMem::getClientInstance()->LocalPlayer;
			Actor* lookingAtEnt = LunMem::getClientInstance()->LocalPlayer->MultiPlayerLevel->LookingActor;
			//logHex("Looking", (ulong)lookingAtEnt);
			if (lookingAtEnt != NULL) {
				player->swing();
				gm->attack(lookingAtEnt);
			}
		}
	}
}