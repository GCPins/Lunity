#include "pch.h"
#include "TestModule.h"

bool testToggle = false;

float testSliderValue = 0.0f;

TestModule::TestModule() :Cheat::Cheat("TestModule", "Other")
{
	registerToggleSetting("TestToggle", &testToggle);
	registerSliderSetting("TestSlider", &testSliderValue, -1.0f, 1.0f);
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

void TestModule::onGmTick(GameMode* GM) {
	Cheat::onGmTick(GM);
}