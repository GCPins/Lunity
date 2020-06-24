#include "pch.h"
#include "MouseHook.h"

std::map<ulong, bool> buttonState;
void MouseHook::ButtonPressed(ulong button) {
	buttonState[button] = true;
	CheatManager::distroButtonPress(button);
}

void MouseHook::ButtonReleased(ulong button) {
	buttonState[button] = false;
	//log("Release");
}

void MouseHook::MouseMoved() {
	CheatManager::distroMouseMove();
}

bool MouseHook::ButtonState(ulong button) {
	return buttonState[button];
}


typedef int (__fastcall* MouseOriginal)(ulong param_1, char param_2, ulong param_3, ulong param_4,
	ulong param_5, short param_6, short param_7, byte param_8);
MouseOriginal __fastcall original;

int __fastcall MouseHookCallback(ulong param_1, char action, ulong param_3, ulong param_4,
	ulong param_5, short param_6, short param_7, byte param_8) {

	//Logger::logHex("action", action);
	if (action == 0) {
		MouseHook::MouseMoved();
	}
	else {
		if (MouseHook::ButtonState(action)) {
			MouseHook::ButtonReleased(action);
		}
		else {
			MouseHook::ButtonPressed(action);
		}
	}
	/*Logger::logHex("param_1", param_1);
	Logger::logHex("action", action);
	Logger::logHex("param_3", param_3);
	Logger::logHex("param_4", param_4);
	Logger::logHex("param_5", param_5);
	Logger::logHex("param_6", param_6);
	Logger::logHex("param_7", param_7);
	Logger::logHex("param_8", param_8);*/

	return original(param_1, action, param_3, param_4, param_5, param_6, param_7, param_8);
}

void MouseHook::installHook()
{
	Logger::log("installing mouse hook...");
	void* toHook = (void*)(LunMem::getBaseModule() + 0x1AB5FC0);
	Logger::logHex("ToHook", (ulong)toHook);
	bool installSuccess = false;
	if (MH_CreateHook(toHook, &MouseHookCallback, reinterpret_cast<LPVOID*>(&original)) == MH_OK) {
		Logger::log("Mouse Hook successfully created!");
		if (MH_EnableHook(toHook) == MH_OK) {
			installSuccess = true;
			Logger::log("Mouse hook installed");
		}
	}
	if (!installSuccess) {
		Logger::log("Failed to hook mouse!");
	}
}

void MouseHook::uninstallHook()
{
	void* toHook = (void*)(LunMem::getBaseModule() + 0x1AB5FC0);
	MH_DisableHook(toHook);
}
