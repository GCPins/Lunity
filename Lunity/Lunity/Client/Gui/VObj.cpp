#include "pch.h"
#include "VObj.h"

short VObj::getMouseX()
{
	GuiData* gd = DrawUtils::getGuiData();
	short mx = float(gd->MouseX) / gd->GuiScale;
	return mx;
}

short VObj::getMouseY()
{
	GuiData* gd = DrawUtils::getGuiData();
	short my = float(gd->MouseY) / gd->GuiScale;
	return my;
}

void VObj::onRender()
{
}
