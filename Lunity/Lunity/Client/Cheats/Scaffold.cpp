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

Vector3i* blockPos = new Vector3i;
Vector3 currentPos;

void Scaffold::onGmTick(GameMode* gm) {
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {

			LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
			currentPos = *Player->getPos();

			int side = 0;
			bool bridgedSideways = false;

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
			
			switch (side) {

			case 5:
				if (floor(currentPos.z - 0.2f) == floor(currentPos.z - 1.0f)) {
					bridgedSideways = true;
					gm->buildBlock(blockPos, 2);
					blockPos->z--;
					gm->buildBlock(blockPos, 5);
					//TextHolder* Text = new TextHolder("Facing East, turning left");
					//Player->displayLocalizableMessage(Text);
				}
				else if (floor(currentPos.z + 0.2f) == floor(currentPos.z + 1.0f)) {
					bridgedSideways = true;
					gm->buildBlock(blockPos, 3);
					blockPos->z++;
					gm->buildBlock(blockPos, 5);
					//TextHolder* Text = new TextHolder("Facing East, turning right");
					//Player->displayLocalizableMessage(Text);
				}

				if (floor(currentPos.x - 0.2f) == floor(currentPos.x - 1.0f)) {
					gm->buildBlock(blockPos, 4);
					//TextHolder* Text = new TextHolder("Facing East, going backwards");
					//Player->displayLocalizableMessage(Text);
				}
				break;

			case 4:
				if (floor(currentPos.z + 0.2f) == floor(currentPos.z + 1.0f)) {
					bridgedSideways = true;
					gm->buildBlock(blockPos, 3);
					blockPos->z++;
					gm->buildBlock(blockPos, 4);
					//TextHolder* Text = new TextHolder("Facing West, turning left");
					//Player->displayLocalizableMessage(Text);
				}
				else if (floor(currentPos.z - 0.2f) == floor(currentPos.z - 1.0f)) {
					bridgedSideways = true;
					gm->buildBlock(blockPos, 2);
					blockPos->z--;
					gm->buildBlock(blockPos, 4);
					//TextHolder* Text = new TextHolder("Facing West, turning right");
					//Player->displayLocalizableMessage(Text);
				}

				if (floor(currentPos.x + 0.2f) == floor(currentPos.x + 1.0f)) {
					gm->buildBlock(blockPos, 5);
					//TextHolder* Text = new TextHolder("Facing West, going backwards");
					//Player->displayLocalizableMessage(Text);
				}
				break;

			case 3:
				if (floor(currentPos.x + 0.2f) == floor(currentPos.x + 1.0f)) {
					bridgedSideways = true;
					gm->buildBlock(blockPos, 5);
					blockPos->x++;
					gm->buildBlock(blockPos, 3);
					//TextHolder* Text = new TextHolder("Facing South, turning left");
					//Player->displayLocalizableMessage(Text);
				}
				else if (floor(currentPos.x - 0.2f) == floor(currentPos.x - 1.0f)) {
					bridgedSideways = true;
					gm->buildBlock(blockPos, 4);
					blockPos->x--;
					gm->buildBlock(blockPos, 3);
					//TextHolder* Text = new TextHolder("Facing South, turning right");
					//Player->displayLocalizableMessage(Text);
				}

				if (floor(currentPos.z - 0.2f) == floor(currentPos.z - 1.0f)) {
					gm->buildBlock(blockPos, 2);
					//TextHolder* Text = new TextHolder("Facing South, going backwards");
					//Player->displayLocalizableMessage(Text);
				}
				break;

			case 2:
				if (floor(currentPos.x - 0.2f) == floor(currentPos.x - 1.0f)) {
					bridgedSideways = true;
					gm->buildBlock(blockPos, 4);
					blockPos->x--;
					gm->buildBlock(blockPos, 2);
					//TextHolder* Text = new TextHolder("Facing North, turning left");
					//Player->displayLocalizableMessage(Text);
				}
				else if (floor(currentPos.x + 0.2f) == floor(currentPos.x + 1.0f)) {
					bridgedSideways = true;
					gm->buildBlock(blockPos, 5);
					blockPos->x++;
					gm->buildBlock(blockPos, 2);
					//TextHolder* Text = new TextHolder("Facing North, turning right");
					//Player->displayLocalizableMessage(Text);
				}

				if (floor(currentPos.z + 0.2f) == floor(currentPos.z + 1.0f)) {
					gm->buildBlock(blockPos, 3);
					//TextHolder* Text = new TextHolder("Facing North, going backwards");
					//Player->displayLocalizableMessage(Text);
				}
				break;
			}
			if (!bridgedSideways) {
				gm->buildBlock(blockPos, side);
			}

			bridgedSideways = false;
		}
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
