#pragma once

/* Combat */
#include "../BigHead.h"
#include "Cheat.h"
#include "Cheats/Killaura.h"
#include "Cheats/Triggerbot.h"
#include "Cheats/Hitbox.h"
#include "Cheats/Criticals.h"
#include "Cheats/Misplace.h"

/* Movement */

#include "Cheats/Jetpack.h"
#include "Cheats/AirJump.h"
#include "Cheats/AutoSprint.h"
#include "Cheats/NoSlowDown.h"
#include "Cheats/BunnyHop.h"
#include "Cheats/NoWeb.h"
#include "Cheats/Speed.h"
#include "Cheats/Jesus.h"
#include "Cheats/Glide.h"
#include "Cheats/Step.h"
#include "Cheats/AutoWalk.h"
#include "Cheats/NoWater.h"
#include "Cheats/CCFly.h"
#include "Cheats/WarpShift.h"
#include "Cheats/HiveGlide.h"
#include "Cheats/Longjump.h"
#include "Cheats/LBfly.h"
#include "Cheats/AirAcceleration.h"
#include "Cheats/Antivoid.h"
#include "Cheats/Fastfall.h"

/* Player */

#include "Cheats/Scaffold.h"
#include "Cheats/Nuker.h"
#include "Cheats/Velocity.h"
#include "Cheats/Instabreak.h"
#include "Cheats/ClickTP.h"
#include "Cheats/Gamemode.h"
#include "Cheats/InventoryMove.h"
#include "Cheats/NoFall.h"
#include "Cheats/Phase.h"
#include "Cheats/Flight.h"

/* Visuals */

#include "Cheats/TabGUI.h"
#include "Cheats/ModuleList.h"
#include "Cheats/Coords.h"
#include "Cheats/ClickGui.h"
#include "Cheats/Radar.h"

/* Other */

#include "Cheats/Uninject.h"
#include "Cheats/CPULimiter.h"
#include "Cheats/MineplexBP.h"
#include "Cheats/PacketLogger.h"
#include "Cheats/NoPacket.h"
#include "Cheats/Freecam.h"
#include "Cheats/CCGodMode.h"
#include "Cheats/Profiler.h"

#include "Cheats/TestModule.h"
#include "Hooks/NetworkHook.h"



#include <chrono>

class CheatManager {
public:
	static bool cpuLimiter;
	static vector<Cheat*> getCheats();
	static vector<Cheat*> getCheatsOfCategory(string category);
	static vector<string> getCategories();
	static void loadCheats();
	static void tickCheats();
	static void gmTickCheats(GameMode* gm);
	static void distroKeyPress(ulong key);
	static void distroButtonPress(ulong key);
	static void distroMouseMove();
	static void onPreRender();
	static void onPostRender();
	static void onPacket(void* Packet, PacketType type, bool* cancel);
};