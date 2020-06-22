#pragma once
#include "pch.h"
#include "Radar.h"
#include "../../SDK/DrawUtils.h"
#include "../../SDK/EntList.h"
#include "../Hooks/MouseHook.h"

float winSize = 100.0f;
int x = 0;
int y = 0;
bool dragging = false;
int diffx = 0;
int diffy = 0;
Radar::Radar() : Cheat::Cheat("Radar", "Visuals") {
	registerSliderSetting("Size", &winSize, 20, 200);
}

void Radar::onMouseButton(ulong button) {
	if (button == 1) {
		Rect winRect = Rect(x, y, winSize, winSize);
		GuiData* gd = LunMem::getClientInstance()->getGuiData();
		int mx = gd->MouseX / gd->GuiScale;
		int my = gd->MouseY / gd->GuiScale;
		if (winRect.contains(mx, my)) {
			diffx = mx - x;
			diffy = my - y;
			dragging = true;
		}
	}
}

void drawEntityBoxes() {
	vector<Actor*>* actors = getEntities();
	LocalPlayer* lp = LunMem::getClientInstance()->LocalPlayer;
	for (int i = 0; i < actors->size(); i++) {
		Actor* currentActor = actors->at(i);
		if (currentActor != NULL) {
			float entX = currentActor->getPos()->x;
			float entZ = currentActor->getPos()->z;

			float offX = lp->getPos()->x - entX;
			float offZ = lp->getPos()->z - entZ;

			DrawUtils::fillRectangle(Rect(x + offX + (winSize / 2), y + offZ + (winSize / 2), 1, 1), Color(1, 0, 0, 1), 1);
		}
	}
}
void Radar::onPostRender() {
	if (enabled) {
		if (LunMem::getClientInstance() != NULL) {
			GuiData* gd = LunMem::getClientInstance()->getGuiData();
			int mx = gd->MouseX / gd->GuiScale;
			int my = gd->MouseY / gd->GuiScale;
			if (dragging) {
				x = mx - diffx;
				y = my - diffy;
			}
			if (!MouseHook::ButtonState(1)) {
				dragging = false;
			}
			Rect winRect = Rect(x, y, winSize, winSize);
			DrawUtils::fillRectangle(winRect, Color(.05, .05, .05, 1), 1);
			DrawUtils::drawRectangle(winRect, Color(.2, .2, .2, 1), 1, 1);

			if (LunMem::getClientInstance()->LocalPlayer != NULL) {
				drawEntityBoxes();
			}

			DrawUtils::drawRectangle(Rect(x + (winSize / 2), y, 0, winSize), Color(.2, .2, .2, 1), 1, 1);
			DrawUtils::drawRectangle(Rect(x, y + (winSize / 2), winSize, 0), Color(.2, .2, .2, 1), 1, 1);
		}
	}
}