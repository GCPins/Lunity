#pragma once
#include "../../SDK/DrawUtils.h"
#include "../Hooks/MouseHook.h"
#include "../Hooks/KeyHook.h"
#include "../../SDK/LunMath.h"

/*
VObj class
*/
class VObj
{
public:
	short getMouseX();
	short getMouseY();
	virtual void onRender();
};
short VObj::getMouseX()
{
	GuiData* gd = DrawUtils::getGuiData();
	short mx = float(gd->MouseX) / gd->GuiScale;
	if (mx < 0 || mx > gd->ScaledResolution.x) {
		mx = 0;
	}
	return mx;
}
short VObj::getMouseY()
{
	GuiData* gd = DrawUtils::getGuiData();
	short my = float(gd->MouseY) / gd->GuiScale;
	if (my < 0 || my > gd->ScaledResolution.y) {
		my = 0;
	}
	return my;
}
void VObj::onRender()
{
}



/*
Control base class, hopefully fixes compiler issues
*/
/*
VControl
*/
class VControl : public VObj
{
public:
	class VWindow* parent;
	virtual void onMouseButton(ulong button);
	virtual void onMouseRelease(ulong button);
	virtual void onMouseMove();
	virtual void onRender();
};
void VControl::onMouseButton(ulong button)
{
}
void VControl::onMouseRelease(ulong button)
{
}
void VControl::onMouseMove()
{
}
void VControl::onRender()
{
}


/*
VWindow class
*/
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
	vector<class VControl*> controls;
	VWindow(string title);
	VWindow(string title, int x, int y);
	VWindow(string title, int x, int y, int width, int height);
	virtual void onMouseButton(ulong button);
	virtual void onMouseRelease(ulong button);
	virtual void onMouseMove();
	virtual void onRender();
	virtual void contentRender();
	virtual void addControl(class VControl* control);
};
VWindow::VWindow(string title) {
	VWindow::VWindow(title, 0, 0);
}
VWindow::VWindow(string title, int x, int y) {
	VWindow::VWindow(title, 0, 0, 80, 15);
}
VWindow::VWindow(string title, int x, int y, int width, int height) {
	titleRect = VRectI(x, y, width, height);
	this->title = title;
	contentRect.height = 100;
}
void VWindow::onMouseButton(ulong button) {
	int mx = getMouseX();
	int my = getMouseY();
	if (button == 0x1) {
		if (titleRect.contains(mx, my)) {
			dx = mx - titleRect.x;
			dy = my - titleRect.y;
			dragging = true;
		}
	}
	if (button == 0x2) {
		if (titleRect.contains(mx, my)) {
			expanded = !expanded;
		}
	}
}
void VWindow::onMouseRelease(ulong button) {
	dragging = false;
}
void VWindow::onMouseMove()
{
	if (dragging) {
		int mx = getMouseX();
		int my = getMouseY();
		titleRect.x = mx - dx;
		titleRect.y = my - dy;
	}
}
void VWindow::onRender()
{
	vec4_t rect = vec4_t(titleRect.x, titleRect.y, titleRect.x + titleRect.width, titleRect.y + titleRect.height);
	DrawUtils::fillRectangle(rect, MC_Color(.15, .15, .15, 1), 1);
	vec2_t loc = vec2_t(titleRect.x, titleRect.y);
	DrawUtils::drawText(loc, &title, nullptr, 1);
	string expTecks = "-";
	if (!expanded) {
		expTecks = "+";
	}
	loc = vec2_t(titleRect.x + titleRect.width - DrawUtils::getTextWidth(expTecks, 1), titleRect.y);
	DrawUtils::drawText(loc, &expTecks, nullptr, 1);

	if (expanded) {
		contentRect.x = titleRect.x;
		contentRect.y = titleRect.y + titleRect.height;
		contentRect.width = titleRect.width;

		contentRender();
	}
}
void VWindow::contentRender()
{
	vec4_t rect = vec4_t(contentRect.x, contentRect.y, contentRect.x + contentRect.width, contentRect.y + contentRect.height);
	DrawUtils::fillRectangle(rect, MC_Color(.25, .25, .25, 1), 1);

	for (int i = 0; i < controls.size(); i++) {
		controls[i]->onRender();
	}
}
void VWindow::addControl(class VControl* control)
{
	controls.push_back(control);
}


/*
VResizable Window
*/
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
VResizableWindow::VResizableWindow(string title) : VWindow::VWindow(title)
{
	resizer = VRectI(contentRect.x + contentRect.width - 2,
		contentRect.y + contentRect.height - 2,
		contentRect.x + contentRect.width,
		contentRect.y + contentRect.height);
}
VResizableWindow::VResizableWindow(string title, int x, int y) : VWindow::VWindow(title, x, y)
{
	resizer = VRectI(contentRect.x + contentRect.width - 2,
		contentRect.y + contentRect.height - 2,
		contentRect.x + contentRect.width,
		contentRect.y + contentRect.height);
}
VResizableWindow::VResizableWindow(string title, int x, int y, int width, int height) : VWindow::VWindow(title, x, y, width, height)
{
	resizer = VRectI(contentRect.x + contentRect.width - 2,
		contentRect.y + contentRect.height - 2,
		contentRect.width,
		contentRect.height);
}
void VResizableWindow::onMouseButton(ulong button)
{
	VWindow::onMouseButton(button);
	int mx = getMouseX();
	int my = getMouseY();
	if (resizer.contains(mx, my)) {
		dragging = true;
	}
}
void VResizableWindow::onMouseRelease(ulong button)
{
	VWindow::onMouseRelease(button);
	dragging = false;
}
void VResizableWindow::onMouseMove()
{
	VWindow::onMouseMove();
	int mx = getMouseX();
	int my = getMouseY();
	if (dragging) {
		titleRect.width = mx - contentRect.x;
		contentRect.height = my - contentRect.y;
		if (titleRect.width < 30) {
			titleRect.width = 30;
		}
		if (contentRect.height < 5) {
			contentRect.height = 5;
		}
	}
}
void VResizableWindow::contentRender()
{
	VWindow::contentRender();

	//Draw resizer
	resizer.x = contentRect.x + contentRect.width - 4;
	resizer.y = contentRect.y + contentRect.height - 4;
	resizer.width = 4;
	resizer.height = 4;
	vec4_t rect = vec4_t(resizer.x, resizer.y, resizer.x + resizer.width, resizer.y + resizer.height);
	DrawUtils::fillRectangle(rect, MC_Color(.10, .10, .10, 1), 1);
}





/*

Controls

*/
/*
VButton
*/
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
VButton::VButton(string text, int x, int y)
{
}
VButton::VButton(string text, int x, int y, int width, int height)
{
}
void VButton::onRender()
{
	int mx = getMouseX();
	int my = getMouseY();
	MC_Color bg = MC_Color(.30, .30, .30, 1);
	if (rect.contains(mx, my)) {
		bg = MC_Color(.35, .35, .35, 1);
	}
	VRectI pRect = parent->contentRect;
	DrawUtils::fillRectangle(vec4_t(rect.x,
		rect.y,
		rect.x + rect.width,
		rect.y + rect.height), bg, 1);
	DrawUtils::drawText(vec2_t(rect.x + (rect.width / 2), rect.y + (rect.height / 2)), &text, nullptr, 1);
}