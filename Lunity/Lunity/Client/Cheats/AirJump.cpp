#include "pch.h"
#include "AirJump.h"

AirJump::AirJump():Cheat::Cheat("AirJump")
{
	enabled = true;
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
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			//logHex("OnGround: ", LunMem::getClientInstance()->localPlayer->onGround);
			LunMem::getClientInstance()->LocalPlayer->OnGround = 0xFFFFFFFF;
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
