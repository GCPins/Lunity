#pragma once
#include "../BigHead.h"
class KeyHook
{
public:
	static void installHook();
	static int hookCallback(void* keycodePtr, void* keycodeItem);
};

