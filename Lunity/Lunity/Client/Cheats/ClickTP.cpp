#include "pch.h"
#include "ClickTP.h"
#include "../Hooks/MouseHook.h"

bool useless = false;
ClickTP::ClickTP() :Cheat::Cheat("ClickTP", "Player")
{
	registerToggleSetting("Test", &useless);
}

bool clickedOnce = false;

void ClickTP::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
			int lookingBlockX = Player->MultiPlayerLevel->LookingBlockX;
			int lookingBlockY = Player->MultiPlayerLevel->LookingBlockY;
			int lookingBlockZ = Player->MultiPlayerLevel->LookingBlockZ;

			if (MouseHook::ButtonState(0x02) && !clickedOnce) {
				if (lookingBlockY > 0) {
					clickedOnce = true;
					Vector3 teleportToVec;
					teleportToVec.x = (float)lookingBlockX;
					teleportToVec.y = (float)lookingBlockY + 3.0f;
					teleportToVec.z = (float)lookingBlockZ;
					Player->setPos(&teleportToVec);
				}
			}

			if (!MouseHook::ButtonState(0x02) && clickedOnce) {
				clickedOnce = false;
			}
		}
	}
}