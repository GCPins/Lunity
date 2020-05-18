#include "pch.h"
#include "Spinbot.h"

Vector2* rot;
Spinbot::Spinbot():Cheat::Cheat("Spinbot", "Player")
{
	keyBind = 0x4F;
	rot = new Vector2();
	rot->x = 0.0f;
}

void Spinbot::onLoop()
{
	Cheat::onLoop();
}

void Spinbot::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL)
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* player = LunMem::getClientInstance()->LocalPlayer;
			//if(player->isJumping() && player->)
			rot->y += 5;
			player->setRot(rot);
		}
}

void Spinbot::onEnable()
{
	Cheat::onEnable();
}

void Spinbot::onDisable()
{
	Cheat::onDisable();
}

void Spinbot::onKey(ulong key) {
}
