class CfgPatches
{
	class FLAY_HangGlider_Core
	{
		units[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};

class DefaultEventhandlers;

class CfgVehicles
{
	class Air;
	class Plane: Air
	{
		class NewTurret;
		class ViewPilot;
		class AnimationSources;
		class Turrets;
		class Sounds;
	};
	
	class FLAY_GliderBase: Plane
	{
		scope = 1;
		
		class EventHandlers: DefaultEventHandlers
		{
			killed = ""; // disable explosion effect on crash
		};
		
		damageEffect = ""; // disable smoke when damaged
		//crewVulnerable = true;		
			
		armor = 5;		
		side = 4;
		Icon = "\flay\flay_hangglider\hangglider\glider_ico_ca.paa";
		picture = "\flay\flay_hangglider\hangglider\glider_pic_ca.paa";
		mapSize = 10;
		
		nameSound = "veh_parachute";
		accuracy = 0.1;
		camouflage = 1;
		audible = 0;
		hasGunner = 0;
		fuelCapacity = 0;
		
		soundEngine[] = {};
		soundEnviron[] = {"\FLAY\FLAY_Hangglider\hangglider\sounds\padak_let",0.31622776,1,80};
		soundGetIn[] = {"\FLAY\FLAY_Hangglider\hangglider\sounds\padak_getIN",0.31622776,1,80};
		soundGetOut[] = {"\FLAY\FLAY_Hangglider\hangglider\sounds\padak_getIN",0.31622776,1,80};
		soundCrash[] = {"\FLAY\FLAY_Hangglider\hangglider\sounds\padak_dopad",0.031622775,0,80};
		soundLandCrash[] = {"\FLAY\FLAY_Hangglider\hangglider\sounds\padak_dopad",0.031622775,0,80};
		soundWaterCrash[] = {"\FLAY\FLAY_Hangglider\hangglider\sounds\padak_dopadvoda",3.1622777,0,80};

		driverLeftHandAnimName = "pilot_lefthand";
		driverRightHandAnimName = "pilot_righthand";
		driverLeftLegAnimName = "pilot_leftfoot";
		driverRightLegAnimName = "pilot_rightfoot";
		
		simulation="airplane";
		unitInfoType = "RscUnitInfoNoHUD";		
				
		threat[] = {1,0.900000,0.100000};
		
		htMin = 60;
		htMax = 1800;
		afMax = 100;
		mfMax = 80;
		mFact = 0;
		tBody = 0;
				
		//turnCoef = 5;//TEST
		//wheelCircumference = 2.28;
		
		transportMaxMagazines = 0;
		transportMaxWeapons = 0;
		
		driverCanSee = "2"; 
		extCameraPosition[] = {0,1,-3};

		enableGPS = 0;
		
		class ViewPilot: ViewPilot
		{
			initFov = 1.3;
			minFov = 0.5;
			maxFov = 1.3;
			initAngleX = 0;
			minAngleX = -80;
			maxAngleX = 80;
			initAngleY = 30;
			minAngleY = -110;
			maxAngleY = 110;
		};

		driverAction = "HangGlider_Pilot";
		driverInAction = "HangGlider_Pilot";
		getInAction = "GetInLow";
		getOutAction = "GetOutLow";
		
		cabinOpening = 1;
		attenuationEffectType = "OpenCarAttenuation";
		obstructSoundLFRatio = 0;
		obstructSoundsWhenIn = 0;
		//obstructSoundsWhenIn = 0.316228;
		//occludeSoundLFRatio = 0.25;
		occludeSoundLFRatio = 0;
		occludeSoundsWhenIn = 0;
		//occludeSoundsWhenIn = 0.1;
		outsideSoundFilter = 0.5;
		//outsideSoundFilter = 0;
		
		class Sounds: Sounds {};
		class Turrets {};
		class Reflectors {};
		
		gearRetracting = 0;
		flaps = 0;
		envelope[] = { 0.10, 0.20, 0.5, 0.9, 1.0, 1.5, 2.0, 2.5, 2.5, 3.0, 2.5, 2.5, 2.0, 1.75, 1.75, 1.75, 1.75, 1.5, 1.25, 1.0 };
		
		maxSpeed = 200;
		aileronSensitivity = 0.5;
		elevatorSensitivity = 0.05;
		wheelSteeringSensitivity = 0.001;
		noseDownCoef = 0.1;
		
		ejectDeadDriver = true;
		ejectSpeed[] = {0,0,0};
	};
};

// ===========================================================================
// WEAPONS
// ===========================================================================

class cfgWeapons
{
    class Default;
	class RocketPods;
	class HangGliderBombs: RocketPods
	{
		scope = 1;
		displayName = "Grenades";
		cursorAim = "EmptyCursor";
		cursor = "EmptyCursor";
		cursorSize = 1;
		autoFire = 0;
		sound[] = {"",10.0,1};
		magazines[] = {"4Rnd_Bomb_HangGlider","2Rnd_Bomb_WingSuit","3Rnd_AT_Mine_WingSuit","6Rnd_AP_Mine_WingSuit"};
		reloadTime = 1;
		magazineReloadTime = 0.1;
		dispersion = 0.015;
		minRange = 1;
		minRangeProbab = 0.8;
		midRange = 50;
		midRangeProbab = 0.7;
		maxRange = 150;
		maxRangeProbab = 0.1;
		autoReload = 1;
		canLock = 0;
	};
	class launch_RPG32_F;
	class FLAY_HangGlider_BagLauncher: launch_RPG32_F
	{
		scope = 2;
		displayName = "FLAY Hang Glider Bag";
		model = "FLAY\FLAY_HangGlider\FLAY_HangGlider_Bag.p3d";
		cursorAim = "EmptyCursor";
		cursor = "EmptyCursor";
		modelOptics = "-";
		sound[] = {"",10.0,1,1400};
		drySound[] = {"",0.0001,1,10};
		reloadMagazineSound[] = {"",0.00031622776,1,20};
		soundFly[] = {"",100.0,1.5,700};
		class Library
		{
			libTextDesc = "FLAY Hang Glider Bag";
		};
		descriptionShort = "FLAY Hang Glider Bag";
	};
};

// ===========================================================================
// MAGAZINES
// ===========================================================================

class CfgMagazines
{
	class Default;
	class CA_Magazine: Default {};
	class VehicleMagazine: CA_Magazine {};
	class 4Rnd_Bomb_HangGlider: VehicleMagazine
	{
		scope = 2;
		displayName = "Bomb";
		ammo = "Bo_HangGlider_50";
		count = 4;
		initSpeed = 1;
		maxLeadSpeed = 200;
		nameSound = "grenade";
	};
	class 2Rnd_Bomb_WingSuit: VehicleMagazine
	{
		scope = 2;
		displayName = "Grenade";
		ammo = "Bo_WingSuit_5";
		count = 2;
		initSpeed = 1;
		maxLeadSpeed = 200;
		nameSound = "grenade";
	};	
	class 3Rnd_AT_Mine_WingSuit: VehicleMagazine
	{
		scope = 2;
		displayName = "Grenade";
		ammo = "Bo_AT_Mine_WingSuit";
		count = 3;
		initSpeed = 1;
		maxLeadSpeed = 200;
		nameSound = "grenade";
	};
	class 6Rnd_AP_Mine_WingSuit: VehicleMagazine
	{
		scope = 2;
		displayName = "Grenade";
		ammo = "Bo_AP_Mine_WingSuit";
		count = 6;
		initSpeed = 1;
		maxLeadSpeed = 200;
		nameSound = "grenade";
	};		
};

// ===========================================================================
// AMMO
// ===========================================================================

class CfgAmmo
{
    class Default;
	class BombCore {};
	class Bo_HangGlider_50: BombCore
	{
		hit = 100;
		indirectHit = 20;
		indirectHitRange = 10;
		cost = 1000;
		irLock = 0;
		laserLock = 0;
		maxControlRange = 10;
		maneuvrability = 16.0;
		sideAirFriction = 0.1;
		simulation = "shotRocket";
		maxSpeed = 100;
		timeToLive = 120;
		initTime = 0;
		thrustTime = 0;
		thrust = 0;
		soundHit1[] = {"A3\Sounds_F\weapons\Explosion\expl_big_1",5.0118723,1,2400};
		soundHit2[] = {"A3\Sounds_F\weapons\Explosion\expl_big_2",5.0118723,1,2400};
		soundHit3[] = {"A3\Sounds_F\weapons\Explosion\expl_big_3",5.0118723,1,2400};
		soundHit4[] = {"A3\Sounds_F\weapons\Explosion\expl_shell_1",5.0118723,1,2400};
		soundHit5[] = {"A3\Sounds_F\weapons\Explosion\expl_shell_2",5.0118723,1,2400};
		multiSoundHit[] = {"soundHit1",0.2,"soundHit2",0.2,"soundHit3",0.2,"soundHit4",0.2,"soundHit5",0.2};
		explosionSoundEffect = "DefaultExplosion";
		model = "\A3\weapons_f\Ammo\UGL_slug";
		proxyShape = "\A3\weapons_f\Ammo\UGL_slug";
		//CraterEffects = "BombCrater";
		//explosionEffects = "BombExplosion";
		CraterEffects = "HERocketCrater";
		explosionEffects = "HERocketExplosion";
		whistleDist = 24;
	};
	class Bo_WingSuit_5: Bo_HangGlider_50
	{
		hit = 24;
		indirectHit = 12;
		indirectHitRange = 3;
		cost = 100;
	};		
	class Bo_AT_Mine_WingSuit: Bo_HangGlider_50
	{
		hit = 0;
		indirectHit = 0;
		indirectHitRange = 0;
		soundHit[] = {"",1,1};				
		multiSoundHit[] = {};
		cost = 1;
		whistleDist = 0;		
		model = "\A3\weapons_f\explosives\mine_AT";
		proxyShape = "\A3\weapons_f\explosives\mine_AT";
		CraterEffects = "NoCrater";
		explosionEffects = "NoExplosion";
		explosive = 0;
	};
	class Bo_AP_Mine_WingSuit: Bo_HangGlider_50
	{
		hit = 0;
		indirectHit = 0;
		indirectHitRange = 0;
		soundHit[] = {"",1,1};
		multiSoundHit[] = {};
		cost = 1;
		whistleDist = 0;		
		model = "\A3\weapons_f\explosives\mine_AP";
		proxyShape = "\A3\weapons_f\explosives\mine_AP";
		CraterEffects = "NoCrater";
		explosionEffects = "NoExplosion";
		explosive = 0;
	};	
	class Bo_Rocks_WingSuit: Bo_HangGlider_50
	{
		hit = 5;
		indirectHit = 2;
		indirectHitRange = 1;
		soundHit[] = {"",1,1};
		multiSoundHit[] = {};
		cost = 1;
		whistleDist = 0;		
		model = "\A3\weapons_f\explosives\mine_AT";
		proxyShape = "\A3\weapons_f\explosives\mine_AT";
		CraterEffects = "NoCrater";
		explosionEffects = "NoExplosion";
		explosive = 1;
	};	
};
