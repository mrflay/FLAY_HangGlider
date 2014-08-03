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
		crewVulnerable = true; // default?
			
		armor = 5;		
		side = 4;
		Icon = "\flay\flay_hangglider\hangglider\glider_ico_ca.paa";
		picture = "\flay\flay_hangglider\hangglider\glider_pic_ca.paa";
		mapSize = 10;
		
		nameSound = "veh_air_parachute_s";
		accuracy = 0.1;
		camouflage = 1;
		audible = 0;
		hasGunner = 0;
		fuelCapacity = 0;
		
		soundEngine[] = {};
		soundEnviron[] = {"\FLAY\FLAY_Hangglider\hangglider\sounds\padak_let",1,1,80};
		soundGetIn[] = {"\FLAY\FLAY_Hangglider\hangglider\sounds\padak_getIN",1,1,80};
		soundGetOut[] = {"\FLAY\FLAY_Hangglider\hangglider\sounds\padak_getIN",1,1,80};
		soundCrash[] = {"\FLAY\FLAY_Hangglider\hangglider\sounds\padak_dopad",1,1,80};
		soundLandCrash[] = {"\FLAY\FLAY_Hangglider\hangglider\sounds\padak_dopad",1,1,80};
		soundWaterCrash[] = {"\FLAY\FLAY_Hangglider\hangglider\sounds\padak_dopadvoda",1,1,80};

		driverLeftHandAnimName = "pilot_lefthand";
		driverRightHandAnimName = "pilot_righthand";
		//driverLeftLegAnimName = "pilot_leftfoot";
		//driverRightLegAnimName = "pilot_rightfoot";
		
		simulation="airplane";
		unitInfoType = "RscUnitInfoNoHUD";		
				
		threat[] = {1,0.900000,0.100000};
		
		htMin = 60;
		htMax = 1800;
		afMax = 100;
		mfMax = 100;
		mFact = 0.2;
		tBody = 150;
		
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
			initAngleY = 0;
			minAngleY = -150;
			maxAngleY = 150;
		};

		driverAction = "HangGlider_Pilot";
		driverInAction = "HangGlider_Pilot";
		getInAction = "GetInLow";
		getOutAction = "GetOutLow";
		
		attenuationEffectType = "OpenCarAttenuation";
		obstructSoundLFRatio = 0;
		obstructSoundsWhenIn = 1;
		occludeSoundLFRatio = 0;
		occludeSoundsWhenIn = 1;
		outsideSoundFilter = 1;
		
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
