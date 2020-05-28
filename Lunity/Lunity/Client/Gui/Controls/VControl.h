#pragma once
#include "../VWindow.h"
class VControl : public VObj
{
public:
	VWindow* parent;
	virtual void onMouseButton(ulong button);
	virtual void onMouseRelease(ulong button);
	virtual void onMouseMove();
};

