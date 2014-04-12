class CfgPatches
{
	class FLAY_HangGlider_Thermals
	{
		units[] = {"FLAY_Thermal"};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};

// ===========================================================================
// VEHICLES
// ===========================================================================

class DefaultEventhandlers;

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
	
	class FLAY_3DAxis10m: Thing
	{
		scope = 1;
		displayName = "FLAY 3D Axis 10m";
		model = "FLAY\FLAY_HangGlider\thermals\FLAY_3DAxis10m.p3d";
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
		scope = 1;
		displayName = "FLAY Arrow Green";
		model = "FLAY\FLAY_HangGlider\thermals\FLAY_ArrowFwGreen.p3d";
		vehicleClass = "Misc";
		animated = 1;
	};	
	
	class FLAY_Thermal: Static
	{
		scope = 1;
		displayName = "FLAY Thermal";
		model = "FLAY\FLAY_HangGlider\thermals\FLAY_Thermal.p3d";
		vehicleClass = "Misc";
		animated=1;
		class EventHandlers: DefaultEventhandlers
		{
			init = "_scr = _this execVM '\FLAY\FLAY_HangGlider\thermals\scripts\fn_init.sqf';";
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
};
