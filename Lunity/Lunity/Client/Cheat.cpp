#pragma once
#include "pch.h"
#include "Cheat.h"

Cheat::Cheat(string name, string category)
{
	this->name = name;
	this->category = category;
	Logger::log("Loaded "+name);
}

void Cheat::onLoop()
{
	if (wasEnabled != enabled) {
		if (enabled) {
			onEnable();
			Logger::log("Enabled " + name);
		}
		else {
			onDisable();
			Logger::log("Disabled " + name);
		}
		wasEnabled = enabled;
	}
	if (enabled) {
		onTick();
	}
}

void Cheat::onTick()
{
}

void Cheat::onGmLoop(GameMode* gm)
{
	if (enabled) {
		onGmTick(gm);
	}
}

void Cheat::onGmTick(GameMode* gm)
{
}

void Cheat::onEnable()
{
}

void Cheat::onDisable()
{
}

void Cheat::onKey(ulong key)
{
}

void Cheat::onMouseButton(ulong button)
{
}

void Cheat::onMouseMove()
{
}

void Cheat::onPreRender()
{
}

void Cheat::onPostRender()
{
}

void Cheat::onPacket(void* Packet, PacketType type, bool* cancel)
{
}

void Cheat::registerToggleSetting(string text, bool* value)
{
	toggleSettings.push_back(new ToggleSetting(text, value));
}

void Cheat::registerSliderSetting(string text, float* value, float min, float max)
{
	sliderSettings.push_back(new SliderSetting(text, value, min, max));
}