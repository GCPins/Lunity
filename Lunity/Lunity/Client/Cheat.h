#pragma once
#include "../BigHead.h"
#include "Hooks/NetworkHook.h"
#include "SliderSetting.h"
#include "ToggleSetting.h"

class Cheat
{
public:
	string name;
	string category;
	bool enabled = false;
	bool wasEnabled = false;
	ulong keyBind = 0x0;
	vector<ToggleSetting*> toggleSettings;
	vector<SliderSetting*> sliderSettings;
	bool expandedInClickUi;
	bool reassigningKey;
	Cheat(string name, string category);
	virtual void onLoop();
	virtual void onTick();
	virtual void onGmLoop(GameMode* gm);
	virtual void onGmTick(GameMode* gm);
	virtual void onEnable();
	virtual void onDisable();
	virtual void onKey(ulong key);
	virtual void onMouseButton(ulong button);
	virtual void onMouseMove();
	virtual void onPreRender();
	virtual void onPostRender();
	virtual void onPacket(void* Packet, PacketType type, bool* cancel);
	void registerToggleSetting(string text, bool* value);
	void registerSliderSetting(string text, float* value, float min, float max);
};

