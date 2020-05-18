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

	blockPos->x = (int)currentPos.x + 0.3f;
	blockPos->y = (int)currentPos.y - 2;
	blockPos->z = (int)currentPos.z + 0.3f;

	gm->buildBlock(blockPos, 0);

	//gm->buildBlock();
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
