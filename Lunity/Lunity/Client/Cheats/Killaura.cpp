#include "pch.h"
#include "Killaura.h"
#include "../Hooks/GamemodeHook.h"
#include "../../SDK/EntList.h"
#include "../../SDK/LunMath.h"

Killaura::Killaura() :Cheat::Cheat("Killaura", "Combat")
{

}

void Killaura::onGmTick(GameMode* gm) {
	LocalPlayer* player = LunMem::getClientInstance()->LocalPlayer;
	vector<Actor*>* ents = getEntities();
	if (ents != NULL) {
		for (uint i = 0; i < ents->size(); i++) {
			if (LunMath::distanceVec3(*ents->at(i)->getPos(), *player->getPos()) <= 12.0f) {
				Vector2 anglesVec = LunMath::getRotationAnglesToEnt(*ents->at(i)->getPos(), *player->getPos());
				player->setRot(&anglesVec);
				player->swing();
				gm->attack(ents->at(i));
			}
		}
	}
}
