enum {
	stabilizedinaxisx = 1,
	compartment1 = 1,
	stabilizedinaxisy = 2,
	compartment2 = 2,
	stabilizedinaxesboth = 3,
	compartment3 = 4,
	compartment4 = 8,
	stabilizedinaxesnone = 0
};


class CfgPatches
{
	class FLAY_HangGlider
	{
		units[] = {"FLAY_HangGlider","FLAY_HangGlider2","FLAY_HangGlider3","FLAY_NightWing","FLAY_DragonWing","FLAY_DeathWing","FLAY_WingSuit","FLAY_ArrowDownHelper"};
		requiredVersion = 1.04;
		requiredAddons[] = {"CACharacters","CAData","CASounds"};
	};
};


class DefaultEventhandlers;


// ===========================================================================
// VEHICLES
// ===========================================================================


class CfgVehicles
{
	class Static { ladders[] = {}; };
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
		armor = 5;
		scope = 2;
		
		side = 4;
		Icon = "\flay\flay_hangglider\data\glider_ico_ca.paa";
		picture = "\flay\flay_hangglider\data\glider_pic_ca.paa";
		mapSize = 10;
		
		nameSound = "veh_parachute";
		accuracy = 0.1;
		camouflage = 1;
		audible = 0;
		hasGunner = 0;
		fuelCapacity = 0;
		
		soundEngine[] = {};
		soundEnviron[] = {"\Ca\sounds\Air\Noises\padak_let",0.31622776,1,80};
		soundGetIn[] = {"\Ca\sounds\Air\Noises\padak_getIN",0.31622776,1,20};
		soundGetOut[] = {"\Ca\sounds\Air\Noises\padak_getIN",0.31622776,1,20};
		soundCrash[] = {"\Ca\sounds\Air\Noises\padak_dopad",0.031622775,1,50};
		soundLandCrash[] = {"\Ca\sounds\Air\Noises\padak_dopad",0.031622775,1,50};
		soundWaterCrash[] = {"\Ca\sounds\Air\Noises\padak_dopadvoda",3.1622777,1,80};

		//threat[] = {0.0,0.0,0.0};
		threat[] = {1,0.900000,0.100000};
		class DestructionEffects {};
		
		htMin = 60;
		htMax = 1800;
		afMax = 100;
		mfMax = 80;
		mFact = 0;
		tBody = 0;
		turnCoef = 5;//TEST
		outsideSoundFilter = 0;
		wheelCircumference = 2.28;
		transportMaxMagazines = 0;
		transportMaxWeapons = 0;
		
		driverCanSee = "2";
		secondaryExplosion = 0;
		extCameraPosition[] = {0,1,-3};
		destrType = "DestructNo";
		enableGPS = 0;

		driverOpticsModel = "\ca\weapons\optika_empty";
		
		class ViewPilot: ViewPilot
		{
			initFov = 1.2;
			minFov = 0.5;
			maxFov = 1.2;
			initAngleX = 0;
			minAngleX = -80;
			maxAngleX = 80;
			initAngleY = 30;
			minAngleY = -110;
			maxAngleY = 110;
		};

		driverAction = "WingSuit_Pilot";
		driverInAction = "WingSuit_Pilot";
		getInAction = "GetInLow";
		getOutAction = "GetOutLow";
		
		cabinOpening = 1;
		occludeSoundsWhenIn = 1.0;
		obstructSoundsWhenIn = 1.0;
		
		class Sounds: Sounds {};
		class Turrets {};
		class Reflectors {};
		class Armory
		{
			disabled = 1;
		};
		
		gearRetracting = 0;
		flaps = 0;
		envelope[] = { 0.10, 0.20, 0.5, 0.9, 1.0, 1.5, 2.0, 2.5, 2.5, 3.0, 2.5, 2.5, 2.0, 1.75, 1.75, 1.75, 1.75, 1.5, 1.25, 1.0 };
		
		maxSpeed = 200;
		aileronSensitivity = 0.5;
		elevatorSensitivity = 0.05;
		wheelSteeringSensitivity = 0.001;
		noseDownCoef = 0.1;
		ejectDeadDriver = false;
		ejectSpeed[] = {0,0,0};
	};
	
	class FLAY_HangGlider: FLAY_GliderBase
	{
		class EventHandlers: DefaultEventhandlers
		{
			init = "_scr = _this execVM ""\FLAY\FLAY_HangGlider\scripts\init.sqf"";";
		};

		displayName = "FLAY Hang Glider";
		model = "FLAY\FLAY_HangGlider\FLAY_HangGlider";

		weapons[] = {"BikeHorn"};
		//weapons[] = {};
		//magazines[] = {};	
		armor = 5000;
		accuracy = 0.5;
		camouflage = 2;

		extCameraPosition[] = {0,4,-9};
		enableGPS = 1;

		driverAction = "HangGlider_Pilot";
		driverInAction = "HangGlider_Pilot";
		getInAction = "GetInLow";
		getOutAction = "GetOutLow";
		
		//envelope[] = { 0.4, 0.9, 1.7, 2.5, 2.7, 3.0, 3.1, 3.2, 3.4, 3.5, 3.4, 3.3, 3.2, 3.1, 3.0, 2.8, 2.5, 2.0 };
		envelope[] = { 0.1, 0.2, 0.9, 1.5, 2.7, 3.0, 3.1, 3.2, 3.4, 3.5, 3.4, 3.3, 3.2, 3.1, 3.0, 2.8, 2.5, 2.0 };

		maxSpeed = 180;
		aileronSensitivity = 2.5;
		elevatorSensitivity = 0.2;
		wheelSteeringSensitivity = 2.7;
		noseDownCoef = 0.0025;
		ejectDeadDriver = true;
		ejectSpeed[] = {0,-1,-5};
		
		class AnimationSources: AnimationSources
		{
			class GliderPitch
			{
				source = "user";
				animPeriod = 0.05;
				initPhase = 0;
			};		
			class HarnessHide
			{
				source = "user";
				animPeriod = 0.000001;
				initPhase = 0;
			};
			class FeetRotation
			{
				source = "user";
				animPeriod = 0;
				initPhase = 0;
			};
			class FeetDamper {};
			class LegsDamper 
			{
				source = "user";
				animPeriod = 0;
				initPhase = 1;
			};
			class FeetStabilizer
			{
				source = "user";
				animPeriod = 0.1;
				initPhase = 0;
			};
			class HelperHide
			{
				source = "user";
				animPeriod = 0.000001;
				initPhase = 1;
			};
			class PilotPosX
			{
				source = "user";
				animPeriod = 0.000001;
				initPhase = 0;	
			};
			class PilotPosY
			{
				source = "user";
				animPeriod = 0.000001;
				initPhase = 0;	
			};
			class PilotPosZ
			{
				source = "user";
				animPeriod = 0.000001;
				initPhase = 0;	
			};
			class Variometer {
				source = "vertSpeed";
				animPeriod = 0.000001;
				initPhase = 0;
			};
		};

		class Sounds: Sounds
		{
			//class BeepIn
			//{
			//	sound[] = {"\ca\sounds_e\sfx\locking_target_1",0.17782794,1.0,50};
			//	frequency = "1";
			//	volume = "0.5";
			//};
			class CreakNoiseIn1
			{
				sound[] = {"\FLAY\FLAY_HangGlider\data\sfx\squeak1.ogg",0.31622776,1,50};
				frequency = "(randomizer*0.05+1.0)";
				volume = "10*(speed factor[1, 80])*(1-camPos)";
			};
			class CreakNoiseIn2
			{
				sound[] = {"\FLAY\FLAY_HangGlider\data\sfx\squeak1.ogg",0.31622776,1,50};
				frequency = "(randomizer*0.5+0.5)";
				volume = "10*(speed factor[70, 100])*(1-camPos)";
			};
			class CreakNoiseIn3
			{
				sound[] = {"\FLAY\FLAY_HangGlider\data\sfx\squeak3.ogg",0.31622776,1,50};
				frequency = "(randomizer*0.5+0.2)";
				volume = "10*(speed factor[70, 100])*(1-camPos)";
			};			
			class CreakNoiseOut
			{
				sound[] = {"\FLAY\FLAY_HangGlider\data\sfx\squeak1.ogg",0.31622776,1,50};
				frequency = "(randomizer*0.05+1.0)";
				volume = "10*camPos*(speed factor[1, 80])";
			};
			//class FootStepsIn
			//{
			//	sound[] = {"\FLAY\FLAY_HangGlider\data\sfx\squeak1.ogg",0.31622776,1,10};
			//	frequency = "(randomizer*0.05+1.0)";
			//	volume = "10*camPos*(speed factor[1, 80])";
			//};			
		};

		//class assembleInfo
		//{
		//	primary = 0;
		//	base = "";
		//	assembleTo = "";
		//	dissasembleTo[] = {"FLAY_HangGlider_Bag","Tripod_Bag"};
		//	displayName = "";
		//};
	};
	
	class FLAY_HangGlider2: FLAY_HangGlider
	{
		displayName = "FLAY Hang Glider 2";
		model = "FLAY\FLAY_HangGlider\FLAY_HangGlider2";
	};
	
	class FLAY_HangGlider3: FLAY_HangGlider
	{
		displayName = "FLAY Hang Glider 3";
		model = "FLAY\FLAY_HangGlider\FLAY_HangGlider3";
	};
	
	class FLAY_NightWing: FLAY_HangGlider
	{
		displayName = "FLAY Night Wing";
		model = "FLAY\FLAY_HangGlider\FLAY_NightWing";
	};
	
	class FLAY_DeathWing: FLAY_HangGlider
	{
		displayName = "FLAY Death Wing";
		model = "FLAY\FLAY_HangGlider\FLAY_DeathWing";
		weapons[] = {"HangGliderM60A4","HangGliderBombs"};
		magazines[] = {"400Rnd_762x51_M240_HangGlider","4Rnd_Bomb_HangGlider"};
		gunAimDown = 0.15;
		HeadAimDown = 8;		
	};
	
	class FLAY_DragonWing: FLAY_HangGlider
	{
		displayName = "FLAY Dragon Wing";
		model = "FLAY\FLAY_HangGlider\FLAY_DragonWing";
		weapons[] = {"M2","DSHKM","HangGliderBombs"};
		magazines[] = {"100Rnd_127x99_M2","100Rnd_127x99_M2","100Rnd_127x99_M2","50Rnd_127x107_DSHKM","50Rnd_127x107_DSHKM","50Rnd_127x107_DSHKM","4Rnd_Bomb_HangGlider"};
		gunAimDown = 0.15;
		HeadAimDown = 8;
	};

	class FLAY_HangGliderAI: FLAY_HangGlider
	{
		displayName = "FLAY Hang Glider (AI)";
		model = "FLAY\FLAY_HangGlider\FLAY_HangGlider3";
		fuelCapacity = 100;
		maxSpeed = 100;
		landingSpeed = 70;
		landingAoa = "rad -15";
		envelope[] = { 0.1, 0.2, 1.0, 2.0, 3.5, 3.5, 3.5, 3.5, 4.5, 4.5, 4.5, 3.5, 3.5, 2.5, 2.5, 2.5, 2.5, 2.5, 2.5, 2.5 };
		aileronSensitivity = 3.5;
		elevatorSensitivity = 0.1;
		wheelSteeringSensitivity = 2.7;
		noseDownCoef = 0.00000025;		
	};
	
	class FLAY_WingSuit: FLAY_GliderBase
	{
		displayName = "FLAY Wing Suit";
		model = "FLAY\FLAY_HangGlider\FLAY_WingSuit";
		Icon = "\ca\air\data\map_ico\icomap_Para_CA.paa";
		picture = "\ca\air\data\ico\Para_CA.paa";
		
		driverAction = "WingSuit_Pilot";
		driverInAction = "WingSuit_Pilot";

		envelope[] = { 0.10, 0.20, 0.5, 0.9, 1.0, 1.5, 2.0, 2.5, 2.5, 3.0, 2.5, 2.5, 2.0, 1.75, 1.75, 1.75, 1.75, 1.5, 1.25, 1.0 };

		maxSpeed = 200;
		aileronSensitivity = 0.5;
		elevatorSensitivity = 0.05;
		wheelSteeringSensitivity = 0.001;
		noseDownCoef = 0.1;
	};
	
	// Assemble Info
	
//	class Bag_Base_EP1;
//	class Weapon_Bag_Base_EP1: Bag_Base_EP1
//	{
//		class assembleInfo{};
//	};
//	class FLAY_HangGlider_Bag: Weapon_Bag_Base_EP1
//	{
//		scope = 2;
//		displayName = "Hang Glider Bag";
//		class assembleInfo: assembleInfo
//		{
//			displayName = "Hang Glider";
//			assembleTo = "FLAY_HangGlider";
//		};
//	};

	class FLAY_HiddenTrolley: Plane
	{
		scope = 2;
		displayName = "FLAY - Hidden Trolley";
		model = "FLAY\FLAY_HangGlider\FLAY_HiddenTrolley";
		armor = 5;
		
		side = 4;
		Icon = "\flay\flay_hangglider\data\glider_ico_ca.paa";
		picture = "\flay\flay_hangglider\data\glider_pic_ca.paa";
		mapSize = 10;
		
		//nameSound = "veh_parachute";
		accuracy = 0.1;
		camouflage = 1;
		audible = 0;
		hasGunner = 0;
		fuelCapacity = 0;

		threat[] = {0.0,0.0,0.0};
		class DestructionEffects {};
		
		htMin = 60;
		htMax = 1800;
		afMax = 100;
		mfMax = 80;
		mFact = 0;
		tBody = 0;
		turnCoef = 2;
		outsideSoundFilter = 0;
		wheelCircumference = 2.28;
		transportMaxMagazines = 0;
		transportMaxWeapons = 0;
		
		driverCanSee = "2";
		secondaryExplosion = 0;
		extCameraPosition[] = {0,1,-3};
		destrType = "DestructNo";
		enableGPS = 0;

		driverOpticsModel = "\ca\weapons\optika_empty";
		
		class ViewPilot: ViewPilot
		{
			initFov = 1.2;
			minFov = 0.5;
			maxFov = 1.2;
			initAngleX = 0;
			minAngleX = -80;
			maxAngleX = 80;
			initAngleY = 30;
			minAngleY = -110;
			maxAngleY = 110;
		};

		driverAction = "HangGlider_Pilot";
		driverInAction = "HangGlider_Pilot";
		getInAction = "";
		getOutAction = "";
		
		cabinOpening = 1;
		occludeSoundsWhenIn = 1.0;
		obstructSoundsWhenIn = 1.0;
		
		class Turrets {};
		class Reflectors {};
		class Armory
		{
			disabled = 1;
		};
		
		gearRetracting = 0;
		flaps = 0;
		envelope[] = { 0.10, 0.20, 0.5, 0.9, 1.0, 1.5, 2.0, 2.5, 2.5, 3.0, 2.5, 2.5, 2.0, 1.75, 1.75, 1.75, 1.75, 1.5, 1.25, 1.0 };
		
		maxSpeed = 200;
		aileronSensitivity = 0.5;
		elevatorSensitivity = 0.05;
		wheelSteeringSensitivity = 0.001;
		noseDownCoef = 0.1;
		ejectDeadDriver = false;
		ejectSpeed[] = {0,0,0};		
	};
	
	class FLAY_HangGlider_Bag: Static
	{
		scope = 1;
		displayName = "FLAY HangGlider Bag";
		model = "FLAY\FLAY_HangGlider\FLAY_HangGlider_Bag.p3d";
		vehicleClass = "Misc";
	};
	
	class FLAY_ArrowDnHelper: Static
	{
		scope = 1;
		displayName = "FLAY Arrow Down Helper";
		model = "FLAY\FLAY_HangGlider\FLAY_ArrowDnHelper.p3d";
		vehicleClass = "Misc";
		class AnimationSources
		{
			class RY
			{
				source = "user";
				animPeriod = 5;
				initPhase = "0";
			};
		};
	};
	
	class FLAY_ArrowUpHelper: Static
	{
		scope = 1;
		displayName = "FLAY Arrow Up Helper";
		model = "FLAY\FLAY_HangGlider\FLAY_ArrowUpHelper.p3d";
		vehicleClass = "Misc";
		class AnimationSources
		{
			class RY
			{
				source = "user";
				animPeriod = 5;
				initPhase = "0";
			};
		};
	};
	
	class Sound;
	class Sound_VarioDn01: Sound
	{
		scope = 2;
		sound = "FLAY_VarioDn01Sfx";
		displayName = "VarioDn01";
	};
	class Sound_Silence: Sound
	{
		scope = 2;
		sound = "FLAY_SilenceSfx";
		displayName = "Silence";
	};	
	class Sound_VarioUp01: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp01Sfx";
		displayName = "VarioUp01";
	};	
	class Sound_VarioUp02: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp02Sfx";
		displayName = "VarioUp02";
	};	
	class Sound_VarioUp03: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp03Sfx";
		displayName = "VarioUp03";
	};	
	class Sound_VarioUp04: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp04Sfx";
		displayName = "VarioUp04";
	};
	class Sound_VarioUp05: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp05Sfx";
		displayName = "VarioUp05";
	};	
	class Sound_VarioUp06: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp06Sfx";
		displayName = "VarioUp06";
	};	
	class Sound_VarioUp07: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp07Sfx";
		displayName = "VarioUp07";
	};	
	class Sound_VarioUp08: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp08Sfx";
		displayName = "VarioUp08";
	};	
	class Sound_VarioUp09: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp09Sfx";
		displayName = "VarioUp09";
	};
	class Sound_VarioUp10: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp10Sfx";
		displayName = "VarioUp10";
	};
	class Sound_VarioUp11: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp11Sfx";
		displayName = "VarioUp11";
	};
	class Sound_VarioUp12: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp12Sfx";
		displayName = "VarioUp12";
	};
	class Sound_VarioUp13: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp13Sfx";
		displayName = "VarioUp13";
	};
	class Sound_VarioUp14: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp14Sfx";
		displayName = "VarioUp14";
	};
	class Sound_VarioUp15: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp15Sfx";
		displayName = "VarioUp15";
	};
	class Sound_VarioUp16: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp16Sfx";
		displayName = "VarioUp16";
	};
	class Sound_VarioUp17: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp17Sfx";
		displayName = "VarioUp17";
	};
	class Sound_VarioUp18: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp18Sfx";
		displayName = "VarioUp18";
	};
	class Sound_VarioUp19: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp19Sfx";
		displayName = "VarioUp19";
	};
	class Sound_VarioUp20: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp20Sfx";
		displayName = "VarioUp20";
	};
	class Sound_VarioUp21: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp21Sfx";
		displayName = "VarioUp21";
	};
	class Sound_VarioUp22: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp22Sfx";
		displayName = "VarioUp22";
	};
	class Sound_VarioUp23: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp23Sfx";
		displayName = "VarioUp23";
	};
	class Sound_VarioUp24: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp24Sfx";
		displayName = "VarioUp24";
	};
	class Sound_VarioUp25: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp25Sfx";
		displayName = "VarioUp25";
	};
	class Sound_VarioUp26: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp26Sfx";
		displayName = "VarioUp26";
	};
	class Sound_VarioUp27: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp27Sfx";
		displayName = "VarioUp27";
	};
	class Sound_VarioUp28: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp28Sfx";
		displayName = "VarioUp28";
	};
	class Sound_VarioUp29: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp29Sfx";
		displayName = "VarioUp29";
	};	
	class Sound_VarioUp30: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp30Sfx";
		displayName = "VarioUp30";
	};	
	class Sound_VarioUp31: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp31Sfx";
		displayName = "VarioUp31";
	};	
	class Sound_VarioUp32: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp32Sfx";
		displayName = "VarioUp32";
	};	
	class Sound_VarioUp33: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp33Sfx";
		displayName = "VarioUp33";
	};	
	class Sound_VarioUp34: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp34Sfx";
		displayName = "VarioUp34";
	};
	class Sound_VarioUp35: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp35Sfx";
		displayName = "VarioUp35";
	};	
	class Sound_VarioUp36: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp36Sfx";
		displayName = "VarioUp36";
	};	
	class Sound_VarioUp37: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp37Sfx";
		displayName = "VarioUp37";
	};	
	class Sound_VarioUp38: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp38Sfx";
		displayName = "VarioUp38";
	};	
	class Sound_VarioUp39: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp39Sfx";
		displayName = "VarioUp39";
	};
	class Sound_VarioUp40: Sound
	{
		scope = 2;
		sound = "FLAY_VarioUp40Sfx";
		displayName = "VarioUp40";
	};
	
};

// ===========================================================================
// WEAPONS
// ===========================================================================


class cfgWeapons
{
    class Default;
	class Rifle;
	class LauncherCore;
	class RocketPods: LauncherCore {};	
	class HangGliderBombs: RocketPods
	{
		scope = 1;
		displayName = "Bombs";
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "Vehicle_Grenade_W";
		cursorSize = 1;
		autoFire = 0;
		sound[] = {"",10.0,1};
		magazines[] = {"6Rnd_Grenade_HangGlider","2Rnd_Bomb_HangGlider","4Rnd_Bomb_HangGlider"};
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
	class MGun;	
	class M134: MGun
	{
		class LowROF {};
	};
	class HangGliderM134: M134
	{
	    modes[] = {"LowROF"};
		class LowROF: LowROF
		{
			reloadTime = 0.015;
			dispersion = 0.025;
			minRange = 1;
			minRangeProbab = 0.09;
			midRange = 2;
			midRangeProbab = 0.058;
			maxRange = 3;
			maxRangeProbab = 0.004;
		};
	};
	class M60A4_EP1: Rifle {
		class manual;
	};	
	class HangGliderM60A4: M60A4_EP1
	{
		cursor = "Air_W_MG";
		cursorAim = "Air_Dot";
		cursorSize = 1;
		showAimCursorInternal = 1;	
		magazines[] = {"400Rnd_762x51_M240_HangGlider","100Rnd_762x51_M240"};
	    modes[] = {"manual"};
		class manual: manual
		{
			dispersion = 0.020;
			//dispersion = 0.0008;
			reloadTime = 0.06;
		};
	};
	/*
	class Binocular;
	class Binocular_Vector: Binocular
	{
		displayName = "$STR_EP1_DN_cfgWeapons_Binocular_Vector";
		visionMode[] = {"Normal","NVG"};
		modelOptics = "\ca\weapons_E\optics_vector.p3d";
		opticsZoomInit = 0.0293;
		opticsZoomMin = 0.0293;
		opticsZoomMax = 0.0293;
		weaponInfoType = "RscWeaponRangeFinder";
		model = "\ca\weapons_E\vector\vector21dt";
		Picture = "\CA\weapons_E\Data\icons\bino_vector_CA.paa";
	};
	class Laserdesignator: Binocular
	{
		weaponInfoType = "RscWeaponRangeFinder";
		visionMode[] = {"Normal","NVG","TI"};
		thermalMode[] = {0,1};
	};
	*/
};


// ===========================================================================
// MAGAZINES
// ===========================================================================


class CfgMagazines
{
	class Default;
	class CA_Magazine: Default {};
	class 100Rnd_762x51_M240: CA_Magazine {};
	class VehicleMagazine: CA_Magazine {};
	class 400Rnd_762x51_M240_HangGlider: 100Rnd_762x51_M240
	{
		scope = 2;
		displayName = "400 Rnd M240";
		count = 400;
		//ammo = "B_762x51_Ball";
		//tracersEvery = 4;
		//lastRoundsTracer = 4;
	};	
	class 6Rnd_Grenade_HangGlider: VehicleMagazine
	{
		scope = 2;
		displayName = "Bomb";
		ammo = "G_HangGlider_HE";
		count = 4;
		initSpeed = 1;
		maxLeadSpeed = 200;
		nameSound = "grenade";
	};
	class 2Rnd_Bomb_HangGlider: VehicleMagazine
	{
		scope = 2;
		displayName = "Bomb";
		ammo = "Bo_HangGlider_50";
		count = 2;
		initSpeed = 1;
		maxLeadSpeed = 200;
		nameSound = "grenade";
	};
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
};


// ===========================================================================
// AMMO
// ===========================================================================


class CfgAmmo
{
    class Default;
	class BulletBase;
	class RocketCore {};
	class BombCore {};
    class G_Camel_HE: RocketCore {};
	class B_545x39_Ball_HangGlider: BulletBase
	{
		hit = 8;
		indirectHit = 0;
		indirectHitRange = 0;
		cost = 1;
		airFriction = -0.001412;
		caliber = 0.5;
		model = "\ca\Weapons\Data\bullettracer\tracer_green";
		tracerScale = 2;
		tracerStartTime = 0.05;
		tracerEndTime = 2;
		nvgOnly = 0;
	};	
	class G_HangGlider_HE: G_Camel_HE
	{
		model = "\ca\Weapons\granat";
		hit = 20;
		indirectHit = 12;
		indirectHitRange = 5;
		visibleFire = 18;
		audibleFire = 18;
		explosive = 1;
		cost = 10;
		initTime = 0;
		thrustTime = 0.01;
		thrust = 0.01;
		whistleDist = 10;
	};
	class Bo_HangGlider_50: BombCore
	{
		hit = 100;
		indirectHit = 20;
		indirectHitRange = 10;
		visibleFire = 28;
		audibleFire = 28;		
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
		soundHit[] = {"Ca\sounds\Weapons\explosions\explosion_large1",28.183832,1,1900};
		model = "\ca\Weapons\granat";
		proxyShape = "\ca\Weapons\granat";
		CraterEffects = "HERocketCrater";
		explosionEffects = "HERocketExplosion";
		whistleDist = 24;
	};
};


// ===========================================================================
// MOVES
// ===========================================================================


class CfgMovesBasic
{
	class DefaultDie;
	class NoActions;
	class Crew;
	class ManActions
	{
		HangGlider_Pilot = "HangGlider_Pilot";
		HangGlider_PilotWpn = "HangGlider_PilotWpn";
		HangGlider_PilotLand = "HangGlider_PilotLand";
		HangGlider_PilotWlk = "HangGlider_PilotWlk";
		WingSuit_Pilot = "WingSuit_Pilot";
		CarryHangGliderGesture[] = {"CarryHangGlider","Gesture"};
		ResetGesture[] = {"ResetGesture","Gesture"};
	};
};

class CfgMovesMaleSdr: CfgMovesBasic
{
	class Default;
	class States
	{
		class Crew;
		class HangGlider_Dead: DefaultDie
		{
			actions = "DeadActions";
			file = "\ca\air\Data\Anim\KIA_Para_Pilot.rtm";
			speed = 0.5;
			looped = 0;
			terminal = 1;
			soundEnabled = 0;
			connectTo[] = {"DeadState",0.1};
		};
		class HangGlider_Pilot: Crew
		{
			actions = "RifleLowStandActions";
			file = "\FLAY\FLAY_HangGlider\anims\HangGlider_Pilot.rtm";
			speed = 0.6;
			soundEnabled = 0;
			ConnectTo[] = {};			
			interpolateTo[] = {"HangGlider_Dead",1,"HangGlider_PilotWpn",0.1,"HangGlider_PilotLand",0.1"HangGlider_PilotWpn",0.1};
		};
		class HangGlider_PilotWpn: HangGlider_Pilot
		{
			file = "\FLAY\FLAY_HangGlider\anims\HangGlider_PilotWpn.rtm";
			interpolateTo[] = {"HangGlider_Dead",1,"HangGlider_Pilot",0.1,"HangGlider_PilotLand",0.1"HangGlider_PilotWpn",0.1};
		};		
		class HangGlider_PilotLand: Crew
		{
			file = "\FLAY\FLAY_HangGlider\anims\HangGlider_PilotLand.rtm";
			interpolateTo[] = {"HangGlider_Dead",1,"HangGlider_PilotWpn",0.1,"HangGlider_Pilot",0.1,"HangGlider_PilotWpn",0.1};
		};
		class HangGlider_PilotWlk: Crew
		{
			file = "\FLAY\FLAY_HangGlider\anims\HangGlider_PilotWlk.rtm";
			interpolateTo[] = {"HangGlider_Dead",1,"HangGlider_PilotLand",0.1,"HangGlider_PilotWpn",0.1,"HangGlider_Pilot",0.1};
		};
		class WingSuit_Pilot: Crew
		{
			file = "\FLAY\FLAY_HangGlider\anims\WingSuit_Pilot.rtm";
			interpolateTo[] = {"HangGlider_Dead",1};
		};		
	};
};

class CfgGesturesMale
{

	class Default;
	class States
	{
		class CarryHangGlider: Default
		{
			file = "\FLAY\FLAY_HangGlider\anims\HangGlider_Carry.rtm";
			looped = 0;
			speed = 0;
			mask = "handsWeapon";
			//mask = "upperTorso";
			headBobStrength = 0;
			headBobMode = 0;
			leftHandIKCurve[] = {0};
			rightHandIKCurve[] = {0};			
		};
		class ResetGesture: Default
		{
			file = "";
			looped = 0;
			speed = 1000;
			mask = "BodyFull";
			leftHandIKCurve[] = {0};
			rightHandIKCurve[] = {0};
		};
	};
};


// ===========================================================================
// PARTICLES
// ===========================================================================

// ===========================================================================
// SOUNDS
// ===========================================================================

class CfgSounds
{
	class FLAY_VarioClimb1
	{
		name = "VarioClimb1";
		sound[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario1.ogg",1.0,1.0};
		titles[] = {};
	};
};

class CfgSFX
{
	access = 2;
	class FLAY_VarioSfx
	{
		sounds[] = {"sound3"};
		name = "FLAY_VarioSfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario1.ogg",0.31622776,1,30,0.5,0,2,5};
		sound2[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario2.ogg",0.31622776,1,30,0.4,0,1,10};
		sound3[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario3.ogg",0.31622776,1,30,1,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
	
	class FLAY_VarioDn01Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioDn01Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\varioDn1.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
	
	class FLAY_SilenceSfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_SilenceSfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\silence.ogg",0.31622776,1,1,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp01Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp01Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario1.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};

	class FLAY_VarioUp02Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp02Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario2.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};

	class FLAY_VarioUp03Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp03Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario3.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};

	class FLAY_VarioUp04Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp04Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario4.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};

	class FLAY_VarioUp05Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp05Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario5.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};

	class FLAY_VarioUp06Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp06Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario6.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};

	class FLAY_VarioUp07Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp07Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario7.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};

	class FLAY_VarioUp08Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp08Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario8.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};

	class FLAY_VarioUp09Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp09Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario9.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
	
	class FLAY_VarioUp10Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp10Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario10.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp11Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp11Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario11.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp12Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp12Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario12.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp13Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp13Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario13.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp14Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp14Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario14.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp15Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp15Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario15.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
	
	class FLAY_VarioUp16Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp16Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario16.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp17Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp17Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario17.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp18Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp18Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario18.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp19Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp19Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario19.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp20Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp20Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario20.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp21Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp21Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario21.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp22Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp22Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario22.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp23Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp23Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario23.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp24Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp24Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario24.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
	
	class FLAY_VarioUp25Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp25Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario25.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
	
	class FLAY_VarioUp26Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp26Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario26.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp27Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp27Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario27.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp28Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp28Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario28.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp29Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp29Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario29.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp30Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp30Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario30.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
			
	class FLAY_VarioUp31Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp31Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario31.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
			
	class FLAY_VarioUp32Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp32Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario32.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
			
	class FLAY_VarioUp33Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp33Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario33.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
			
	class FLAY_VarioUp34Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp34Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario34.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
	
	class FLAY_VarioUp35Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp35Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario35.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
	
	class FLAY_VarioUp36Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp36Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario36.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp37Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp37Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario37.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp38Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp38Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario38.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp39Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp39Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario39.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp40Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp40Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario40.ogg",0.31622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
	
	class FLAY_MusicSfx
	{
		sounds[] = {"music1","music2","music3","music4"};
		name = "FLAY_MusicSfx";
		music1[] = {"\FLAY\FLAY_HangGlider\data\music\sample1.ogg",0.0031622776,1,300,1,0,0,0};
		music2[] = {"\FLAY\FLAY_HangGlider\data\music\sample2.ogg",0.0031622776,1,300,1,0,0,0};
		music3[] = {"\FLAY\FLAY_HangGlider\data\music\sample3.ogg",0.0031622776,1,300,1,0,0,0};
		music4[] = {"\FLAY\FLAY_HangGlider\data\music\sample4.ogg",0.0031622776,1,300,1,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
	class FLAY_IntroMusicSfx
	{
		sounds[] = {"music1"};
		name = "FLAY_IntroMusicSfx";
		music1[] = {"\FLAY\FLAY_HangGlider\data\music\intro1.ogg",0.0031622776,1,300,1,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
};

class CfgEnvSounds
{
	//class Rain
	//{
	//	name = "$STR_DN_RAIN";
	//	sound[] = {"\Ca\sounds\Ambient\rain\rain_hard1",0.17782794,1};
	//	soundNight[] = {"\Ca\sounds\Ambient\rain\rain_hard1",0.17782794,1};
	//};
	//class WindNoForestHigh
	//{
	//	name = "$STR_DN_WIND";
	//	sound[] = {"ca\sounds\Ambient\forest\wind-global-2",0.03981072,1};
	//	volume = "(1-forest)*(windy factor[0,1])*(0.1+(hills factor[0,1])*0.9)-(night*0.25)";
	//};
	//class Forest
	//{
	//	name = "$STR_DN_WIND";
	//	sound[] = {"ca\sounds\Ambient\forest\forest-day-2",0.03981072,1};
	//	volume = "forest*(1-night)";
	//	randSamp11[] = {"ca\sounds\Ambient\forest\forest-sfx-9bird",0.1,1,30,0.14,5,8,10};
	//	randSamp10[] = {"ca\sounds\Ambient\forest\forest-sfx-12datel",0.1,30,0.125,10,20,40};
	//	randSamp0[] = {"ca\sounds\Ambient\forest\forest-sfx-5bird",0.12589253,1,30,0.13,4,8,12};
	//	randSamp1[] = {"ca\sounds\Ambient\forest\forest-sfx-6bird",0.12589253,1,30,0.125,4,8,12};
	//	randSamp2[] = {"ca\sounds\Ambient\forest\forest-sfx-7bird",0.12589253,1,30,0.125,4,8,12};
	//	randSamp3[] = {"ca\sounds\Ambient\forest\forest-sfx-8bird",0.12589253,1,30,0.1,4,8,12};
	//	randSamp8[] = {"ca\sounds\Ambient\forest\forest-sfx-10bird-flapping",0.1,1,30,0.04,10,20,40};
	//	randSamp9[] = {"ca\sounds\Ambient\forest\forest-sfx-11holub-flapping",0.1,1,30,0.04,10,20,40};
	//	randSamp4[] = {"ca\sounds\Ambient\forest\forest-sfx-1",0.1,1,30,0.025,4,8,10};
	//	randSamp5[] = {"ca\sounds\Ambient\forest\forest-sfx-2",0.1,1,30,0.025,4,8,10};
	//	randSamp6[] = {"ca\sounds\Ambient\forest\forest-sfx-3",0.1,1,30,0.025,4,8,10};
	//	randSamp7[] = {"ca\sounds\Ambient\forest\forest-sfx-4",0.1,1,30,0.025,4,8,10};
	//	random[] = {"randSamp11","randSamp10","randSamp0","randSamp1","randSamp2","randSamp3","randSamp8","randSamp9","randSamp4","randSamp5","randSamp6","randSamp7"};
	//};
};
