#include "pch.h"
#include "VWindow.h"

VWindow::VWindow(string title) {
	VWindow::VWindow(title, 0, 0);
}
VWindow::VWindow(string title, int x, int y) {
	VWindow::VWindow(title, 0, 0, 80, 15);
}
VWindow::VWindow(string title, int x, int y, int width, int height) {
	titleRect = VRectI(x,y,width,height);
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
	vec4_t rect = vec4_t(titleRect.x, titleRect.y, titleRect.x+titleRect.width, titleRect.y+titleRect.height);
	DrawUtils::fillRectangle(rect, MC_Color(.15, .15, .15, 1), 1);
	vec2_t loc = vec2_t(titleRect.x, titleRect.y);
	DrawUtils::drawText(loc, &title, nullptr, 1);
	string expTecks = "-";
	if (!expanded) {
		expTecks = "+";
	}
	loc = vec2_t(titleRect.x+titleRect.width-DrawUtils::getTextWidth(expTecks,1), titleRect.y);
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
}
