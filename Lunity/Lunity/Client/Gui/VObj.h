#pragma once
#include "../../SDK/DrawUtils.h"
#include "../Hooks/MouseHook.h"
#include "../Hooks/KeyHook.h"

class VObj
{
public:
	short getMouseX();
	short getMouseY();
	void onRender();
};

