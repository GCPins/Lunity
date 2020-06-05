#include "pch.h"
#include "TestModule.h"

TestModule::TestModule() :Cheat::Cheat("TestModule", "Other")
{

}

void TestModule::onLoop()
{
	Cheat::onLoop();
}

void TestModule::onTick()
{
	Cheat::onTick();
}

void TestModule::onEnable()
{
	Cheat::onEnable();
}

void TestModule::onDisable()
{
	Cheat::onDisable();
}

void TestModule::onGamemodeTick(GameMode* GM) {
	//
}