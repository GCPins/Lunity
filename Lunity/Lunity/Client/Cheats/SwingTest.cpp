#include "pch.h"
#include "SwingTest.h"
SwingTest::SwingTest() : Cheat::Cheat("SwingTest") {
	enabled = true;
}

void SwingTest::onTick()
{
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* player = LunMem::getClientInstance()->LocalPlayer;
			player->swing();
			Sleep(10);
		}
	}
}