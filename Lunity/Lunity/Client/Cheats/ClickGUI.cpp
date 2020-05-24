#include "pch.h"
#include "ClickGUI.h"
#include "../../SDK/DrawUtils.h"

ClickGUI::ClickGUI() : Cheat::Cheat("ClickGUI", "Visuals")
{
}

void ClickGUI::onPostRender()
{
	if (enabled) {
		//Logger::logHex("GuiData", (ulong)DrawUtils::getGuiData());
		GuiData* gd = DrawUtils::getGuiData();
		int mx = float(gd->MouseX) / gd->GuiScale;
		int my = float(gd->MouseY) / gd->GuiScale;
		DrawUtils::fillRectangle(vec4_t(mx - 1, my - 1, mx + 1, my + 1), MC_Color(0,0,0,1), 1);
		//DrawUtils::drawText(vec2_t(mx, my), &string("°"), nullptr, 1.0f);
	}
}
