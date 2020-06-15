#include "pch.h"
#include "InventoryMove.h"
#include "../Hooks/KeyHook.h"

float walkSpeed;
bool supportAutoSprint = true;

InventoryMove::InventoryMove() :Cheat::Cheat("InventoryMove", "Player")
{
	registerToggleSetting("Allow Sprinting", &supportAutoSprint);
}

void InventoryMove::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;

			if (Player->InventoryUiState == 4) {
				float calcYaw = Player->LookingVec.y;

				if (Player->OnGround) {
					if (!Player->isJumping() && KeyHook::KeyState(0x20)) Player->jumpFromGround();
				}

				if (KeyHook::KeyState(0x57)) {
					if (!KeyHook::KeyState(0x41) && !KeyHook::KeyState(0x44)) {
						calcYaw += 90.0f;
					}
					else if (KeyHook::KeyState(0x41)) {
						calcYaw += 45.0f;
					}
					else if (KeyHook::KeyState(0x44)) {
						calcYaw += 135.0f;
					}
				}
				else if (KeyHook::KeyState(0x53)) {
					if (!KeyHook::KeyState(0x41) && !KeyHook::KeyState(0x44)) {
						calcYaw -= 90.0f;
					}
					else if (KeyHook::KeyState(0x41)) {
						calcYaw -= 45.0f;
					}
					else if (KeyHook::KeyState(0x44)) {
						calcYaw -= 135.0f;
					}
				}
				else if (!KeyHook::KeyState(0x57) && !KeyHook::KeyState(0x53)) {
					if (KeyHook::KeyState(0x44)) {
						calcYaw += 180.0f;
					}
				}

				if (KeyHook::KeyState(0x57) | KeyHook::KeyState(0x53) | KeyHook::KeyState(0x41) | KeyHook::KeyState(0x44)) {
					if (supportAutoSprint) {
						if (Player->isSprinting()) {
							walkSpeed = 0.35f;
						}
						else {
							walkSpeed = 0.235f;
						}
					}
					else {
						walkSpeed = 0.235f;
					}

					Player->VelocityXYZ.x = cos((calcYaw) * (3.14159 / 180.0f)) * walkSpeed;
					Player->VelocityXYZ.z = sin((calcYaw) * (3.14159 / 180.0f)) * walkSpeed;
				}
			}
		}
	}
}