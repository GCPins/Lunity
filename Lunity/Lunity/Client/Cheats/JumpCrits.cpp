#include "pch.h"
#include "JumpCrits.h"

JumpCrits::JumpCrits() :Cheat::Cheat("JumpCrits", "Combat")
{
}

void JumpCrits::onLoop()
{
	Cheat::onLoop();
}

void JumpCrits::onTick()
{
	Cheat::onTick();
}

void JumpCrits::onGmTick(GameMode* gm) {
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
			Actor* lookingAtEnt = LunMem::getClientInstance()->LocalPlayer->MultiPlayerLevel->LookingActor;
			//logHex("Looking", (ulong)lookingAtEnt);
			if (lookingAtEnt != NULL) {
				if (Player->OnGround)
				{
						Player->jumpFromGround();
				}
			}
		}
	}
}

void JumpCrits::onEnable()
{
	Cheat::onEnable();
}

void JumpCrits::onDisable()
{
	Cheat::onDisable();
}

void JumpCrits::onKey(ulong key) {
}