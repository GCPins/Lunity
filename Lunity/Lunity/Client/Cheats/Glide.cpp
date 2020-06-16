#include "pch.h"
#include "Glide.h"
#include "../Hooks/KeyHook.h"

Glide::Glide() :Cheat::Cheat("Glide", "Movement")
{

}

void Glide::onGmTick(GameMode* gm) {
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			bool holdingLeftShift = KeyHook::KeyState(0x10);
			bool holdingSpace = KeyHook::KeyState(0x20);

			if (!holdingLeftShift && !holdingSpace) {
				LunMem::getClientInstance()->LocalPlayer->VelocityXYZ.y = (float)0;
			}
			else {
				if (holdingLeftShift && !holdingSpace) {
					LunMem::getClientInstance()->LocalPlayer->VelocityXYZ.y = (float)-0.15f;
				}
				else if (holdingSpace && !holdingLeftShift) {
					LunMem::getClientInstance()->LocalPlayer->VelocityXYZ.y = (float)0.15f;
				}
			}
		}
	}
}