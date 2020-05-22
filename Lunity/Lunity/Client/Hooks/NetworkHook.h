#pragma once
class NetworkHook
{
public:
	enum PacketType {
		Movement
	};
	static void installHook();
	static void uninstallHook();
};

