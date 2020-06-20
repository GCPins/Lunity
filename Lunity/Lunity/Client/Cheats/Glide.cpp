#include "pch.h"
#include "Glide.h"
#include "../Hooks/KeyHook.h"

float glide = 0.0f;
float glideup = 0.15f;
float glidedown = -0.15f;


Glide::Glide() :Cheat::Cheat("Glide", "Movement")
{
	registerSliderSetting("Glide", &glide, -1.0f, 1.0f);
	registerSliderSetting("Up", &glideup, 0.0f, 1.0f);
	registerSliderSetting("Down", &glidedown, -1.0f, 0.0f);
}

void Glide::onGmTick(GameMode* gm) {
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			bool holdingLeftShift = KeyHook::KeyState(0x10);
			bool holdingSpace = KeyHook::KeyState(0x20);

			if (!holdingLeftShift && !holdingSpace) {
				LunMem::getClientInstance()->LocalPlayer->VelocityXYZ.y = glide;
			}
			else {
				if (holdingLeftShift && !holdingSpace) {
					LunMem::getClientInstance()->LocalPlayer->VelocityXYZ.y = glidedown;
				}
				else if (holdingSpace && !holdingLeftShift) {
					LunMem::getClientInstance()->LocalPlayer->VelocityXYZ.y = glideup;
				}
			}
		}
	}
}