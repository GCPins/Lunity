#pragma once
#include "../../BigHead.h"
#include <MinHook.h>
#include <map>
#include "../CheatManager.h"

class MouseHook
{
public:
	static void installHook();
	static void uninstallHook();
	static void ButtonPressed(ulong button);
	static void ButtonReleased(ulong button);
	static bool ButtonState(ulong button);
	static void MouseMoved();
};

