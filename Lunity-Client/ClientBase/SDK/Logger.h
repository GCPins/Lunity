#pragma once
#include <string>
#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <sstream>

static void log(std::string log) {
	std::string debugFolder = std::string(getenv("APPDATA") + std::string("\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\Lunity"));
	std::wstring wDebugFolder(debugFolder.begin(), debugFolder.end());
	CreateDirectory(wDebugFolder.c_str(), NULL);
	std::string debugFile = std::string(debugFolder + std::string("\\debug.txt"));
	std::wstring wDebugFile(debugFile.begin(), debugFile.end());
	CloseHandle(CreateFile(wDebugFile.c_str(), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL));
	std::ofstream outfile;
	outfile.open(debugFile.c_str(), std::ios_base::app);
	outfile << log << std::endl;
	outfile.close();
	return;
}