#include "pch.h"
#include "VWindow.h"

VWindow::VWindow() {
	VWindow::VWindow(0, 0);
}
VWindow::VWindow(int x, int y) {
	VWindow::VWindow(0, 0, 60, 15);
}
VWindow::VWindow(int x, int y, int width, int height) {
	titleRect = VRectI(x,y,width,height);
}

void VWindow::onMouseButton(ulong button) {
	int mx = getMouseX();
	int my = getMouseY();
	if (button == 0x1) {
		if (titleRect.contains(mx, my)) {
			Logger::log("Start");
			dx = mx - titleRect.x;
			dy = my - titleRect.y;
			dragging = true;
		}
	}
}
void VWindow::onMouseRelease(ulong button) {
	Logger::log("Stop");
	dragging = false;
}

void VWindow::onMouseMove()
{
	if (dragging) {
		Logger::log("Drag");
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
}
