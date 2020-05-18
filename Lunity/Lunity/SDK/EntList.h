#pragma once
#include "../BigHead.h"


static vector<Actor*>* getEntities() {
	if (LunMem::getClientInstance() == NULL)
		return (vector<Actor*>*)NULL;
	if (LunMem::getClientInstance()->LocalPlayer == NULL)
		return (vector<Actor*>*)NULL;
	vector<Actor*>* ret = new vector<Actor*>();
	LocalPlayer* player = LunMem::getClientInstance()->LocalPlayer;
	MultiPlayerLevel* mpl = player->MultiPlayerLevel;
	Actor** list = (Actor**)mpl->playerListBegin;
	uint index = 0;
	while (1) {
		if (list[index] == NULL) {
			break;
		}
		if ((ulong)list[index] > 0x30000000000) {
			break;
		}
		if (list[index] == (Actor*)((uintptr_t)mpl->playerListEnd-0x8)) {
			break;
		}
		if (list[index] == (Actor*)player) {
			index++;
			continue;
		}
		if (list[index]->isAlive()) {
			if (!list[index]->isInvisible()) {
				if (list[index]->MovedTick != NULL) {
					//Logger::logHex("Current ent", (ulong)list[index]);
					ret->push_back(list[index]);
				}
			}
		}
		index++;
	}
	return ret;
}