#include "pch.h"
#include "Triggerbot.h"
#include "../Hooks/GamemodeHook.h"

float triggerbotDelayF;
std::chrono::time_point<std::chrono::steady_clock> oldTime_C = std::chrono::high_resolution_clock::now();

Triggerbot::Triggerbot() :Cheat::Cheat("Triggerbot", "Combat")
{
	registerSliderSetting("Delay (MS)", &triggerbotDelayF, 0.f, 1000.f);
}

void Triggerbot::onGmTick(GameMode* gm) {
	int triggerbotTime = (int)triggerbotDelayF;

	if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - oldTime_C) >= std::chrono::milliseconds{ triggerbotTime }) {
		if (LunMem::getClientInstance() != NULL) {
			if (LunMem::getClientInstance()->LocalPlayer != NULL) {
				LocalPlayer* player = LunMem::getClientInstance()->LocalPlayer;
				Actor* lookingAtEnt = LunMem::getClientInstance()->LocalPlayer->MultiPlayerLevel->LookingActor;
				if (lookingAtEnt != NULL) {
					player->swing();
					gm->attack(lookingAtEnt);
				}
			}
		}

		oldTime_C = std::chrono::high_resolution_clock::now();
	}
}