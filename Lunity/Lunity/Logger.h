#pragma once
#include "BigHead.h"
#include "SDK/LunMem.h"

class Logger {
public:
	static void log(string log);
	static void logHex(string str, ulong num);
};