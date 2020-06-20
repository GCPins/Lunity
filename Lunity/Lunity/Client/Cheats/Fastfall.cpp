#include "pch.h"
#include "Fastfall.h"

float speed = 0.3f;

bool fallcheck = true;

Fastfall::Fastfall() :Cheat::Cheat("Fastfall", "Movement")
{
	registerToggleSetting("Fall check", &fallcheck);
	registerSliderSetting("Speed", &speed, 0.0f, 10.0f);
}

void Fastfall::onLoop()
{
	Cheat::onLoop();
}

void Fastfall::onTick()
{
	Cheat::onTick();
}

void Fastfall::onEnable()
{
	Cheat::onEnable();
	Logger::logHex("The return", LunMem::getClientInstance()->Function49());
}

void Fastfall::onDisable()
{
	Cheat::onDisable();
}

void Fastfall::onGmTick(GameMode* GM) {
	Cheat::onGmTick(GM);
	LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
	if (Player->VelocityXYZ.y < 0 & fallcheck)
	{
		Player->VelocityXYZ.y += (float)-1 * speed;
	}
	else {
		if (!fallcheck)
		{
			Player->VelocityXYZ.y += (float)-1 * speed;
		}
	}
}