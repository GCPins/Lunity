#include "pch.h"
#include "AirJump.h"

AirJump::AirJump()
{
	log("Loaded AirJump!");
}

void AirJump::onLoop()
{
	//log("Ticking AirJump");
	if(LunMem::getClientInstance() != NULL)
		if (LunMem::getClientInstance()->localPlayer != NULL) {
			//logHex("OnGround: ", LunMem::getClientInstance()->localPlayer->onGround);
			LunMem::getClientInstance()->localPlayer->onGround = 0xFFFFFFFF;
		}
}

void AirJump::onTick()
{
}

void AirJump::onEnable()
{
}

void AirJump::onDisable()
{
}
