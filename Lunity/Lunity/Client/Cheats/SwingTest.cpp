#include "pch.h"
#include "SwingTest.h"
#include "../KeyHook.h"
SwingTest::SwingTest() : Cheat::Cheat("SwingTest") {
	enabled = true;
}

void SwingTest::onTick()
{
	if (KeyHook::KeyState(0x4A)) {
		if (LunMem::getClientInstance() != NULL) {
			if (LunMem::getClientInstance()->LocalPlayer != NULL) {
				LocalPlayer* player = LunMem::getClientInstance()->LocalPlayer;
				player->swing();
				Sleep(10);
			}
		}
	}
}