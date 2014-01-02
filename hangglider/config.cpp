class CfgPatches
{
	class FLAY_HangGlider
	{
		units[] = {"FLAY_HangGlider","FLAY_HangGliderAI"};
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
	
	class FLAY_HangGlider: FLAY_GliderBase
	{
		scope = 2;

		class EventHandlers: EventHandlers
		{
			init = "_scr = _this execVM ""\FLAY\FLAY_HangGlider\hangglider\scripts\fn_init.sqf"";";
			killed = "";
		};

		displayName = "Hang Glider";
		model = "FLAY\FLAY_HangGlider\hangglider\FLAY_HangGlider";

		//weapons[] = {};
		//magazines[] = {};	
		
		weapons[] = {"HangGliderBombs"};
		magazines[] = {"4Rnd_Bomb_HangGlider"};
		
		armor = 5;
		accuracy = 0.5;
		camouflage = 2;

		//airFriction0[] = {25,12,2.500000};
		//airFriction1[] = {25,12,2.500000};
		//airFriction2[] = {25,12,2.500000};
		
		//canFloat = true;
		//canBeShot = true;
		damageResistance = 0.000000000001;
		//damperSize = 2;
		//damperForce = 0.5;
		//hideUnitInfo = true;
		//hideWeaponsDriver = true;
		//selectionFabric = "latka";
		//type = 0;
		
		unitInfoType = "UnitInfoSoldier";
		
		extCameraPosition[] = {0,3.5,-9};
		enableGPS = 1;

		driverAction = "HangGlider_Pilot";
		driverInAction = "HangGlider_Pilot";
		getInAction = "GetInLow";
		getOutAction = "GetOutLow";
		
		envelope[] = { 0.1, 0.2, 0.9, 1.5, 2.7, 3.0, 3.1, 3.2, 3.4, 3.5, 3.4, 3.3, 3.2, 3.1, 3.0, 2.8, 2.5, 2.0 };

		maxSpeed = 150;
		aileronSensitivity = 1.5;
		elevatorSensitivity = 0.2;
		wheelSteeringSensitivity = 3;
		noseDownCoef = 0.0025;
				
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
			
			// animated pilot adjustments
			class PilotPosX2
			{
				source = "user";
				animPeriod = 4;
				initPhase = 0;	
			};			
			class PilotPosY2
			{
				source = "user";
				animPeriod = 4;
				initPhase = 0;	
			};			
			class PilotPosZ2
			{
				source = "user";
				animPeriod = 4;
				initPhase = 0;	
			};			
			
		};

		class UserActions
		{
			class FLAY_Variometer_ON
			{
				displayNameDefault = "Variometer On";
				showWindow = 0;
				//hideOnUse = 1;
				displayName = "Variometer On";
				position = "action";
				radius = 0.5;
				onlyForPlayer = 1;
				condition = "(alive player) and not (player getVariable ['FLAY.variometer.power.on',false])";
				//condition = "(alive player) and ('FLAY_Flytec3040_Variometer' in (weapons player) or 'FLAY_Flytec3040_Variometer' in (weapons (vehicle player))) and not (player getVariable ['FLAY.variometer.power.on',false])";
				statement = "[player] execVM '\FLAY\FLAY_HangGlider\variometer\scripts\ui_variometer_show.sqf'";
			};
			class FLAY_Variometer_OFF
			{
				displayNameDefault = "Variometer Off";
				showWindow = 0;
				//hideOnUse = 1;
				displayName = "Variometer Off";
				position = "action";
				radius = 0.5;
				onlyForPlayer = 1;
				condition = "(alive player) and (player getVariable ['FLAY.variometer.power.on',false])";
				//condition = "(alive player) and ('FLAY_Flytec3040_Variometer' in (weapons player) or 'FLAY_Flytec3040_Variometer' in (weapons (vehicle player))) and (player getVariable ['FLAY.variometer.power.on',false])";
				statement = "[player] execVM '\FLAY\FLAY_HangGlider\variometer\scripts\ui_variometer_hide.sqf'";
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
				statement = "[this,-1,player] execVM 'FLAY\FLAY_HangGlider\hangglider\scripts\ev_getIn.sqf'";
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
				statement = "[this,'DRIVER',player] execVM 'FLAY\FLAY_HangGlider\hangglider\scripts\ev_getOut.sqf'";
			};
		};
		
		class Sounds: Sounds
		{
			class CreakNoiseIn1
			{
				sound[] = {"\FLAY\FLAY_HangGlider\hangglider\sounds\squeak1.ogg",0.31622776,1,80};
				frequency = "(randomizer*0.05+1.0)";
				volume = "10*(speed factor[1, 80])*(1-camPos)";
			};
			class CreakNoiseIn2
			{
				sound[] = {"\FLAY\FLAY_HangGlider\hangglider\sounds\squeak1.ogg",0.31622776,1,80};
				frequency = "(randomizer*0.5+0.5)";
				volume = "10*(speed factor[70, 100])*(1-camPos)";
			};
			class CreakNoiseIn3
			{
				sound[] = {"\FLAY\FLAY_HangGlider\hangglider\sounds\squeak3.ogg",0.31622776,1,80};
				frequency = "(randomizer*0.5+0.2)";
				volume = "10*(speed factor[70, 100])*(1-camPos)";
			};			
			class CreakNoiseOut
			{
				sound[] = {"\FLAY\FLAY_HangGlider\hangglider\sounds\squeak1.ogg",0.31622776,1,80};
				frequency = "(randomizer*0.05+1.0)";
				volume = "10*camPos*(speed factor[1, 80])";
			};
		};
	};

	class FLAY_HangGliderAI: FLAY_HangGlider
	{
		scope = 2;
		displayName = "Hang Glider (AI)";
		model = "FLAY\FLAY_HangGlider\hangglider\FLAY_HangGlider2";
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
		
	class B_AssaultPack_blk;
	class FLAY_HangGlider_Bag: B_AssaultPack_blk
	{
		scope = 2;
		displayName = "Hang Glider Kit";
		descriptionShort = "Hang Glider Kit";
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
			file = "\FLAY\FLAY_HangGlider\hangglider\anims\HangGlider_Pilot.rtm";
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
			file = "\FLAY\FLAY_HangGlider\hangglider\anims\HangGlider_PilotWpn.rtm";
			interpolateTo[] = {"HangGlider_Dead",1,"HangGlider_Pilot",0.1,"HangGlider_PilotLand",0.1"HangGlider_PilotWlk",0.1};
			rightHandIKCurve[] = {0};
			disableWeapons = 0;
			canPullTrigger = 1;
		};		
		class HangGlider_PilotLand: HangGlider_Pilot
		{
			file = "\FLAY\FLAY_HangGlider\hangglider\anims\HangGlider_PilotLand.rtm";
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
			file = "\FLAY\FLAY_HangGlider\hangglider\anims\HangGlider_PilotSwoop.rtm";
			speed = 0.5;
			interpolationSpeed = 0.5;
			interpolateTo[] = {"HangGlider_Dead",1,"HangGlider_PilotLand",0.05,"HangGlider_PilotWpn",0.05,"HangGlider_Pilot",0.05};
			interpolateFrom[] = {"HangGlider_PilotLand",0.05,"HangGlider_PilotWpn",0.05,"HangGlider_Pilot",0.05};
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
		class CarryHangGlider: Default
		{
			file = "\FLAY\FLAY_HangGlider\hangglider\anims\HangGlider_Carry.rtm";
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
			file = "\FLAY\FLAY_HangGlider\hangglider\anims\HangGlider_PilotSwoop.rtm";
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
