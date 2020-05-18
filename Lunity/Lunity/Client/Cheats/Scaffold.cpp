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

			gm->buildBlock(blockPos, side);
			int diagonalFace = Scaffold::calculateNewBlockSide(side, *Player->getPos());
			if (diagonalFace > 0) gm->buildBlock(blockPos, diagonalFace);
		}
	}
}

int Scaffold::calculateNewBlockSide(int currSide, Vector3 currentPos) {
	LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;

	float playerX = currentPos.x;
	float playerZ = currentPos.z;

	int newFace = 0;

	switch (currSide) {

	case 5:
		if (floor(playerZ - 0.2f) == floor(playerZ - 1.0f)) {
			newFace = 2;
			TextHolder* Text = new TextHolder("Facing East, turning left");
			//Player->displayLocalizableMessage(Text);
		}
		else if (floor(playerZ + 0.2f) == floor(playerZ + 1.0f)) {
			newFace = 3;
			TextHolder* Text = new TextHolder("Facing East, turning right");
			//Player->displayLocalizableMessage(Text);
		}
		break;

	case 4:
		if (floor(playerZ + 0.2f) == floor(playerZ + 1.0f)) {
			newFace = 3;
			TextHolder* Text = new TextHolder("Facing West, turning left");
			//Player->displayLocalizableMessage(Text);
		}
		else if (floor(playerZ - 0.2f) == floor(playerZ - 1.0f)) {
			newFace = 2;
			TextHolder* Text = new TextHolder("Facing West, turning right");
			//Player->displayLocalizableMessage(Text);
		}
		break;

	case 3:
		if (floor(playerX + 0.2f) == floor(playerX + 1.0f)) {
			newFace = 5;
			TextHolder* Text = new TextHolder("Facing South, turning left");
			//Player->displayLocalizableMessage(Text);
		}
		else if (floor(playerX - 0.2f) == floor(playerX - 1.0f)) {
			newFace = 4;
			TextHolder* Text = new TextHolder("Facing South, turning right");
			//Player->displayLocalizableMessage(Text);
		}
		break;

	case 2:
		if (floor(playerX - 0.2f) == floor(playerX - 1.0f)) {
			newFace = 5;
			TextHolder* Text = new TextHolder("Facing North, turning left");
			//Player->displayLocalizableMessage(Text);
		}
		else if (floor(playerX + 0.2f) == floor(playerX + 1.0f)) {
			newFace = 4;
			TextHolder* Text = new TextHolder("Facing North, turning right");
			//Player->displayLocalizableMessage(Text);
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
