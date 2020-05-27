#pragma once
enum class PacketType {
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

