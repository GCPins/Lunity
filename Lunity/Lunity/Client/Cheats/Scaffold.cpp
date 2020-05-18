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
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {

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

			int diagonalFace = Scaffold::calculateNewBlockSide(side, *Player->getPos());
			if(diagonalFace > 0) gm->buildBlock(blockPos, diagonalFace);
			gm->buildBlock(blockPos, side);
		}
	}
}

int Scaffold::calculateNewBlockSide(int currSide, Vector3 currentPos) {
	float playerX = currentPos.x;
	float playerZ = currentPos.z;

	int newFace = 0;

	switch (currSide) {

	case 5:
		if (playerZ - 0.2f == floor(playerZ - 1.0f)) {
			newFace = 2;
		}
		else if (playerZ + 0.2f == floor(playerZ + 1.0f)) {
			newFace = 3;
		}
	break;

	case 4:
		if (playerZ + 0.2f == floor(playerZ + 1.0f)) {
			newFace = 3;
		}
		else if (playerZ - 0.2f == floor(playerZ - 1.0f)) {
			newFace = 2;
		}
	break;

	case 3:
		if (playerX + 0.2f == floor(playerX + 1.0f)) {
			newFace = 5;
		} else if (playerX - 0.2f == floor(playerX - 1.0f)) {
			newFace = 4;
		}
	break;

	case 2:
		if (playerX - 0.2f == floor(playerX - 1.0f)) {
			newFace = 5;
		}
		else if (playerX + 0.2f == floor(playerX + 1.0f)) {
			newFace = 4;
		}
	break;

	}

	return newFace;
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
