#pragma once
#include "TextHolder.h"
#include "LunMath.h"
#include "LunMem.h"
#include <functional>
#define ulong uint64_t
// Created with ReClass.NET 1.2 by KN4CK3R

class GuiData
{
public:
	char pad_0008[16]; //0x0008
	Vector2 Resolution; //0x0018
	Vector2 Resolution2; //0x0020
	Vector2 ScaledResolution; //0x0028
	int N0000190A; //0x0030
	float GuiScale; //0x0034
	char pad_0038[26]; //0x0038
	uint16_t MouseX; //0x0052
	uint16_t MouseY; //0x0054
	char pad_0056[1006]; //0x0056

	virtual void Destructor();
	virtual void onInitMinecraftGame();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
	virtual void Function12();
	virtual void Function13();
	virtual void Function14();
	virtual void Function15();
	virtual void Function16();
	virtual void Function17();
	virtual void Function18();
	virtual void Function19();
	virtual void Function20();
	virtual void Function21();
	virtual void Function22();
	virtual void Function23();
	virtual void Function24();
	virtual void Function25();
	virtual void Function26();
	virtual void Function27();
	virtual void Function28();
	virtual void Function29();
	virtual void Function30();
	virtual void Function31();
	virtual void Function32();
	virtual void Function33();
	virtual void Function34();
	virtual void Function35();
	virtual void Function36();
	virtual void Function37();
	virtual void Function38();
	virtual void Function39();
	virtual void Function40();
	virtual void Function41();
	virtual void Function42();
	virtual void Function43();
	virtual void Function44();
	virtual void Function45();
	virtual void Function46();
	virtual void Function47();
	virtual void Function48();
	virtual void Function49();
	virtual void Function50();
	virtual void Function51();
	virtual void Function52();
	virtual void Function53();
	virtual void Function54();
	virtual void Function55();
	virtual void Function56();
	virtual void Function57();
}; //Size: 0x0440

class ClientInstance
{
public:
	char pad_0008[160]; //0x0008
	class MinecraftGame* MinecraftGame; //0x00A8
	class MinecraftGame* MinecraftGame2; //0x00B0
	class Minecraft* Minecraft; //0x00B8
	char pad_00C0[8]; //0x00C0
	class LevelRenderer* LevelRenderer; //0x00C8
	char pad_00D0[8]; //0x00D0
	class LoopbackPacketSender* LoopbackPacketSender; //0x00D8
	class HolographicPlatform* HolographicPlatform; //0x00E0
	class VoiceSystem* VoiceSystem; //0x00E8
	class VanillaMoveInputHandler* VanillaMoveInputHandler; //0x00F0
	char pad_00F8[8]; //0x00F8
	class MinecraftKeyboardManager* MinecraftKeyboardManager; //0x0100
	class HitDetectSystem* HitDetectSystem; //0x0108
	class UserAuthentication* UserAuthentication; //0x0110
	class SceneFactory* SceneFactory; //0x0118
	char pad_0120[32]; //0x0120
	class LocalPlayer* LocalPlayer; //0x0140
	char pad_0148[256]; //0x0148

	virtual void destructorClientInstance();
	virtual void onInitMinecraftGame();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
	virtual void Function10();
	virtual long Function11();
	virtual void Function12();
	virtual void Function13();
	virtual void Function14();
	virtual void Function15();
	virtual void Function16();
	virtual void Function17();
	virtual void Function18();
	virtual void Function19();
	virtual void Function20();
	virtual class BlockSource* getBlockSource();
	virtual class LocalPlayer* getLocalPlayerButTheGayOffset();
	virtual class LocalPlayer* getLocalPlayerAgain();
	virtual class LocalPlayer* getLocalPlayerButPleaseDontCrash();
	virtual void setOldLocalPlayer(void* thePlayer);
	virtual void getLocalPlayer();
	virtual void setLocalPlayer(void* player);
	virtual void Function28();
	virtual void Function29();
	virtual void Function30();
	virtual ulong Function31();
	virtual ulong Function32();
	virtual ulong Function33();
	virtual ulong Function34();
	virtual ulong Function35();
	virtual ulong Function36();
	virtual ulong Function37();
	virtual ulong Function38();
	virtual ulong Function39();
	virtual ulong Function40();
	virtual ulong Function41();
	virtual ulong Function42();
	virtual ulong Function43();
	virtual ulong Function44();
	virtual class LocalPlayer** getLocalPlayerPointer();
	virtual ulong Function46();
	virtual bool Function47(); //Dunno
	virtual ulong Function48();
	virtual ulong Function49();
	virtual ulong Function50();
	virtual ulong Function51();
	virtual ulong Function52();
	virtual ulong Function53();
	virtual ulong Function54();
	virtual ulong Function55();
	virtual ulong Function56();
	virtual ulong Function57();
	virtual ulong Function58();
	virtual ulong Function59();
	virtual ulong Function60();
	virtual ulong Function61();
	virtual ulong Function62();
	virtual ulong Function63();
	virtual ulong Function64();
	virtual ulong Function65();
	virtual ulong Function66();
	virtual ulong Function67();
	virtual ulong Function68();
	virtual ulong Function69();
	virtual ulong Function70();
	virtual ulong Function71();
	virtual ulong Function72();
	virtual ulong Function73();
	virtual ulong Function74();
	virtual ulong Function75();
	virtual ulong Function76();
	virtual ulong Function77();
	virtual ulong Function78();
	virtual ulong Function79();
	virtual ulong Function80();
	virtual ulong Function81();
	virtual ulong Function82();
	virtual ulong Function83();
	virtual ulong Function84();
	virtual ulong Function85();
	virtual ulong Function86();
	virtual ulong Function87();
	virtual ulong Function88();
	virtual ulong Function89();
	virtual ulong Function90();
	virtual ulong Function91();
	virtual ulong Function92();
	virtual ulong Function93();
	virtual ulong Function94();
	virtual ulong Function95();
	virtual ulong Function96();
	virtual ulong Function97();
	virtual ulong Function98();
	virtual ulong Function99();
	virtual ulong Function100();
	virtual ulong Function101();
	virtual ulong Function102();
	virtual ulong Function103();
	virtual ulong Function104();
	virtual ulong Function105();
	virtual ulong Function106();
	virtual ulong Function107();
	virtual ulong Function108();
	virtual ulong Function109();
	virtual ulong Function110();
	virtual ulong Function111();
	virtual ulong Function112();
	virtual ulong Function113();
	virtual ulong Function114();
	virtual ulong Function115();
	virtual ulong Function116();
	virtual ulong Function117();
	virtual ulong Function118();
	virtual ulong Function119();
	virtual ulong Function120();
	virtual ulong Function121();
	virtual ulong Function122();
	virtual ulong Function123();
	virtual ulong Function124();
	virtual ulong Function125();
	virtual ulong Function126();
	virtual ulong Function127();
	virtual ulong Function128();
	virtual ulong Function129();
	virtual ulong Function130();
	virtual ulong Function131();
	virtual ulong Function132();
	virtual ulong Function133();
	virtual ulong Function134();
	virtual ulong Function135();
	virtual ulong Function136();
	virtual ulong Function137();
	virtual ulong Function138();
	virtual ulong Function139();
	virtual ulong Function140();
	virtual ulong Function141();
	virtual ulong Function142();
	virtual ulong Function143();
	virtual ulong Function144();
	virtual ulong Function145();
	virtual ulong Function146();
	virtual ulong Function147();
	virtual ulong Function148();
	virtual ulong Function149();
	virtual ulong Function150();
	virtual ulong Function151();
	virtual ulong Function152();
	virtual ulong Function153();
	virtual ulong Function154();
	virtual ulong Function155();
	virtual ulong Function156();
	virtual ulong Function157();
	virtual ulong Function158();
	virtual ulong Function159();
	virtual ulong Function160();
	virtual ulong Function161();
	virtual ulong Function162();
	virtual ulong Function163();
	virtual ulong Function164();
	virtual ulong Function165();
	virtual ulong Function166();
	virtual ulong Function167();
	virtual ulong Function168();
	virtual ulong Function169();
	virtual ulong Function170();
	virtual ulong Function171();
	virtual ulong Function172();
	virtual ulong Function173();
	virtual ulong Function174();
	virtual void* Function175();
	virtual void* Function176();
	virtual void* Function177();
	virtual void* Function178();
	virtual void* Function179();
	virtual void* Function180();
	virtual void* Function181();
	virtual void* Function182();
	virtual void* Function183();
	virtual void* Function184();
	virtual void* Function185();
	virtual void* Function186();
	virtual void* Function187();
	virtual void* Function188();
	virtual void* Function189();
	virtual void* Function190();
	virtual void* Function191();
	virtual GuiData* getGuiData();
	virtual void* Function193();
	virtual void* Function194();
	virtual void* Function195();
	virtual void* Function196();
	virtual void* Function197();
	virtual void* Function198();
	virtual void* Function199();
	virtual void* Function200();
	virtual void* Function201();
	virtual void* Function202();
	virtual void Function203();
	virtual void Function204();
	virtual void Function205();
	virtual void Function206();
	virtual void Function207();
	virtual void Function208();
	virtual void Function209();
	virtual void Function210();
	virtual void Function211();
	virtual void Function212();
	virtual void Function213();
	virtual void Function214();
	virtual void Function215();
	virtual void Function216();
	virtual void Function217();
	virtual void Function218();
	virtual void Function219();
	virtual void Function220();
	virtual void Function221();
	virtual void Function222();
	virtual void Function223();
	virtual void Function224();
	virtual void Function225();
	virtual void Function226();
	virtual void Function227();
	virtual void Function228();
	virtual void Function229();
	virtual void Function230();
	virtual void Function231();
	virtual void Function232();
	virtual void Function233();
	virtual void Function234();
	virtual void Function235();
	virtual void Function236();
	virtual void Function237();
	virtual void Function238();
	virtual void Function239();
	virtual void Function240();
	virtual void Function241();
	virtual void Function242();
	virtual void Function243();
	virtual void Function244();
	virtual void Function245();
	virtual void Function246();
	virtual void Function247();
	virtual void Function248();
	virtual void Function249();
	virtual void Function250();
	virtual void Function251();
	virtual void Function252();
	virtual void Function253();
	virtual void Function254();
	virtual void Function255();
	virtual void Function256();
	virtual void Function257();
	virtual void Function258();
	virtual void Function259();
	virtual void Function260();
	virtual void Function261();
	virtual void Function262();
	virtual void Function263();
	virtual void Function264();
	virtual void Function265();
}; //Size: 0x01F0

class SimpleContainer
{
public:
	char pad_0008[264]; //0x0008

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void getItem(int);
	virtual bool hasRoomForItem(struct ItemStack);
	virtual void addItem(struct ItemStack);
	virtual void addItemToFirstEmptySlot(struct ItemStack);
	virtual void setItem(int, struct ItemStack);
	virtual void removeItem(int, int);
	virtual void removeAllItems(void);
	virtual void Function11();
	virtual __int64 getContainerSize(void);
	virtual __int64 getMaxStackSize(void);
	virtual void Function14();
	virtual void Function15();
	virtual void Function16();
	virtual void Function17();
	virtual void Function18();
	virtual void Function19();
	virtual int findFirstSlotForItem(struct ItemStack);
	virtual void Function21();
	virtual void Function22();
	virtual void Function23();
	virtual void Function24();
	virtual void setCustomName(TextHolder);
	virtual bool hasCustomName(void);
	virtual void Function27();
	virtual void Function28();
	virtual void createTransactionContext(std::function<void(struct Container&, int, ItemStack const&, ItemStack const&)>, std::function<void(void)>);
	virtual void triggerTransactionChange(int, struct ItemStack const&, struct ItemStack const&);
}; //Size: 0x0110

class PlayerUIContainer
{
public:
	char pad_0000[32]; //0x0000
	int8_t InvenOpen; //0x0020
	char pad_0021[271]; //0x0021
}; //Size: 0x0130

class Actor
{
public:
	char pad_0000[216]; //0x0000
	uint64_t ActorId; //0x00D8
	char pad_00E0[152]; //0x00E0
	bool OnGround; //0x0178
	char pad_0179[399]; //0x0179
	int MovedTick; //0x0308
	char pad_030C[36]; //0x030C
	class MultiPlayerLevel* MultiPlayerLevel; //0x0330
	char pad_0338[120]; //0x0338
	char Type[8]; //0x03B0
	char pad_03B8[160]; //0x03B8
	Vector3 Pos; //0x0458
	Vector3 Pos2; //0x0464
	uint32_t N00000E3B; //0x0470
	Vector2 Size; //0x0474
	Vector3 Pos3; //0x047C
	char pad_0488[912]; //0x0488

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
	virtual void setPos(Vector3* pos);
	virtual Vector3* getPos();
	virtual void Function12();
	virtual void Function13();
	virtual void Function14();
	virtual void getFiringPos(void);
	virtual void setRot(Vector2* vector);
	virtual void Function17();
	virtual void Function18();
	virtual void Function19();
	virtual void Function20();
	virtual void Function21();
	virtual void Function22();
	virtual void Function23();
	virtual void Function24();
	virtual void Function25();
	virtual void Function26();
	virtual void Function27();
	virtual void Function28();
	virtual void Function29();
	virtual void Function30();
	virtual void Function31();
	virtual void chorusFruitTeleport();
	virtual void Function33();
	virtual void Function34();
	virtual void Function35();
	virtual void Function36();
	virtual void Function37();
	virtual void Function38();
	virtual void Function39();
	virtual void Function40();
	virtual void Function41();
	virtual void Function42();
	virtual void Function43();
	virtual void Function44();
	virtual void Function45();
	virtual void Function46();
	virtual void Function47();
	virtual bool isInWall(void);
	virtual bool isInvisible(void);
	virtual void Function50();
	virtual void Function51();
	virtual void setNameTagVisible(bool);
	virtual void getNameTag();
	virtual void Function54();
	virtual void Function55();
	virtual void Function56();
	virtual void Function57();
	virtual void Function58();
	virtual void Function59();
	virtual void Function60();
	virtual bool isInWater(void);
	virtual bool hasEnteredWater(void);
	virtual bool isImmersedInWater(void);
	virtual void Function64();
	virtual bool isInLava(void);
	virtual bool isUnderLiquid(void);
	virtual bool isOverWater(void);
	virtual void Function68();
	virtual void Function69();
	virtual void Function70();
	virtual void Function71();
	virtual void Function72();
	virtual void Function73();
	virtual void Function74();
	virtual void Function75();
	virtual void Function76();
	virtual void Function77();
	virtual void Function78();
	virtual void Function79();
	virtual void Function80();
	virtual void Function81();
	virtual bool isImmobile();
	virtual void isSilent();
	virtual void Function84();
	virtual void Function85();
	virtual void Function86();
	virtual void Function87();
	virtual void isSneaking();
	virtual void setSneaking(bool);
	virtual void Function90();
	virtual void Function91();
	virtual bool isAlive(void);
	virtual void Function93();
	virtual void Function94();
	virtual void Function95();
	virtual void Function96();
	virtual void Function97();
	virtual void canAttack(class Actor*, bool);
	virtual void setTarget(class Actor*);
	virtual void Function100();
	virtual void Function101();
	virtual void attack(class Actor*);
	virtual void Function103();
	virtual void Function104();
	virtual void Function105();
	virtual void Function106();
	virtual void setSitting(bool);
	virtual void Function108();
	virtual void Function109();
	virtual void getInventorySize(void);
	virtual void getEquippedSlots(void);
	virtual void Function112();
	virtual void setStanding(bool);
	virtual void Function114();
	virtual void getEntityTypeId(bool);
	virtual bool isJumping(void);
	virtual void Function117();
	virtual void Function118();
	virtual void Function119();
	virtual void Function120();
	virtual void Function121();
	virtual void Function122();
	virtual void Function123();
	virtual void Function124();
	virtual void Function125();
	virtual void Function126();
	virtual void feed(int);
	virtual void Function128();
	virtual void Function129();
	virtual void Function130();
	virtual void Function131();
	virtual void Function132();
	virtual void Function133();
	virtual void Function134();
	virtual void Function135();
	virtual void Function136();
	virtual void Function137();
	virtual void Function138();
	virtual void Function139();
	virtual void Function140();
	virtual void Function141();
	virtual void Function142();
	virtual void Function143();
	virtual void Function144();
	virtual void Function145();
	virtual void getSelectedItem(void);
	virtual void setCarriedItem(class ItemStack const&);
	virtual void setOffHandSlot(class ItemStack const&);
	virtual void getEquippedTotem(void);
	virtual void consumeTotem(void);
	virtual void Function151();
	virtual void Function152();
	virtual void Function153();
	virtual void Function154();
	virtual void Function155();
	virtual void Function156();
	virtual void Function157();
	virtual void Function158();
	virtual void Function159();
	virtual void Function160();
	virtual void Function161();
	virtual void Function162();
	virtual void Function163();
	virtual void Function164();
	virtual void Function165();
	virtual void changeDimension(int, bool); //Think int is supposed to be custom dimension id class
	virtual void Function167();
	virtual void Function168();
	virtual void Function169();
	virtual void Function170();
	virtual void Function171();
	virtual void Function172();
	virtual void Function173();
	virtual void Function174();
	virtual void Function175();
	virtual void Function176();
	virtual void Function177();
	virtual void Function178();
	virtual void Function179();
	virtual void Function180();
	virtual void Function181();
	virtual void Function182();
	virtual void Function183();
	virtual void Function184();
	virtual void Function185();
	virtual void Function186();
	virtual void Function187();
	virtual void Function188();
	virtual void Function189();
	virtual void Function190();
	virtual void Function191();
	virtual void Function192();
	virtual void Function193();
	virtual void Function194();
	virtual void Function195();
	virtual void Function196();
	virtual void Function197();
	virtual void Function198();
	virtual void swing();
	virtual void Function200();
	virtual void Function201();
	virtual void Function202();
	virtual void Function203();
	virtual void Function204();
	virtual void Function205();
	virtual void Function206();
	virtual void Function207();
	virtual bool isCreative(void);
	virtual bool isAdventure(void);
	virtual void add(class ItemStack const&);
	virtual void drop(class ItemStack const&, bool);
	virtual void Function212();
	virtual void Function213();
	virtual void Function214();
	virtual void setSize(float, float);
	virtual void Function216();
	virtual void Function217();
	virtual void Function218();
	virtual void Function219();
	virtual void Function220();
	virtual void Function221();
	virtual void Function222();
	virtual void Function223();
	virtual void Function224();
	virtual void Function225();
	virtual void Function226();
	virtual void Function227();
	virtual void Function228();
	virtual void Function229();
	virtual void Function230();
	virtual void Function231();
	virtual void outOfWorld();
	virtual void Function233();
	virtual void Function234();
	virtual void Function235();
	virtual void Function236();
	virtual void Function237();
	virtual void Function238();
	virtual void Function239();
	virtual void Function240();
}; //Size: 0x0800

class LocalPlayer
{
public:
	char pad_0008[208]; //0x0008
	uint64_t ActorId; //0x00D8
	char pad_00E0[32]; //0x00E0
	Vector2 LookingVec; //0x0100
	Vector2 LookingVec2; //0x0108
	char pad_0110[144]; //0x0110
	bool OnGround; //0x01A0
	char pad_01A1[27]; //0x01A1
	float FallingIncrementer; //0x01BC
	char pad_01C0[96]; //0x01C0
	float stepHeight; //0x0220
	char pad_0224[220]; //0x0224
	int N000006AB; //0x0300
	float Speed; //0x0304
	int MoveTick; //0x0308
	char pad_030C[20]; //0x030C
	class BlockSource* BlockSource; //0x0320
	int N000006B0; //0x0328
	char pad_032C[4]; //0x032C
	class MultiPlayerLevel* MultiPlayerLevel; //0x0330
	char pad_0338[120]; //0x0338
	char Type[8]; //0x03B0
	char pad_03B8[160]; //0x03B8
	Vector3 Pos; //0x0458
	Vector3 Pos2; //0x0464
	int N000006E7; //0x0470
	float HitboxWidth; //0x0474
	float HitboxHeight; //0x0478
	Vector3 Pos3; //0x047C
	char pad_0488[8]; //0x0488
	int N000006EA; //0x0490
	Vector3 VelocityXYZ; //0x0494
	char pad_04A0[216]; //0x04A0
	class SimpleContainer SimpleContainer; //0x0578
	class SimpleContainer SimpleContainer2; //0x0688
	char pad_0798[308]; //0x0798
	float airAcceleration; //0x08CC
	char pad_08D0[488]; //0x08D0
	bool isFlying; //0x0AB8
	char pad_0AB9[1287]; //0x0AB9
	class CraftingContainerManagerModel* CraftingContainerManagerModel; //0x0FC0
	char pad_0FC8[8]; //0x0FC8
	class PlayerInventoryProxy* PlayerInventoryProxy; //0x0FD0
	char pad_0FD8[456]; //0x0FD8
	class ItemStack* ItemStacks; //0x11A0
	char pad_11A8[272]; //0x11A8
	uint64_t InventoryUiState; //0x12B8
	char pad_12C0[488]; //0x12C0
	class PlayerUIContainer PlayerUIContainer; //0x14A8
	char pad_15D8[2196]; //0x15D8
	int currentGamemode; //0x1E6C

	virtual void hasComponent();
	virtual void reloadHardcoded();
	virtual void reloadHardcodedClient();
	virtual void initializeComponents();
	virtual void reloadComponents();
	virtual void _serverInitItemStackIds();
	virtual void _doInitialMove();
	virtual void scalar_deleting_destructor();
	virtual void reset();
	virtual void getOnDeathExperience();
	virtual void getOwnerEntityType();
	virtual void remove();
	virtual void setPos(Vector3* pos);
	virtual Vector3* getPos();
	virtual Vector3* getPosOld();
	virtual void getPosExtrapolated();
	virtual void getAttachPos();
	virtual void getFiringPos(void);
	virtual void setRot(Vector2* vector);
	virtual void move();
	virtual void getInterpolatedRidingPosition();
	virtual void getInterpolatedBodyRot();
	virtual void getInterpolatedHeadRot();
	virtual void getInterpolatedBodyYaw();
	virtual void getYawSpeedInDegreesPerSecond();
	virtual void getInterpolatedWalkAnimSpeed();
	virtual void getInterpolatedRidingOffset();
	virtual void checkBlockCollisions();
	virtual void checkBlockCollisions2();
	virtual void isFireImmune();
	virtual void Function28();
	virtual void blockedByShield();
	virtual void moveRelative();
	virtual void teleportTo();
	virtual void tryTeleportTo();
	virtual void chorusFruitTeleport();
	virtual void lerpTo(Vector3* start, Vector3* end, int fracOfJourney); //According to unity documentation LMAO
	virtual void lerpMotion(Vector3*);
	virtual void getAddPacket();
	virtual void normalTick();
	virtual void baseTick();
	virtual void rideTick();
	virtual void positionRider();
	virtual void getRidingHeight();
	virtual void startRiding();
	virtual void addRider();
	virtual void flagRiderToRemove();
	virtual void getExitTip();
	virtual void intersects();
	virtual void isFree();
	virtual void isFree2();
	virtual bool isInWall(void);
	virtual bool isInvisible(void);
	virtual void canShowNameTag();
	virtual void allowAscendingScaffolding();
	virtual void setNameTagVisible(bool);
	virtual void getNameTag();
	virtual void getNameTagAsHash();
	virtual void getFormattedNameTag();
	virtual void filterFormattedNameTag();
	virtual void setNameTag();
	virtual void allowAscendingScaffolding2();
	virtual void setScoreTag();
	virtual void getScoreTag();
	virtual bool isInWater(void);
	virtual bool hasEnteredWater(void);
	virtual bool isImmersedInWater(void);
	virtual void Function64();
	virtual bool isInLava(void);
	virtual bool isUnderLiquid(void);
	virtual bool isOverWater(void);
	virtual void makeStuckInBlock();
	virtual void getCameraOffset();
	virtual void getShadowHeightOffs();
	virtual void getShadowRadius();
	virtual void getHeadLookVector();
	virtual void Function73();
	virtual void canSee();
	virtual void canSee2();
	virtual void isSkyLit();
	virtual void getBrightness();
	virtual void Function78();
	virtual void Function79();
	virtual void onAboveBubbleColumn();
	virtual void onInsideBubbleColumn();
	virtual bool isImmobile();
	virtual void isSilent();
	virtual void isPickable();
	virtual void allowAscendingScaffolding3();
	virtual void isSleeping();
	virtual void allowAscendingScaffolding4();
	virtual bool isSneaking();
	virtual void setSneaking(bool);
	virtual bool isBlocking();
	virtual bool isDamageBlocked();
	virtual bool isAlive(void);
	virtual bool isOnFire();
	virtual bool isOnHotBlock();
	virtual void allowAscendingScaffolding5();
	virtual void canAttack(class Actor*, bool);
	virtual void setTarget(class Actor*);
	virtual void Function100();
	virtual void Function101();
	virtual void attack(class Actor*);
	virtual void performRangedAttack();
	virtual void adjustDamageAmount(int amt);
	virtual void getEquipmentCount();
	virtual void setOwner();
	virtual void setSitting(bool);
	virtual void Function108();
	virtual void Function109();
	virtual void getInventorySize(void);
	virtual void getEquipSlots(void);
	virtual void getChestSlots();
	virtual void setStanding(bool);
	virtual bool canPowerJump();
	virtual void setCanPowerJump(bool);
	virtual bool isJumping(void);
	virtual void isEnchanted();
	virtual void Function118();
	virtual void Function119();
	virtual void shouldRender();
	virtual bool isInvulnerableTo();
	virtual bool getBlockDamageCause();
	virtual void actuallyHurt(int damage, Actor* dealer, bool unknown);
	virtual void animateHurt();
	virtual void doFireHurt(int damage);
	virtual void onLightningHit();
	virtual void onBounceStarted();
	virtual void feed(int);
	virtual void handleEntityEvent();
	virtual void getBaseAmbientValue();
	virtual void getActorRendererId();
	virtual void spawnAtLocation();
	virtual void spawnAtLocation2();
	virtual void spawnAtLocation3();
	virtual void spawnAtLocation4();
	virtual void spawnAtLocation5();
	virtual void despawn();
	virtual void killed();
	virtual void awardKillScore();
	virtual void setArmor();
	virtual void getArmor();
	virtual void getArmorMaterialTypeInSlot();
	virtual void getArmorMaterialTextureTypeInSlot();
	virtual void getArmorColorInSlot();
	virtual void setEquippedSlot();
	virtual void setEquippedSlot2();
	virtual void getCarriedItem(void);
	virtual void setCarriedItem(class ItemStack const&);
	virtual void setOffHandSlot(class ItemStack const&);
	virtual void getEquippedTotem(void);
	virtual void consumeTotem(void);
	virtual void save();
	virtual void saveWithoutId();
	virtual void load();
	virtual void loadLinks();
	virtual void getEntityTypeId();
	virtual void queryEntityRenderer();
	virtual void getDamagingEntityUniqueID();
	virtual void setOnFire();
	virtual void getHandleWaterAABB();
	virtual void handleInsidePortal();
	virtual void getPortalCooldown();
	virtual void getPortalWaitTime();
	virtual void getDimensionId();
	virtual void allowAscendingScaffolding6();
	virtual void Function165();
	virtual void changeDimension(int, bool); //Think int is supposed to be custom dimension id class
	virtual void getDamagingEntityUniqueID2();
	virtual void checkFallDamage();
	virtual void causeFallDamage();
	virtual void handleFallDistanceOnServer();
	virtual void playSynchronizedSound();
	virtual void playSynchronizedSound2();
	virtual void onSynchedDataUpdate();
	virtual void canAddRider();
	virtual void allowAscendingScaffolding7();
	virtual void Function176();
	virtual void inCaravan();
	virtual void Function178();
	virtual void tickLeash();
	virtual void Function180();
	virtual void allowAscendingScaffolding8();
	virtual void stopRiding();
	virtual void startSwimming();
	virtual void stopSwimming();
	virtual void buildDebugInfo();
	virtual void getCommandPermissionLevel();
	virtual void getMutableAttribute();
	virtual void getAttribute();
	virtual void getDeathTime();
	virtual void heal();
	virtual void isInvertedHealAndHarm();
	virtual void canBeAffected();
	virtual void canBeAffected2();
	virtual void canBeAffectedByArrow();
	virtual void onEffectAdded();
	virtual void onEffectUpdated();
	virtual void onEffectRemoved();
	virtual void getAnimationComponent();
	virtual void openContainerComponent();
	virtual void swing();
	virtual void useItem();
	virtual void Function201();
	virtual void Function202();
	virtual void getDebugText();
	virtual void getYHeadRot();
	virtual void getRiderYRotation();
	virtual void getYHeadRot2();
	virtual void isWorldBuilder();
	virtual bool isCreative(void);
	virtual bool isAdventure(void);
	virtual void add(class ItemStack const&);
	virtual void drop(class ItemStack const&, bool);
	virtual void getInteraction();
	virtual void allowAscendingScaffolding10okwtfwhysomany();
	virtual void Function214();
	virtual void setSize(float, float);
	virtual void getLifeSpan();
	virtual void onOrphan();
	virtual void wobble();
	virtual void wasHurt();
	virtual void startSpinAttack();
	virtual void stopSpinAttack();
	virtual void setDamageNearbyMobs();
	virtual void Function223();
	virtual void reloadLootTable();
	virtual void reloadLootTable2();
	virtual void getWalkTargetValue();
	virtual void kill();
	virtual void die();
	virtual void shouldTick();
	virtual void updateEntitySpecificMolangVariables();
	virtual void shouldTryMakeStepSound();
	virtual void getNextStep();
	virtual void allowAscendingScaffoldingHolyShitStop();
	virtual void outOfWorld();
	virtual void hurt();
	virtual void markHurt();
	virtual void readAdditionalSaveData();
	virtual void addAdditionalSaveData();
	virtual void playStepSound();
	virtual void playFlySound();
	virtual void Function241();
	virtual void checkInsideBlocks();
	virtual void pushOutOfBlocks();
	virtual void updateWaterState(void);
	virtual void doWaterSplashEffect(void);
	virtual void spawnTrailBubbles();
	virtual void updateInsideBlock();
	virtual void getDefaultLootTable();
	virtual void Function247();
	virtual void removeRider();
	virtual void onSizeUpdated();
	virtual void Function250();
	virtual void knockback();
	virtual void resolveDeathLoot();
	virtual void Function253();
	virtual void setSleeping();
	virtual bool isSprinting(void);
	virtual void setSprinting(bool);
	virtual void playAmbientSound();
	virtual void getAmbientSound();
	virtual void getAmbientSoundPostponeTicks();
	virtual void getAmbientSoundPostponeTicksRange();
	virtual void getItemInHandIcon();
	virtual float getSpeed(void);
	virtual void setSpeed(float);
	virtual void getJumpPower();
	virtual void hurtEffects();
	virtual void getMeleeWeaponDamageBonus();
	virtual void getMeleeKnockbackBonus();
	virtual void travel();
	virtual void applyFinalFriction();
	virtual void updateWalkAnim();
	virtual void aiStep();
	virtual void pushActors();
	virtual void lookAt();
	virtual void isLookingAtAnEntity();
	virtual void checkSpawnRules();
	virtual void checkSpawnObstruction();
	virtual void getAttackAnim();
	virtual void getItemUseDuration();
	virtual void getItemUseStartupProgress();
	virtual void getItemUseIntervalProgress();
	virtual void getItemuseIntervalAxis();
	virtual void getTimeAlongSwing();
	virtual void Function282();
	virtual void getMaxHeadXRot();
	virtual void getLastHurtByMob();
	virtual void setLastHurtByMob();
	virtual void getLastHurtByPlayer();
	virtual void setLastHurtByPlayer();
	virtual void getLastHurtMob();
	virtual void setLastHurtMob();
	virtual void Function290();
	virtual void doHurtTarget();
	virtual void Function292();
	virtual void leaveCaravan();
	virtual void joinCaravan();
	virtual void hasCaravanTail();
	virtual void getCaravanHead();
	virtual void getArmorValue();
	virtual void getArmorCoverPercentage();
	virtual void hurtArmor();
	virtual void setDamagedArmor();
	virtual void Function301();
	virtual void sendArmor();
	virtual void containerChanged();
	virtual void updateEquipment();
	virtual void clearEquipment();
	virtual void getAllArmor();
	virtual void getAllArmorID();
	virtual void getAllHand();
	virtual void getAllEquipment();
	virtual void getArmorTypeHash();
	virtual void dropEquipment();
	virtual void dropEquipment2();
	virtual void Function313();
	virtual void Function314();
	virtual void getDamageAfterMagicAbsorb();
	virtual void createAIGoals();
	virtual void Function317();
	virtual void setItemSlot();
	virtual void setTransitioningSitting();
	virtual void attackAnimation();
	virtual void getCooldownTime();
	virtual void getWalkTargetValue2();
	virtual void allowAscendingScaffoldingSTOP_PLEASE();
	virtual void Function324();
	virtual void ascendLadder();
	virtual void ascendScaffolding();
	virtual void descendScaffolding();
	virtual void initBodyControl();
	virtual void jumpFromGround(void);
	virtual void Function327();
	virtual void newServerAiStep();
	virtual void Function329();
	virtual void getDamageAfterEnchantReduction();
	virtual void getDamageAfterArmorAbsorb();
	virtual void dropBags();
	virtual void dropContainer();
	virtual void tickDeath();
	virtual void endJump(void);
	virtual void updateGliding(void);
	virtual void Function339();
	virtual void Function340();
	virtual void Function341();
	virtual void Function342();
	virtual void Function343();
	virtual void Function344();
	virtual void Function345();
	virtual void Function346();
	virtual void Function347();
	virtual void Function348();
	virtual void Function349();
	virtual void Function350();
	virtual void setName(TextHolder* name);
	virtual void Function352();
	virtual void Function353();
	virtual void Function354();
	virtual void respawn(void);
	virtual void Function356();
	virtual void Function357();
	virtual void Function358();
	virtual void Function359();
	virtual void Function360();
	virtual void Function361();
	virtual void Function362();
	virtual void Function363();
	virtual void Function364();
	virtual void Function365();
	virtual void Function366();
	virtual void openContainer(Vector3i* pos);
	virtual void openFurnace(Vector3i* pos);
	virtual void openBlastFurnace(Vector3i* pos);
	virtual void openSmoker(Vector3i* pos);
	virtual void openEnchanter(Vector3i* pos);
	virtual void openAnvil(Vector3i* pos);
	virtual void openGrindstone(Vector3i* pos);
	virtual void openBrewingStand(Vector3i* pos);
	virtual void Function375();
	virtual void openHopper(Vector3i* pos);
	virtual void openDispenser(Vector3i* pos);
	virtual void openBeacon(Vector3i* pos);
	virtual void Function379();
	virtual void Function380();
	virtual void openCommandBlock(Vector3i* pos);
	virtual void Function382();
	virtual void Function383();
	virtual void Function384();
	virtual void Function385();
	virtual void Function386();
	virtual void Function387();
	virtual void openInventory();
	virtual void openStructureEditor(Vector3i* pos);
	virtual void openLabTable(Vector3i* pos);
	virtual void openElementConstructor(Vector3i* pos);
	virtual void openCompoundCreator(Vector3i* pos);
	virtual void openMaterialReader(Vector3i* pos);
	virtual void Function394();
	virtual void Function395();
	virtual void Function396();
	virtual void Function397();
	virtual void Function398();
	virtual void displayLocalizableMessage(TextHolder* text);
	virtual void displayTextObjectMessage();//(TextObjectRoot* textObj, TextHolder* textHolder);
	virtual void Function401();
	virtual void Function402();
	virtual void Function403();
	virtual void Function404();
	virtual void Function405();
	virtual void Function406();
	virtual void Function407();
	virtual void Function408();
	virtual void Function409();
	virtual void Function410();
	virtual void Function411();
	virtual void Function412();
	virtual void Function413();
	virtual void Function414();
	virtual void Function415();
	virtual void setPlayerGameType(int);
	virtual void crit(class Actor*);
	virtual void Function418();
	virtual void Function419();
	virtual void Function420();
	virtual void Function421();
	virtual void addLevels(int);
	virtual void Function423();
	virtual void Function424();
	virtual void Function425();
	virtual void Function426();
	virtual void Function427();
	virtual void setFieldOfViewModifier(float);
	virtual void Function429();
	virtual void Function430();
	virtual void Function431();
	virtual void Function432();
	virtual void Function433();
	virtual void Function434();
	virtual void Function435();
	virtual void Function436();
	virtual void sendInventoryTransaction(void* transaction);//void is actually a InventoryTransaction, but i dont have that
	virtual void Function438();
	virtual void Function439();
	virtual void Function440();
	virtual void Function441();
	virtual void Function442();
	virtual void Function443();
	virtual void Function444();
	virtual void onMovePlayerPacketNormal(Vector3* pos, Vector2* looking, float param_3);
	virtual void Function446();
	virtual void Function447();
	virtual void Function448();
	virtual void Function449();
	virtual void Function450();
	virtual void Function451();
	virtual void Function452();
	virtual void Function453();
	virtual void Function454();
	virtual void Function455();
	virtual void Function456();
	virtual void Function457();
	virtual void Function458();
	virtual void Function459();
	virtual void Function460();
	virtual void Function461();
	virtual void Function462();
	virtual void Function463();
	virtual void Function464();
	virtual void Function465();
	virtual void Function466();
	virtual void Function467();
	virtual void Function468();
	virtual void Function469();
	virtual void Function470();
	virtual void Function471();
	virtual void Function472();
	virtual void Function473();
	virtual void Function474();
	virtual void Function475();
	virtual void Function476();
	virtual void Function477();
	virtual void Function478();
	virtual void Function479();
	virtual void Function480();
	virtual void Function481();
	virtual void Function482();
	virtual void Function483();
	virtual void Function484();
	virtual void Function485();
	virtual void Function486();
	virtual void Function487();
	virtual void Function488();
	virtual void Function489();
	virtual void Function490();
	virtual void Function491();
	virtual void Function492();
	virtual void Function493();
	virtual void Function494();
	virtual void Function495();
	virtual void Function496();
	virtual void Function497();
	virtual void Function498();
	virtual void Function499();
	virtual void Function500();
	virtual void Function501();
	virtual void Function502();
	virtual void Function503();
	virtual void Function504();
	virtual void Function505();
	virtual void Function506();
	virtual void Function507();
	virtual void Function508();
	virtual void Function509();
	virtual void Function510();
	virtual void Function511();
	virtual void Function512();
	virtual void Function513();
	virtual void Function514();
	virtual void Function515();
	virtual void Function516();
	virtual void Function517();
	virtual void Function518();
	virtual void Function519();
	virtual void Function520();
	virtual void Function521();
	virtual void Function522();
	virtual void Function523();
	virtual void Function524();
	virtual void Function525();
	virtual void Function526();
	virtual void Function527();
	virtual void Function528();
	virtual void Function529();
}; //Size: 0x0800

class MultiPlayerLevel
{
public:
	char pad_0000[64]; //0x0000
	void* playerListBegin; //0x0040
	void* playerListEnd; //0x0048
	char pad_0050[8]; //0x0050
	void* playerListBegin2; //0x0058
	void* playerListEnd2; //0x0060
	char pad_0068[344]; //0x0068
	long EntityCount; //0x01C0
	char pad_01C8[1816]; //0x01C8
	int N000008BE; //0x08E0
	int LookingBlockSide; //0x08E4
	int LookingBlockX; //0x08E8
	int LookingBlockY; //0x08EC
	int LookingBlockZ; //0x08F0
	char pad_08F4[12]; //0x08F4
	class Actor* LookingActor; //0x0900
	char pad_0908[120]; //0x0908
}; //Size: 0x1010

class MinecraftGame
{
public:
	char pad_0008[48]; //0x0008
	class MinecraftGraphics* MinecraftGraphics; //0x0038
	class MinecraftGraphics* MinecraftGraphics2; //0x0040
	class NullFrameBuilder* NullFrameBuilder; //0x0048
	class GameArguments* GameArguments; //0x0050
	class GameRenderer* GameRenderer; //0x0058
	char pad_0060[56]; //0x0060
	class TextureGroup* TextureGroup; //0x0098
	class TextureGroup* TextureGroup2; //0x00A0
	class FontRepository* FontRepository; //0x00A8
	class FontRepository* FontRepository2; //0x00B0
	class BitmapFont* leBetterFont; //0x00B8
	class BitmapFont* theBetterFont; //0x00C0
	char pad_00C8[40]; //0x00C8
	class BitmapFont* anotherFont; //0x00F0
	char pad_00F8[40]; //0x00F8
	class BitmapFont* fourthFont; //0x0120
	char pad_0128[40]; //0x0128
	class BitmapFont* fifthFontIdk; //0x0150
	char pad_0158[40]; //0x0158
	class BitmapFont* sixthFontOk; //0x0180
	char pad_0188[1712]; //0x0188

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
	virtual void Function10();
	virtual void Function11();
	virtual void Function12();
	virtual void Function13();
	virtual void Function14();
	virtual void Function15();
	virtual void Function16();
	virtual void Function17();
	virtual void Function18();
	virtual void Function19();
	virtual void Function20();
	virtual void Function21();
	virtual void Function22();
	virtual void Function23();
	virtual void Function24();
	virtual void Function25();
	virtual void Function26();
	virtual void Function27();
	virtual void Function28();
	virtual void Function29();
	virtual void Function30();
	virtual void Function31();
	virtual void Function32();
	virtual void Function33();
	virtual void Function34();
	virtual void Function35();
	virtual void Function36();
	virtual void Function37();
	virtual void Function38();
	virtual void Function39();
	virtual void Function40();
	virtual void Function41();
	virtual int getScreenWidth();
	virtual int getScreenHeight();
	virtual void Function44();
	virtual void Function45();
	virtual void Function46();
	virtual void Function47();
	virtual void Function48();
	virtual void Function49();
}; //Size: 0x0810


class MinecraftGraphics
{
public:
	char pad_0008[8]; //0x0008
	class ShaderGroup* ShaderGroup; //0x0010
	char pad_0018[2032]; //0x0018

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
}; //Size: 0x0808

class ShaderGroup
{
public:
	char pad_0000[8]; //0x0000
}; //Size: 0x0008

class NullFrameBuilder
{
public:
	char pad_0000[1024]; //0x0000
}; //Size: 0x0400

class GameArguments
{
public:
	char pad_0000[1032]; //0x0000
}; //Size: 0x0408

class GameRenderer
{
public:
	char pad_0000[2056]; //0x0000
}; //Size: 0x0808

class TextureGroup
{
public:
	char pad_0000[8]; //0x0000
}; //Size: 0x0008

class FontRepository
{
public:
	char pad_0008[256]; //0x0008

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
}; //Size: 0x0108

class MinecraftUIRenderContext
{
public:
	char pad_0008[56]; //0x0008

	virtual ~MinecraftUIRenderContext();
	virtual float getLineLength(BitmapFont* font, TextHolder* str, float textSize, bool unknown);
	virtual float getTextAlpha();
	virtual void setTextAlpha(float alpha);
	virtual __int64 drawDebugText(const float* pos, TextHolder* text, float* color, float alpha, unsigned int textAlignment, const float* textMeasureData, const void* caretMeasureData);
	virtual __int64 drawText(BitmapFont* font, float* pos, TextHolder* text, Color* color, float alpha, long textAlignment, const float* textMeasureData, const uintptr_t* caretMeasureData);
	virtual void flushText(float timeSinceLastFlush); // time used for ticking the obfuscated text
	virtual __int64 drawImageNOTIMPLEMENTED(); // didnt bother putting in the parameters
	virtual __int64 drawNinesliceNOTIMPLEMENTED();
	virtual __int64 flushImagesNOTIMPLEMENTED();
	virtual __int64 beginSharedMeshBatchNOTIMPLEMENTED();
	virtual __int64 endSharedMeshBatchNOTIMPLEMENTED();
	virtual void drawRectangle(const float* pos, const float* color, float alpha, int lineWidth); // line width is guessed
	virtual void fillRectangle(const float* pos, const float* color, float alpha);
}; //Size: 0x0040

class UserAuthentication
{
public:
	char pad_0000[72]; //0x0000
}; //Size: 0x0048

class BitmapFont
{
public:
	char pad_0000[72]; //0x0000
}; //Size: 0x0048

class LoopbackPacketSender
{
public:
	char pad_0008[8]; //0x0008
	class NetworkHandler* NetworkHandler; //0x0010
	char pad_0018[48]; //0x0018

	virtual void Function0();
	virtual void Function1();
	virtual void sendToServer(void* packet);
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
}; //Size: 0x0048


class HolographicPlatform
{
public:
	char pad_0000[8]; //0x0000
}; //Size: 0x0008

class VoiceSystem
{
public:
	char pad_0000[8]; //0x0000
}; //Size: 0x0008

class VanillaMoveInputHandler
{
public:
	char pad_0000[8]; //0x0000
}; //Size: 0x0008

class MinecraftKeyboardManager
{
public:
	char pad_0000[8]; //0x0000
}; //Size: 0x0008

class HitDetectSystem
{
public:
	char pad_0000[8]; //0x0000
}; //Size: 0x0008

class PrivateKeyManager
{
public:
	char pad_0000[24]; //0x0000
}; //Size: 0x0018

class SceneFactory
{
public:
	char pad_0000[8]; //0x0000
}; //Size: 0x0008

class Minecraft
{
public:
	char pad_0000[192]; //0x0000
	class NetworkHandler* NetworkHandler; //0x00C0
	class LoopbackPacketSender* LoopbackPacketSender; //0x00C8
	char pad_00D0[56]; //0x00D0
}; //Size: 0x0108

class N00000D28
{
public:
	char pad_0000[8]; //0x0000
}; //Size: 0x0008

class N00000D51
{
public:
	char pad_0000[8]; //0x0000
}; //Size: 0x0008
class GameMode
{
public:
	class ServerPlayer* Player; //0x0008
	char pad_0010[48]; //0x0010

	virtual void Destructor();
	virtual void startDestroyBlock(Vector3i*, UCHAR, bool);
	virtual void destroyBlock(Vector3i*, UCHAR);
	virtual void continueDestroyBlock(Vector3i*, UCHAR, bool);
	virtual void stopDestroyBlock(Vector3i*);
	virtual void startBuildBlock(Vector3i*, UCHAR);
	virtual void buildBlock(Vector3i*, UCHAR);
	virtual void continueBuildBlock(Vector3i*, UCHAR);
	virtual void stopBuildBlock(void);
	virtual void tick(void);
	virtual float getPickRange();
	virtual void useItem();
	virtual void useItemOn();
	virtual void interact();
	virtual void attack(Actor*);
	virtual void releaseUsingItem();
}; //Size: 0x0040

class PlayerInventoryProxy
{
public:
	char pad_0000[16]; //0x0000
	long CurrentSlot; //0x0010
	char pad_0018[244]; //0x0018
}; //Size: 0x010C

class ItemStack
{
public:
	char pad_0000[24]; //0x0000
	class N000013CA* N00001345; //0x0018
	char pad_0020[104]; //0x0020
}; //Size: 0x0088

class NetworkHandler
{
public:
	char pad_0000[24]; //0x0000
	class RakNetInstance* RakNetInstance; //0x0018
	class LocalConnector* LocalConnector; //0x0020
	class RakNetServerLocator* RakNetServerLocator; //0x0028
	char pad_0030[448]; //0x0030
}; //Size: 0x01F0

class RakNetServerLocator
{
public:
	char pad_0000[8]; //0x0000
}; //Size: 0x0008

class RakNetInstance
{
public:
	char pad_0000[864]; //0x0000
	TextHolder ServerIp; //0x0360
	char pad_0368[8]; //0x0368
}; //Size: 0x0370

class LocalConnector
{
public:
	char pad_0000[8]; //0x0000
}; //Size: 0x0008

class MovePlayerPacket
{
public:
	ulong VTable; //0x0000
	ulong dunno;
	char pad_0008[16]; //0x0008
	ulong dunno2;
	uint64_t ActorId; //0x0028
	Vector3 Pos; //0x0030
	Vector2 LookingVec; //0x003C
	char pad_0044[4]; //0x0044
	int8_t N00001248; //0x0048
	int8_t onGround; //0x0049
	char pad_004A[54]; //0x004A
	class Actor* Player; //0x0080
	char pad_0088[136]; //0x0088

	MovePlayerPacket(Actor* player, Vector3* pos, Vector2* looking, int8_t onGround) {
		VTable = (ulong)GetModuleHandle(NULL) + 0x2B04E68;
		dunno = 0x0200000001000000;
		dunno2 = 0x8F41000000000000;
		this->ActorId = player->ActorId;
		this->Pos = *pos;
		this->LookingVec = *looking;
		this->onGround = onGround;
		this->Player = player;
	}
}; //Size: 0x0110

class PlayerAuthInputPacket
{
public:
	ulong VTable; //0x0000
	char pad_0008[32]; //0x0008
	Vector2 LookingVec; //0x0028
	Vector3 Pos; //0x0030
	float HeadYawOrSomeShit; //0x003C
	char pad_0040[36]; //0x0040
	PlayerAuthInputPacket(Vector2 lookingVec, Vector3 position) {
		VTable = (ulong)GetModuleHandle(NULL) + 0x2B04FF0;
		LookingVec = lookingVec;
		Pos = position;
	}
}; //Size: 0x0064
class LoginPacket
{
public:
	char pad_0000[88]; //0x0000
	TextHolder Language; //0x0058
	char pad_0060[32]; //0x0060
}; //Size: 0x0080
class ClientToServerHandshakePacket
{
public:
	char pad_0000[192]; //0x0000
}; //Size: 0x00C0