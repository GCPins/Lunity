#pragma once
#include "../../SDK/DrawUtils.h"
#include "../Hooks/MouseHook.h"
#include "../Hooks/KeyHook.h"
#include "../../SDK/LunMath.h"

class VObj
{
public:
	short getMouseX();
	short getMouseY();
	virtual void onRender();
};

