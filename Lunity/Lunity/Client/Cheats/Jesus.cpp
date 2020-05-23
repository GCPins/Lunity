#include "pch.h"
#include "Jesus.h"

Jesus::Jesus() :Cheat::Cheat("Jesus", "Movement")
{

}

void Jesus::onEnable()
{
	Cheat::onEnable();
}

void Jesus::onDisable()
{
	Cheat::onDisable();
}

void Jesus::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* localPlayer = LunMem::getClientInstance()->LocalPlayer;

			if (localPlayer->isInWater() | localPlayer->isInLava()) {
				if (localPlayer->isJumping()) {
					localPlayer->VelocityXYZ.y = 0.25f;
				}
				else {
					localPlayer->jumpFromGround();
				}
			}
		}
	}
}