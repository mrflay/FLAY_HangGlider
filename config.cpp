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
		soundCrash[] = {"\Ca\sounds\Air\Noises\padak_dopad",0.031622775,0,0};
		soundLandCrash[] = {"\Ca\sounds\Air\Noises\padak_dopad",0.031622775,0,0};
		soundWaterCrash[] = {"\Ca\sounds\Air\Noises\padak_dopadvoda",3.1622777,0,0};

		class DestructionEffects
		{
			class DamageAround1
			{
				simulation = "damageAround";
				type = "DamageAroundPole";
				position = "";
				intensity = 1;
				interval = 1;
				lifeTime = 1;
			};
			class Smoke1
			{
				simulation = "particles";
				type = "BarelDestructionSmoke";
				position = "destructionEffect1";
				intensity = 0.15;
				interval = 1;
				lifeTime = 3.2;
			};			
		};
		
		//destrType = "DestructNo";
		//secondaryExplosion = 0;
		
		//threat[] = {0.0,0.0,0.0};
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
		
		driverCanSee = "2"; // crosshair / no compass
		extCameraPosition[] = {0,1,-3};

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
			init = "_scr = _this execVM ""\FLAY\FLAY_HangGlider\scripts\init_HangGlider.sqf"";";
		};

		displayName = "FLAY Hang Glider";
		model = "FLAY\FLAY_HangGlider\FLAY_HangGlider";

		//weapons[] = {"BikeHorn"};
		weapons[] = {};
		magazines[] = {};	
		armor = 5000;
		accuracy = 0.5;
		camouflage = 2;

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

		class UserActions
		{
			class FLAY_Flytec3040_ON
			{
				displayNameDefault = "Flytec 3040 ON";
				showWindow = 0;
				//hideOnUse = 1;
				displayName = "Flytec 3040 ON";
				position = "action";
				radius = 0.5000;
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
				radius = 0.5000;
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
				position = "camera";
				radius = 3.0000;
				onlyForPlayer = 1;
				condition = "(alive player) and isNull (driver this)";
				statement = "[this,-1,player] execVM 'FLAY\FLAY_HangGlider\scripts\ev_getIn.sqf'";
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
	
	class FLAY_HangGlider4: FLAY_HangGlider
	{
		displayName = "FLAY Hang Glider 4";
		model = "FLAY\FLAY_HangGlider\FLAY_HangGlider4";
	};

	class FLAY_HangGlider5: FLAY_HangGlider
	{
		displayName = "FLAY Hang Glider 5";
		model = "FLAY\FLAY_HangGlider\FLAY_HangGlider5";
	};
	
	class FLAY_HangGlider6: FLAY_HangGlider
	{
		displayName = "FLAY Hang Glider 6";
		model = "FLAY\FLAY_HangGlider\FLAY_HangGlider6";
	};

	class FLAY_HangGlider7: FLAY_HangGlider
	{
		displayName = "FLAY Hang Glider 7";
		model = "FLAY\FLAY_HangGlider\FLAY_HangGlider7";
	};
	
	class FLAY_HangGlider8: FLAY_HangGlider
	{
		displayName = "FLAY Hang Glider 8";
		model = "FLAY\FLAY_HangGlider\FLAY_HangGlider8";
	};

	class FLAY_HangGlider9: FLAY_HangGlider
	{
		displayName = "FLAY Hang Glider 9";
		model = "FLAY\FLAY_HangGlider\FLAY_HangGlider9";
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
		model = "FLAY\FLAY_HangGlider\FLAY_HangGlider8";
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
	
	class FLAY_HangGlider_Bag: Thing
	{
		class EventHandlers: DefaultEventhandlers
		{
			init = "_scr = _this execVM ""\FLAY\FLAY_HangGlider\scripts\init_HangGliderBag.sqf"";";
		};	
		scope = 1;
		displayName = "FLAY HangGlider Bag";
		model = "FLAY\FLAY_HangGlider\FLAY_HangGlider_Bag.p3d";
		vehicleClass = "Misc";
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

	class Man;
	class CaManbase: Man
	{
		class UserActions
		{
			class FLAY_Flytec3040_ON
			{
				displayNameDefault = "Flytec 3040 ON";
				showWindow = 0;
				//hideOnUse = 1;
				displayName = "Flytec 3040 ON";
				position = "action";
				radius = 3.0000;
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
				radius = 3.0000;
				onlyForPlayer = 1;
				condition = "(alive player) and ('FLAY_Flytec3040_Variometer' in (weapons player) or 'FLAY_Flytec3040_Variometer' in (weapons (vehicle player))) and (player getVariable ['FLAY.variometer.power.on',false])";
				statement = "[player] execVM '\FLAY\FLAY_HangGlider\scripts\ui_variometer_hide.sqf'";
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
	class ItemCore: Default {};
	class FLAY_Flytec3040_Variometer: ItemCore
	{
		scope=2;
		displayName="Flytec 3040";
		picture="\FLAY\FLAY_HangGlider\data\img\item_vario.paa";
		descriptionShort="Visual and acoustic vario display with adjustable sink alarm tone.";
	};	
	class RocketPods;
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
	class Rifle;
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
	
	class Launcher;
	class FLAY_HangGlider_BagLauncher: Launcher
	{
		scope = 2;
		displayName = "FLAY Hang Glider Bag";
		model = "FLAY\FLAY_HangGlider\FLAY_HangGlider_Bag.p3d";
		cursorAim = "\ca\Weapons\Data\clear_empty";
		cursor = "\ca\Weapons\Data\clear_empty";
		handAnim[] = {"OFP2_ManSkeleton","\Ca\weapons\Data\Anim\m136.rtm"};
		modelOptics = "-";
		magazines[] = {"M136"};
		sound[] = {"",10.0,1,1400};
		drySound[] = {"",0.0001,1,10};
		reloadMagazineSound[] = {"",0.00031622776,1,20};
		soundFly[] = {"",100.0,1.5,700};
		picture = "\CA\weapons\data\equip\W_m136_launcher_CA.paa";
		UiPicture = "\CA\weapons\data\Ico\i_at_CA.paa";
		recoil = "launcherBase";
		minRange = 0;
		midRange = 0;
		maxRange = 0;
		aiRateOfFire = 0;
		aiRateOfFireDistance = 0;
		class Library
		{
			libTextDesc = "$STR_LIB_M136";
		};
		descriptionShort = "$STR_DSS_M136";
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

// ===========================================================================
// DIALOGS
// ===========================================================================
	
class RscButton;
class RscActiveText
{
	access = 0;
	type = 11;
	style = 2;
	color[] = { 0, 0, 0, 1 };
	colorActive[] = { 0.3, 0.4, 0, 1 };
	soundEnter[] = { "", 0.1, 1 };
	soundPush[] = { "", 0.1, 1 };
	soundClick[] = { "", 0.1, 1 };
	soundEscape[] = { "", 0.1, 1 };
	text = "";
	default = 0;
	idc = -1;
	x = 0;
	y = 0;
	h = 0.035;
	w = 0.035;
	font = "Zeppelin32";
	sizeEx = 0.03921;
	colortext[] = { 0, 0, 0, 1 };
};

class Test
{
	idd = 3000; // hmm
	enableSimulation=1;
	movingEnable=0;
	class Controls {
		class foo : RscActiveText {
			idc = 3001;
			style = 48;
			x = -1;
			y = -1;
			w = 3;
			h = 3;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			color[] = {0, 0, 0, 0};
			colorActive[] = {0, 0, 0, 0};
			onMouseMoving = "hintSilent format ['%1\n%2',_this select 1, _this select 2];";
			//onMouseButtonClick = "player sidechat 'button clicked foo'"; 
		};
		class uiButton : RscActiveText {
			idc = 3002;
			style = 48;
			x = safezoneX + 0.01;
			y = safezoneY + safezoneH - 0.7 * 4 / 3;
			w = .4;
			h = .7 * 4/3;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			color[] = {1, 1, 1, 0.0};
			colorActive[] = {1, 1, 1, 0.2};
			onMouseButtonClick = "player sidechat 'button clicked bar'"; 
		};
	};
};


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
	class Land: None
	{
		priority = 0.9;
		text = "asd";
		textDefault = "asd";
		show = false;
	};
	class Eject: None
	{
		priority = 0.05;
		//No parameters.
		show = false;
		shortcut = "Eject";
		text = $STR_ACTION_EJECT;
		textDefault = $STR_ACTION_EJECT;
	};	
	class GetOut: None
	{
		priority = 0.9;
		showWindow = true;
		shortcut = "GetOut";
		//No parameters.
		text = "$STR_ACTION_GETOUT";
		textDefault = "$STR_ACTION_GETOUT";
	};
};

class CfgWrapperUI
{
	class Cursors
	{
		class Pointer
		{
			texture = "\FLAY\FLAY_HangGlider\data\cursors\pointer_ca.paa";
			width = 32;
			height = 32;
			hotspotX = 0.5;
			hotspotY = 0.5;
		};
	};
};













/*

class RscText;
class RscStructuredText;
class RscProgress;
//class RscActiveText;
class RscPicture;
class CfgInGameUI
{
	colorBackground[] = {0.96,0.96,0.94,0.1};
	colorText[] = {1,1,1,1};
	colorBackgroundCommand[] = {0.96,0.96,0.94,0.1};
	colorBackgroundHelp[] = {0.96,0.96,0.94,0.1};
	class SideColors
	{
		colorFriendly[] = {0.0,0.7,0.0,1};
		colorEnemy[] = {0.2,0.0,0.0,1};
		colorNeutral[] = {0.8,0.8,0.8,1};
		colorCivilian[] = {0.8,0.8,0.8,1};
		colorUnknown[] = {0.8,0.6,0.0,1};
	};
	class Capture
	{
		colorBackground[] = {0.07,0.24,0.47,0};
		colorText[] = {0.96,0.96,0.94,0.1};
		colorLine[] = {0.9,0,0,0};
	};
	class TacticalDisplay: SideColors
	{
		colorCamera[] = {1,1,0.95,0.4};
	};
	class Compass
	{
		color[] = {1,1,1,0.75};
		dirColor[] = {1,1,1,0.75};
	};
	class Menu
	{
		colorChecked[] = {1,1,1,1};
		colorEnabled[] = {0.46,0.46,0.44,1};
		colorDisabled[] = {0.5,0.5,0.5,0};
		colorSelected[] = {0.07,0.24,0.47,0};
		colorSelectedText[] = {0.95,0.95,0.95,0};
	};
	class GroupDir
	{
		colorBackground[] = {0.96,0.96,0.94,0.1};
	};
	class PlayerInfo
	{
		colorBackground[] = {0.96,0.96,0.94,0.1};
	};
	class Bar
	{
		colorBackground[] = {0.96,0.96,0.94,0.1};
		colorGreen[] = {0.6,0.8392,0.4706,1.0};
		colorYellow[] = {0.6,0.8392,0.4706,1.0};
		colorRed[] = {0.706,0.0745,0.0196,1};
		colorBlinkOn[] = {0.863,0.584,0.0,1};
		colorBlinkOff[] = {0.706,0.0745,0.0196,1};
	};
	class Actions
	{
		colorText[] = {0.46,0.46,0.44,1};
		colorBackground[] = {0.96,0.96,0.94,0.1};
		colorSelect[] = {1,1,1,1};
		colorBackgroundSelected[] = {0,0,0,0};
		dimmStartTime = 2;
		dimmEndTime = 8;
		hideTime = 5;
	};
	class DefaultAction
	{
		colorBackground[] = {1,0,0,1};
	};
	class PeripheralVision
	{
		cueColor[] = {1,1,1,1};
		cueEnemyColor[] = {1,1,1,1};
		cueFriendlyColor[] = {1,1,1,1};
	};
};
class RscIGText: RscText
{
	colorText[] = {1,1,1,1};
};
class RscIGProgress;
class RscInGameUI
{
	colorReady[] = {1,1,1,1};
	colorPrepare[] = {0.57,0.28,0.0,1.0};
	colorUnload[] = {1,0.0,0.0,1.0};
	class RscUnitInfoSoldier
	{
		controls[] = {"Background","Weapon","Ammo"};
		class Background
		{
			colorBackground[] = {0.96,0.96,0.94,0};
		};
		class Weapon: RscIGText
		{
			colorText[] = {1,1,1,0};
			style = 0;
		};
		class Ammo: RscIGText
		{
			colorText[] = {1,1,1,0};
			style = 0;
		};
	};
	class RscUnitInfoTank
	{
		controls[] = {"Background","Background2","ProgressBackground","TextSpeed","Weapon","Ammo","Speed","Heading","ValueFuel"};
		class Background
		{
			colorbackground[] = {0.96,0.96,0.94,0.1};
		};
		class Background2
		{
			colorbackground[] = {0.96,0.96,0.94,0.1};
		};
		class ProgressBackground: RscPicture
		{
			colorText[] = {1,1,1,1};
		};
		class ValueFuel: RscIGProgress
		{
			colorBar[] = {1,1,1,1};
			colorFrame[] = {1,0,0,0};
		};
		class Weapon: RscIGText
		{
			colorText[] = {1,1,1,1};
			style = 1;
		};
		class Ammo: RscIGText
		{
			colorText[] = {1,1,1,1};
			style = 1;
		};
		class TextSpeed: RscIGText
		{
			colorText[] = {1,1,1,1};
			style = 0;
		};
		class Speed: RscIGText
		{
			colorText[] = {1,1,1,1};
			style = 1;
		};
		class Heading: RscIGText
		{
			colorText[] = {1,1,1,1};
			style = "0x00 + 0x100";
			x = 0.74;
			y = "0.018 + SafeZoneY";
			w = 0.1;
		};
	};
	class RscUnitVehicle: RscUnitInfoSoldier
	{
		controls[] = {"Background","Background2","Weapon","Ammo","Speed","Heading","ProgressBackground","ValueArmor","ValueFuel"};
		class Background
		{
			colorbackground[] = {0.96,0.96,0.94,0};
		};
		class Background2
		{
			colorbackground[] = {0.96,0.96,0.94,0};
		};
		class Weapon: RscIGText
		{
			colorText[] = {1,1,1,0};
			style = 1;
		};
		class Ammo: RscIGText
		{
			colorText[] = {1,1,1,0};
			style = 1;
		};
		class Speed: RscIGText
		{
			colorText[] = {1,1,1,0};
			style = 0;
		};
		class Heading: RscIGText
		{
			colorText[] = {1,1,1,0};
			style = "0x00 + 0x100";
			x = 0.74;
			y = "0.018 + SafeZoneY";
			w = 0.1;
		};
		class ProgressBackground: RscPicture
		{
			colorText[] = {1,1,1,0};
		};
		class ValueArmor: RscIGProgress
		{
			colorBar[] = {1,1,1,0};
			colorFrame[] = {1,0,0,0};
		};
		class ValueFuel: RscIGProgress
		{
			colorBar[] = {1,1,1,0};
			colorFrame[] = {1,0,0,0};
		};
	};
	class RscUnitInfo
	{
		controls[] = {"Background","Background2","ProgressBackground","ValueArmor","ValueFuel","TextSpeed","Speed","Weapon","Ammo","Heading"};
		class Background
		{
			colorbackground[] = {0.96,0.96,0.94,0};
		};
		class ProgressBackground: RscPicture
		{
			colorText[] = {1,1,1,0};
		};
		class TextSpeed: RscIGText
		{
			colorText[] = {1,1,1,0};
			style = 0;
		};
		class Speed: RscIGText
		{
			colorText[] = {1,1,1,0};
			style = 1;
		};
		class Heading: RscIGText
		{
			colorText[] = {1,1,1,0};
			style = "0x00 + 0x100";
			x = 0.74;
			y = "0.018 + SafeZoneY";
			w = 0.1;
		};
		class ValueArmor: RscIGProgress
		{
			colorBar[] = {1,1,1,0};
			colorFrame[] = {1,0,0,0};
		};
		class ValueFuel: RscIGProgress
		{
			colorBar[] = {1,1,1,0};
			colorFrame[] = {1,0,0,0};
		};
		class Background2
		{
			colorbackground[] = {0.96,0.96,0.94,0};
		};
		class Weapon: RscIGText
		{
			colorText[] = {1,1,1,0};
			style = 1;
		};
		class Ammo: RscIGText
		{
			colorText[] = {1,1,1,0};
			style = 1;
		};
	};
	class RscUnitInfoAir: RscUnitInfo
	{
		controls[] = {"Background","Background2","ProgressBackground","ValueArmor","ValueFuel","TextSpeed","Speed","TextAlt","Alt","Weapon","Ammo","Heading"};
		class TextAlt: RscIGText
		{
			colorText[] = {1,1,1,0};
			style = 0;
		};
		class Alt: RscIGText
		{
			colorText[] = {1,1,1,0};
			style = 1;
		};
	};
	class RscUnitInfoAPC: RscUnitInfo
	{
		controls[] = {"Background","Background2","ProgressBackground","ValueArmor","ValueFuel","TextSpeed","Speed","TextAlt","Alt","Weapon","Ammo","Heading"};
		class Background
		{
			colorbackground[] = {0.96,0.96,0.94,0.1};
		};
		class Background2
		{
			colorText[] = {1,1,1,0};
			colorbackground[] = {0.96,0.96,0.94,0.1};
		};
		class TextAlt: RscIGText
		{
			colorText[] = {1,1,1,1};
			style = 0;
		};
		class Alt: RscIGText
		{
			colorText[] = {1,1,1,1};
			style = 1;
		};
	};
	class RscUnitInfoVehicleUnarmed: RscUnitInfo
	{
		controls[] = {"Background","Background2","ProgressBackground","ValueArmor","ValueFuel","TextSpeed","Speed","TextAlt","Alt","Weapon","Ammo","Heading"};
		class Background
		{
			colorbackground[] = {0.96,0.96,0.94,0};
		};
		class Background2
		{
			colorText[] = {1,1,1,0};
			colorbackground[] = {0.96,0.96,0.94,0};
		};
		class TextAlt: RscIGText
		{
			colorText[] = {1,1,1,0};
			style = 0;
		};
		class Alt: RscIGText
		{
			colorText[] = {1,1,1,0};
			style = 1;
		};
	};
	class RscUnitInfoShip: RscUnitInfo
	{
		controls[] = {"Background","Background2","ProgressBackground","ValueArmor","ValueFuel","TextSpeed","Speed","TextAlt","Alt","Weapon","Ammo","Heading"};
		class Background
		{
			colorbackground[] = {0.96,0.96,0.94,0.1};
		};
		class Background2
		{
			colorText[] = {1,1,1,0};
			colorbackground[] = {0.96,0.96,0.94,0.1};
		};
		class TextAlt: RscIGText
		{
			colorText[] = {1,1,1,1};
			style = 0;
		};
		class Alt: RscIGText
		{
			colorText[] = {1,1,1,1};
			style = 1;
		};
	};
	class RscUnitInfoUAV: RscUnitInfoAir
	{
		controls[] = {"Background","Background2","Type","TextSpeed","Speed","TextSpeedWanted","SpeedWanted","TextAlt","Alt","TextAltWanted","AltWanted","TextPosition","Position","TextZoom","Zoom","Weapon","Ammo","Heading","Time","Date","UAV_Cross","LineTLH","LineTLV","LineTRH","LineTRV","LineBLH","LineBLV","LineBRH","LineBRV"};
		class Background
		{
			colorbackground[] = {0.96,0.96,0.94,0.1};
			colorText[] = {0.0,0.0,0.0,1.0};
		};
		class TextSpeed: RscIGText
		{
			colorText[] = {1,1,1,1};
			style = 0;
		};
		class Type: TextSpeed
		{
			colorText[] = {1,1,1,1};
			style = 2;
		};
		class Speed: TextSpeed
		{
			colorText[] = {1,1,1,1};
			style = 1;
		};
		class LineTLH: RscText
		{
			colorBackground[] = {1.0,1.0,1.0,1.0};
		};
		class LineTLV: RscText
		{
			colorBackground[] = {1.0,1.0,1.0,1.0};
		};
		class LineTRH: RscText
		{
			colorBackground[] = {1.0,1.0,1.0,1.0};
		};
		class LineTRV: RscText
		{
			colorBackground[] = {1.0,1.0,1.0,1.0};
		};
		class LineBLH: RscText
		{
			colorBackground[] = {1.0,1.0,1.0,1.0};
		};
		class LineBLV: RscText
		{
			colorBackground[] = {1.0,1.0,1.0,1.0};
		};
		class LineBRH: RscText
		{
			colorBackground[] = {1.0,1.0,1.0,1.0};
		};
		class LineBRV: RscText
		{
			colorBackground[] = {1.0,1.0,1.0,1.0};
		};
	};
	class RscHint
	{
		controls[] = {"Background","Hint"};
		class Background
		{
			colorBackground[] = {0.96,0.96,0.94,0.1};
		};
		class Hint: RscStructuredText
		{
			colorText[] = {1,0,1,1};
			class controlsBackground
			{
				class Background
				{
					colorBackground[] = {0.96,0.96,0.94,0.1};
				};
			};
		};
	};
	class RscTaskHint
	{
		idd = 302;
		movingEnable = 0;
		class controlsBackground
		{
			class Background
			{
				colorBackground[] = {0.96,0.96,0.94,0.1};
			};
		};
		class Controls
		{
			class Hint: RscStructuredText
			{
				colorText[] = {1.0,1.0,1.0,1.0};
				colorBackground[] = {0.0,0.0,0.0,1.0};
			};
		};
	};
};
*/

class RscListBox;
class RscIGUIValue;
class RscIGUIText;
class RscText;
class RscEdit;
class RscStructuredText;
class RscProgress;
class RscPicture;
class RscIGText: RscText
{
	colorText[] = {0,0,0,0};
};
class RscIGProgress;
class RscInGameUI
{
	class RscUnitInfo;
	class RscUnitInfoAir: RscUnitInfo
	{
		idd = 300;
		colorBackground[] = {0,0,0,0};
		colorText[] = {0,0,0,0};
		colorSelection[] = {0,0,0,0};
		colorBar[] = {0,0,0,0};
		colorFrame[] = {0,0,0,0};				
		updateWidthByWeapon = 0;
		updateHeightByCrew = 0;
		updateWidthByCrew = 0;
		controls[] = {"CA_Weapon","CA_Mode","CA_Ammo","CA_ValueFuelBackground","CA_ValueFuel","CA_GunnerWeapon","CA_SpeedBackground","CA_TextSpeed","CA_Speed","CA_AltBackground","CA_TextAlt","CA_Alt","CA_HeadingBackground","CA_Heading","CA_ValueArmor","CA_TextFlares","CA_TextFlaresMode"};
		class CA_Mode: RscIGUIText
		{
			idc = 149;
			style = 0;
			x = "(SafeZoneW + SafeZoneX) - (1 - 0.761)";
			y = "0.054 + SafeZoneY";
			w = 0.214;
			h = 0.039;
		colorBackground[] = {0,0,0,0};
		colorText[] = {0,0,0,0};
		colorSelection[] = {0,0,0,0};
		colorBar[] = {0,0,0,0};
		colorFrame[] = {0,0,0,0};				
			
		};
		class CA_Ammo: RscIGUIValue
		{
			idc = 119;
			style = 1;
			x = "(SafeZoneW + SafeZoneX) - (1 - 0.761)";
			y = "0.054 + SafeZoneY";
			w = 0.214;
			h = 0.039;
		colorBackground[] = {0,0,0,0};
		colorText[] = {0,0,0,0};
		colorSelection[] = {0,0,0,0};
		colorBar[] = {0,0,0,0};
		colorFrame[] = {0,0,0,0};				

		};
		class CA_Weapon: RscIGUIText
		{
			idc = 118;
			style = 0;
			x = "(SafeZoneW + SafeZoneX) - (1 - 0.761)";
			y = "0.015 + SafeZoneY";
			w = 0.214;
			h = 0.039;
		colorBackground[] = {0,0,0,0};
		colorText[] = {0,0,0,0};
		colorSelection[] = {0,0,0,0};
		colorBar[] = {0,0,0,0};
		colorFrame[] = {0,0,0,0};				

			};
		class CA_GunnerWeapon: RscIGUIText
		{
			idc = 150;
			style = 0;
			x = "(SafeZoneW + SafeZoneX) - (1 - 0.761)";
			y = "0.132 + SafeZoneY";
			w = 0.214;
			h = 0.039;
			SizeEx = 0.034;
		colorBackground[] = {0,0,0,0};
		colorText[] = {0,0,0,0};
		colorSelection[] = {0,0,0,0};
		colorBar[] = {0,0,0,0};
		colorFrame[] = {0,0,0,0};				

		};
		class CA_SpeedBackground: RscEdit
		{
			idc = -1;
			sizeEx = 0.034;
		colorBackground[] = {0,0,0,0};
		colorText[] = {0,0,0,0};
		colorSelection[] = {0,0,0,0};
		colorBar[] = {0,0,0,0};
		colorFrame[] = {0,0,0,0};				
			style = "0x02 + 0x40";
			shadow = 2;
			type = 0;
			x = 0.314;
			y = "0.017 + SafeZoneY";
			w = 0.06;
			h = 0.033;
		};
		class CA_TextSpeed: RscIGUIText
		{
			style = 0;
			x = 0.257;
			y = "0.015 + SafeZoneY";
			w = 0.12;
			text = "SPD";
		colorBackground[] = {0,0,0,0};
		colorText[] = {0,0,0,0};
		colorSelection[] = {0,0,0,0};
		colorBar[] = {0,0,0,0};
		colorFrame[] = {0,0,0,0};				
			
		};
		class CA_Speed: RscIGUIValue
		{
			idc = 121;
			style = 0;
			x = 0.257;
			//y = "0.015 + SafeZoneY";
			y = -1;
			w = 0.12;
		colorBackground[] = {0,0,0,0};
		colorText[] = {0,0,0,0};
		colorSelection[] = {0,0,0,0};
		colorBar[] = {0,0,0,0};
		colorFrame[] = {0,0,0,0};				
			
		};
		class CA_AltBackground: RscEdit
		{
			idc = -1;
			sizeEx = 0.034;
		colorBackground[] = {0,0,0,0};
		colorText[] = {0,0,0,0};
		colorSelection[] = {0,0,0,0};
		colorBar[] = {0,0,0,0};
		colorFrame[] = {0,0,0,0};				

			style = "0x02 + 0x40";
			type = 0;
			x = 0.625;
			y = "0.017 + SafeZoneY";
			w = 0.06;
			h = 0.033;
		};
		class CA_TextAlt: RscIGUIText
		{
			style = 1;
			x = 0.625;
			y = "0.015 + SafeZoneY";
			w = 0.12;
			text = "ALT";
		colorBackground[] = {0,0,0,0};
		colorText[] = {0,0,0,0};
		colorSelection[] = {0,0,0,0};
		colorBar[] = {0,0,0,0};
		colorFrame[] = {0,0,0,0};				
			
		};
		class CA_Alt: RscIGUIValue
		{
			idc = 122;
			style = 0;
			x = 0.625;
			y = "0.015 + SafeZoneY";
			w = 0.12;
		colorBackground[] = {0,0,0,0};
		colorText[] = {0,0,0,0};
		colorSelection[] = {0,0,0,0};
		colorBar[] = {0,0,0,0};
		colorFrame[] = {0,0,0,0};				
			
		};
		class CA_HeadingBackground: RscEdit
		{
			idc = -1;
			sizeEx = 0.034;
		colorBackground[] = {0,0,0,0};
		colorText[] = {0,0,0,0};
		colorSelection[] = {0,0,0,0};
		colorBar[] = {0,0,0,0};
		colorFrame[] = {0,0,0,0};				

			style = "0x02 + 0x40";
			type = 0;
			x = 0.469;
			y = "0.017 + SafeZoneY";
			w = 0.061;
			h = 0.033;
		};
		class CA_Heading: RscIGUIValue
		{
			idc = 148;
			style = 2;
			x = 0.45;
			y = "0.015 + SafeZoneY";
			w = 0.1;
		colorBackground[] = {0,0,0,0};
		colorText[] = {0,0,0,0};
		colorSelection[] = {0,0,0,0};
		colorBar[] = {0,0,0,0};
		colorFrame[] = {0,0,0,0};				
			
		};
		class CA_ValueFuelBackground: RscPicture
		{
			idc = -1;
			shadow = 2;
			x = "0.018 + SafeZoneX";
			y = "0.01 + SafeZoneY";
			w = 0.0196078;
			h = 0.2091503;
		colorBackground[] = {0,0,0,0};
		colorText[] = {0,0,0,0};
		colorSelection[] = {0,0,0,0};
		colorBar[] = {0,0,0,0};
		colorFrame[] = {0,0,0,0};				

			text = "\ca\ui\data\ui_fuel_background.paa";
		};
		class CA_ValueFuel: RscIGProgress
		{
			idc = 113;
			x = "0.02 + SafeZoneX";
			y = "0.036 + SafeZoneY";
			w = 0.01;
			h = 0.18;
			texture = "\ca\ui\data\igui_fuel_progress.paa";
		colorBackground[] = {0,0,0,0};
		colorText[] = {0,0,0,0};
		colorSelection[] = {0,0,0,0};
		colorBar[] = {0,0,0,0};
		colorFrame[] = {0,0,0,0};				
			
		};
		class CA_ValueArmor: RscListBox
		{
			idc = 111;
			sizeEx = 0.03525;
			x = "0.040 + SafeZoneX";
			//y = "0.016 + SafeZoneY";
			y = -1;
			w = 0.0357;
			h = 0.76;
		colorBackground[] = {0,0,0,0};
		colorText[] = {0,0,0,0};
		colorSelection[] = {0,0,0,0};
		colorBar[] = {0,0,0,0};
		colorFrame[] = {0,0,0,0};				
			
		};
		class CA_TextFlaresMode: RscIGUIText
		{
			idc = 152;
			style = 0;
			sizeEx = 0.02674;
			x = "0.078 + SafeZoneX";
			y = "0.012 + SafeZoneY";
			w = "0.161*SafezoneW";
		colorBackground[] = {0,0,0,0};
		colorText[] = {0,0,0,0};
		colorSelection[] = {0,0,0,0};
		colorBar[] = {0,0,0,0};
		colorFrame[] = {0,0,0,0};				
			
		};
		class CA_TextFlares: RscIGUIValue
		{
			idc = 151;
			style = 1;
			sizeEx = 0.02674;
			x = "0.078  + SafeZoneX";
			y = "0.012 + SafeZoneY";
			w = "0.161*SafezoneW";
		colorBackground[] = {0,0,0,0};
		colorText[] = {0,0,0,0};
		colorSelection[] = {0,0,0,0};
		colorBar[] = {0,0,0,0};
		colorFrame[] = {0,0,0,0};				
			
		};
	};
};