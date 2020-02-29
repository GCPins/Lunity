#include "AirJump.h"
void AirJump::onTick() {
	*localPlayer.onGround = true;
}

void AirJump::onEnable()
{
}

void AirJump::onDisable()
{
}
