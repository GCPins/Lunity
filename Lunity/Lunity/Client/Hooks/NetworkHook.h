#pragma once
enum class PacketType {
	Movement,
	Text,
	PlayerAuthInput,
	CraftingEvent,
	Login,
	ClientToServerHandshake,
	Unknown
};
class NetworkHook
{
public:
	static void installHook();
	static void uninstallHook();
};

