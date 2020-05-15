#include "pch.h"
#include "AirJump.h"

AirJump::AirJump():Cheat::Cheat("AirJump")
{
	enabled = true;
	keyBind = 0x4b;
}

void AirJump::onLoop()
{
	Cheat::onLoop();
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
