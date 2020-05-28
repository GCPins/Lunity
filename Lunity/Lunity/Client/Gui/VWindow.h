#pragma once
#ifndef VWINDOW_H
#define VWINDOW_H
#include "VObj.h"
#include "Controls/VControl.h"
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
	vector<VControl*> controls;
	VWindow(string title);
	VWindow(string title, int x, int y);
	VWindow(string title, int x, int y, int width, int height);
	virtual void onMouseButton(ulong button);
	virtual void onMouseRelease(ulong button);
	virtual void onMouseMove();
	virtual void onRender();
	virtual void contentRender();
	virtual void addControl(VControl* control);
};
#endif