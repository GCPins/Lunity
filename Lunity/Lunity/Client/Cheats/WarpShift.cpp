#include "pch.h"
#include "WarpShift.h"

WarpShift::WarpShift() :Cheat::Cheat("WarpShift", "Movement")
{

}

void WarpShift::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			if (KeyHook::KeyState(0x43)) {
				Vector3 currentPos = *LunMem::getClientInstance()->LocalPlayer->getPos();
				currentPos.x += cos((LunMem::getClientInstance()->LocalPlayer->LookingVec.y + 90.0f) * (3.14159 / 180.0f)) * 0.05f;
				currentPos.z += sin((LunMem::getClientInstance()->LocalPlayer->LookingVec.y + 90.0f) * (3.14159 / 180.0f)) * 0.05f;

				LunMem::getClientInstance()->LocalPlayer->VelocityXYZ.y = (float)0;
				LunMem::getClientInstance()->LocalPlayer->setPos(&currentPos);
			}
		}
	}
}

void WarpShift::onEnable()
{
	Cheat::onEnable();
	Logger::log("Hold 'C' to warp!");
}