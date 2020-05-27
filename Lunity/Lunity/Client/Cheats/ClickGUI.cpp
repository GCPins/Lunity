#include "pch.h"
#include "ClickGUI.h"
#include "../../SDK/DrawUtils.h"
#include "../CheatManager.h"
#include "../Gui/VWindow.h"

VWindow* testWindow;
ClickGUI::ClickGUI() : Cheat::Cheat("ClickGUI", "Visuals")
{
	testWindow = new VWindow(0,0,60,10);
}

vector<vec4_t> linesss;

void ClickGUI::onDisable() {
	linesss.clear();
}

float rainOff = 0.0f;

void ClickGUI::onMouseMove() {
	rainOff += 0.01f;
	//Logger::log("RainbowOff: " + to_string(rainOff));
	if (rainOff >= 1) {
		rainOff = 0;
	}
}

void ClickGUI::onPostRender()
{
	if (enabled) {
		testWindow->onRender();


		//Fancy mouse shit
		//Logger::logHex("GuiData", (ulong)DrawUtils::getGuiData());
		GuiData* gd = DrawUtils::getGuiData();
		int mx = float(gd->MouseX) / gd->GuiScale;
		int my = float(gd->MouseY) / gd->GuiScale;
		linesss.push_back(vec4_t(mx - 1, my - 1, mx + 1, my + 1));
		for (int i = 0; i < linesss.size(); i++) {
			float colorProg = (float)i / 50.0f;
			colorProg += rainOff;
			if (colorProg >= 1) {
				colorProg -= 1;
			}
			DrawUtils::fillRectangle(linesss[i], DrawUtils::rainbow(colorProg), 1);
		}
		if (linesss.size() > 50) {
			linesss.erase(linesss.begin());
		}
	}
}
