#include "pch.h"
#include "NameTest.h"

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

void NameTest::onGmTick(GameMode* gm) {
	ClientInstance* inst = LunMem::getClientInstance();
	LocalPlayer* plr = inst->LocalPlayer;
	Vector3* pos = new Vector3();
	pos->x = 0;
	pos->y = 5;
	pos->z = 0;
	Vector2* look = &plr->LookingVec;
	MovePlayerPacket* packet = new MovePlayerPacket((Actor*)plr, pos, look, 0x1);
	//Logger::logHex("Genned", (ulong)packet);
	inst->LoopbackPacketSender->sendToServer(packet);
}