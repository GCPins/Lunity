#pragma once
#include "VControl.h"
class VButton :
	public VControl
{
public:
	string text;
	VRectI rect;
	VButton(string text, int x, int y);
	VButton(string text, int x, int y, int width, int height);
	virtual void onRender();
};

