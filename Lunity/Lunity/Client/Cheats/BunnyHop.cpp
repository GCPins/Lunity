#include "pch.h"
#include "BunnyHop.h"
#include "../Hooks/KeyHook.h"

#define PI 3.14159
float bunnyHopSpeed = 0.42f;

BunnyHop::BunnyHop() :Cheat::Cheat("BunnyHop", "Movement")
{
	registerSliderSetting("Speed", &bunnyHopSpeed, 0.1f, 2.f);
}

void BunnyHop::onGmTick(GameMode* gm)
{
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
			float calcYaw = Player->LookingVec.y;

			bool pressedWKey = KeyHook::KeyState(0x57);
			bool pressedSKey = KeyHook::KeyState(0x53);
			bool pressedAKey = KeyHook::KeyState(0x41);
			bool pressedDKey = KeyHook::KeyState(0x44);
			
			if (pressedWKey) {
				if (!pressedAKey && !pressedDKey) {
					calcYaw += 90.0f;
				}
				else if (pressedAKey) {
					calcYaw += 45.0f;
				}
				else if (pressedDKey) {
					calcYaw += 135.0f;
				}
			}
			else if (pressedSKey) {
				if (!pressedAKey && !pressedDKey) {
					calcYaw -= 90.0f;
				}
				else if (pressedAKey) {
					calcYaw -= 45.0f;
				}
				else if (pressedDKey) {
					calcYaw -= 135.0f;
				}
			}
			else if (!pressedWKey && !pressedSKey) {
				if (pressedDKey) {
					calcYaw += 180.0f;
				}
			}

			if (pressedWKey | pressedSKey | pressedAKey | pressedDKey) {
				Player->VelocityXYZ.x = cos((calcYaw) * (PI / 180.0f)) * bunnyHopSpeed;
				Player->VelocityXYZ.z = sin((calcYaw) * (PI / 180.0f)) * bunnyHopSpeed;

				if (Player->OnGround) {
					if(!Player->isJumping()) Player->jumpFromGround();
				}
			}
		}
	}
}
