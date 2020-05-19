#include "pch.h"
#include "NameTest.h"
#include "../../SDK/DrawUtils.h"

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
	//enabled = false;
	Logger::logHex("GuiData", (uintptr_t)DrawUtils::getGuiData());
}

void NameTest::onPreRender() {
	if (enabled) {
		vec2_t* locOnScr = new vec2_t();
		GuiData* guiD = DrawUtils::getGuiData();
		if (DrawUtils::WorldToScreen(vec3_t(0, 5, 0), *locOnScr)) {
			/*vec2_t scaled;
			scaled.x = locOnScr->x * guiD->Scale;
			scaled.y = locOnScr->y * guiD->Scale;
			Logger::log("X: " + to_string(scaled.x));
			Logger::log("Y: " + to_string(scaled.y));*/
			Logger::log("X: " + to_string(locOnScr->x));
			Logger::log("Y: " + to_string(locOnScr->y));
			DrawUtils::drawText(*locOnScr, &string("T"), nullptr, 1);
		}
	}
}