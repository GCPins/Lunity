#include "pch.h"
#include "PlaceFly.h"

PlaceFly::PlaceFly() : Cheat::Cheat("PlaceFly", "Movement")
{
}

void PlaceFly::onEnable()
{
	//add = true;
}

//bool add = true;
void PlaceFly::onGmTick(GameMode* gm) {
	LocalPlayer* player = LunMem::getClientInstance()->LocalPlayer;
	Vector3* pos = player->getPos();
	//player.
	/*Vector3_i* vec3i = new Vector3_i();
	vec3i->x = floor(pos->x);
	vec3i->y = floor(pos->y - 2);
	vec3i->z = floor(pos->z);
	gm->buildBlock(vec3i, 1);*/
}