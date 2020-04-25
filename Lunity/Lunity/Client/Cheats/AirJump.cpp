#include "pch.h"
#include "AirJump.h"

AirJump::AirJump():Cheat::Cheat("AirJump")
{
}

void AirJump::onLoop()
{
	Cheat::onLoop();
	if (GetAsyncKeyState('k') || GetAsyncKeyState('K')) {
		log("K is down");
		enabled = !enabled;
	}
}

void AirJump::onTick()
{
	Cheat::onTick();
	//log("Ticking AirJump");
	if (LunMem::getClientInstance() != NULL)
		if (LunMem::getClientInstance()->localPlayer != NULL) {
			//logHex("OnGround: ", LunMem::getClientInstance()->localPlayer->onGround);
			LunMem::getClientInstance()->localPlayer->onGround = 0xFFFFFFFF;
		}
}

void AirJump::onEnable()
{
	Cheat::onEnable();
}

void AirJump::onDisable()
{
	Cheat::onDisable();
}
