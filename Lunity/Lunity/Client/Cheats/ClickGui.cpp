#include "pch.h"
#include "ClickGui.h"
#include "../CheatManager.h"
#include "../../SDK/DrawUtils.h"
#include "../../SDK/LunMath.h"

struct Frame {
	string title;
	int x;
	int y;
};
vector<Frame*> windows;
int frameWid = 75;
ClickGui::ClickGui() : Cheat::Cheat("ClickGui", "Visuals")
{
	
}

void ClickGui::onEnable() {
	if (windows.size() > 0) {
		windows.clear();
	}
	vector<string> categories = CheatManager::getCategories();
	for (int i = 0; i < categories.size(); i++) {
		windows.push_back(new Frame{
			categories[i],
			i * frameWid,
			0
		});
	}
}

void ClickGui::onPostRender()
{
	if (enabled) {
		for (int i = 0; i < windows.size(); i++) {
			Frame* window = windows[i];
			Vector4 titleRect = Vector4(window->x, window->y, window->x + frameWid, window->y + 10);
			DrawUtils::fillRectangle(titleRect, Color(.15,.15,.15,1), 1);
			DrawUtils::drawText(Vector2(window->x, window->y), &window->title, nullptr, 1);
		}
	}
}
