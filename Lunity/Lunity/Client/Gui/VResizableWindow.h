#pragma once
#include "VWindow.h"

class VResizableWindow : public VWindow
{
public:
	VRectI resizer;
	VResizableWindow(string title);
	VResizableWindow(string title, int x, int y);
	VResizableWindow(string title, int x, int y, int width, int height);
	bool dragging = false;
	virtual void onMouseButton(ulong button);
	virtual void onMouseRelease(ulong button);
	virtual void onMouseMove();
	virtual void contentRender();
};

