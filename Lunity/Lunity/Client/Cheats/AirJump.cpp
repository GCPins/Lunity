#include "pch.h"
#include "AirJump.h"

AirJump::AirJump():Cheat::Cheat("AirJump", "Movement")
{
	//keyBind = 0x4b;
}

void AirJump::onLoop()
{
	Cheat::onLoop();
}

void AirJump::onTick()
{
	Cheat::onTick();
	//log("Ticking AirJump");
	if (LunMem::getClientInstance() != NULL)
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			//logHex("OnGround: ", LunMem::getClientInstance()->localPlayer->onGround);
			LunMem::getClientInstance()->LocalPlayer->OnGround = 0xFFFFFFFF;
		}
}

void AirJump::onEnable()
{
	Cheat::onEnable();
	TextHolder playerName = TextHolder(string("Hacker"));
	TextHolder textH = TextHolder(string("no"));
	TextPacket* text = new TextPacket(playerName, textH);
	Logger::logHex("Constructed", (ulong)text);
	//while(1){}
	LunMem::getClientInstance()->LoopbackPacketSender->sendToServer(text);
}

void AirJump::onDisable()
{
	Cheat::onDisable();
}

void AirJump::onKey(ulong key) {
}
