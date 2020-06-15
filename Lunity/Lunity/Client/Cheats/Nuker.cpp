#include "pch.h"
#include "Nuker.h"
#include "../Hooks/GamemodeHook.h"
#include "../Hooks/KeyHook.h"
#include "../Hooks/MouseHook.h"

float radiusSizeF = 6;

Nuker::Nuker() :Cheat::Cheat("Nuker", "Player")
{
	registerSliderSetting("Radius", &radiusSizeF, 1.0f, 20.0f);
}

void Nuker::onGmTick(GameMode* gm) {
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			int staringBlockX = LunMem::getClientInstance()->LocalPlayer->MultiPlayerLevel->LookingBlockX;
			int staringBlockY = LunMem::getClientInstance()->LocalPlayer->MultiPlayerLevel->LookingBlockY;
			int staringBlockZ = LunMem::getClientInstance()->LocalPlayer->MultiPlayerLevel->LookingBlockZ;

			if (MouseHook::ButtonState(0x01) && staringBlockY > 0) {

				Vector3i blockPos;
				blockPos.x = staringBlockX;
				blockPos.y = staringBlockY;
				blockPos.z = staringBlockZ;

				gm->destroyBlock(&blockPos, 1);

				int radiusSize = (int)radiusSizeF;

				Vector3i newBlockPos = blockPos;

				for (int varX = blockPos.x; varX < blockPos.x + radiusSize; varX++) {
					for (int varZ = blockPos.z; varZ < blockPos.z + radiusSize; varZ++) {
						for (int varY = blockPos.y; varY > blockPos.y - radiusSize; varY--) {
							if (varY > 0) {
								newBlockPos.y = varY;
							}
							else {
								newBlockPos.y = 1;
							}
							newBlockPos.x = varX;
							newBlockPos.z = varZ;
							gm->destroyBlock(&newBlockPos, 1);
						}
					}
				}

				newBlockPos = blockPos;

				for (int varX = blockPos.x; varX > blockPos.x - radiusSize; varX--) {
					for (int varZ = blockPos.z; varZ > blockPos.z - radiusSize; varZ--) {
						for (int varY = blockPos.y; varY > blockPos.y - radiusSize; varY--) {
							if (varY > 0) {
								newBlockPos.y = varY;
							}
							else {
								newBlockPos.y = 1;
							}
							newBlockPos.x = varX;
							newBlockPos.z = varZ;
							gm->destroyBlock(&newBlockPos, 1);
						}
					}
				}

				newBlockPos = blockPos;

				for (int varX = blockPos.x; varX > blockPos.x - radiusSize; varX--) {
					for (int varZ = blockPos.z; varZ < blockPos.z + radiusSize; varZ++) {
						for (int varY = blockPos.y; varY > blockPos.y - radiusSize; varY--) {
							if (varY > 0) {
								newBlockPos.y = varY;
							}
							else {
								newBlockPos.y = 1;
							}
							newBlockPos.x = varX;
							newBlockPos.z = varZ;
							gm->destroyBlock(&newBlockPos, 1);
						}
					}
				}

				for (int varX = blockPos.x; varX < blockPos.x + radiusSize; varX++) {
					for (int varZ = blockPos.z; varZ > blockPos.z - radiusSize; varZ--) {
						for (int varY = blockPos.y; varY > blockPos.y - radiusSize; varY--) {
							if (varY > 0) {
								newBlockPos.y = varY;
							}
							else {
								newBlockPos.y = 1;
							}
							newBlockPos.x = varX;
							newBlockPos.z = varZ;
							gm->destroyBlock(&newBlockPos, 1);
						}
					}
				}
			}
		}
	}
}