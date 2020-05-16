#include "pch.h"
#include "TabGUI.h"
#include "../../SDK/DrawUtils.h"
#include "../CheatManager.h"

TabGUI::TabGUI():Cheat::Cheat("TabGUI", "Visuals")
{
	enabled = true;
}

uint selectedCat = 0;
void TabGUI::onPostRender()
{
	vector<Cheat*> cheats = CheatManager::getCheats();
	vector<string> categories = CheatManager::getCategories();
	//Cant be used in another function for some reason
	DrawUtils::fillRectangle(vec4_t(8, 8, 100, 35 + (categories.size() * 10)), MC_Color(0, 0, 0, 1), .5);
	DrawUtils::drawRectangle(vec4_t(8, 8, 100, 35 + (categories.size() * 10)), MC_Color(.5, 0, .5, 1), .5, 2);
	std::string lunStr = std::string("Lunity");
	DrawUtils::drawText(vec2_t(10, 10), &lunStr, nullptr, 3.0f);
	for (uint i = 0; i < categories.size(); i++) {
		bool selected = selectedCat == i;
		if (selected) {
			DrawUtils::drawText(vec2_t(10, 35 + (i * 10)), &string(">"+categories[i]), nullptr, 1.0f);
		}
		else {
			DrawUtils::drawText(vec2_t(10, 35 + (i * 10)), &categories[i], nullptr, 1.0f);
		}
	}
}

void TabGUI::onKey(ulong key)
{
	vector<string> categories = CheatManager::getCategories();
	if (key == 0x28) {
		selectedCat++;
	}
	if (key == 0x26) {
		selectedCat--;
	}
	if (selectedCat >= categories.size()) {
		selectedCat = 0;
	}
}
