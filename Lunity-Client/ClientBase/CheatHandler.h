#include "Cheat.h"
#include <vector>

#include "Cheats/AirJump.h"

static std::vector<Cheat> cheats = std::vector<Cheat>();

static void loadCheats() {
	//Load cheats here
	cheats.push_back(AirJump());
}
static void tickCheats() {
	for (Cheat cheat : cheats) {
		cheat.onLoop();
	}
}