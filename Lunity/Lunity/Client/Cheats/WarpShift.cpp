#include "pch.h"
#include "WarpShift.h"

WarpShift::WarpShift() :Cheat::Cheat("WarpShift", "Movement")
{

}

void WarpShift::onGmTick(GameMode* gm)
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			if (KeyHook::KeyState(0x43)) {
				LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;

				Player->VelocityXYZ.x = cos((Player->LookingVec.y + 90.0f) * (3.14159 / 180.0f)) * 0.5f;
				Player->VelocityXYZ.y = (float)0;
				Player->VelocityXYZ.z = sin((Player->LookingVec.y + 90.0f) * (3.14159 / 180.0f)) * 0.5f;
			}
		}
	}
}

void WarpShift::onEnable()
{
	Cheat::onEnable();
	Logger::log("Hold 'C' to warp");
}