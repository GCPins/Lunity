#pragma once
#include "pch.h"
#include "ForceM2P.h"
#include "../../SDK/EntList.h"
ForceM2P::ForceM2P() : Cheat::Cheat("ForceM2P", "Other") {

}

int offset = 0x590;
void ForceM2P::onKey(ulong key) {
	if (key == 'L') {
		offset += 0x4;
	}
	if (key == 'K') {
		offset -= 0x4;
	}
	Logger::logHex("Offset", offset);
}

void ForceM2P::onPostRender() {
	if (enabled) {
		Vector2 coords;
		GuiData* gd = DrawUtils::getGuiData();
		Vector2 res = gd->Resolution;
		uintptr_t levelRenderer = (uintptr_t)LunMem::getClientInstance();//LunMem::getClientInstance()->MinecraftGame->GameRenderer;
		Vector3 origin = LunMem::getClientInstance()->LevelRenderer->Origin;
		Vector2 fov = Vector2(LunMem::getClientInstance()->fovX, LunMem::getClientInstance()->fovY);
		Matrix* possibleMatrix = (Matrix*)(levelRenderer + offset);
		vector<Actor*>* acts = getEntities();
		for (int i = 0; i < acts->size(); i++) {
			Actor* currentEnt = acts->at(i);
			possibleMatrix->DirtyWorldToScreen(origin, currentEnt->Pos, coords, fov, res);
			//DrawUtils::DirtyWorldToScreen(Vector3(0, 5, 0), coords, possibleMatrix, res.x, res.y);
			coords = Vector2(coords.x / 2, coords.y / 2);
			//DrawUtils::WorldToScreen(Vector3(0, 5, 0), coords);
			DrawUtils::drawText(coords, &string("T"), nullptr, 1);
		}

		/*Logger::log("X: " + to_string(coords.x));
		Logger::log("Y: " + to_string(coords.y));*/
		/*if (KeyHook::KeyState('P')) {
			offset += 0x4;
		}
		if (KeyHook::KeyState('O')) {
			offset -= 0x4;
		}*/
	}
}