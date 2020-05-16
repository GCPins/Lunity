#pragma once
#include "../../BigHead.h"
class GamemodeHook
{
public:
	static GameMode* getLastGm();
	static void installHook();
	static void uninstallHook();
};

