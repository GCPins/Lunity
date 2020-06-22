#include "pch.h"
#include "Misplace.h"
#include "../../SDK/EntList.h"
#include "../../SDK/EntList.h"

float range = 3.0f;

float offset = 2.5f;

Misplace::Misplace() :Cheat::Cheat("Misplace", "Combat")
{
	registerSliderSetting("Range", &range, 0.0f, 15.0f);
	registerSliderSetting("Offset", &offset, 0.0f, 5.0f);
}

void Misplace::onLoop()
{
	Cheat::onLoop();
}

void Misplace::onTick()
{
	Cheat::onTick();
}

void Misplace::onEnable()
{
	Cheat::onEnable();
}

void Misplace::onDisable()
{
	Cheat::onDisable();
}

void Misplace::onGmTick(GameMode* GM) {
	Cheat::onGmTick(GM);
	LocalPlayer* player = LunMem::getClientInstance()->LocalPlayer;
	vector<Actor*>* ents = getEntities();
	Vector2 lookingAngless;
	if (ents != NULL) {
		for (uint i = 0; i < ents->size(); i++) {
			if (LunMath::distanceVec3(*ents->at(i)->getPos(), *player->getPos()) <= range) {
				lookingAngless = LunMath::getRotationAnglesToEnt(*player->getPos(), *ents->at(i)->getPos());
				Vector3 eek;
				Vector3 playerpos;
				playerpos = *player->getPos();
				eek.x = cos((player->LookingVec.y + 90.0f) * (3.14 / 180.0f)) * offset;
				eek.y = sin((player->LookingVec.x) * -(3.14 / 180.0f)) * offset;
				eek.z = sin((player->LookingVec.y + 90.0f) * (3.14 / 180.0f)) * offset;

				eek.x += playerpos.x;
				eek.y += playerpos.y;
				eek.z += playerpos.z;

				ents->at(i)->setPos(&eek);
			}
		}
	}
}