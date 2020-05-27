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

void VWindow::onRender()
{
	short mx = getMouseX();
	short my = getMouseY();
	if (MouseHook::ButtonState(0x1)) {
		if (titleRect.contains(mx, my)) {
			if (!dragging) {
				dx = mx - titleRect.x;
				dy = my - titleRect.x;
				dragging = true;
			}
		}
		if(dragging) {
			titleRect.x = mx - dx;
			titleRect.y = my - dy;
		}
	}
	else {
		dragging = false;
	}
	vec4_t rect = vec4_t(titleRect.x, titleRect.y, titleRect.x+titleRect.width, titleRect.y+titleRect.height);
	DrawUtils::fillRectangle(rect, MC_Color(.15, .15, .15, 1), 1);
	vec2_t loc = vec2_t(titleRect.x, titleRect.y);
	DrawUtils::drawText(loc, &title, nullptr, 1);
}
