#include "pch.h"
#include "VResizableWindow.h"

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
