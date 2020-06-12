#include "pch.h"
#include "ModuleList.h"
#include "../../SDK/DrawUtils.h"
#include "../CheatManager.h"

ModuleList::ModuleList():Cheat::Cheat("ModuleList", "Visuals")
{
	enabled = true;
}

void ModuleList::onPostRender()
{
	if (enabled) {
		vector<Cheat*> cheats = CheatManager::getCheats();
		vector<Cheat*> enabledCheats;
		for (uint i = 0; i < cheats.size(); i++) {
			if (cheats[i]->enabled) {
				enabledCheats.push_back(cheats[i]);
			}
		}
		GuiData* gui = DrawUtils::getGuiData();
		Vector2 res = gui->ScaledResolution;
		for (uint i = 0; i < enabledCheats.size(); i++) {
			float wid = DrawUtils::getTextWidth(enabledCheats[i]->name, 1);
			float safeX = res.x - wid;
			DrawUtils::fillRectangle(Vector4(safeX - 7, i * 10 + 5, safeX + wid - 3, i * 10 + 15), Color(0, 0, 0, 1), 0.2f);
			DrawUtils::drawText(Vector2(safeX - 5, i * 10 + 5), &enabledCheats[i]->name, nullptr, 1);
		}
	}
}