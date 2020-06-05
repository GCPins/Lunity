#include "pch.h"
#include "ClickGui.h"
#include "../CheatManager.h"
#include "../Hooks/MouseHook.h"
#include "../../SDK/DrawUtils.h"
#include "../../SDK/LunMath.h"

struct Frame {
	string title;
	Rect titleRect;
};
int dx;
int dy;
Frame* beingDragged = nullptr;
vector<Frame*> windows;
int frameWid = 75;
ClickGui::ClickGui() : Cheat::Cheat("ClickGui", "Visuals")
{
	
}

short getMouseX()
{
	GuiData* gd = DrawUtils::getGuiData();
	short mx = float(gd->MouseX) / gd->GuiScale;
	if (mx < 0 || mx > gd->ScaledResolution.x) {
		mx = 0;
	}
	return mx;
}
short getMouseY()
{
	GuiData* gd = DrawUtils::getGuiData();
	short my = float(gd->MouseY) / gd->GuiScale;
	if (my < 0 || my > gd->ScaledResolution.y) {
		my = 0;
	}
	return my;
}

void ClickGui::onMouseButton(ulong button) {
	if (button == 1) {
		if (beingDragged == nullptr) {
			GuiData* gd = DrawUtils::getGuiData();
			int x = getMouseX();
			int y = getMouseY();
			for (int i = 0; i < windows.size(); i++) {
				Frame* window = windows[i];
				Rect titleRect = window->titleRect;
				if (titleRect.contains(Vector2(x, y))) {
					dx = x - titleRect.x;
					dy = y - titleRect.y;
					beingDragged = window;
				}
			}
		}
	}
}
void ClickGui::onMouseMove() {
	if (beingDragged != nullptr) {
		if (MouseHook::ButtonState(1)) {
			Rect titleRect = beingDragged->titleRect;
			int x = getMouseX();
			int y = getMouseY();
			Vector2 newPos = Vector2(x - dx, y - dy);
			beingDragged->titleRect.setPos(newPos);
		}
		else {
			beingDragged = nullptr;
		}
	}
}

void ClickGui::onEnable() {
	if (windows.size() > 0) {
		windows.clear();
	}
	beingDragged == nullptr;
	vector<string> categories = CheatManager::getCategories();
	for (int i = 0; i < categories.size(); i++) {
		windows.push_back(new Frame{
			categories[i],
			Rect(i * frameWid, 0, frameWid, 10)
		});
	}
}

void ClickGui::onPostRender()
{
	if (enabled) {
		for (int i = 0; i < windows.size(); i++) {
			Frame* window = windows[i];
			Rect titleRect = window->titleRect;
			DrawUtils::fillRectangle(titleRect, Color(.15,.15,.15,1), 1);
			DrawUtils::drawText(Vector2(titleRect.x, titleRect.y), &window->title, nullptr, 1);
		}
	}
}
