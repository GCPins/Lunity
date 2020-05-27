#pragma once

/* Combat */
#include "../BigHead.h"
#include "Cheat.h"
#include "Cheats/Killaura.h"
#include "Cheats/Triggerbot.h"
#include "Cheats/Hitbox.h"

/* Movement */

#include "Cheats/Jetpack.h"
#include "Cheats/AirJump.h"
#include "Cheats/AutoSprint.h"
#include "Cheats/NoSlowDown.h"
#include "Cheats/BunnyHop.h"
#include "Cheats/NoWeb.h"
#include "Cheats/Speed.h"
#include "Cheats/Jesus.h"

/* Player */

#include "Cheats/Scaffold.h"
#include "Cheats/Nuker.h"
#include "Cheats/Velocity.h"
#include "Cheats/Instabreak.h"
#include "Cheats/ClickTP.h"

/* Visuals */

#include "Cheats/TabGUI.h"
#include "Cheats/ModuleList.h"
#include "Cheats/Coords.h"
#include "Cheats/ClickGUI.h"

/* Other */

#include "Cheats/Uninject.h"
#include "Cheats/MineplexYesCheat.h"
#include "Cheats/PacketLogger.h"
#include "Hooks/NetworkHook.h"


#include "Cheats/TestModule.h"

class CheatManager {
public:
	static vector<Cheat*> getCheats();
	static vector<string> getCategories();
	static void loadCheats();
	static void tickCheats();
	static void gmTickCheats(GameMode* gm);
	static void distroKeyPress(ulong key);
	static void distroButtonPress(ulong key);
	static void distroButtonRelease(ulong key);
	static void distroMouseMove();
	static void onPreRender();
	static void onPostRender();
	static void onPacket(void* Packet, PacketType type);
};