#include "pch.h"
#include "NameTest.h"
#include "../../SDK/EntList.h"

NameTest::NameTest() : Cheat::Cheat("NameTest", "Other")
{
}

void NameTest::onEnable()
{
	/*
	LunMem::getClientInstance()->LocalPlayer->displayLocalizableMessage(new TextHolder("Test!"));
	LunMem::getClientInstance()->LocalPlayer->setName(new TextHolder("Franklin"));
	LunMem::getClientInstance()->LocalPlayer->setNameTagVisible(true);
	*/
	//LunMem::getClientInstance()->LoopbackPacketSender->sendToServer(new TextHolder(string("Hello!")));
	//enabled = false;
}

void NameTest::onTick() {
	
}

int i = 0;
void NameTest::onGmTick(GameMode* gm) {
	ClientInstance* inst = LunMem::getClientInstance();
	LocalPlayer* plr = inst->LocalPlayer;
	MovePlayerPacket* packet = new MovePlayerPacket((Actor*)plr, plr->getPos(), &plr->LookingVec, 0x1);
	inst->LoopbackPacketSender->sendToServer(packet);
	Logger::logHex("Genned", (ulong)packet);
	/*
	ClientInstance* inst = LunMem::getClientInstance();
	LocalPlayer* plr = inst->LocalPlayer;
	Vector2* look = &plr->LookingVec;
	vector<Actor*>* ents = getEntities();

	Actor* ent = ents->at(i);
	if (ent != (Actor*)plr) {
		Vector3* pos = ent->getPos();
		MovePlayerPacket* packet = new MovePlayerPacket((Actor*)plr, pos, look, 0x1);
		inst->LoopbackPacketSender->sendToServer(packet);

		plr->swing();
		gm->attack(ent);
	}

	i++;
	if (ents->size() <= i) {
		i = 0;
	}
	//Logger::logHex("Genned", (ulong)packet);
	*/
}