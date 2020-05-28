#pragma once
#include "../VObj.h"
class VControl : public VObj
{
public:
	VObj* parent;
	virtual void onMouseButton(ulong button);
	virtual void onMouseRelease(ulong button);
	virtual void onMouseMove();
};

