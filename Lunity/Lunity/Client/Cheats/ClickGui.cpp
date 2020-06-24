#include "pch.h"
#include "ClickGui.h"
#include "../CheatManager.h"
#include "../Hooks/MouseHook.h"
#include "../../SDK/DrawUtils.h"
#include "../../SDK/LunMath.h"
#include <iomanip>

struct Frame {
	string title;
	Rect titleRect;
	bool expanded;
};
int dx;
int dy;
Frame* beingDragged = nullptr;
vector<Frame*> windows;
int frameWid = 90;
ClickGui::ClickGui() : Cheat::Cheat("ClickGui", "Visuals")
{
	keyBind = 0x2d;
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
	my += 1;
	return my;
}

void ClickGui::onMouseButton(ulong button) {
	if (enabled) {
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
					else {
						if (window->expanded) {
							int cheatExpOff = 0;
							vector<Cheat*> cheatsInCat = CheatManager::getCheatsOfCategory(window->title);
							for (int i = 0; i < cheatsInCat.size(); i++) {
								int settingOff = 0;
								Cheat* leCheat = cheatsInCat[i];
								Rect cheatRect = Rect(titleRect.x, titleRect.y + titleRect.height + i * 10 + cheatExpOff, 75, 10);
								int mx = getMouseX();
								int my = getMouseY();
								Color rectColor = Color(.15, .15, .15, 1);
								if (cheatRect.contains(mx, my)) {
									leCheat->enabled = !leCheat->enabled;
								}
								Rect expRect = Rect(titleRect.x + 75, titleRect.y + titleRect.height + (i == 0) + i * 10 + settingOff + cheatExpOff, 15, 10);
								if (expRect.contains(mx, my)) {
									leCheat->expandedInClickUi = !leCheat->expandedInClickUi;
								}
								if (leCheat->expandedInClickUi) {
									//For keybinds
									Rect settingRect = cheatRect.add(0, settingOff + 10, 15, 0);
									if (settingRect.contains(mx, my)) {
										leCheat->reassigningKey = !leCheat->reassigningKey;
									}
									settingOff += 10;
									cheatExpOff += 10;

									vector<ToggleSetting*> toggleSettings = leCheat->toggleSettings;
									for (int s = 0; s < toggleSettings.size(); s++) {
										ToggleSetting* currentSetting = toggleSettings[s];
										Color settingsRectColor = Color(.20, .20, .20, 1);
										Rect settingRect = cheatRect.add(0, settingOff + 10, 15, 0);
										if (settingRect.contains(mx, my)) {
											currentSetting->setValue(!currentSetting->getValue());
										}
										settingOff += 10;
										cheatExpOff += 10;
									}
									vector<SliderSetting*> sliderSettings = leCheat->sliderSettings;
									for (int s = 0; s < sliderSettings.size(); s++) {
										settingOff += 20;
										cheatExpOff += 20;
									}
								}
							}
						}
					}
				}
			}
		}
		if (button == 2) {
			int mx = getMouseX();
			int my = getMouseY();
			for (int i = 0; i < windows.size(); i++) {
				Frame* window = windows[i];
				Rect titleRect = window->titleRect;
				if (titleRect.contains(Vector2(mx, my))) {
					window->expanded = !window->expanded;
				}
				else {
					if (window->expanded) {
						int cheatExpOff = 0;
						vector<Cheat*> cheatsInCat = CheatManager::getCheatsOfCategory(window->title);
						for (int i = 0; i < cheatsInCat.size(); i++) {
							int settingOff = 0;
							Cheat* leCheat = cheatsInCat[i];
							Rect cheatRect = Rect(titleRect.x, titleRect.y + titleRect.height + i * 10 + cheatExpOff, 75, 10);
							if (leCheat->expandedInClickUi) {
								Rect settingRect = cheatRect.add(0, settingOff + 10, 15, 0);
								if (settingRect.contains(mx, my)) {
									leCheat->reassigningKey = false;
									leCheat->keyBind = 0;
								}
							}
						}
					}
				}
			}
		}
	}
}
void ClickGui::onMouseMove() {
	if (enabled) {
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
}

void ClickGui::onEnable() {
	if (windows.size() == 0) {
		beingDragged == nullptr;
		vector<string> categories = CheatManager::getCategories();
		for (int i = 0; i < categories.size(); i++) {
			windows.push_back(new Frame{
				categories[i],
				Rect(i * frameWid, 0, frameWid, 10)
				});
		}
	}
}
void ClickGui::onDisable() {

}


void ClickGui::onKey(ulong key) {
	vector<Cheat*> cheats = CheatManager::getCheats();
	for (int i = 0; i < cheats.size(); i++) {
		Cheat* current = cheats[i];
		if (current->reassigningKey) {
			current->keyBind = key;
			current->reassigningKey = false;
		}
	}
}


string tKeybind = "KeyBind:";
void drawKeybindSetting(Cheat* cheat, Rect cheatRect, int* cheatExpOff, int* settingOff, int mx, int my) {
	Rect settingRect = cheatRect.add(0, *settingOff + 10, 15, 0);
	Color settingsRectColor = Color(.20, .20, .20, 1);
	if (settingRect.contains(mx, my)) {
		settingsRectColor.x += .2;
		settingsRectColor.y += .2;
		settingsRectColor.z += .2;
	}
	DrawUtils::fillRectangle(settingRect, settingsRectColor, 1);
	DrawUtils::drawText(Vector2(settingRect.x, settingRect.y), &tKeybind, nullptr, 1);

	string keyTxt;
	if (cheat->reassigningKey)
		keyTxt = "...";
	else
		keyTxt = string((char*)&cheat->keyBind);
	float valWid = DrawUtils::getTextWidth(keyTxt, 1);
	DrawUtils::drawText(Vector2(settingRect.x + 90 - valWid, settingRect.y), &keyTxt, nullptr, 1);

	*settingOff += 10;
	*cheatExpOff += 10;

}

void drawToggleSetting(ToggleSetting* currentSetting, Rect cheatRect, int* cheatExpOff, int* settingOff, int mx, int my) {
	Rect settingRect = cheatRect.add(0, *settingOff + 10, 15, 0);
	Color settingsRectColor = Color(.20, .20, .20, 1);
	if (settingRect.contains(mx, my)) {
		settingsRectColor.x += .2;
		settingsRectColor.y += .2;
		settingsRectColor.z += .2;
	}
	if (currentSetting->getValue()) {
		settingsRectColor.z = 1;
	}
	string text = currentSetting->text;
	DrawUtils::fillRectangle(settingRect, settingsRectColor, 1);
	DrawUtils::drawText(Vector2(settingRect.x, settingRect.y), &text, nullptr, 1);
	*settingOff += 10;
	*cheatExpOff += 10;
}
float getPixelValue(float min, float max) {
	float total = std::abs(min) + std::abs(max);
	return total / (frameWid-5);
}

void drawSliderSetting(SliderSetting* currentSetting, Rect cheatRect, int* cheatExpOff, int* settingOff, int mx, int my) {
	Rect settingRect = cheatRect.add(0, *settingOff + 10, 15, 10);
	string text = currentSetting->text;
	std::stringstream ss;
	ss << fixed << setprecision(2) << currentSetting->getValue();
	string valueText = ss.str();
	float valWid = DrawUtils::getTextWidth(valueText, 1);
	Color settingsRectColor = Color(.20, .20, .20, 1);
	DrawUtils::fillRectangle(settingRect, settingsRectColor, 1);
	DrawUtils::drawText(Vector2(settingRect.x, settingRect.y), &text, nullptr, 1);
	DrawUtils::drawText(Vector2(settingRect.x + 90 - valWid, settingRect.y), &valueText, nullptr, 1);

	float pixelVal = getPixelValue(currentSetting->getMin(), currentSetting->getMax());
	//Logger::log("PixelVal: " + to_string(pixelVal));

	float sliderOff = ((currentSetting->getValue() + abs(currentSetting->getMin())) / pixelVal);
	//Logger::log("SliderOff: " + to_string(sliderOff));

	if (MouseHook::ButtonState(1)) {
		Rect sliderRegion = settingRect.add(0, 10, 0, -10);
		if (sliderRegion.contains(mx, my)) {
			if (!currentSetting->dragging) {
				currentSetting->dragging = true;
			}
		}
		if (currentSetting->dragging) {
			int xOff = mx - sliderRegion.x;
			float newVal = pixelVal * xOff;
			newVal += currentSetting->getMin();
			currentSetting->setValue(newVal);
		}
	}
	else if (MouseHook::ButtonState(2)) {
		Rect sliderRegion = settingRect.add(0, 10, 0, -10);
		if (sliderRegion.contains(mx, my)) {
			currentSetting->setValue(currentSetting->getDefault());
		}
	}
	else {
		currentSetting->dragging = false;
	}

	Rect sliderRect = settingRect.add(sliderOff, 10, -85, -10);
	Color sliderRectColor = Color(.20, .20, 1, 1);
	if (sliderRect.contains(mx, my)) {
		sliderRectColor.x += .2;
		sliderRectColor.y += .2;
		sliderRectColor.z += .2;
	}
	DrawUtils::fillRectangle(sliderRect, sliderRectColor, 1);

	*settingOff += 20;
	*cheatExpOff += 20;
}

float rainbowProg = 0;
void ClickGui::onPostRender()
{
	if (rainbowProg >= 1) {
		rainbowProg = 0;
	}
	rainbowProg += 0.001;
	if (enabled) {
		for (int i = 0; i < windows.size(); i++) {
			Frame* window = windows[i];
			Rect titleRect = window->titleRect;
			DrawUtils::fillRectangle(titleRect, Color(.35,.35,.35,1), 1);
			DrawUtils::drawText(Vector2(titleRect.x, titleRect.y), &window->title, nullptr, 1);
			string expIco = "+";
			if (window->expanded) {
				expIco = "-";
			}
			float expWid = DrawUtils::getTextWidth(expIco, 1);
			DrawUtils::drawText(Vector2(titleRect.x + titleRect.width - expWid, titleRect.y), &expIco, nullptr, 1);
			int cheatExpOff = 0;
			string settingsIco = string("...");
			if (window->expanded) {
				DrawUtils::fillRectangle(Rect(titleRect.x, titleRect.y + titleRect.height, titleRect.width, 1), Color(.5, .5, .5, 1), 1);
				vector<Cheat*> cheatsInCat = CheatManager::getCheatsOfCategory(window->title);
				for (int i = 0; i < cheatsInCat.size(); i++) {
					Cheat* leCheat = cheatsInCat[i];
					Rect cheatRect = Rect(titleRect.x, titleRect.y + titleRect.height + (i==0) + i * 10 + cheatExpOff, 75, 10);
					int mx = getMouseX();
					int my = getMouseY();
					Color rectColor = Color(.15, .15, .15, 1);
					if (cheatRect.contains(mx, my)) {
						rectColor.x += .2;
						rectColor.y += .2;
						rectColor.z += .2;
					}
					if (leCheat->enabled) {
						rectColor.z = 1;
					}
					DrawUtils::fillRectangle(cheatRect, rectColor, 1);
					DrawUtils::drawText(Vector2(cheatRect.x, cheatRect.y), &leCheat->name, nullptr, 1);
					Rect expRect = Rect(titleRect.x+75, titleRect.y + titleRect.height + (i == 0) + i * 10 + cheatExpOff, 15, 10);
					Color expColor = Color(.15, .15, .15, 1);
					if (expRect.contains(mx, my)) {
						expColor.x += .2;
						expColor.y += .2;
						expColor.z += .2;
					}
					if (leCheat->expandedInClickUi) {
						expColor.z = 1;
					}
					DrawUtils::fillRectangle(expRect, expColor, 1);
					float settingsIcoWid = DrawUtils::getTextWidth(settingsIco, 1);
					DrawUtils::drawText(Vector2(expRect.x + settingsIcoWid-1, expRect.y-2), &settingsIco, nullptr, 1);
					if (leCheat->expandedInClickUi) {
						int settingOff = 0;
						drawKeybindSetting(leCheat, cheatRect, &cheatExpOff, &settingOff, mx, my);
						vector<ToggleSetting*> toggleSettings = leCheat->toggleSettings;
						for (int s = 0; s < toggleSettings.size(); s++) {
							drawToggleSetting(toggleSettings[s], cheatRect, &cheatExpOff, &settingOff, mx, my);
						}
						vector<SliderSetting*> sliderSettings = leCheat->sliderSettings;
						for (int s = 0; s < sliderSettings.size(); s++) {
							drawSliderSetting(sliderSettings[s], cheatRect, &cheatExpOff, &settingOff, mx, my);
						}
					}
				}
			}
		}
	}
}