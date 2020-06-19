#include "pch.h"
#include "Antivoid.h"

static std::chrono::time_point<std::chrono::steady_clock> savedTime;

bool bruhmoment = false;

float yeetSliderValue = 4.0f;

Vector3 fallpos;

Vector3 actualfallpos;

Vector3 thiccposeins;
Vector3 thiccposzvei;

float theythingy;

int thicc = 0;
bool lastcounter = false;

Antivoid::Antivoid() :Cheat::Cheat("Antivoid", "Movement")
{
	registerSliderSetting("Fall distance", &yeetSliderValue, 0.0f, 10.0f);
}

void Antivoid::onLoop()
{
	Cheat::onLoop();
}

void Antivoid::onTick()
{
	Cheat::onTick();
	LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
	if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - savedTime) >= std::chrono::milliseconds(500))
	{
		if (lastcounter)
		{
			lastcounter = false;
			thiccposeins = *Player->getPos();
		}
		else
		{
			lastcounter = true;
			thiccposzvei = *Player->getPos();
		}
		savedTime = std::chrono::high_resolution_clock::now();
	}
}

void Antivoid::onEnable()
{
	Cheat::onEnable();
	Logger::logHex("The return", LunMem::getClientInstance()->Function49());
}

void Antivoid::onDisable()
{
	Cheat::onDisable();
}

void Antivoid::onGmTick(GameMode* GM) {
	Cheat::onGmTick(GM);
	LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
	if (!Player->OnGround)
	{
		if (!bruhmoment) {
			bruhmoment = true;
			//once
			fallpos = *Player->getPos();
		}
		if (bruhmoment) {
			//untill notfalling
			actualfallpos = *Player->getPos();
			theythingy = fallpos.y - actualfallpos.y;
			if (theythingy > 0)
			{
				if (theythingy > yeetSliderValue - 0.4f)
				{
					if (lastcounter)
					{
						Player->setPos(&thiccposeins);
					}
					else
					{
						Player->setPos(&thiccposzvei);
					}
				}
			}
		}
	}
	else {
		if (bruhmoment) {
			bruhmoment = false;
			//once when not falling
		}
		//when not falling (every thicc)
	}
}