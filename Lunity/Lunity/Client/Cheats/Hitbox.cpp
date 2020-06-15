#include "pch.h"
#include "Hitbox.h"
#include "../Hooks/KeyHook.h"
#include "../../SDK/EntList.h"

Hitbox::Hitbox() :Cheat::Cheat("Hitbox", "Combat")
{

}

void Hitbox::onTick()
{
	Cheat::onTick();
	vector<Actor*>* ents = getEntities();
	if (ents != NULL) {
		for (uint i = 0; i < ents->size(); i++) {
			Actor* Entity = (Actor*)ents->at(i);
			Entity->setSize((float)6, (float)6);
		}
		Sleep(10);
	}
}

void Hitbox::onEnable()
{
	Cheat::onEnable();
}

void Hitbox::onDisable()
{
	Cheat::onDisable();
	vector<Actor*>* ents = getEntities();
	if (ents != NULL) {
		for (uint i = 0; i < ents->size(); i++) {
			Actor* Entity = (Actor*)ents->at(i);
			Entity->setSize((float)0.6, (float)1.8);
		}
	}
}
