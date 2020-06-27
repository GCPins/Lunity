#include "pch.h"
#include "TestModule.h"

bool testToggle = false;

float testSliderValue = -1.0f;

TestModule::TestModule() :Cheat::Cheat("TestModule", "Other")
{
	registerToggleSetting("TestToggle", &testToggle);
	registerSliderSetting("TestSlider", &testSliderValue, 2.0f, 10.0f);
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
	Logger::logHex("GuiData", (ulong)LunMem::getClientInstance()->getGuiData());
	//Logger::logHex("The return", LunMem::getClientInstance()->Function49());
}

void TestModule::onPostRender() {
	if (enabled) {
		ClientInstance* instance = LunMem::getClientInstance();
		if (instance != NULL) {
			LocalPlayer* player = instance->LocalPlayer;
			if (player != NULL) {
				player->shouldRender();
			}
		}
	}
}

void TestModule::onDisable()
{
	Cheat::onDisable();
}

void TestModule::onGmTick(GameMode* GM) {
	Cheat::onGmTick(GM);
}