#include "pch.h"
#include "AutoWalk.h"

AutoWalk::AutoWalk() :Cheat::Cheat("AutoWalk", "Movement")
{

}

void AutoWalk::onGmTick(GameMode* gm)
{
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
			Player->VelocityXYZ.x = cos((LunMem::getClientInstance()->LocalPlayer->LookingVec.y + 90) * (3.14159 / 180.0f)) * 0.235f;
			Player->VelocityXYZ.z = sin((LunMem::getClientInstance()->LocalPlayer->LookingVec.y + 90) * (3.14159 / 180.0f)) * 0.235f;
		}
	}
}