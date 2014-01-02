class CfgPatches
{
	class FLAY_Wingsuit
	{
		units[] = {"FLAY_Wingsuit"};
		requiredVersion = 0.1;
		requiredAddons[] = {"FLAY_HangGlider_Core"};
	};
};

// ===========================================================================
// VEHICLES
// ===========================================================================

class CfgVehicles
{
	class Plane;
	
	class FLAY_GliderBase: Plane {
		class AnimationSources;
		class Sounds;
		class EventHandlers;
	};
	
	class FLAY_Wingsuit: FLAY_GliderBase
	{
		scope = 2;

		class EventHandlers: EventHandlers
		{
			init = "_scr = _this execVM ""\FLAY\FLAY_HangGlider\wingsuit\scripts\fn_init.sqf"";";
		};
		
		displayName = "Wingsuit";
		model = "FLAY\FLAY_HangGlider\wingsuit\FLAY_Wingsuit";		
		
		driverAction = "Wingsuit_Pilot";
		driverInAction = "Wingsuit_Pilot";

		weapons[] = {};
		magazines[] = {};
		
		//envelope[] = { 0, 0, 0.1, 0.5, 1.5, 2.5, 2.5, 2.5, 2.5, 3, 3, 2.5, 2.5, 2.5, 2.5, 2.5, 2, 2, 1, 0 };
		envelope[] = { 0, 0, 0, 1, 1.55, 2.55, 2.55, 2.55, 2.85, 3, 3, 2.85, 2.55, 2.55, 2.55, 2.55, 2.55, 2.55, 2.55, 1, 0 };

		maxSpeed = 200;
		aileronSensitivity = 0.55;
		elevatorSensitivity = 0.032; // 0.035
		wheelSteeringSensitivity = 2;
		noseDownCoef = 0;
				
		unitInfoType = "UnitInfoSoldier";

		extCameraPosition[] = {0,2,-4};
		
	};
	
	class FLAY_Wingsuit2: FLAY_WingSuit
	{
		scope = 1;
		displayName = "Wingsuit 2";
		
		weapons[] = {};
		magazines[] = {};
		
		envelope[] = { 0, 0, 0.5, 1.5, 2, 2.5, 2.5, 2.5, 2.8, 3, 3, 3.2, 3.2, 3.0, 3.0, 2.8, 2.8, 2.5, 2.5, 1, 0 };

		maxSpeed = 200;
		aileronSensitivity = 1;
		elevatorSensitivity = 0.05; // 0.035
		wheelSteeringSensitivity = 4;
		noseDownCoef = 0;
		
		unitInfoType = "UnitInfoSoldier";

		extCameraPosition[] = {0,2.5,-4};
		
		class UserActions {};
	};
	
	class FLAY_Wingsuit3: FLAY_Wingsuit
	{
		scope = 1;
		displayName = "Wingsuit 3";
		
		weapons[] = {};
		magazines[] = {};
		
		envelope[] = { 0, 0, 0, 0.2, 0.4, 0.6, 2.5, 2.55, 2.85, 3, 3, 2.85, 2.75, 2.65, 2.55, 2.55, 2.55, 2.55, 2.55, 1, 0 };

		maxSpeed = 200;
		aileronSensitivity = 1.35;
		elevatorSensitivity = 0.045;
		wheelSteeringSensitivity = 4;
		noseDownCoef = 0;
		
		unitInfoType = "UnitInfoSoldier";

		extCameraPosition[] = {0,2.5,-3.5};
		
		class UserActions {};
	};	
	
};

// ===========================================================================
// MOVES
// ===========================================================================

class CfgMovesBasic
{
	class ManActions
	{
		Wingsuit_Pilot = "Wingsuit_Pilot";
	};
};

class CfgMovesMaleSdr: CfgMovesBasic
{
	class Default;
	class States
	{
		class Crew;
		class HangGlider_Pilot;
		class Wingsuit_Pilot: HangGlider_Pilot
		{
			file = "\FLAY\FLAY_HangGlider\wingsuit\anims\Wingsuit_Pilot.rtm";
		};
	};
};

class CfgGesturesMale
{
	class Default;
	class States
	{
	};
};

// ===========================================================================
// SOUNDS
// ===========================================================================

class CfgSounds
{
	class FLAY_ParachuteOpening
	{
		name = "FLAY_ParachuteOpening";
		sound[] = {"\FLAY\FLAY_HangGlider\wingsuit\sounds\padak_getIN",1.0,1.0};
		titles[] = {};
	};
	
	class FLAY_ParachuteOpeningPain
	{
		name = "FLAY_ParachuteOpeningPain";
		sound[] = {"\FLAY\FLAY_HangGlider\wingsuit\sounds\george-hit-07",1.0,1.0};
		titles[] = {};
	};	
	
	class FLAY_ParachuteLandingPain
	{
		name = "FLAY_ParachuteLandingPain";
		sound[] = {"\FLAY\FLAY_HangGlider\wingsuit\sounds\george-hit-01",1.0,1.0};
		titles[] = {};
	};	
};
