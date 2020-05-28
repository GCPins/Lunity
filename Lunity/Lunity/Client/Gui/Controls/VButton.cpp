#include "pch.h"
#include "VButton.h"

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
	VRectI pRect = 
	DrawUtils::fillRectangle(vec4_t(rect.x,
		rect.y,
		rect.x + rect.width,
		rect.y + rect.height), bg, 1);
	DrawUtils::drawText(vec2_t(rect.x + (rect.width / 2), rect.y + (rect.height / 2)), &text, nullptr, 1);
}
