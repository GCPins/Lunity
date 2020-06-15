#include "pch.h"
#include "AirJump.h"

AirJump::AirJump():Cheat::Cheat("AirJump", "Movement")
{

}

void AirJump::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LunMem::getClientInstance()->LocalPlayer->OnGround = 0xFFFFFFFF;
		}
	}
}
