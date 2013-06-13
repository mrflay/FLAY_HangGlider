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
		requiredVersion = 0.1;
		//requiredAddons[] = {"CACharacters","CAData","CASounds","CAUI"};
		requiredAddons[] = {};
	};
};

class DefaultEventhandlers;

class CfgDamageAround
{
	class DamageAroundPole
	{
		radiusRatio = "0.1";
		indirectHit = "1";
	};
};
class CfgDestructPos
{
	class DelayedDestruction
	{
		timeBeforeHiding = "0.2";
		hideDuration = "0.65+lifeTime*0.05";
	};
};


// ===========================================================================
// VEHICLES
// ===========================================================================


class CfgVehicles
{
	class Thing;
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
		scope = 1;
		armor = 5;
		
		
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
		//soundEnviron[] = {"\Ca\sounds\Air\Noises\padak_let",0.31622776,1,80};
		//soundEnviron[] = {"\FLAY\FLAY_Hangglider\data\sfx\padak_let",0.31622776,1,80}; // A3
		soundEnviron[] = {"c:\flay_hangglider\padak_let",0.31622776,1,80}; // A3
		soundGetIn[] = {"\Ca\sounds\Air\Noises\padak_getIN",0.31622776,1,20};
		soundGetOut[] = {"\Ca\sounds\Air\Noises\padak_getIN",0.31622776,1,20};
		soundCrash[] = {"\Ca\sounds\Air\Noises\padak_dopad",0.031622775,0,0};
		soundLandCrash[] = {"\Ca\sounds\Air\Noises\padak_dopad",0.031622775,0,0};
		soundWaterCrash[] = {"\Ca\sounds\Air\Noises\padak_dopadvoda",3.1622777,0,0};

		driverLeftHandAnimName = "pilot_lefthand";
		driverRightHandAnimName = "pilot_righthand";
		driverLeftLegAnimName = "pilot_leftfoot";
		driverRightLegAnimName = "pilot_rightfoot";
		simulation="airplane";
		
		class DestructionEffects {};
		explosionEffects = "NoExplosion";
		CraterEffects = "NoCrater";
		
		destrType = "DestructNo";
		secondaryExplosion = -1;
		crewVulnerable = true;
		
		threat[] = {1,0.900000,0.100000};
		
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
		scope = 2;
	
		class EventHandlers: DefaultEventhandlers
		{
			init = "_scr = _this execVM ""\FLAY\FLAY_HangGlider\scripts\init_HangGlider.sqf"";";
		};

		displayName = "FLAY Hang Glider";
		model = "FLAY\FLAY_HangGlider\FLAY_HangGlider";

		//weapons[] = {};
		//magazines[] = {};	
		
		weapons[] = {"HangGliderBombs"};
		magazines[] = {"4Rnd_Bomb_HangGlider"};
		
		armor = 5;
		accuracy = 0.5;
		camouflage = 2;

		//rightWaterEffect=;
		//leftWaterEffect=;
		//rightDustEffect=
		//leftWaterEffect=
		airFriction0[] = {25,12,2.500000};
		airFriction1[] = {25,12,2.500000};
		airFriction2[] = {25,12,2.500000};
		canFloat = true;
		canBeShot = true;
		damageResistance = 0.000000000001;
		damperSize = 2;
		damperForce = 0.5;
		hideUnitInfo = true;
		hideWeaponsDriver = true;
		selectionFabric = "latka";
		type = 0;
		unitInfoType = "UnitInfoSoldier";
		
		extCameraPosition[] = {0,3.5,-9};
		enableGPS = 1;

		driverAction = "HangGlider_Pilot";
		driverInAction = "HangGlider_Pilot";
		getInAction = "GetInLow";
		getOutAction = "GetOutLow";
		
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
				initPhase = 5;
			};		
			class HarnessAnchorHide
			{
				source = "user";
				animPeriod = 0.000001;
				initPhase = 0;
			};
			class HarnessStrapsHide
			{
				source = "user";
				animPeriod = 0.000001;
				initPhase = 0;
			};			
			class LandingGear
			{
				source = "user";
				animPeriod = 1.5;
				initPhase =  0.15;
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
			class FireGeoPilotHide
			{
				source = "user";
				animPeriod = 0.000001;
				initPhase = 0;
			};		
		};

		class UserActions
		{
			class FLAY_Flytec3040_ON
			{
				displayNameDefault = "Flytec 3040 ON";
				showWindow = 0;
				//hideOnUse = 1;
				displayName = "Flytec 3040 ON";
				position = "action";
				radius = 4.0;
				onlyForPlayer = 1;
				condition = "(alive player) and ('FLAY_Flytec3040_Variometer' in (weapons player) or 'FLAY_Flytec3040_Variometer' in (weapons (vehicle player))) and not (player getVariable ['FLAY.variometer.power.on',false])";
				statement = "[player] execVM '\FLAY\FLAY_HangGlider\scripts\ui_variometer_show.sqf'";
			};
			class FLAY_Flytec3040_OFF
			{
				displayNameDefault = "Flytec 3040 OFF";
				showWindow = 0;
				//hideOnUse = 1;
				displayName = "Flytec 3040 OFF";
				position = "action";
				radius = 4.0;
				onlyForPlayer = 1;
				condition = "(alive player) and ('FLAY_Flytec3040_Variometer' in (weapons player) or 'FLAY_Flytec3040_Variometer' in (weapons (vehicle player))) and (player getVariable ['FLAY.variometer.power.on',false])";
				statement = "[player] execVM '\FLAY\FLAY_HangGlider\scripts\ui_variometer_hide.sqf'";
			};	
			class FLAY_GetIn
			{
				displayNameDefault = "Get In";
				showWindow = 0;
				//hideOnUse = 1;
				displayName = "Get In";
				position = "action";
				radius = 4.0000;
				onlyForPlayer = 1;
				condition = "(alive player) and isNull (driver this)";
				statement = "[this,-1,player] execVM 'FLAY\FLAY_HangGlider\scripts\ev_getIn.sqf'";
			};
			class FLAY_GetOut
			{
				displayNameDefault = "Get Out";
				showWindow = 0;
				//hideOnUse = 1;
				displayName = "Get Out";
				position = "action";
				radius = 4.0000;
				onlyForPlayer = 1;
				condition = "(alive player) and (driver this == player)";
				statement = "[this,'DRIVER',player] execVM 'FLAY\FLAY_HangGlider\scripts\ev_getOut.sqf'";
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

	class FLAY_HangGliderAI: FLAY_HangGlider
	{
		scope = 2;
		displayName = "FLAY Hang Glider (AI)";
		model = "FLAY\FLAY_HangGlider\FLAY_HangGlider2";
		fuelCapacity = 1000;
		maxSpeed = 100;
		landingSpeed = 70;
		landingAoa = "rad -5";
		envelope[] = { 0.1, 0.2, 1.0, 2.0, 3.5, 3.5, 3.5, 3.5, 4.5, 4.5, 4.5, 3.5, 3.5, 2.5, 2.5, 2.5, 2.5, 2.5, 2.5, 2.5 };
		aileronSensitivity = 3.5;
		elevatorSensitivity = 0.1;
		wheelSteeringSensitivity = 2.7;
		noseDownCoef = 0.00000025;
	};
	
	class FLAY_WingSuit: FLAY_GliderBase
	{
		scope = 2;
		displayName = "FLAY Wing Suit";
		model = "FLAY\FLAY_HangGlider\FLAY_WingSuit";
		unitInfoType = "RscUnitInfoNoHUD";
		
		driverAction = "WingSuit_Pilot";
		driverInAction = "WingSuit_Pilot";

		//envelope[] = { 0.10, 0.20, 0.5, 0.9, 1.0, 1.5, 2.0, 2.5, 2.5, 3.0, 2.5, 2.5, 2.0, 1.75, 1.75, 1.75, 1.75, 1.5, 1.25, 1.0 };
		envelope[] = { 0.20, 0.30, 0.6, 1.0, 1.1, 1.5, 2.0, 2.5, 2.5, 3.0, 2.5, 2.5, 2.0, 1.75, 1.75, 1.75, 1.75, 1.5, 1.25, 1.0 };

		maxSpeed = 300;
		aileronSensitivity = 0.6;
		elevatorSensitivity = 0.06;
		wheelSteeringSensitivity = 0.002;
		noseDownCoef = -0.2;
	};
	
	class FLAY_Parachute: FLAY_GliderBase
	{
		scope = 2;
		displayName = "FLAY Parachute";
		model = "FLAY\FLAY_HangGlider\FLAY_Parachute";
		unitInfoType = "RscUnitInfoNoHUD";
		
		driverAction = "HangGlider_PilotLand";
		driverInAction = "HangGlider_PilotLand";
		simulation="airplane";

		class EventHandlers{};
		class ViewPilot: ViewPilot
		{
			initFov = 0.95;
			minFov = 0.95;
			maxFov = 0.95;
			initAngleX = 0;
			minAngleX = -70;
			maxAngleX = 70;
			initAngleY = 0;
			minAngleY = -110;
			maxAngleY = 110;
		};

		occludeSoundsWhenIn = 1.0;
		obstructSoundsWhenIn = 1.0;
		envelope[] = {0.9,0.9,0.9,0.9,0.9,0.9,0.9,0.9,0.9,0.9,0.9,0.9,0.9,0.9,0.9,0.9,0.9};
		maxSpeed = 1;
		landingSpeed = 1;

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

	class B_AssaultPack_blk;
	class FLAY_HangGlider_Bag: B_AssaultPack_blk
	{
		scope = 2;
		displayName = "Hang Glider Kit";
		descriptionShort = "Hang Glider Kit";
	};
		
	class FLAY_3DAxis10m: Thing
	{
		scope = 1;
		displayName = "FLAY 3D Axis 10m";
		model = "FLAY\FLAY_HangGlider\FLAY_3DAxis10m.p3d";
		vehicleClass = "Misc";
		class AnimationSources
		{
			class RX
			{
				source = "user";
				animPeriod = 0.0001;
				initPhase = "0";
			};
			class RY
			{
				source = "user";
				animPeriod = 0.0001;
				initPhase = "0";
			};
			class RZ
			{
				source = "user";
				animPeriod = 0.0001;
				initPhase = "0";
			};			
		};
	};
	
	class FLAY_ArrowFwdGreen: Thing
	{
		scope = 2;
		displayName = "FLAY Arrow Green";
		model = "FLAY\FLAY_HangGlider\FLAY_ArrowFwGreen.p3d";
		vehicleClass = "Misc";
		animated = 1;
	};	
	
	class FLAY_Thermal: Static
	{
		scope = 2;
		displayName = "FLAY Thermal";
		model = "FLAY\FLAY_HangGlider\FLAY_Thermal.p3d";
		vehicleClass = "Misc";
		animated=1;
		class EventHandlers: DefaultEventhandlers
		{
			init = "_scr = _this execVM '\FLAY\FLAY_HangGlider\scripts\init_Thermal.sqf';";
		};
		class AnimationSources
		{
			class SizeArrowRed
			{
				source = "user";
				animPeriod = 0.0001;
				initPhase = 0;
			};
			class SizeArrowBlue 
			{
				source = "user";
				animPeriod = 0.0001;
				initPhase = 0;			
			};
			class HideArrow
			{
				source = "user";
				animPeriod = 0.0001;
				initPhase = 0;
			};
			class HideArrowRed
			{
				source = "user";
				animPeriod = 0.0001;
				initPhase = 1;
			};
			class HideArrowBlue
			{
				source = "user";
				animPeriod = 0.0001;
				initPhase = 1;
			};		
		};		
	};
	
	class FLAY_Ridge: Static
	{
		scope = 2;
		displayName = "FLAY Ridge";
		model = "FLAY\FLAY_HangGlider\FLAY_Thermal.p3d";
		vehicleClass = "Misc";
		animated=1;
		class AnimationSources
		{
			class SizeArrowRed
			{
				source = "user";
				animPeriod = 0.0001;
				initPhase = 0;
			};
			class SizeArrowBlue 
			{
				source = "user";
				animPeriod = 0.0001;
				initPhase = 0;			
			};
			class HideArrow
			{
				source = "user";
				animPeriod = 0.0001;
				initPhase = 0;
			};
			class HideArrowRed
			{
				source = "user";
				animPeriod = 0.0001;
				initPhase = 0;
			};
			class HideArrowBlue
			{
				source = "user";
				animPeriod = 0.0001;
				initPhase = 0;
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
	class ItemCore;
	class FLAY_Flytec3040_Variometer: ItemCore
	{
		scope=2;
		displayName="Flytec 3040";
		picture="\FLAY\FLAY_HangGlider\data\img\item_vario.paa";
		descriptionShort="Visual and acoustic vario display with adjustable sink alarm tone.";
		class ItemInfo
		{
			mass = 1;
		};		
	};	
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
		magazines[] = {"4Rnd_Bomb_HangGlider"};
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
		HangGlider_PilotSwoop = "HangGlider_PilotSwoop";
		WingSuit_Pilot = "WingSuit_Pilot";
		CarryHangGliderGesture[] = {"CarryHangGlider","Gesture"};
		HangGliderSwoopGesture[] = {"HangGliderSwoopGesture","Gesture"};
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
			//actions = "RifleLowStandActions";
			file = "\FLAY\FLAY_HangGlider\anims\HangGlider_Pilot.rtm";
			speed = 0.6;
			soundEnabled = 1;
			disableWeapons = 1;
			interpolationSpeed = 1;
			ConnectTo[] = {};			
			interpolateTo[] = {"HangGlider_Dead",1,"HangGlider_PilotWpn",0.1,"HangGlider_PilotLand",0.1"HangGlider_PilotWlk",0.1};
			leftHandIKCurve[] = {1};
			rightHandIKCurve[] = {1};
		};
		class HangGlider_PilotWpn: HangGlider_Pilot
		{
			file = "\FLAY\FLAY_HangGlider\anims\HangGlider_PilotWpn.rtm";
			interpolateTo[] = {"HangGlider_Dead",1,"HangGlider_Pilot",0.1,"HangGlider_PilotLand",0.1"HangGlider_PilotWlk",0.1};
			rightHandIKCurve[] = {0};
			disableWeapons = 0;
			canPullTrigger = 1;
		};		
		class HangGlider_PilotLand: HangGlider_Pilot
		{
			file = "\FLAY\FLAY_HangGlider\anims\HangGlider_PilotLand.rtm";
			interpolateTo[] = {"HangGlider_Dead",1,"HangGlider_PilotWpn",0.1,"HangGlider_Pilot",0.1,"HangGlider_PilotWlk",0.1};
		};
		class HangGlider_PilotWlk: HangGlider_Pilot
		{
			//file = "\FLAY\FLAY_HangGlider\anims\HangGlider_PilotWlk.rtm";
			interpolateTo[] = {"HangGlider_Dead",1,"HangGlider_PilotLand",0.1,"HangGlider_PilotWpn",0.1,"HangGlider_Pilot",0.1};
			leftHandIKCurve[] = {1};
			rightHandIKCurve[] = {1};
		};
		class HangGlider_PilotSwoop: HangGlider_Pilot
		{
			file = "\FLAY\FLAY_HangGlider\anims\HangGlider_PilotSwoop.rtm";
			speed = 0.5;
			interpolationSpeed = 0.5;
			interpolateTo[] = {"HangGlider_Dead",1,"HangGlider_PilotLand",0.05,"HangGlider_PilotWpn",0.05,"HangGlider_Pilot",0.05};
			interpolateFrom[] = {"HangGlider_PilotLand",0.05,"HangGlider_PilotWpn",0.05,"HangGlider_Pilot",0.05};
			leftHandIKCurve[] = {1};
			rightHandIKCurve[] = {1};
		};		
		class WingSuit_Pilot: HangGlider_Pilot
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
			headBobStrength = 0;
			headBobMode = 0;
			leftHandIKCurve[] = {1};
			rightHandIKCurve[] = {1};
		};
		class HangGliderSwoopGesture: Default
		{
			file = "\FLAY\FLAY_HangGlider\anims\HangGlider_PilotSwoop.rtm";
			looped = 1;
			speed = 2;
			mask = "legs";
			leftHandIKCurve[] = {1};
			rightHandIKCurve[] = {1};
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
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\varioDn1.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
	
	class FLAY_SilenceSfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_SilenceSfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\silence.ogg",0.61622776,1,1,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp01Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp01Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario1.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};

	class FLAY_VarioUp02Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp02Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario2.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};

	class FLAY_VarioUp03Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp03Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario3.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};

	class FLAY_VarioUp04Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp04Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario4.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};

	class FLAY_VarioUp05Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp05Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario5.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};

	class FLAY_VarioUp06Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp06Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario6.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};

	class FLAY_VarioUp07Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp07Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario7.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};

	class FLAY_VarioUp08Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp08Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario8.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};

	class FLAY_VarioUp09Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp09Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario9.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
	
	class FLAY_VarioUp10Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp10Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario10.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp11Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp11Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario11.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp12Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp12Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario12.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp13Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp13Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario13.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp14Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp14Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario14.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp15Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp15Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario15.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
	
	class FLAY_VarioUp16Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp16Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario16.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp17Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp17Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario17.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp18Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp18Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario18.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp19Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp19Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario19.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp20Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp20Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario20.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp21Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp21Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario21.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp22Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp22Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario22.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp23Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp23Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario23.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp24Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp24Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario24.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
	
	class FLAY_VarioUp25Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp25Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario25.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
	
	class FLAY_VarioUp26Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp26Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario26.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp27Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp27Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario27.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp28Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp28Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario28.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp29Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp29Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario29.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp30Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp30Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario30.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
			
	class FLAY_VarioUp31Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp31Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario31.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
			
	class FLAY_VarioUp32Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp32Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario32.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
			
	class FLAY_VarioUp33Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp33Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario33.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
			
	class FLAY_VarioUp34Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp34Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario34.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
	
	class FLAY_VarioUp35Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp35Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario35.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
	
	class FLAY_VarioUp36Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp36Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario36.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp37Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp37Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario37.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp38Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp38Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario38.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
		
	class FLAY_VarioUp39Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp39Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario39.ogg",0.61622776,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};	
	
	class FLAY_VarioUp40Sfx
	{
		sounds[] = {"sound1"};
		name = "FLAY_VarioUp40Sfx";
		sound1[] = {"\FLAY\FLAY_HangGlider\data\sfx\vario40.ogg",0.61622776,1,300,1.0,0,0,0};
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


// ===========================================================================
// DIALOGS
// ===========================================================================



// hide the landing auto pilot and eject actions from the menu
class CfgActions
{
	class None
	{
		//picture = ; //Path to texture shown as an action image.
		priority = 0; //Base priority.
		show = true; //If set to false, action will not be displayed in the actions menu (but still accessible through shortcut).
		showWindow = false; //Action is displayed as a default action.
		hideOnUse = true; //Action menu is hidden when this action is processed.
		shortcut = ""; //Name of input action used as a shortcut (see class ControllerSchemes for list of input actions).
		text = ""; //Structured parametrized text, shown in the actions menu.
		textDefault = ""; //Structured parametrized text, shown as a default action; if empty, "text" is used instead.
		textSimple = ""; //Raw parametrized text, used in radio protocol for example; if empty, "text" is used instead.
	};
	class Hidden: None
	{
		show = false;
	};
	class Land: Hidden {};
	class Eject: Hidden {};
	class GetOut: Hidden {};
};