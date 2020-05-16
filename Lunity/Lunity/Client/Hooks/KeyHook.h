#pragma once
#include "../../BigHead.h"
class KeyHook
{
public:
	static void installHook();
	static void uninstallHook();
	static void KeyPressed(ulong key);
	static void KeyReleased(ulong key);
	static bool KeyState(ulong key);
	static int hookCallback(ulong key, bool pressed);
};

