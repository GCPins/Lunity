#include "pch.h"
#include "Logger.h"

void Logger::log(string log) {
	/*if (LunMem::getClientInstance() != NULL) {
		if (LunMem::getClientInstance()->LocalPlayer != NULL) {
			TextHolder* dbg = new TextHolder(string(string("[Lunity] ") + log));
			LunMem::getClientInstance()->LocalPlayer->displayLocalizableMessage(dbg);
		}
	}*/
	string debugPath = string(getenv("APPDATA") + string("\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState\\debug.txt"));
	CloseHandle(CreateFileA(debugPath.c_str(), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL));
	ofstream outfile;
	outfile.open(debugPath.c_str(), ios_base::app);
	outfile << log << "\n" << endl;
	outfile.close();
	return;
}

void Logger::logHex(string str, ulong num)
{
	stringstream strm;
	strm << str << ": " << hex << num;
	string result = strm.str();
	log(result);
}