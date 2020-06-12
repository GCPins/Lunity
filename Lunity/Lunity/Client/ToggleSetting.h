#pragma once
#include "../BigHead.h"
class ToggleSetting
{
public:
	string text;
	bool* value;
	ToggleSetting(string text);
	ToggleSetting(string text, bool* value);
	bool getValue();
	void setValue(bool value);
};

