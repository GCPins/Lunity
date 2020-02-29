#include "AirJump.h"
void AirJump::onTick() {
	*localPlayer.onGround = true;
	log("Ticking airjump!");
}

void AirJump::onEnable()
{
}

void AirJump::onDisable()
{
}
