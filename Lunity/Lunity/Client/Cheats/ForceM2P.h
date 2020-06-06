#pragma once
#include "../Cheat.h"
#include "../../SDK/DrawUtils.h"
#include "../Hooks/KeyHook.h"
class ForceM2P : public Cheat
{
public:
	ForceM2P();
	void onKey(ulong key);
	void onPostRender();
};

