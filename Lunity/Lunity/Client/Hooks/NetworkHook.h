#pragma once
enum PacketType {
	Movement,
	Text,
	Unknown
};
class NetworkHook
{
public:
	static void installHook();
	static void uninstallHook();
};

