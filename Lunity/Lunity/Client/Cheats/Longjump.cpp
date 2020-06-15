#include "pch.h"
#include "Longjump.h"
#include "../Hooks/KeyHook.h"

Longjump::Longjump() :Cheat::Cheat("Longjump", "Movement")
{

}


void Longjump::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL) {
		LocalPlayer* Player = LunMem::getClientInstance()->LocalPlayer;
		if (Player != NULL) {
			Vector2 lookingVec = Player->LookingVec;
			if (KeyHook::KeyState(0x20) && Player->OnGround) {
				Player->VelocityXYZ.x = cos((lookingVec.y + 90.0f) * (3.14f / 180.0f));
				Player->VelocityXYZ.z = sin((lookingVec.y + 90.0f) * (3.14f / 180.0f));
				Player->jumpFromGround();
			}
		}
	}
}