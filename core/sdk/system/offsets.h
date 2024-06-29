#pragma once
#define offset_var(name, value) const static std::uintptr_t m_##name = value

namespace offsets
{
	namespace var
	{
		offset_var(ConVar_Graphics_c, 62779880);
		offset_var(ConVar_Admin_c, 63038816);
		offset_var(Skinnable_c, 62740000);
		offset_var(ConVar_Client_c, 63163304);
		offset_var(ConVar_Console_c, 63180640);
		offset_var(System_Collections_Generic_List_BaseGameMode__c, 63276392);
		offset_var(LocalPlayer_c, 62989128);
		offset_var(FlashbangOverlay_c, 62745752);
		offset_var(TOD_Sky_c, 62814712);
		offset_var(ConsoleSystem_c, 63182272);
		offset_var(LaserBeam_c, 62965800);
		offset_var(StorageContainer_c, 62791392);
		offset_var(OutlineManager_c, 63142168);
		offset_var(WaterSystem_c, 62940176);
		offset_var(EffectNetwork_c, 63283808);
		offset_var(StringPool_c, 62798736);
		offset_var(ConsoleSystem_Index_c, 63078704);
		offset_var(MainCamera_c, 63001856);
		offset_var(UIInventory_c, 62885112);
		offset_var(FoliageGrid_c, 62748128);
		offset_var(ConVar_Weather_c, 62943200);
		offset_var(Buttons_c, 63120352);
		offset_var(ItemIcon_c, 62029688);

	}
		namespace BaseCollision
		{
			constexpr auto Owner = 0x20; //	public BaseEntity Owner; // 0x20
			constexpr auto model = 0x28; //	public Model model; // 0x28
		};
		namespace BaseCombatEntity
		{
			constexpr auto __menuOption_Menu_Pickup = 0x188;
			constexpr auto skeletonProperties = 0x200;
			constexpr auto baseProtection = 0x208;
			constexpr auto startHealth = 0x210;
			constexpr auto pickup = 0x218;
			constexpr auto repair = 0x240;
			constexpr auto ShowHealthInfo = 0x270;
			constexpr auto lifestate = 0x274;
			constexpr auto sendsHitNotification = 0x278;
			constexpr auto sendsMeleeHitNotification = 0x279;
			constexpr auto markAttackerHostile = 0x27a;
			constexpr auto _health = 0x27c;
			constexpr auto _maxHealth = 0x280;
			constexpr auto faction = 0x284;
			constexpr auto deathTime = 0x288;
			constexpr auto lastNotifyFrame = 0x28c;
		};
		namespace BaseEntity
		{
			constexpr auto ragdoll = 0x80;
			constexpr auto positionLerp = 0x88;
			constexpr auto ClientNetworkTimek__BackingField = 0x90;
			constexpr auto menuOptions = 0x98;
			constexpr auto bounds = 0xa0;
			constexpr auto impactEffect = 0xb8;
			constexpr auto enableSaving = 0xc0;
			constexpr auto syncPosition = 0xc1;
			constexpr auto model = 0xc8;
			constexpr auto flags = 0xd0;
			constexpr auto parentBone = 0xd4;
			constexpr auto skinID = 0xd8;
			constexpr auto _components = 0xe0;
			constexpr auto HasBrain = 0xe8;
			constexpr auto _name = 0xf0;
			constexpr auto OwnerIDk__BackingField = 0xf8;
			constexpr auto globalBroadcastProtocol = 0x8;
			constexpr auto broadcastProtocol = 0x100;
			constexpr auto links = 0x108;
			constexpr auto linkedToNeighbours = 0x110;
			constexpr auto QueuedFileRequests = 0x10;
			constexpr auto _fileRequestCounter = 0x18;
			constexpr auto _flushQueuedFileRequests = 0x30;
			constexpr auto _pendingFileRequests = 0x118;
			constexpr auto updateParentingAction = 0x120;
			constexpr auto addedToParentEntity = 0x128;
			constexpr auto itemSkin = 0x130;
			constexpr auto successCallback = 0x138;
			constexpr auto failureCallback = 0x140;
			constexpr auto entitySlots = 0x148;
			constexpr auto triggers = 0x150;
			constexpr auto isVisible = 0x158;
			constexpr auto isAnimatorVisible = 0x159;
			constexpr auto isShadowVisible = 0x15a;
			constexpr auto localOccludee = 0x160;
			constexpr auto Weightk__BackingField = 0x180;
		}
		namespace BaseViewModel
		{
			constexpr auto HideViewmodel = 0x0; // public static bool HideViewmodel; // 0x0
			constexpr auto HideViewmodelOverride = 0x20; // 	public bool HideViewmodelOverride; // 0x20
			constexpr auto GestureModel = 0x8; // 	public static BaseViewModel GestureModel; // 0x8
			constexpr auto ActiveModels = 0x10; // 	public static List<BaseViewModel> ActiveModels; // 0x10
			constexpr auto lazyaimRegular = 0x28; // 	public LazyAimProperties lazyaimRegular; // 0x28
			constexpr auto lazyaimIronsights = 0x30; // 	public LazyAimProperties lazyaimIronsights; // 0x30
			constexpr auto pivot = 0x38; // 	public Transform pivot; // 0x38
			constexpr auto useViewModelCamera = 0x40; // 	public bool useViewModelCamera; // 0x40
			constexpr auto wantsHeldItemFlags = 0x41; // 	public bool wantsHeldItemFlags; // 0x41
			constexpr auto hideSightMeshes = 0x48; // 	public GameObject[] hideSightMeshes; // 0x48
			constexpr auto isGestureViewModel = 0x50; // 	public bool isGestureViewModel; // 0x50
			constexpr auto MuzzlePoint = 0x58; // 	public Transform MuzzlePoint; // 0x58
			constexpr auto subsurfaceProfile = 0x60; // 	public SubsurfaceProfile subsurfaceProfile; // 0x60
			constexpr auto animator = 0x68; // 	internal Animator animator; // 0x68
			constexpr auto animationEvent = 0x70; // 	internal AnimationEvents animationEvent; // 0x70
			constexpr auto ironSights = 0x78; // 	internal IronSights ironSights; // 0x78
			constexpr auto sway = 0x80; // 	internal ViewmodelSway sway; // 0x80
			constexpr auto lower = 0x88; // 	internal ViewmodelLower lower; // 0x88
			constexpr auto bob = 0x90; // 	internal ViewmodelBob bob; // 0x90
			constexpr auto punch = 0x98; // 	internal ViewmodelPunch punch; // 0x98
			constexpr auto aspectOffset = 0xA0; // 	internal ViewmodelAspectOffset aspectOffset; // 0xA0
			constexpr auto mountedAnchor = 0xA8; // 	internal ViewmodelMountedAnchor mountedAnchor; // 0xA8
			constexpr auto cameraAnimation = 0xB0; // 	internal ViewmodelCameraAnimation cameraAnimation; // 0xB0
			constexpr auto viewmodelComponent = 0xB8; // 	internal IViewmodelComponent viewmodelComponent; // 0xB8
			constexpr auto model = 0xC0; // 	internal Model model; // 0xC0
			constexpr auto gestureHide = 0x18; // 	internal static bool gestureHide; // 0x18
			constexpr auto gestureHideTime = 0x1C; // 	internal static TimeSince gestureHideTime; // 0x1C
			constexpr auto gestureCollection = 0x20; // 	private static GestureCollection gestureCollection; // 0x20
			constexpr auto aimHelperRoot = 0x28; // 	internal static GameObject aimHelperRoot; // 0x28
			constexpr auto Skeleton = 0xC8; // 	private Skeleton Skeleton; // 0xC8
			constexpr auto Clothing = 0xD0; // 	private GameObject Clothing; // 0xD0
			constexpr auto workshopMode = 0xD8; // 	private bool workshopMode; // 0xD8
			constexpr auto attackHash = 0x30; // 	private static int attackHash; // 0x30
		}
		namespace BaseMountable {
			constexpr auto __menuOption_Menu_ClothingBlocked = 0x290;
			constexpr auto __menuOption_Menu_Mount = 0x308;
			constexpr auto eyePositionOverride = 0x380;
			constexpr auto eyeCenterOverride = 0x388;
			constexpr auto pitchClamp = 0x390;
			constexpr auto yawClamp = 0x398;
			constexpr auto canWieldItems = 0x3a0;
			constexpr auto relativeViewAngles = 0x3a1;
			constexpr auto mountAnchor = 0x3a8;
			constexpr auto mountLOSVertOffset = 0x3b0;
			constexpr auto mountPose = 0x3b4;
			constexpr auto maxMountDistance = 0x3b8;
			constexpr auto dismountPositions = 0x3c0;
			constexpr auto checkPlayerLosOnMount = 0x3c8;
			constexpr auto disableMeshCullingForPlayers = 0x3c9;
			constexpr auto allowHeadLook = 0x3ca;
			constexpr auto ignoreVehicleParent = 0x3cb;
			constexpr auto legacyDismount = 0x3cc;
			constexpr auto wearWhileMounted = 0x3d0;
			constexpr auto modifiesPlayerCollider = 0x3d8;
			constexpr auto customPlayerCollider = 0x3dc;
			constexpr auto clippingCheckRadius = 0x3f0;
			constexpr auto clippingAndVisChecks = 0x3f4;
			constexpr auto clippingChecksLocation = 0x3f8;
			constexpr auto mountSoundDef = 0x400;
			constexpr auto swapSoundDef = 0x408;
			constexpr auto dismountSoundDef = 0x410;
			constexpr auto dismountHoldType = 0x418;
			constexpr auto mountTimeStatType = 0x41c;
			constexpr auto allowedGestures = 0x420;
			constexpr auto canDrinkWhileMounted = 0x424;
			constexpr auto allowSleeperMounting = 0x425;
			constexpr auto animateClothInLocalSpace = 0x426;
			constexpr auto MountedCameraMode = 0x428;
			constexpr auto rigidBody = 0x430;
			constexpr auto isMobile = 0x438;
			constexpr auto SideLeanAmount = 0x43c;
		}
		namespace PlayerWalkMovement {
			constexpr auto zeroFrictionMaterial = 0x60;
			constexpr auto highFrictionMaterial = 0x68;
			constexpr auto capsuleHeight = 0x70;
			constexpr auto capsuleCenter = 0x74;
			constexpr auto capsuleHeightDucked = 0x78;
			constexpr auto capsuleCenterDucked = 0x7c;
			constexpr auto capsuleHeightCrawling = 0x80;
			constexpr auto capsuleCenterCrawling = 0x84;
			constexpr auto gravityTestRadius = 0x88;
			constexpr auto gravityMultiplier = 0x8c;
			constexpr auto gravityMultiplierSwimming = 0x90;
			constexpr auto maxAngleWalking = 0x94;
			constexpr auto maxAngleClimbing = 0x98;
			constexpr auto maxAngleSliding = 0x9c;
			constexpr auto maxStepHeight = 0xa0;
			constexpr auto body = 0xa8;
			constexpr auto initialColDetectionMode = 0xb0;
			constexpr auto capsule = 0xb8;
			constexpr auto ladder = 0xc0;
			constexpr auto maxVelocity = 0xc8;
			constexpr auto groundAngle = 0xcc;
			constexpr auto groundAngleNew = 0xd0;
			constexpr auto groundTime = 0xd4;
			constexpr auto jumpTime = 0xd8;
			constexpr auto landTime = 0xdc;
			constexpr auto previousPosition = 0xe0;
			constexpr auto previousVelocity = 0xec;
			constexpr auto previousInheritedVelocity = 0xf8;
			constexpr auto groundNormal = 0x104;
			constexpr auto groundNormalNew = 0x110;
			constexpr auto groundVelocity = 0x11c;
			constexpr auto groundVelocityNew = 0x128;
			constexpr auto nextSprintTime = 0x134;
			constexpr auto lastSprintTime = 0x138;
			constexpr auto sprintForced = 0x13c;
			constexpr auto attemptedMountTime = 0x140;
			constexpr auto modify = 0x144;
			constexpr auto grounded = 0x148;
			constexpr auto climbing = 0x149;
			constexpr auto sliding = 0x14a;
			constexpr auto swimming = 0x14b;
			constexpr auto wasSwimming = 0x14c;
			constexpr auto jumping = 0x14d;
			constexpr auto wasJumping = 0x14e;
			constexpr auto falling = 0x14f;
			constexpr auto wasFalling = 0x150;
			constexpr auto flying = 0x151;
			constexpr auto wasFlying = 0x152;
			constexpr auto forcedDuckDelta = 0x154;
		}
		namespace BaseMovement {
			constexpr auto adminCheat = 0x20;
			constexpr auto adminSpeed = 0x24;
			constexpr auto Ownerk__BackingField = 0x28;
			constexpr auto InheritedVelocityk__BackingField = 0x30;
			constexpr auto TargetMovementk__BackingField = 0x3c;
			constexpr auto Runningk__BackingField = 0x48;
			constexpr auto Duckingk__BackingField = 0x4c;
			constexpr auto Crawlingk__BackingField = 0x50;
			constexpr auto Groundedk__BackingField = 0x54;
			constexpr auto lastTeleportedTime = 0x58;
		}
		namespace WorldItem {
			constexpr auto item = 0x10;//public Item item; // 0x10
			constexpr auto ShouldPool = 0x18;//public bool ShouldPool; // 0x18
			constexpr auto _disposed = 0x19;//private bool _disposed; // 0x19
		}
		namespace BasePlayer {
			constexpr auto __menuOption_Climb = 0x290;
			constexpr auto __menuOption_Drink = 0x308;
			constexpr auto __menuOption_InviteToClan = 0x380;
			constexpr auto __menuOption_InviteToTeam = 0x3f8;
			constexpr auto __menuOption_Menu_AssistPlayer = 0x470;
			constexpr auto __menuOption_Menu_LootPlayer = 0x4e8;
			constexpr auto __menuOption_SaltWater = 0x560;
			constexpr auto ClanInviteFailure = 0x8;
			constexpr auto ClanInviteFull = 0x10;
			constexpr auto clanId = 0x5d8;
			constexpr auto playerModel = 0x5e0;
			constexpr auto Frozen = 0x5e8;
			constexpr auto LookLocked = 0x5e9;
			constexpr auto voiceRecorder = 0x5f0;
			constexpr auto voiceSpeaker = 0x5f8;
			constexpr auto input = 0x600;
			constexpr auto movement = 0x608;
			constexpr auto collision = 0x610;
			constexpr auto bagCount = 0x618;
			constexpr auto shelterCount = 0x61c;
			constexpr auto emptyState = 0x18;
			constexpr auto modelInitUnderwear = 0x620;
			constexpr auto _lookingAt = 0x628;
			constexpr auto _lookingAtEntity = 0x630;
			constexpr auto _lookingAtCollider = 0x638;
			constexpr auto lookingAtPointk__BackingField = 0x640;
			constexpr auto wakeTime = 0x64c;
			constexpr auto needsClothesRebuild = 0x650;
			constexpr auto wasSleeping = 0x651;
			constexpr auto wokeUpBefore = 0x652;
			constexpr auto wasDead = 0x653;
			constexpr auto HasMountedClothingk__BackingField = 0x654;
			constexpr auto HasWearableClothingk__BackingField = 0x655;
			constexpr auto lastClothesHash = 0x658;
			constexpr auto visiblePlayerList = 0x20;
			constexpr auto craftMode = 0x28;
			constexpr auto lootPanelOverride = 0x30;
			constexpr auto lastOpenSoundPlay = 0x65c;
			constexpr auto currentViewMode = 0x660;
			constexpr auto selectedViewMode = 0x664;
			constexpr auto lastRevivePoint = 0x668;
			constexpr auto lastReviveDirection = 0x674;
			constexpr auto IsWearingDiveGogglesk__BackingField = 0x680;
			constexpr auto GestureViewModel = 0x688;
			constexpr auto currentClientRespawnInformation = 0x690;
			constexpr auto respawnOptionsTimestamp = 0x698;
			constexpr auto lastParachuteRequest = 0x69c;
			constexpr auto timeSinceUpdatedLookingAt = 0x6a0;
			constexpr auto nextTopologyTestTime = 0x6a4;
			constexpr auto usePressTime = 0x6a8;
			constexpr auto useHeldTime = 0x6ac;
			constexpr auto lookingAtTest = 0x6b0;
			constexpr auto lastDeathTimeClient = 0x38;
			constexpr auto _localTransferProtectionExpires = 0x3c;
			constexpr auto cachedWaterDrinkingPoint = 0x6b8;
			constexpr auto hasRequestedServerEmoji = 0x6c4;
			constexpr auto outstandingEmojiRequests = 0x6c8;
			constexpr auto timeGatedEmojiRequests = 0x6d0;
			constexpr auto gestureList = 0x6d8;
			constexpr auto gestureFinishedTime = 0x6e0;
			constexpr auto blockHeldInputTimer = 0x6e4;
			constexpr auto currentGesture = 0x6e8;
			constexpr auto disabledHeldEntity = 0x6f0;
			constexpr auto nextGestureMenuOpenTime = 0x6f8;
			constexpr auto lastGestureCancel = 0x6fc;
			constexpr auto client_lastHelloTime = 0x700;
			constexpr auto currentTeam = 0x708;
			constexpr auto MaxTeamSizeToast = 0x40;
			constexpr auto clientTeam = 0x710;
			constexpr auto clientTeamUsers = 0x718;
			constexpr auto lastReceivedTeamTime = 0x720;
			constexpr auto lastPresenceTeamId = 0x728;
			constexpr auto lastPresenceTeamSize = 0x730;
			constexpr auto playerGroupKey = 0x738;
			constexpr auto playerGroupSizeKey = 0x740;
			constexpr auto clActiveItem = 0x748;
			constexpr auto MarkerLimitPhrase = 0x48;
			constexpr auto ClientCurrentMapNotes = 0x750;
			constexpr auto ClientCurrentDeathNote = 0x758;
			constexpr auto keepOpenMapInterface = 0x760;
			constexpr auto missions = 0x768;
			constexpr auto _activeMission = 0x770;
			constexpr auto modelState = 0x778;
			constexpr auto mounted = 0x780;
			constexpr auto nextSeatSwapTime = 0x790;
			constexpr auto mountInputHeldDuringDismount = 0x794;
			constexpr auto PetEntity = 0x798;
			constexpr auto lastPetCommandIssuedTime = 0x7a0;
			constexpr auto PetPrefabID = 0x7a4;
			constexpr auto PetID = 0x7a8;
			constexpr auto PetWheelHasBeenOpened = 0x50;
			constexpr auto HostileTitle = 0x58;
			constexpr auto HostileDesc = 0x60;
			constexpr auto HostileMarker = 0x68;
			constexpr auto GoToTitle = 0x88;
			constexpr auto GoToDesc = 0x90;
			constexpr auto GoToMarker = 0x98;
			constexpr auto DollarTitle = 0xb8;
			constexpr auto DollarDesc = 0xc0;
			constexpr auto DollarMarker = 0xc8;
			constexpr auto LootTitle = 0xe8;
			constexpr auto LootDesc = 0xf0;
			constexpr auto LootMarker = 0xf8;
			constexpr auto NodeTitle = 0x118;
			constexpr auto NodeDesc = 0x120;
			constexpr auto NodeMarker = 0x128;
			constexpr auto GunTitle = 0x148;
			constexpr auto GunDesc = 0x150;
			constexpr auto GunMarker = 0x158;
			constexpr auto BuildMarker = 0x178;
			constexpr auto RadialPings = 0x198;
			constexpr auto ClientCurrentPings = 0x7b0;
			constexpr auto tapInProcess = 0x7b8;
			constexpr auto lastPingTap = 0x7bc;
			constexpr auto cachedBuildingPrivilegeTime = 0x7c0;
			constexpr auto cachedBuildingPrivilege = 0x7c8;
			constexpr auto cachedVehicleBuildingBlockedTime = 0x7d0;
			constexpr auto cachedVehicleBuildingBlocked = 0x7d4;
			constexpr auto cachedEntityBuildingBlockedTime = 0x7d8;
			constexpr auto cachedEntityBuildingBlocked = 0x7dc;
			constexpr auto cachedPrivilegeFromOther = 0x7e0;
			constexpr auto cachedPrivilegeFromOtherTime = 0x7e8;
			constexpr auto maxProjectileID = 0x7ec;
			constexpr auto lastSpectateCameraUpdate = 0x7f0;
			constexpr auto currentSpectateTeamInfo = 0x1a0;
			constexpr auto memberBuffer = 0x1a8;
			constexpr auto filterSpectateMapTeamID = 0x1b0;
			constexpr auto lastReceivedSpectateTeamInfo = 0x1b4;
			constexpr auto lastUpdateTime = 0x7f4;
			constexpr auto cachedThreatLevel = 0x7f8;
			constexpr auto lastSentTickTime = 0x7fc;
			constexpr auto lastTickStopwatch = 0x800;
			constexpr auto lastSentTick = 0x808;
			constexpr auto CurrentTutorialAllowancek__BackingField = 0x810;
			constexpr auto startTutorialCooldown = 0x814;
			constexpr auto nextVisThink = 0x818;
			constexpr auto lastTimeSeen = 0x81c;
			constexpr auto debugPrevVisible = 0x820;
			constexpr auto fallDamageEffect = 0x828;
			constexpr auto drownEffect = 0x830;
			constexpr auto playerFlags = 0x838;
			constexpr auto eyes = 0x840;
			constexpr auto inventory = 0x848;
			constexpr auto blueprints = 0x850;
			constexpr auto metabolism = 0x858;
			constexpr auto modifiers = 0x860;
			constexpr auto playerCollider = 0x868;
			constexpr auto Belt = 0x870;
			constexpr auto playerRigidbody = 0x878;
			constexpr auto userID = 0x880;
			constexpr auto UserIDString = 0x888;
			constexpr auto gamemodeteam = 0x890;
			constexpr auto reputation = 0x894;
			constexpr auto _displayName = 0x898;
			constexpr auto _lastSetName = 0x8a0;
			constexpr auto playerColliderStanding = 0x8a8;
			constexpr auto playerColliderDucked = 0x8bc;
			constexpr auto playerColliderCrawling = 0x8d0;
			constexpr auto playerColliderLyingDown = 0x8e4;
			constexpr auto cachedProtection = 0x8f8;
			constexpr auto oldCameraFix = 0x1b8;
			constexpr auto lastHeadshotSoundTime = 0x900;
			constexpr auto nextColliderRefreshTime = 0x904;
			constexpr auto weaponMoveSpeedScale = 0x908;
			constexpr auto clothingBlocksAiming = 0x90c;
			constexpr auto clothingMoveSpeedReduction = 0x910;
			constexpr auto clothingWaterSpeedBonus = 0x914;
			constexpr auto clothingAccuracyBonus = 0x918;
			constexpr auto equippingBlocked = 0x91c;
			constexpr auto eggVision = 0x920;
			constexpr auto activeTelephone = 0x928;
			constexpr auto designingAIEntity = 0x930;
		}
		namespace Admin
		{
			constexpr auto admintime = 0x0; //public static float admintime; // 0x0
			constexpr auto adminlight = 0x4;//public static float adminlight; // 0x4
			constexpr auto adminreflectionmultiplier = 0x8;//public static float adminreflectionmultiplier; // 0x8
			constexpr auto adminambientmultiplier = 0xC;//public static float adminambientmultiplier; // 0xC
			constexpr auto allowAdminUI = 0x10;//public static bool allowAdminUI; // 0x10
			constexpr auto underwater_effect = 0x11;//public static bool underwater_effect; // 0x11
			constexpr auto underwater_cinematic = 0x12;//public static bool underwater_cinematic; // 0x12
			constexpr auto underwater_scatter = 0x14;//public static float underwater_scatter; // 0x14
			constexpr auto woundedfreecam = 0x18;//public static bool woundedfreecam; // 0x18
			constexpr auto overrideOceanEnvironmentLerp = 0x1C;//public static float overrideOceanEnvironmentLerp; // 0x1C
			constexpr auto ddraw_netupdate = 0x20;//public static bool ddraw_netupdate; // 0x20
		}
		namespace Client
		{
			constexpr auto anticheatid = 0x0; //public static string anticheatid; // 0x0
			constexpr auto anticheatkey = 0x8;//public static string anticheatkey; // 0x8
			constexpr auto maxpeerspersecond = 0x10;//public static int maxpeerspersecond; // 0x10
			constexpr auto maxpacketspersecond_effect = 0x14;//public static int maxpacketspersecond_effect; // 0x14
			constexpr auto maxpacketspersecond_voice = 0x18;//public static int maxpacketspersecond_voice; // 0x18
			constexpr auto cached_browser_enabled = 0x1C;//public static bool cached_browser_enabled; // 0x1C
			constexpr auto browser_ping_estimate = 0x1D;//public static bool browser_ping_estimate; // 0x1D
			constexpr auto cached_browser_refresh_cooldown = 0x20;//public static int cached_browser_refresh_cooldown; // 0x20
			constexpr auto prediction = 0x24;//public static bool prediction; // 0x24
			constexpr auto maxunack = 0x28;//public static int maxunack; // 0x28
			constexpr auto pushtotalk = 0x2C;//public static bool pushtotalk; // 0x2C
			constexpr auto debugdragdrop = 0x2D;//public static bool debugdragdrop; // 0x2D
			constexpr auto debuglootsounds = 0x2E;//public static bool debuglootsounds; // 0x2E
			constexpr auto headlerp = 0x30;//public static float headlerp; // 0x30
			constexpr auto headlerp_inertia = 0x34;//public static bool headlerp_inertia; // 0x34
			constexpr auto camlerp = 0x38;//public static float camlerp; // 0x38
			constexpr auto camlerptilt = 0x3C;//public static bool camlerptilt; // 0x3C
			constexpr auto camzoomlerp = 0x40;//public static float camzoomlerp; // 0x40
			constexpr auto _camspeed = 0x44;//private static float _camspeed; // 0x44
			constexpr auto camzoomspeed = 0x48;//public static float camzoomspeed; // 0x48
			constexpr auto camlookspeed = 0x4C;//public static float camlookspeed; // 0x4C
			constexpr auto camdist = 0x50;//public static float camdist; // 0x50
			constexpr auto cambone = 0x58;//public static string cambone; // 0x58
			constexpr auto camfov = 0x60;//public static float camfov; // 0x60
			constexpr auto camoffset = 0x64;//public static Vector3 camoffset; // 0x64
			constexpr auto camoffset_relative = 0x70;//public static bool camoffset_relative; // 0x70
			constexpr auto sortSkinsRecentlyUsed = 0x71;//public static bool sortSkinsRecentlyUsed; // 0x71
			constexpr auto headbob = 0x72;//public static bool headbob; // 0x72
			constexpr auto crosshair = 0x73;//public static bool crosshair; // 0x73
			constexpr auto hitcross = 0x74;//public static bool hitcross; // 0x74
			constexpr auto hurtpunch = 0x75;//public static bool hurtpunch; // 0x75
			constexpr auto hasAppliedPhysicalCameraDefaults = 0x76;//private static bool hasAppliedPhysicalCameraDefaults; // 0x76
			constexpr auto CameraSensorSize = 0x78;//public static Vector2[] CameraSensorSize; // 0x78
			constexpr auto showCamInfo = 0x80;//public static bool showCamInfo; // 0x80
			constexpr auto lookatradius = 0x84;//public static float lookatradius; // 0x84
			constexpr auto BuildingSkin = 0x88;//public static int BuildingSkin; // 0x88
			constexpr auto BuildingSkinWood = 0x8C;//public static int BuildingSkinWood; // 0x8C
			constexpr auto BuildingSkinStone = 0x90;//public static int BuildingSkinStone; // 0x90
			constexpr auto BuildingSkinMetal = 0x94;//public static int BuildingSkinMetal; // 0x94
			constexpr auto BuildingSkinTopTier = 0x98;//public static int BuildingSkinTopTier; // 0x98
			constexpr auto RockSkin = 0x9C;//public static int RockSkin; // 0x9C
			constexpr auto UnderwearSkin = 0xA0;//public static int UnderwearSkin; // 0xA0
			constexpr auto TorchSkin = 0xA4;//public static int TorchSkin; // 0xA4
			constexpr auto unlock_all_skins = 0xA8;//public static bool unlock_all_skins; // 0xA8
			constexpr auto RespawnLoadout = 0xB0;//public static string RespawnLoadout; // 0xB0
			constexpr auto BagAssignMode = 0xB8;//public static int BagAssignMode; // 0xB8
			constexpr auto ShowSleepingBagsOnMap = 0xBC;//public static bool ShowSleepingBagsOnMap; // 0xBC
			constexpr auto ShowVendingMachinesOnMap = 0xBD;//public static bool ShowVendingMachinesOnMap; // 0xBD
			constexpr auto ShowMissionProvidersOnMap = 0xBE;//public static bool ShowMissionProvidersOnMap; // 0xBE
			constexpr auto ShowSashes = 0xBF;//public static bool ShowSashes; // 0xBF
			constexpr auto HasDeclinedTutorial = 0xC0;//public static bool HasDeclinedTutorial; // 0xC0
			constexpr auto HasCompletedTutorial = 0xC1;//public static bool HasCompletedTutorial; // 0xC1
			constexpr auto BlockPlayVideo = 0xC2;//public static bool BlockPlayVideo; // 0xC2
		}
		namespace Graphics
		{
			constexpr auto MinShadowDistance = 100;//private const float MinShadowDistance = 100;
			constexpr auto MaxShadowDistance2Split = 600;//private const float MaxShadowDistance2Split = 600;
			constexpr auto MaxShadowDistance4Split = 1000;//private const float MaxShadowDistance4Split = 1000;
			constexpr auto _shadowdistance = 0x0;//private static float _shadowdistance; // 0x0
			constexpr auto shadowmode = 0x4;//public static int shadowmode; // 0x4
			constexpr auto shadowlights = 0x8;//public static int shadowlights; // 0x8
			constexpr auto _shadowquality = 0xC;//private static int _shadowquality; // 0xC
			constexpr auto grassshadows = 0x10;//public static bool grassshadows; // 0x10
			constexpr auto contactshadows = 0x11;//public static bool contactshadows; // 0x11
			constexpr auto drawdistance = 0x14;//public static float drawdistance; // 0x14
			constexpr auto _fov = 0x18;//private static float _fov; // 0x18
			constexpr auto hud = 0x1C;//public static bool hud; // 0x1C
			constexpr auto chat = 0x1D;//public static bool chat; // 0x1D
			constexpr auto branding = 0x1E;//public static bool branding; // 0x1E
			constexpr auto compass = 0x20;//public static int compass; // 0x20
			constexpr auto dof = 0x24;//public static bool dof; // 0x24
			constexpr auto dof_aper = 0x28;//public static float dof_aper; // 0x28
			constexpr auto dof_blur = 0x2C;//public static float dof_blur; // 0x2C
			constexpr auto dof_mode = 0x30;//public static int dof_mode; // 0x30
			constexpr auto dof_focus_dist = 0x34;//public static float dof_focus_dist; // 0x34
			constexpr auto dof_focus_time = 0x38;//public static float dof_focus_time; // 0x38
			constexpr auto dof_squeeze = 0x3C;//public static float dof_squeeze; // 0x3C
			constexpr auto dof_barrel = 0x40;//public static float dof_barrel; // 0x40
			constexpr auto dof_debug = 0x44;//public static bool dof_debug; // 0x44
			constexpr auto dof_kernel_count = 0x48;//public static int dof_kernel_count; // 0x48
			constexpr auto dof_focus_target_entity = 0x50;//public static BaseEntity dof_focus_target_entity; // 0x50
			constexpr auto vm_fov_scale = 0x58;	//public static bool vm_fov_scale; // 0x58
			constexpr auto vm_horizontal_flip = 0x59;//public static bool vm_horizontal_flip; // 0x59
			constexpr auto _resolution = 0x5C;//private static int _resolution; // 0x5C
			constexpr auto uniqueResolutions = 0x60;//private static List<Resolution> uniqueResolutions; // 0x60
			constexpr auto firstResolutionSet = 0x68;//private static bool firstResolutionSet; // 0x68
			constexpr auto _screenmode = 0x6C;//private static int _screenmode; // 0x6C
			constexpr auto _uiscale = 0x70;//private static float _uiscale; // 0x70
			constexpr auto _anisotropic = 0x74;//private static int _anisotropic; // 0x74
			constexpr auto _parallax = 0x78;//private static int _parallax; // 0x78
			constexpr auto _impostorshadows = 0x7C;//private static bool _impostorshadows; // 0x7C
			constexpr auto _showtexeldensity = 0x80;//private static int _showtexeldensity; // 0x80
			constexpr auto _waves = 0x84;//private static bool _waves; // 0x84
			constexpr auto viewModelCamera = 0x85;//public static bool viewModelCamera; // 0x85
			constexpr auto viewModelDepth = 0x86;//public static bool viewModelDepth; // 0x86
			constexpr auto reflexMode = 0x88;//public static int reflexMode; // 0x88
			constexpr auto reflexIntervalUs = 0x8C;//public static int reflexIntervalUs; // 0x8C
			constexpr auto reflexLatencyMarker = 0x90;//public static bool reflexLatencyMarker; // 0x90
			constexpr auto useMarkersToOptimize = 0x91;//public static bool useMarkersToOptimize; // 0x91
			constexpr auto dlss = 0x94;//public static int dlss; // 0x94
			constexpr auto _renderScale = 0x98;//private static float _renderScale; // 0x98
			constexpr auto jitterSpread = 0x9C;//public static float jitterSpread; // 0x9C
			constexpr auto disableLightLod = 0xA0;//public static bool disableLightLod; // 0xA0
			constexpr auto disableParticleLod = 0xA1;//public static bool disableParticleLod; // 0xA1
			constexpr auto disableAnimatorLod = 0xA2;//public static bool disableAnimatorLod; // 0xA2
			constexpr auto aggressiveShadowLod = 0xA3;//public static bool aggressiveShadowLod; // 0xA3
			constexpr auto _aggressiveShadowLodWearable = 0xA4;//private static bool _aggressiveShadowLodWearable; // 0xA4
			constexpr auto _hlod = 0xA5;//private static bool _hlod; // 0xA5
			constexpr auto lastHlodChange = 0xA8;//public static TimeSince lastHlodChange; // 0xA8
		}
		namespace FlashbangOverlay
		{
			constexpr auto Instance = 0x0;//public static FlashbangOverlay Instance; // 0x0
			constexpr auto postProcessVolume = 0x20;//public PostProcessVolume postProcessVolume; // 0x20
			constexpr auto burnIntensityCurve = 0x28;//public AnimationCurve burnIntensityCurve; // 0x28
			constexpr auto whiteoutIntensityCurve = 0x30;//public AnimationCurve whiteoutIntensityCurve; // 0x30
			constexpr auto deafLoopDef = 0x38;//public SoundDefinition deafLoopDef; // 0x38
			constexpr auto flashbangEffect = 0x40;//private FlashbangEffect flashbangEffect; // 0x40
			constexpr auto flashLength = 0x48;//private float flashLength; // 0x48
			constexpr auto flashTime = 0x4C;//private TimeSince flashTime; // 0x4C
			constexpr auto deafLoop = 0x50;//private Sound deafLoop; // 0x50
			constexpr auto deafGain = 0x58;//private SoundModulation.Modulator deafGain; // 0x58
		}
		namespace BowWeapon {
			constexpr auto attackReady = 0x3a8;
			constexpr auto arrowBack = 0x3ac;
			constexpr auto swapArrows = 0x3b0;
			constexpr auto wasAiming = 0x3b8;
		}
		namespace BaseProjectile {
			constexpr auto NoiseRadius = 0x2a0;
			constexpr auto damageScale = 0x2a4;
			constexpr auto distanceScale = 0x2a8;
			constexpr auto projectileVelocityScale = 0x2ac;
			constexpr auto automatic = 0x2b0;
			constexpr auto usableByTurret = 0x2b1;
			constexpr auto turretDamageScale = 0x2b4;
			constexpr auto attackFX = 0x2b8;
			constexpr auto silencedAttack = 0x2c0;
			constexpr auto muzzleBrakeAttack = 0x2c8;
			constexpr auto MuzzlePoint = 0x2d0;
			constexpr auto reloadTime = 0x2d8;
			constexpr auto canUnloadAmmo = 0x2dc;
			constexpr auto primaryMagazine = 0x2e0;
			constexpr auto fractionalReload = 0x2e8;
			constexpr auto reloadStartDuration = 0x2ec;
			constexpr auto reloadFractionDuration = 0x2f0;
			constexpr auto reloadEndDuration = 0x2f4;
			constexpr auto aimSway = 0x2f8;
			constexpr auto aimSwaySpeed = 0x2fc;
			constexpr auto recoil = 0x300;
			constexpr auto aimconeCurve = 0x308;
			constexpr auto aimCone = 0x310;
			constexpr auto hipAimCone = 0x314;
			constexpr auto aimconePenaltyPerShot = 0x318;
			constexpr auto aimConePenaltyMax = 0x31c;
			constexpr auto aimconePenaltyRecoverTime = 0x320;
			constexpr auto aimconePenaltyRecoverDelay = 0x324;
			constexpr auto stancePenaltyScale = 0x328;
			constexpr auto hasADS = 0x32c;
			constexpr auto noAimingWhileCycling = 0x32d;
			constexpr auto manualCycle = 0x32e;
			constexpr auto needsCycle = 0x32f;
			constexpr auto isCycling = 0x330;
			constexpr auto aiming = 0x331;
			constexpr auto useEmptyAmmoState = 0x332;
			constexpr auto isBurstWeapon = 0x333;
			constexpr auto canChangeFireModes = 0x334;
			constexpr auto defaultOn = 0x335;
			constexpr auto internalBurstRecoilScale = 0x338;
			constexpr auto internalBurstFireRateScale = 0x33c;
			constexpr auto internalBurstAimConeScale = 0x340;
			constexpr auto resetDuration = 0x344;
			constexpr auto numShotsFired = 0x348;
			constexpr auto nextReloadTime = 0x34c;
			constexpr auto startReloadTime = 0x350;
			constexpr auto stancePenalty = 0x354;
			constexpr auto aimconePenalty = 0x358;
			constexpr auto cachedModHash = 0x35c;
			constexpr auto sightAimConeScale = 0x360;
			constexpr auto sightAimConeOffset = 0x364;
			constexpr auto hipAimConeScale = 0x368;
			constexpr auto hipAimConeOffset = 0x36c;
			constexpr auto Param_Ammo_False = 0x4;
			constexpr auto isReloading = 0x370;
			constexpr auto timeSinceReloadFinished = 0x374;
			constexpr auto swaySampleTime = 0x378;
			constexpr auto lastShotTime = 0x37c;
			constexpr auto reloadPressTime = 0x380;
			constexpr auto ammoTypePreReload = 0x388;
			constexpr auto fractionalReloadDesiredCount = 0x390;
			constexpr auto fractionalReloadNumAdded = 0x394;
			constexpr auto currentBurst = 0x398;
			constexpr auto triggerReady = 0x39c;
			constexpr auto nextHeightCheckTime = 0x3a0;
			constexpr auto cachedUnderground = 0x3a4;
			constexpr auto createdProjectiles = 0x3a8;
		}
		namespace AttackEntity {
			constexpr auto deployDelay = 0x218;
			constexpr auto repeatDelay = 0x21c;
			constexpr auto animationDelay = 0x220;
			constexpr auto effectiveRange = 0x224;
			constexpr auto npcDamageScale = 0x228;
			constexpr auto attackLengthMin = 0x22c;
			constexpr auto attackLengthMax = 0x230;
			constexpr auto attackSpacing = 0x234;
			constexpr auto aiAimSwayOffset = 0x238;
			constexpr auto aiAimCone = 0x23c;
			constexpr auto aiOnlyInRange = 0x240;
			constexpr auto CloseRangeAddition = 0x244;
			constexpr auto MediumRangeAddition = 0x248;
			constexpr auto LongRangeAddition = 0x24c;
			constexpr auto CanUseAtMediumRange = 0x250;
			constexpr auto CanUseAtLongRange = 0x251;
			constexpr auto reloadSounds = 0x258;
			constexpr auto thirdPersonMeleeSound = 0x260;
			constexpr auto recoilCompDelayOverride = 0x268;
			constexpr auto wantsRecoilComp = 0x26c;
			constexpr auto showCrosshairOnTutorial = 0x26d;
			constexpr auto noHeadshots = 0x26e;
			constexpr auto nextAttackTime = 0x270;
			constexpr auto lastTickTime = 0x274;
			constexpr auto nextTickTime = 0x278;
			constexpr auto timeSinceDeploy = 0x27c;
			constexpr auto lastRecoilCompTime = 0x280;
			constexpr auto startAimingDirection = 0x284;
			constexpr auto wasDoingRecoilComp = 0x290;
			constexpr auto reductionSpeed = 0x294;
		}
		namespace FlintStrikeWeapon
		{
			constexpr auto successFraction = 0x3A8;//public float successFraction; // 0x3A8
			constexpr auto successIncrease = 0x3AC;//public float successIncrease; // 0x3AC
			constexpr auto strikeRecoil = 0x3B0;//public RecoilProperties strikeRecoil; // 0x3B0
			constexpr auto _didSparkThisFrame = 0x3B8;//private bool _didSparkThisFrame; // 0x3B8
			constexpr auto _isStriking = 0x3B9;//private bool _isStriking; // 0x3B9
			constexpr auto strikes = 0x3BC;//private int strikes; // 0x3BC
			constexpr auto lastSpectatorAttack = 0x3C0;//private TimeSince lastSpectatorAttack; // 0x3C0
		}
		namespace CompoundBowWeapon
		{
			constexpr auto stringHoldDurationMax = 0x3C0;//public float stringHoldDurationMax; // 0x3C0
			constexpr auto stringBonusDamage = 0x3C4;//public float stringBonusDamage; // 0x3C4
			constexpr auto stringBonusDistance = 0x3C8;	//public float stringBonusDistance; // 0x3C8
			constexpr auto stringBonusVelocity = 0x3CC;//public float stringBonusVelocity; // 0x3CC
			constexpr auto movementPenaltyRampUpTime = 0x3D0;	//public float movementPenaltyRampUpTime; // 0x3D0
			constexpr auto conditionLossPerSecondHeld = 0x3D4;	//public float conditionLossPerSecondHeld; // 0x3D4
			constexpr auto conditionLossHeldDelay = 0x3D8;	//public float conditionLossHeldDelay; // 0x3D8
			constexpr auto chargeUpSoundDef = 0x3E0;	//public SoundDefinition chargeUpSoundDef; // 0x3E0
			constexpr auto stringHeldSoundDef = 0x3E8;	//public SoundDefinition stringHeldSoundDef; // 0x3E8
			constexpr auto drawFinishSoundDef = 0x3F0;//public SoundDefinition drawFinishSoundDef; // 0x3F0
			constexpr auto chargeUpSound = 0x3F8;	//private Sound chargeUpSound; // 0x3F8
			constexpr auto stringHeldSound = 0x400;	//private Sound stringHeldSound; // 0x400
			constexpr auto movementPenalty = 0x408;//protected float movementPenalty; // 0x408
			constexpr auto lastMoveTime = 0x40C;	//private float lastMoveTime; // 0x40C
			constexpr auto currentHoldProgress = 0x410;	//private float currentHoldProgress; // 0x410
			constexpr auto stringHoldTimeStart = 0x414;	//internal float stringHoldTimeStart; // 0x414
			constexpr auto drawFinishPlayed = 0x418;	//private bool drawFinishPlayed; // 0x418
		}
		namespace HitTest {
			constexpr auto type = 0x10;
			constexpr auto AttackRay = 0x14;
			constexpr auto Radius = 0x2c;
			constexpr auto Forgiveness = 0x30;
			constexpr auto MaxDistance = 0x34;
			constexpr auto RayHit = 0x38;
			constexpr auto MultiHit = 0x64;
			constexpr auto BestHit = 0x65;
			constexpr auto DidHit = 0x66;
			constexpr auto damageProperties = 0x68;
			constexpr auto gameObject = 0x70;
			constexpr auto collider = 0x78;
			constexpr auto ignoreEntity = 0x80;
			constexpr auto ignoredType = 0x88;
			constexpr auto HitEntity = 0x90;
			constexpr auto HitPoint = 0x98;
			constexpr auto HitNormal = 0xa4;
			constexpr auto HitDistance = 0xb0;
			constexpr auto HitTransform = 0xb8;
			constexpr auto HitPart = 0xc0;
			constexpr auto HitMaterial = 0xc8;
		}
		namespace InputMessage
		{
			constexpr auto buttons = 0x10;//public int buttons; // 0x10
			constexpr auto aimAngles = 0x14;//public Vector3 aimAngles; // 0x14
			constexpr auto mouseDelta = 0x20;//public Vector3 mouseDelta; // 0x20
			constexpr auto ShouldPool = 0x2C;//public bool ShouldPool; // 0x2C
			constexpr auto _disposed = 0x2D;//private bool _disposed; // 0x2D
		}
		namespace InputState {
			constexpr auto current = 0x10;
			constexpr auto previous = 0x18;
			constexpr auto SwallowedButtons = 0x20;
		}
		namespace ViewModel {
			constexpr auto viewModelPrefab = 0x20;	//public GameObjectRef viewModelPrefab; // 0x20
			constexpr auto targetEntity = 0x28;	//public HeldEntity targetEntity; // 0x28
			constexpr auto instance = 0x30;	//public BaseViewModel instance; // 0x30
		}
		namespace HeldEntity {
			constexpr auto worldModelAnimator = 0x188;
			constexpr auto thirdPersonDeploySound = 0x190;
			constexpr auto thirdPersonAimSound = 0x198;
			constexpr auto thirdPersonAimEndSound = 0x1a0;
			constexpr auto viewModelk__BackingField = 0x1a8;
			constexpr auto isDeployed = 0x1b0;
			constexpr auto Spine3BoneId = 0x4;
			constexpr auto lastExamineTime = 0x8;
			constexpr auto nextExamineTime = 0x1b4;
			constexpr auto handBone = 0x1b8;
			constexpr auto HoldAnimationOverride = 0x1c0;
			constexpr auto isBuildingTool = 0x1c8;
			constexpr auto hostileScore = 0x1cc;
			constexpr auto holsterInfo = 0x1d0;
			constexpr auto HeldCameraMode = 0x1d8;
			constexpr auto FirstPersonArmOffset = 0x1dc;
			constexpr auto FirstPersonArmRotation = 0x1e8;
			constexpr auto FirstPersonRotationStrength = 0x1f4;
			constexpr auto ownerItemUID = 0x1f8;
			constexpr auto _punches = 0x200;
			constexpr auto punchAdded = 0x208;
			constexpr auto lastPunchTime = 0x214;
		}
		namespace ModelState {
			constexpr auto waterLevel = 0x10;
			constexpr auto lookDir = 0x14;
			constexpr auto flags = 0x20;
			constexpr auto poseType = 0x24;
			constexpr auto inheritedVelocity = 0x28;
			constexpr auto ladderType = 0x34;
			constexpr auto guidePosition = 0x38;
			constexpr auto guideRotation = 0x44;
			constexpr auto guidePrefab = 0x50;
			constexpr auto guideValid = 0x54;
			constexpr auto ShouldPool = 0x55;
			constexpr auto _disposed = 0x56;
		}
		namespace PlayerInventory {
			constexpr auto containerMain = 0x28;
			constexpr auto containerBelt = 0x30;
			constexpr auto containerWear = 0x38;
			constexpr auto crafting = 0x40;
			constexpr auto loot = 0x48;
			constexpr auto lastSet = 0x50;
			constexpr auto cachedResult = 0x58;
			constexpr auto returnItems = 0x68;
		}
		namespace PlayerModel {
			constexpr auto acceleration = 0x4;
			constexpr auto rotationYaw = 0x8;
			constexpr auto forward = 0xc;
			constexpr auto right = 0x10;
			constexpr auto up = 0x14;
			constexpr auto ducked = 0x18;
			constexpr auto grounded = 0x1c;
			constexpr auto crawling = 0x20;
			constexpr auto waterlevel = 0x24;
			constexpr auto attack = 0x28;
			constexpr auto attack_alt = 0x2c;
			constexpr auto deploy = 0x30;
			constexpr auto turnOn = 0x34;
			constexpr auto turnOff = 0x38;
			constexpr auto reload = 0x3c;
			constexpr auto throwWeapon = 0x40;
			constexpr auto holster = 0x44;
			constexpr auto aiming = 0x48;
			constexpr auto onLadder = 0x4c;
			constexpr auto posing = 0x50;
			constexpr auto poseType = 0x54;
			constexpr auto relaxGunPose = 0x58;
			constexpr auto vehicle_aim_yaw = 0x5c;
			constexpr auto vehicle_aim_speed = 0x60;
			constexpr auto usePoseTransition = 0x64;
			constexpr auto onPhone = 0x68;
			constexpr auto leftFootIK = 0x6c;
			constexpr auto rightFootIK = 0x70;
			constexpr auto vehicleSteering = 0x74;
			constexpr auto sitReaction = 0x78;
			constexpr auto forwardReaction = 0x7c;
			constexpr auto rightReaction = 0x80;
			constexpr auto ladderType = 0x84;
			constexpr auto hasParachute = 0x88;
			constexpr auto nonGroundedTime = 0x8c;
			constexpr auto deployParachuteTrigger = 0x90;
			constexpr auto collision = 0x20;
			constexpr auto censorshipCube = 0x28;
			constexpr auto censorshipCubeBreasts = 0x30;
			constexpr auto jawBone = 0x38;
			constexpr auto neckBone = 0x40;
			constexpr auto headBone = 0x48;
			constexpr auto eyeController = 0x50;
			constexpr auto blinkController = 0x58;
			constexpr auto SpineBones = 0x60;
			constexpr auto leftFootBone = 0x68;
			constexpr auto rightFootBone = 0x70;
			constexpr auto leftHandPropBone = 0x78;
			constexpr auto rightHandPropBone = 0x80;
			constexpr auto rightHandTarget = 0x88;
			constexpr auto isPreview = 0x94;
			constexpr auto leftHandTargetPosition = 0x98;
			constexpr auto leftHandTargetRotation = 0xa4;
			constexpr auto rightHandTargetPosition = 0xb4;
			constexpr auto rightHandTargetRotation = 0xc0;
			constexpr auto steeringTargetDegrees = 0xd0;
			constexpr auto rightFootTargetPosition = 0xd4;
			constexpr auto rightFootTargetRotation = 0xe0;
			constexpr auto leftFootTargetPosition = 0xf0;
			constexpr auto leftFootTargetRotation = 0xfc;
			constexpr auto CinematicAnimationController = 0x110;
			constexpr auto DefaultAvatar = 0x118;
			constexpr auto CinematicAvatar = 0x120;
			constexpr auto DefaultHoldType = 0x128;
			constexpr auto SleepGesture = 0x130;
			constexpr auto CrawlToIncapacitatedGesture = 0x138;
			constexpr auto StandToIncapacitatedGesture = 0x140;
			constexpr auto CurrentGesture = 0x148;
			constexpr auto MaleSkin = 0x150;
			constexpr auto FemaleSkin = 0x158;
			constexpr auto subsurfaceProfile = 0x160;
			constexpr auto voiceVolume = 0x168;
			constexpr auto skinColor = 0x16c;
			constexpr auto skinNumber = 0x170;
			constexpr auto meshNumber = 0x174;
			constexpr auto hairNumber = 0x178;
			constexpr auto skinType = 0x17c;
			constexpr auto movementSounds = 0x180;
			constexpr auto showSash = 0x188;
			constexpr auto tempPoseType = 0x18c;
			constexpr auto underwearSkin = 0x190;
			constexpr auto overrideSkinSeedk__BackingField = 0x198;
			constexpr auto AimAnglesk__BackingField = 0x1a0;
			constexpr auto LookAnglesk__BackingField = 0x1b0;
			constexpr auto modelState = 0x1c0;
			constexpr auto position = 0x1c8;
			constexpr auto velocity = 0x1d4;
			constexpr auto speedOverride = 0x1e0;
			constexpr auto newVelocity = 0x1ec;
			constexpr auto rotation = 0x1f8;
			constexpr auto mountedRotation = 0x208;
			constexpr auto fallingTime = 0x218;
			constexpr auto smoothLeftFootIK = 0x21c;
			constexpr auto smoothRightFootIK = 0x228;
			constexpr auto drawShadowOnly = 0x234;
			constexpr auto isIncapacitated = 0x235;
			constexpr auto flinchLocation = 0x238;
			constexpr auto visible = 0x23c;
			constexpr auto nameTag = 0x240;
			constexpr auto animatorNeedsWarmup = 0x248;
			constexpr auto isLocalPlayer = 0x249;
			constexpr auto aimSoundDef = 0x250;
			constexpr auto aimEndSoundDef = 0x258;
			constexpr auto InGesture = 0x260;
			constexpr auto CurrentGestureConfig = 0x268;
			constexpr auto InCinematic = 0x270;
			constexpr auto defaultAnimatorController = 0x278;
			constexpr auto _multiMesh = 0x280;
			constexpr auto _animator = 0x288;
			constexpr auto _lodGroup = 0x290;
			constexpr auto _currentGesture = 0x298;
			constexpr auto holdTypeLock = 0x2a0;
			constexpr auto hasHeldEntity = 0x2a4;
			constexpr auto wasMountedRightAim = 0x2a5;
			constexpr auto cachedMask = 0x2a8;
			constexpr auto cachedConstructionMask = 0x2ac;
			constexpr auto WorkshopHeldEntity = 0x2b0;
			constexpr auto wasCrawling = 0x2b8;
			constexpr auto mountedSpineLookWeight = 0x2bc;
			constexpr auto mountedAnimSpeed = 0x2c0;
			constexpr auto preserveBones = 0x2c4;
			constexpr auto downLimitOverride = 0x2c8;
			constexpr auto blendShapeControllers = 0x2d0;
			constexpr auto IsNpck__BackingField = 0x2d8;
			constexpr auto timeSinceReactionStart = 0x2dc;
			constexpr auto timeSinceLeftFootTest = 0x2e0;
			constexpr auto cachedLeftFootPos = 0x2e4;
			constexpr auto cachedLeftFootNormal = 0x2f0;
			constexpr auto timeSinceRightFootTest = 0x2fc;
			constexpr auto cachedRightFootPos = 0x300;
			constexpr auto cachedRightFootNormal = 0x30c;
			constexpr auto pm_uplimit = 0x94;
			constexpr auto pm_downlimit = 0x98;
			constexpr auto pm_upspine = 0x9c;
			constexpr auto pm_downspine = 0xa0;
			constexpr auto pm_lookoffset = 0xa4;
			constexpr auto pm_anglesmoothspeed = 0xb0;
			constexpr auto pm_nohold = 0xb4;
			constexpr auto pm_ladder = 0xb8;
			constexpr auto pm_minweight = 0xbc;
			constexpr auto _smoothAimWeight = 0x318;
			constexpr auto _smoothVelocity = 0x31c;
			constexpr auto _smoothlookAngle = 0x320;
			constexpr auto allowMountedHeadLook = 0x32c;
			constexpr auto overrideLeftHandIkWeight = 0x330;
			constexpr auto overrideRightHandIkWeight = 0x334;
			constexpr auto smoothLookDir = 0x338;
			constexpr auto lastSafeLookDir = 0x344;
			constexpr auto cinematicLookAt = 0x350;
			constexpr auto lastCinematicLookAt = 0x35c;
			constexpr auto cinematicLookAtWeight = 0x368;
			constexpr auto cinematicTargetWeight = 0x36c;
			constexpr auto Shoulders = 0x370;
			constexpr auto AdditionalSpineBones = 0x378;
			constexpr auto FinishedLegWearables = 0xc0;
			constexpr auto LegParts = 0x380;
			constexpr auto fadeToggles = 0x388;
			constexpr auto fakeSpineBones = 0x390;
			constexpr auto extraLeanBack = 0x398;
			constexpr auto drawState = 0x39c;
			constexpr auto timeInArmsMode = 0x3a0;
		}
		namespace PlayerTick {
			constexpr auto inputState = 0x10;//public InputMessage inputState; // 0x10
			constexpr auto position = 0x18;//public Vector3 position; // 0x18
			constexpr auto modelState = 0x28;//public ModelState modelState; // 0x28
			constexpr auto activeItem = 0x30;//public ItemId activeItem; // 0x30
			constexpr auto eyePos = 0x38;//public Vector3 eyePos; // 0x38
			constexpr auto parentID = 0x48;//public NetworkableId parentID; // 0x48
			constexpr auto deltaMs = 0x50;//public uint deltaMs; // 0x50
			constexpr auto ShouldPool = 0x54;//public bool ShouldPool; // 0x54
			constexpr auto _disposed = 0x55;//private bool _disposed; // 0x55
		}
		namespace Projectile {
			constexpr auto initialVelocity = 0x20;
			constexpr auto drag = 0x2c;
			constexpr auto gravityModifier = 0x30;
			constexpr auto thickness = 0x34;
			constexpr auto initialDistance = 0x38;
			constexpr auto remainInWorld = 0x3c;
			constexpr auto stickProbability = 0x40;
			constexpr auto breakProbability = 0x44;
			constexpr auto conditionLoss = 0x48;
			constexpr auto ricochetChance = 0x4c;
			constexpr auto penetrationPower = 0x50;
			constexpr auto waterIntegrityLoss = 0x54;
			constexpr auto damageProperties = 0x58;
			constexpr auto damageDistances = 0x60;
			constexpr auto damageMultipliers = 0x68;
			constexpr auto damageTypes = 0x70;
			constexpr auto rendererToScale = 0x78;
			constexpr auto firstPersonRenderer = 0x80;
			constexpr auto createDecals = 0x88;
			constexpr auto doDefaultHitEffects = 0x89;
			constexpr auto flybySound = 0x90;
			constexpr auto flybySoundDistance = 0x98;
			constexpr auto closeFlybySound = 0xa0;
			constexpr auto closeFlybyDistance = 0xa8;
			constexpr auto tumbleSpeed = 0xac;
			constexpr auto tumbleAxis = 0xb0;
			constexpr auto swimScale = 0xbc;
			constexpr auto swimSpeed = 0xc8;
			constexpr auto owner = 0xd8;
			constexpr auto sourceWeaponPrefab = 0xe0;
			constexpr auto sourceProjectilePrefab = 0xe8;
			constexpr auto mod = 0xf0;
			constexpr auto projectileID = 0xf8;
			constexpr auto seed = 0xfc;
			constexpr auto clientsideEffect = 0x100;
			constexpr auto clientsideAttack = 0x101;
			constexpr auto integrity = 0x104;
			constexpr auto maxDistance = 0x108;
			constexpr auto modifier = 0x10c;
			constexpr auto invisible = 0x11c;
			constexpr auto noheadshots = 0x11d;
			constexpr auto currentThickness = 0x120;
			constexpr auto currentVelocity = 0x124;
			constexpr auto currentPosition = 0x130;
			constexpr auto traveledDistance = 0x13c;
			constexpr auto traveledTime = 0x140;
			constexpr auto launchTime = 0x144;
			constexpr auto sentPosition = 0x148;
			constexpr auto previousPosition = 0x154;
			constexpr auto previousVelocity = 0x160;
			constexpr auto previousTraveledTime = 0x16c;
			constexpr auto isUnderwater = 0x170;
			constexpr auto isRicochet = 0x171;
			constexpr auto isRetiring = 0x172;
			constexpr auto flybyPlayed = 0x173;
			constexpr auto wasFacingPlayer = 0x174;
			constexpr auto flybyPlane = 0x178;
			constexpr auto flybyRay = 0x188;
			constexpr auto cleanupAction = 0x1a0;
			constexpr auto hitTest = 0x1a8;
			constexpr auto swimRandom = 0x1b0;
			constexpr auto _waterMaterialID = 0x4;
			constexpr auto cachedWaterString = 0x8;

		}
		namespace Skinnable
		{
			constexpr auto shadowOnly = 0x20;//public bool shadowOnly; // 0x20
			constexpr auto IsVisible = 0x21;//internal bool IsVisible; // 0x21
			constexpr auto eyesView = 0x22;//public bool eyesView; // 0x22
			constexpr auto skeleton = 0x28;//public Skeleton skeleton; // 0x28
			constexpr auto skeletonSkinLod = 0x30;	//public SkeletonSkinLod skeletonSkinLod; // 0x30
			constexpr auto parts = 0x38;	//public List<SkinnedMultiMesh.Part> parts; // 0x38
			constexpr auto createdParts = 0x40;	//public List<SkinnedMultiMesh.Part> createdParts; // 0x40
			constexpr auto lastBuildHash = 0x48;	//public long lastBuildHash; // 0x48
			constexpr auto sharedPropertyBlock = 0x50;	//public MaterialPropertyBlock sharedPropertyBlock; // 0x50
			constexpr auto hairPropertyBlock = 0x58;	//public MaterialPropertyBlock hairPropertyBlock; // 0x58
			constexpr auto skinNumber = 0x60;	//public float skinNumber; // 0x60
			constexpr auto meshNumber = 0x64;	//public float meshNumber; // 0x64
			constexpr auto hairNumber = 0x68;	//public float hairNumber; // 0x68
			constexpr auto skinType = 0x6C;	//public int skinType; // 0x6C
			constexpr auto SkinCollection = 0x70;	//public SkinSetCollection SkinCollection; // 0x70
			constexpr auto Renderersk__BackingField = 0x78;	//private readonly List<Renderer> <Renderers>k__BackingField; // 0x78
		}
		namespace ViewmodelPunch {
			constexpr auto punchScale = 0x20;//public AnimationCurve punchScale; // 0x20
			constexpr auto punchDirection = 0x28;//public Vector3 punchDirection; // 0x28
			constexpr auto punchDuration = 0x34;//public float punchDuration; // 0x34
			constexpr auto punchMagnitude = 0x38;//public float punchMagnitude; // 0x38
			constexpr auto punchStartTime = 0x3C;//private float punchStartTime; // 0x3C
		}
		namespace ViewmodelSway {
			constexpr auto positionalSwaySpeed = 0x20;//public float positionalSwaySpeed; // 0x20
			constexpr auto positionalSwayAmount = 0x24;//public float positionalSwayAmount; // 0x24
			constexpr auto rotationSwaySpeed = 0x28;//public float rotationSwaySpeed; // 0x28
			constexpr auto rotationSwayAmount = 0x2C;//public float rotationSwayAmount; // 0x2C
			constexpr auto rotateAmountTest = 0x30;//public float rotateAmountTest; // 0x30
			constexpr auto SwayEnabled = 0x34;//public bool SwayEnabled; // 0x34
			constexpr auto lastPosition = 0x38;//internal Vector3 lastPosition; // 0x38
			constexpr auto smoothedVelocity = 0x44;//internal Vector3 smoothedVelocity; // 0x44
			constexpr auto lastRotation = 0x50;//internal Vector3 lastRotation; // 0x50
			constexpr auto smoothedRotation = 0x5C;//internal Vector3 smoothedRotation; // 0x5C
		}
		namespace ViewmodelLower {
			constexpr auto lowerOnSprint = 0x20;//public bool lowerOnSprint; // 0x20
			constexpr auto lowerWhenCantAttack = 0x21;//public bool lowerWhenCantAttack; // 0x21
			constexpr auto forceLower = 0x22;//public bool forceLower; // 0x22
			constexpr auto lowerScale = 0x24;//public float lowerScale; // 0x24
			constexpr auto shouldLower = 0x28;//private bool shouldLower; // 0x28
			constexpr auto rotateAngle = 0x2C;//internal float rotateAngle; // 0x2C
			constexpr auto updatePlayer = 0x30;	//private BasePlayer updatePlayer; // 0x30
		}
		namespace ViewmodelBob {
			constexpr auto bobSpeedWalk = 0x20;	//public float bobSpeedWalk; // 0x20
			constexpr auto bobSpeedRun = 0x24;	//public float bobSpeedRun; // 0x24
			constexpr auto bobAmountWalk = 0x28;	//public float bobAmountWalk; // 0x28
			constexpr auto bobAmountRun = 0x2C;//public float bobAmountRun; // 0x2C
			constexpr auto leftOffsetRun = 0x30;//public float leftOffsetRun; // 0x30
			constexpr auto BobEnabled = 0x34;	//public bool BobEnabled; // 0x34
			constexpr auto bobAmountRotateYaw = 0x38;//internal float bobAmountRotateYaw; // 0x38
			constexpr auto bobAmountRotateRoll = 0x3C;//internal float bobAmountRotateRoll; // 0x3C
			constexpr auto velocity = 0x40;//internal Vector3 velocity; // 0x40
			constexpr auto bobOffset = 0x4C;//internal Vector3 bobOffset; // 0x4C
			constexpr auto bobRotateYaw = 0x58;//internal float bobRotateYaw; // 0x58
			constexpr auto bobRotateRoll = 0x5C;//internal float bobRotateRoll; // 0x5C
			constexpr auto bobCycle = 0x60;//internal float bobCycle; // 0x60
			constexpr auto smoothedBob = 0x64;//internal ViewmodelBob.BobSettings smoothedBob; // 0x64
		}
		namespace SkinSetCollection
		{
			constexpr auto Skins = 0x18;//	public SkinSet[] Skins; // 0x18
		}
		namespace Skinnable
		{
			constexpr auto Name = 0x18;//public string Name; // 0x18
			constexpr auto ItemName = 0x20;//public string ItemName; // 0x20
			constexpr auto EntityPrefab = 0x28;	//public GameObject EntityPrefab; // 0x28
			constexpr auto EntityPrefabName = 0x30;	//public string EntityPrefabName; // 0x30
			constexpr auto ViewmodelPrefab = 0x38;//public GameObject ViewmodelPrefab; // 0x38
			constexpr auto ViewmodelPrefabName = 0x40;//public string ViewmodelPrefabName; // 0x40
			constexpr auto MeshDownloads = 0x48;//public Mesh[] MeshDownloads; // 0x48
			constexpr auto MeshDownloadPaths = 0x50;//public string[] MeshDownloadPaths; // 0x50
			constexpr auto Category = 0x58;//public Category Category; // 0x58
			constexpr auto HideInWorkshopUpload = 0x5C;//public bool HideInWorkshopUpload; // 0x5C
			constexpr auto Groups = 0x60;//public Skinnable.Group[] Groups; // 0x60
			constexpr auto All = 0x0;//public static Skinnable[] All; // 0x0
			constexpr auto _sourceMaterials = 0x68;//private Material[] _sourceMaterials; // 0x68
		}
		namespace SkinReplacement {
			constexpr auto skinReplacementType = 0x10;//public SkinReplacement.SkinType skinReplacementType; // 0x10
			constexpr auto targetReplacement = 0x18;//public GameObjectRef targetReplacement; // 0x18
		}
		namespace SkinSet {
			constexpr auto Label = 0x18;//public string Label; // 0x18
			constexpr auto SkinColour = 0x20;//public Gradient SkinColour; // 0x20
			constexpr auto HairCollection = 0x28;//public HairSetCollection HairCollection; // 0x28
			constexpr auto Head = 0x30;//public GameObjectRef Head; // 0x30
			constexpr auto Torso = 0x38;//public GameObjectRef Torso; // 0x38
			constexpr auto Legs = 0x40;//public GameObjectRef Legs; // 0x40
			constexpr auto Feet = 0x48;//public GameObjectRef Feet; // 0x48
			constexpr auto Hands = 0x50;//public GameObjectRef Hands; // 0x50
			constexpr auto CensoredTorso = 0x58;//public GameObjectRef CensoredTorso; // 0x58
			constexpr auto CensoredLegs = 0x60;//public GameObjectRef CensoredLegs; // 0x60
			constexpr auto HeadMaterial = 0x68;//public Material HeadMaterial; // 0x68
			constexpr auto BodyMaterial = 0x70;//public Material BodyMaterial; // 0x70
			constexpr auto EyeMaterial = 0x78;//public Material EyeMaterial; // 0x78
		}
		namespace RecoilProperties {
			constexpr auto recoilYawMin = 0x18;
			constexpr auto recoilYawMax = 0x1c;
			constexpr auto recoilPitchMin = 0x20;
			constexpr auto recoilPitchMax = 0x24;
			constexpr auto timeToTakeMin = 0x28;
			constexpr auto timeToTakeMax = 0x2c;
			constexpr auto ADSScale = 0x30;
			constexpr auto movementPenalty = 0x34;
			constexpr auto clampPitch = 0x38;
			constexpr auto pitchCurve = 0x40;
			constexpr auto yawCurve = 0x48;
			constexpr auto useCurves = 0x50;
			constexpr auto curvesAsScalar = 0x51;
			constexpr auto shotsUntilMax = 0x54;
			constexpr auto maxRecoilRadius = 0x58;
			constexpr auto overrideAimconeWithCurve = 0x5c;
			constexpr auto aimconeCurveScale = 0x60;
			constexpr auto aimconeCurve = 0x68;
			constexpr auto aimconeProbabilityCurve = 0x70;
			constexpr auto ammoAimconeScaleMultiProjectile = 0x78;
			constexpr auto ammoAimconeScaleSingleProjectile = 0x7c;
			constexpr auto newRecoilOverride = 0x80;
		}
		namespace String
		{
			constexpr auto StackallocIntBufferSizeLimit = 128;//private const int StackallocIntBufferSizeLimit = 128;
			constexpr auto PROBABILISTICMAP_BLOCK_INDEX_MASK = 7;//private const int PROBABILISTICMAP_BLOCK_INDEX_MASK = 7;
			constexpr auto PROBABILISTICMAP_BLOCK_INDEX_SHIFT = 3;//private const int PROBABILISTICMAP_BLOCK_INDEX_SHIFT = 3;
			constexpr auto PROBABILISTICMAP_SIZE = 8;//private const int PROBABILISTICMAP_SIZE = 8;
			constexpr auto _stringLength = 0x10;//private int _stringLength; // 0x10
			constexpr auto _firstChar = 0x14;//private char _firstChar; // 0x14
			constexpr auto Empty = 0x0;//public static readonly string Empty; // 0x0
		}
		namespace Item {
			constexpr auto _condition = 0x10;
			constexpr auto _maxCondition = 0x14;
			constexpr auto info = 0x18;
			constexpr auto uid = 0x20;
			constexpr auto dirty = 0x28;
			constexpr auto amount = 0x2c;
			constexpr auto position = 0x30;
			constexpr auto busyTime = 0x34;
			constexpr auto removeTime = 0x38;
			constexpr auto fuel = 0x3c;
			constexpr auto isServer = 0x40;
			constexpr auto instanceData = 0x48;
			constexpr auto skin = 0x50;
			constexpr auto name = 0x58;
			constexpr auto streamerName = 0x60;
			constexpr auto text = 0x68;
			constexpr auto ammoCountk__BackingField = 0x70;
			constexpr auto cookTimeLeft = 0x78;
			constexpr auto progressBar = 0x7c;
			constexpr auto OnDirty = 0x80;
			constexpr auto flags = 0x88;
			constexpr auto contents = 0x90;
			constexpr auto parent = 0x98;
			constexpr auto worldEnt = 0xa0;
			constexpr auto heldEntity = 0xb0;
			constexpr auto amountOverride = 0xc0;
		}
		namespace PlayerInput {
			constexpr auto state = 0x28;
			constexpr auto hadInputBuffer = 0x30;
			constexpr auto bodyRotation = 0x34;
			constexpr auto bodyAngles = 0x44;
			constexpr auto bodyAnglesOverride = 0x50;
			constexpr auto clearBodyAnglesOverrideOnLerpComplete = 0x5c;
			constexpr auto bodyAnglesOverrideLerpSpeed = 0x60;
			constexpr auto headRotation = 0x64;
			constexpr auto headAngles = 0x74;
			constexpr auto recoilAngles = 0x80;
			constexpr auto viewDelta = 0x8c;
			constexpr auto headLerp = 0x94;
			constexpr auto mouseWheelUp = 0x98;
			constexpr auto mouseWheelDn = 0x9c;
			constexpr auto autorun = 0xa0;
			constexpr auto toggleDuck = 0xa1;
			constexpr auto toggleAds = 0xa2;
			constexpr auto lastAdsEntity = 0xa8;
			constexpr auto pendingMouseDelta = 0xb0;
			constexpr auto offsetAngles = 0xbc;
			constexpr auto ignoredButtons = 0xc8;
			constexpr auto hasKeyFocus = 0xcc;
		}
		namespace PlayerEyes {
			constexpr auto DuckOffset = 0xc;
			constexpr auto CrawlOffset = 0x18;
			constexpr auto ParachuteOffset = 0x24;
			constexpr auto thirdPersonSleepingOffset = 0x28;
			constexpr auto defaultLazyAim = 0x38;
			constexpr auto viewOffset = 0x40;
			constexpr auto bodyRotationk__BackingField = 0x4c;
			constexpr auto headAnglesk__BackingField = 0x5c;
			constexpr auto rotationLookk__BackingField = 0x68;
			constexpr auto postRotationLookk__BackingField = 0x78;
			constexpr auto postRotationLookAlphak__BackingField = 0x88;
			constexpr auto IsAltLookingLegsThresholdk__BackingField = 0x8c;
		}
		namespace ItemContainer {
			constexpr auto flags = 0x10;
			constexpr auto allowedContents = 0x14;
			constexpr auto onlyAllowedItems = 0x18;
			constexpr auto availableSlots = 0x20;
			constexpr auto capacity = 0x28;
			constexpr auto uid = 0x30;
			constexpr auto dirty = 0x38;
			constexpr auto itemList = 0x40;
			constexpr auto temperature = 0x48;
			constexpr auto parent = 0x50;
			constexpr auto playerOwner = 0x58;
			constexpr auto entityOwner = 0x60;
			constexpr auto isServer = 0x68;
			constexpr auto maxStackSize = 0x6c;
			constexpr auto containerVolume = 0x70;
		}
		namespace ItemDefinition {
			constexpr auto itemid = 0x20;
			constexpr auto shortname = 0x28;
			constexpr auto displayName = 0x30;
			constexpr auto displayDescription = 0x38;
			constexpr auto iconSprite = 0x40;
			constexpr auto category = 0x48;
			constexpr auto selectionPanel = 0x4c;
			constexpr auto maxDraggable = 0x50;
			constexpr auto itemType = 0x54;
			constexpr auto amountType = 0x58;
			constexpr auto occupySlots = 0x5c;
			constexpr auto stackable = 0x60;
			constexpr auto volume = 0x64;
			constexpr auto quickDespawn = 0x68;
			constexpr auto blockStealingInSafeZone = 0x69;
			constexpr auto tutorialAllowance = 0x6c;
			constexpr auto rarity = 0x70;
			constexpr auto despawnRarity = 0x74;
			constexpr auto spawnAsBlueprint = 0x78;
			constexpr auto inventoryGrabSound = 0x80;
			constexpr auto inventoryDropSound = 0x88;
			constexpr auto physImpactSoundDef = 0x90;
			constexpr auto condition = 0x98;
			constexpr auto hidden = 0xb0;
			constexpr auto flags = 0xb4;
			constexpr auto hideSelectedPanel = 0xb8;
			constexpr auto steamItem = 0xc0;
			constexpr auto steamDlc = 0xc8;
			constexpr auto Parent = 0xd0;
			constexpr auto worldModelPrefab = 0xd8;
			constexpr auto worldModelOverrides = 0xe0;
			constexpr auto treatAsComponentForRepairs = 0xe8;
			constexpr auto AlignWorldModelOnDrop = 0xe9;
			constexpr auto WorldModelDropOffset = 0xec;
			constexpr auto isRedirectOf = 0xf8;
			constexpr auto redirectVendingBehaviour = 0x100;
			constexpr auto itemMods = 0x108;
			constexpr auto Traits = 0x110;
			constexpr auto skins = 0x118;
			constexpr auto _skins2 = 0x120;
			constexpr auto panel = 0x128;
			constexpr auto ItemModWearablek__BackingField = 0x130;
			constexpr auto ItemModBurnablek__BackingField = 0x138;
			constexpr auto ItemModCookablek__BackingField = 0x140;
			constexpr auto isHoldablek__BackingField = 0x148;
			constexpr auto isUsablek__BackingField = 0x149;
			constexpr auto CraftableWithSkink__BackingField = 0x14a;
			constexpr auto Children = 0x150;
		}
		namespace ItemModProjectile
		{
			constexpr auto projectileObject = 0x20;
			constexpr auto mods = 0x28;
			constexpr auto ammoType = 0x30;
			constexpr auto numProjectiles = 0x34;
			constexpr auto projectileSpread = 0x38;
			constexpr auto projectileVelocity = 0x3c;
			constexpr auto projectileVelocitySpread = 0x40;
			constexpr auto useCurve = 0x44;
			constexpr auto spreadScalar = 0x48;
			constexpr auto attackEffectOverride = 0x50;
			constexpr auto barrelConditionLoss = 0x58;
			constexpr auto category = 0x60;
		}
		namespace Magazine
		{
			constexpr auto capacity = 0x10;//public int capacity; // 0x10
			constexpr auto contents = 0x14;	//public int contents; // 0x14
			constexpr auto ammoType = 0x18;	//public int ammoType; // 0x18
			constexpr auto ShouldPool = 0x1C;	//public bool ShouldPool; // 0x1C
			constexpr auto _disposed = 0x1D;	//private bool _disposed; // 0x1D
		}
		namespace TOD_Sky {
			constexpr auto ColorSpace = 0x20;
			constexpr auto ColorRange = 0x24;
			constexpr auto ColorOutput = 0x28;
			constexpr auto SkyQuality = 0x2c;
			constexpr auto CloudQuality = 0x30;
			constexpr auto MeshQuality = 0x34;
			constexpr auto StarQuality = 0x38;
			constexpr auto Cycle = 0x40;
			constexpr auto World = 0x48;
			constexpr auto Atmosphere = 0x50;
			constexpr auto Day = 0x58;
			constexpr auto Night = 0x60;
			constexpr auto Sun = 0x68;
			constexpr auto Moon = 0x70;
			constexpr auto Stars = 0x78;
			constexpr auto Clouds = 0x80;
			constexpr auto Light = 0x88;
			constexpr auto Fog = 0x90;
			constexpr auto Ambient = 0x98;
			constexpr auto Reflection = 0xa0;
			constexpr auto Initializedk__BackingField = 0xa8;
			constexpr auto Componentsk__BackingField = 0xb0;
			constexpr auto Resourcesk__BackingField = 0xb8;
			constexpr auto IsDayk__BackingField = 0xc0;
			constexpr auto IsNightk__BackingField = 0xc1;
			constexpr auto LerpValuek__BackingField = 0xc4;
			constexpr auto SunZenithk__BackingField = 0xc8;
			constexpr auto SunAltitudek__BackingField = 0xcc;
			constexpr auto SunAzimuthk__BackingField = 0xd0;
			constexpr auto MoonZenithk__BackingField = 0xd4;
			constexpr auto MoonAltitudek__BackingField = 0xd8;
			constexpr auto MoonAzimuthk__BackingField = 0xdc;
			constexpr auto SunsetTimek__BackingField = 0xe0;
			constexpr auto SunriseTimek__BackingField = 0xe4;
			constexpr auto LocalSiderealTimek__BackingField = 0xe8;
			constexpr auto SunVisibilityk__BackingField = 0xec;
			constexpr auto MoonVisibilityk__BackingField = 0xf0;
			constexpr auto SunDirectionk__BackingField = 0xf4;
			constexpr auto MoonDirectionk__BackingField = 0x100;
			constexpr auto LightDirectionk__BackingField = 0x10c;
			constexpr auto LocalSunDirectionk__BackingField = 0x118;
			constexpr auto LocalMoonDirectionk__BackingField = 0x124;
			constexpr auto LocalLightDirectionk__BackingField = 0x130;
			constexpr auto SunLightColork__BackingField = 0x13c;
			constexpr auto MoonLightColork__BackingField = 0x14c;
			constexpr auto SunRayColork__BackingField = 0x15c;
			constexpr auto MoonRayColork__BackingField = 0x16c;
			constexpr auto SunSkyColork__BackingField = 0x17c;
			constexpr auto MoonSkyColork__BackingField = 0x18c;
			constexpr auto SunMeshColork__BackingField = 0x19c;
			constexpr auto MoonMeshColork__BackingField = 0x1ac;
			constexpr auto SunCloudColork__BackingField = 0x1bc;
			constexpr auto MoonCloudColork__BackingField = 0x1cc;
			constexpr auto FogColork__BackingField = 0x1dc;
			constexpr auto GroundColork__BackingField = 0x1ec;
			constexpr auto AmbientColork__BackingField = 0x1fc;
			constexpr auto MoonHaloColork__BackingField = 0x20c;
			constexpr auto ReflectionCur = 0x220;
			constexpr auto ReflectionSrc = 0x228;
			constexpr auto ReflectionDst = 0x230;
			constexpr auto ReflectionUpdateSpeed = 0x8;
			constexpr auto ReflectionResolution = 0xc;
			constexpr auto ReflectionUpdateInterval = 0x10;
			constexpr auto ReflectionTimeSlicing = 0x14;
			constexpr auto timeSinceLightUpdate = 0x238;
			constexpr auto timeSinceAmbientUpdate = 0x23c;
			constexpr auto timeSinceReflectionUpdate = 0x240;
			constexpr auto kBetaMie = 0x244;
			constexpr auto kSun = 0x250;
			constexpr auto k4PI = 0x260;
			constexpr auto kRadius = 0x270;
			constexpr auto kScale = 0x280;
		}
		namespace TOD_AtmosphereParameters {
			constexpr auto RayleighMultiplier = 0x10;
			constexpr auto MieMultiplier = 0x14;
			constexpr auto Brightness = 0x18;
			constexpr auto Contrast = 0x1c;
			constexpr auto Directionality = 0x20;
			constexpr auto Fogginess = 0x24;
		}
		namespace TOD_MoonParameters {
			constexpr auto MeshSize = 0x10;
			constexpr auto MeshBrightness = 0x14;
			constexpr auto MeshContrast = 0x18;
			constexpr auto HaloSize = 0x1c;
			constexpr auto HaloBrightness = 0x20;
			constexpr auto Position = 0x24;
		}
		namespace TOD_CloudParameters {
			constexpr auto Size = 0x10;
			constexpr auto Opacity = 0x14;
			constexpr auto Coverage = 0x18;
			constexpr auto Sharpness = 0x1c;
			constexpr auto Coloring = 0x20;
			constexpr auto Attenuation = 0x24;
			constexpr auto Saturation = 0x28;
			constexpr auto Scattering = 0x2c;
			constexpr auto Brightness = 0x30;
		}
		namespace TOD_NightParameters {
			constexpr auto MoonColor = 0x10;
			constexpr auto LightColor = 0x18;
			constexpr auto RayColor = 0x20;
			constexpr auto SkyColor = 0x28;
			constexpr auto CloudColor = 0x30;
			constexpr auto FogColor = 0x38;
			constexpr auto AmbientColor = 0x40;
			constexpr auto LightIntensity = 0x48;
			constexpr auto ShadowStrength = 0x4c;
			constexpr auto AmbientMultiplier = 0x50;
			constexpr auto ReflectionMultiplier = 0x54;
		}
}