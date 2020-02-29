#pragma once
#include <string>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <sstream>

static void log(std::string log) {
	std::string debugPath = std::string(getenv("APPDATA") + std::string("\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\debug.txt"));
	std::wstring wDebugPath(debugPath.begin(), debugPath.end());
	CloseHandle(CreateFile(wDebugPath.c_str(), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL));
	std::ofstream outfile;
	outfile.open(debugPath.c_str(), std::ios_base::app);
	outfile << log << std::endl;
	outfile.close();
	return;
}