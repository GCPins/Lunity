#include "pch.h"
#include "Killaura.h"
#include "../Hooks/GamemodeHook.h"
#include "../../SDK/EntList.h"

Killaura::Killaura() :Cheat::Cheat("Killaura", "Combat")
{
	//keyBind = 0x4b;
}

void Killaura::onLoop()
{
	Cheat::onLoop();
}

void Killaura::onTick()
{
	Cheat::onTick();
	//LocalPlayer* player = LunMem::getClientInstance()->LocalPlayer;
	//if (GamemodeHook::getLastGm() != NULL) {
	//	vector<Actor*>* ents = getEntities();
	//	if (ents != NULL) {
	//		for (uint i = 0; i < ents->size(); i++) {
	//			Vector3* vec = ents->at(i)->getPos();
	//			Vector3* localVec = player->getPos();
	//			float dX = localVec->x - vec->x;
	//			float dY = localVec->y - vec->y;
	//			float dZ = localVec->z - vec->z;
	//			float dist = sqrt(dX * dX + dY * dY + dZ * dZ);
	//			Logger::log("Dist:" + to_string(dist));
	//			if (dist < 6) {
	//				player->swing();
	//				//player->setTarget(ents->at(i));
	//				GamemodeHook::getLastGm()->attack(ents->at(i));
	//			}
	//		}
	//		Sleep(10);
	//	}
	//}
}

void Killaura::onGmTick(GameMode* gm) {
	LocalPlayer* player = LunMem::getClientInstance()->LocalPlayer;
	vector<Actor*>* ents = getEntities();
	if (ents != NULL) {
		for (uint i = 0; i < ents->size(); i++) {
			Vector3* vec = ents->at(i)->getPos();
			Vector3* localVec = player->getPos();
			float dX = localVec->x - vec->x;
			float dY = localVec->y - vec->y;
			float dZ = localVec->z - vec->z;
			float dist = sqrt(dX * dX + dY * dY + dZ * dZ);
			//Logger::log("Dist:" + to_string(dist));
			if (dist < 6) {
				//Logger::log("Can attack");
				player->swing();
				//player->setTarget(ents->at(i));
				gm->attack(ents->at(i));
			}
		}
	}
}

void Killaura::onEnable()
{
	Cheat::onEnable();
}

void Killaura::onDisable()
{
	Cheat::onDisable();
}

void Killaura::onKey(ulong key) {
}
