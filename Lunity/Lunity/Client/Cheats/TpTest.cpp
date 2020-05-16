#include "pch.h"
#include "TpTest.h"
TpTest::TpTest() :Cheat::Cheat("TpTest", "Movement")
{
	enabled = true;
}

void TpTest::onTick()
{
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LocalPlayer* player = LunMem::getClientInstance()->LocalPlayer;
			Vector3* pos = player->getPos();
			if (pos->x > 100) {
				pos->x = 90;
				player->setPos(pos);
			}
		}
	}
}
