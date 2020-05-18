#include "pch.h"
#include "TpAura.h"
#include "../../SDK/EntList.h"

TpAura::TpAura():Cheat::Cheat("TpAura", "Combat")
{
	keyBind = 0x4F;
}

void TpAura::onLoop()
{
	Cheat::onLoop();
}

void TpAura::onTick()
{
	Cheat::onTick();
}

void TpAura::onGmTick(GameMode* gm) {
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
			if (dist > 6) {
				//player->swing();
				player->setPos(vec);
			}
		}
	}
}

void TpAura::onEnable()
{
	Cheat::onEnable();
}

void TpAura::onDisable()
{
	Cheat::onDisable();
}

void TpAura::onKey(ulong key) {
}
