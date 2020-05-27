#pragma once
#include "VObj.h"
class VWindow : public VObj
{
public:
	VRectI titleRect;
	VRectI contentRect;
	bool dragging;
	int dx;
	int dy;
	bool expanded;
	string title;
	VWindow();
	VWindow(int x, int y);
	VWindow(int x, int y, int width, int height);
	virtual void onRender();
};

