#pragma once
#include "pch.h"
#include "ToggleSetting.h"

ToggleSetting::ToggleSetting(string text) {
	this->text = text;
}
ToggleSetting::ToggleSetting(string text, bool* value) {
	this->text = text;
	this->value = value;
}
bool ToggleSetting::getValue()
{
	return *value;
}
void ToggleSetting::setValue(bool value)
{
	*this->value = value;
}