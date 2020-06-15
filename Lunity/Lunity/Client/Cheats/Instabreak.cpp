#include "pch.h"
#include "Instabreak.h"
#include "../Hooks/MouseHook.h"

Instabreak::Instabreak() :Cheat::Cheat("Instabreak", "Player")
{

}

void Instabreak::onGmTick(GameMode* gm) {
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
			int lookingBlockX = Player->MultiPlayerLevel->LookingBlockX;
			int lookingBlockY = Player->MultiPlayerLevel->LookingBlockY;
			int lookingBlockZ = Player->MultiPlayerLevel->LookingBlockZ;

			if (MouseHook::ButtonState(0x01) && lookingBlockY > 0) {
				Vector3i blockPos;
				blockPos.x = lookingBlockX;
				blockPos.y = lookingBlockY;
				blockPos.z = lookingBlockZ;
				gm->destroyBlock(&blockPos, 1);
			}
		}
	}
}
