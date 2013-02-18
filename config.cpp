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
		requiredAddons[] = {"CACharacters","CAData"};
	};
};


class DefaultEventhandlers;


// ===========================================================================
// VEHICLES
// ===========================================================================


class CfgVehicles
{
	class Static { class ladders; };
	class Air;
	class Plane: Air
	{
		class NewTurret;
		class ViewPilot;
		class AnimationSources;
		class Turrets;
	};
	
	class FLAY_GliderBase: Plane
	{
		armor = 1;
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

		driverCanSee = "0";
		secondaryExplosion = -1;
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

		weapons[] = {};
		magazines[] = {};	
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
		
		class AnimationSources: AnimationSources
		{
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
		};

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
	
	class FLAY_ArrowDownHelper: Static
	{
		scope = 1;
		displayName = "FLAY Arrow Down Helper";
		model = "FLAY\FLAY_HangGlider\FLAY_ArrowDownHelper.p3d";
		vehicleClass = "Misc";
		class AnimationSources
		{
			class RotY
			{
				source = "user";
				animPeriod = 5;
				initPhase = "360*20";
			};
		};
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
