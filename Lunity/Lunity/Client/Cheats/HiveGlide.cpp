#include "pch.h"
#include "HiveGlide.h"

/*
0x900617
(BYTE*)"\xFF\x50\x08"
*/

static std::chrono::time_point<std::chrono::steady_clock> savedTime;
bool toggle = false;

HiveGlide::HiveGlide() :Cheat::Cheat("HiveGlide", "Movement")
{

}

void HiveGlide::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
			Player->VelocityXYZ.y = (float)0;

			if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - savedTime) >= std::chrono::milliseconds(250)) {

				if (toggle) {
					LunMem::Nop((BYTE*)LunMem::getBaseModule() + 0x900617, 3);
					Logger::log("NOP");
					toggle = false;
				}
				else {
					LunMem::Patch((BYTE*)LunMem::getBaseModule() + 0x900617, (BYTE*)"\xFF\x50\x08", 3);
					Logger::log("Patch");
					toggle = true;
				}

				savedTime = std::chrono::high_resolution_clock::now();
			}
		}
	}
}

void HiveGlide::onEnable()
{
	Cheat::onEnable();
	Logger::log("Made by the help of R3coil");
	savedTime = std::chrono::high_resolution_clock::now();
}

void HiveGlide::onDisable() {
	Cheat::onDisable();
	LunMem::Patch((BYTE*)LunMem::getBaseModule() + 0x900617, (BYTE*)"\xFF\x50\x08", 3);
	toggle = false;
}