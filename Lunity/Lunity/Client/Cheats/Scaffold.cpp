#include "pch.h"
#include "Scaffold.h"
#include "../Hooks/GamemodeHook.h"

Scaffold::Scaffold() :Cheat::Cheat("Scaffold", "Player")
{

}

void Scaffold::onLoop()
{
	Cheat::onLoop();
}

void Scaffold::onTick()
{
	Cheat::onTick();
}

void Scaffold::onGmTick(GameMode* gm) {
	LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
	Vector3_i* blockPos = new Vector3_i;
	Vector3 currentPos = *Player->getPos();

	int side = 0;

	blockPos->x = (int)floor(currentPos.x);
	blockPos->y = (int)floor(currentPos.y - (float)2.0f);
	blockPos->z = (int)floor(currentPos.z);

	Vector2 playerLookingVec = Player->LookingVec;
	float playerYaw = playerLookingVec.y;
	
	if (playerYaw < -45 && playerYaw > -135)
		side = 5;
	else if (playerYaw > 45 && playerYaw < 135)
		side = 4;
	else if ((playerYaw <= 0 && playerYaw >= -45) || (playerYaw >= 0 && playerYaw <= 45))
		side = 3;
	else if (playerYaw >= 135 && playerYaw <= 180 || (playerYaw >= -180 && playerYaw <= -135))
		side = 2;

	if (Player->isJumping()) {
		gm->buildBlock(blockPos, 1);
	}
	else {
		gm->buildBlock(blockPos, side);
	}
}

void Scaffold::onEnable()
{
	Cheat::onEnable();
}

void Scaffold::onDisable()
{
	Cheat::onDisable();
}

void Scaffold::onKey(ulong key) {
}

void calculateOnKey() {

}
