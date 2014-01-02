class CfgPatches
{
	class FLAY_Paraglider
	{
		units[] = {"FLAY_Paraglider"};
		requiredVersion = 0.1;
		requiredAddons[] = {"FLAY_HangGlider_Core"};
	};
};

// ===========================================================================
// VEHICLES
// ===========================================================================

class CfgVehicles
{
	class Air;
	class Plane: Air {};
	
	class FLAY_GliderBase: Plane {
		class AnimationSources;
		class Sounds;
		class EventHandlers;
		class ViewPilot;
	};
		
	class FLAY_Paraglider: FLAY_GliderBase
	{
		scope = 1;
		displayName = "Paraglider";
		model = "FLAY\FLAY_HangGlider\paraglider\FLAY_Paraglider";
		unitInfoType = "RscUnitInfoNoHUD";
		
		driverAction = "HangGlider_PilotLand";
		driverInAction = "HangGlider_PilotLand";

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

		envelope[] = {0.9,0.9,0.9,0.9,0.9,0.9,0.9,0.9,0.9,0.9,0.9,0.9,0.9,0.9,0.9,0.9,0.9};
		maxSpeed = 1;
		landingSpeed = 1;
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
		Paraglider_Pilot = "Paraglider_Pilot";
	};
};

class CfgMovesMaleSdr: CfgMovesBasic
{
	class Default;
	class States
	{
		class Crew;
		class Paraglider_Dead: DefaultDie
		{
			actions = "DeadActions";
			file = "\ca\air\Data\Anim\KIA_Para_Pilot.rtm";
			speed = 0.5;
			looped = 0;
			terminal = 1;
			soundEnabled = 0;
			connectTo[] = {"DeadState",0.1};
		};
		class Paraglider_Pilot: Crew
		{
			file = "\FLAY\FLAY_HangGlider\paraglider\anims\Paraglider_Pilot.rtm";
			speed = 0.6;
			soundEnabled = 1;
			disableWeapons = 1;
			interpolationSpeed = 1;
			ConnectTo[] = {};			
			interpolateTo[] = {"Paraglider_Dead",1};
			leftHandIKCurve[] = {1};
			rightHandIKCurve[] = {1};
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
