#include "pch.h"
#include "Coords.h"
#include "../../SDK/DrawUtils.h"
#include "../CheatManager.h"

Coords::Coords() :Cheat::Cheat("Coords", "Visuals")
{

}

void Coords::onPostRender()
{
	if (enabled) {
		if (LunMem::getClientInstance() != NULL) {
			if (LunMem::getClientInstance()->LocalPlayer != NULL) {
				GuiData* GuiData = DrawUtils::getGuiData();
				Vector2 ScreenRes = GuiData->ScaledResolution;
				LocalPlayer* localPlayer = LunMem::getClientInstance()->LocalPlayer;
				Vector3 playerPos = *localPlayer->getPos();
				if (playerPos.x != 0 || playerPos.y != 0 || playerPos.z != 0) {
					std::string CoordsStr = to_string((int)playerPos.x) + ", " + to_string((int)playerPos.y - 1) + ", " + to_string((int)playerPos.z);
					float textSize = DrawUtils::getTextWidth(CoordsStr, 1);
					DrawUtils::fillRectangle(Vector4(ScreenRes.x - textSize, ScreenRes.y - 10, (ScreenRes.x - textSize) + (textSize * 2), ScreenRes.y + 10), Color(0, 0, 0, 1), 0.2f);
					DrawUtils::drawText(Vector2(ScreenRes.x - textSize, ScreenRes.y - 10), &CoordsStr, nullptr, 1);
				}
			}
		}
	}
}