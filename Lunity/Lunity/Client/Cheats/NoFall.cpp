#include "pch.h"
#include "NoFall.h"

NoFall::NoFall() :Cheat::Cheat("NoFall", "Player")
{

}

void NoFall::onTick()
{
	Cheat::onTick();
	if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			LunMem::getClientInstance()->LocalPlayer->FallingIncrementer = (float)0;
		}
	}
}