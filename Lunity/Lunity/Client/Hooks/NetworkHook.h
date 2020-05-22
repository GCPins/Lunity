#pragma once
enum PacketType {
	Movement,
	Unknown
};
class NetworkHook
{
public:
	static void installHook();
	static void uninstallHook();
};

