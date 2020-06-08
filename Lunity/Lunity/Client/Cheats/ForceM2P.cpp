#pragma once
#include "pch.h"
#include "ForceM2P.h"
#include "../../SDK/EntList.h"
ForceM2P::ForceM2P() : Cheat::Cheat("ForceM2P", "Other") {

}

int offset = 0x2B0;
int LROffset = 0x69C;
void ForceM2P::onKey(ulong key) {
	if (key == 'L') {
		offset += 0x4;
	}
	if (key == 'K') {
		offset -= 0x4;
	}
	Logger::logHex("MOffset", offset);
	if (key == 'P') {
		LROffset += 0x4;
	}
	if (key == 'O') {
		LROffset -= 0x4;
	}
	Logger::logHex("LROffset", LROffset);
}

void ForceM2P::onPostRender() {
	if (enabled) {
		Vector2 coordsH;
		Vector2 coordsG;
		GuiData* gd = DrawUtils::getGuiData();
		Vector2 res = gd->Resolution;
		uintptr_t clientInstancePtr = (uintptr_t)LunMem::getClientInstance();//LunMem::getClientInstance()->MinecraftGame->GameRenderer;
		Vector3* origin = (Vector3*)(((uintptr_t)LunMem::getClientInstance()->LevelRenderer) + LROffset);
		Vector2 fov = Vector2(LunMem::getClientInstance()->fovX, LunMem::getClientInstance()->fovY);
		Matrix* possibleMatrix = (Matrix*)(clientInstancePtr + offset);
		vector<Actor*>* acts = getEntities();
		for (int i = 0; i < acts->size(); i++) {
			Actor* currentEnt = acts->at(i);
			possibleMatrix->DirtyWorldToScreen(*origin, currentEnt->Pos, coordsH, fov, res);
			possibleMatrix->DirtyWorldToScreenGH(currentEnt->Pos, coordsG, res.x, res.y);
			//DrawUtils::DirtyWorldToScreen(Vector3(0, 5, 0), coords, possibleMatrix, res.x, res.y);
			coordsG = Vector2(coordsG.x / 2, coordsG.y / 2);
			coordsH = Vector2(coordsH.x / 2, coordsH.y / 2);
			//DrawUtils::WorldToScreen(Vector3(0, 5, 0), coords);
			DrawUtils::drawText(coordsH, &string("H"), nullptr, 1);
			DrawUtils::drawText(coordsG, &string("G"), nullptr, 1);
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