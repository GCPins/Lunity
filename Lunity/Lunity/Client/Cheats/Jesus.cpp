#include "pch.h"
#include "Jesus.h"

Jesus::Jesus() :Cheat::Cheat("Jesus", "Movement")
{

}

void Jesus::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* localPlayer = LunMem::getClientInstance()->LocalPlayer;

			if (localPlayer->isInWater() | localPlayer->isOverWater() | localPlayer->isInLava()) {
				localPlayer->VelocityXYZ.y = 0.35f;
			}
		}
	}
}