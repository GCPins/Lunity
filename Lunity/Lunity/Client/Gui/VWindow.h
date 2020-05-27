#pragma once
#include "VObj.h"
class VWindow : public VObj
{
public:
	VRectI titleRect;
	VRectI contentRect;
	bool dragging = false;
	int dx;
	int dy;
	bool expanded;
	string title;
	VWindow(string title);
	VWindow(string title, int x, int y);
	VWindow(string title, int x, int y, int width, int height);
	void onMouseButton(ulong button);
	void onMouseRelease(ulong button);
	void onMouseMove();
	virtual void onRender();
};

