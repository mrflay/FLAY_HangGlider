scriptName "fn_gearIndicator.sqf";
/*
	Author: Karel Moricky

	Description:
	Direction indicator (similar to one CWC-era military game)

	Parameter(s):
	_this select 0: OBJECT - Center
	_this select 1: OBJECT - Related object

	Returns:
	True
*/
_this spawn {
	disableserialization;
	
	_fadeOut = 0.8;
	_color = [1,1,1,1];
	
	17 cutrsc ["RscMissionScreen","plain"];
	waituntil {!isnull (uinamespace getvariable "BIS_RscMissionScreen")};
	uinamespace setvariable ["BIS_RscMissionScreen_dirIndicator",uinamespace getvariable "BIS_RscMissionScreen"];
	
	#define IND_DISPLAY	(uinamespace getvariable "BIS_RscMissionScreen_dirIndicator")
	#define IND_CONTROL	1200

	#define IND_W		(0.35)
	#define IND_H		(IND_W * 4/3)
	#define IND_COEF	(1.0)

	#define GEAR_R	(IND_DISPLAY displayctrl (IND_CONTROL + 1))	//--- Reverse
	#define GEAR_N	(IND_DISPLAY displayctrl (IND_CONTROL + 2))	//--- Neutral
	#define GEAR_1	(IND_DISPLAY displayctrl (IND_CONTROL + 3))	//--- First
	#define GEAR_2	(IND_DISPLAY displayctrl (IND_CONTROL + 4))	//--- Second
	#define GEAR_3	(IND_DISPLAY displayctrl (IND_CONTROL + 5))	//--- Third
	#define GEAR_4	(IND_DISPLAY displayctrl (IND_CONTROL + 6))	//--- Fourth
	#define GEAR_5	(IND_DISPLAY displayctrl (IND_CONTROL + 7))	//--- Fifth

	//--- Init
	_pos = [
		(safezoneX + safezoneW / 2) - ((IND_W) * IND_COEF)/2,
		(safezoneY + safezoneH) - (IND_H) * IND_COEF,
		IND_W,
		IND_H
	];

	GEAR_R ctrlsetposition _pos;
	GEAR_N ctrlsetposition _pos;
	GEAR_1 ctrlsetposition _pos;
	GEAR_2 ctrlsetposition _pos;
	GEAR_3 ctrlsetposition _pos;
	GEAR_4 ctrlsetposition _pos;
	GEAR_5 ctrlsetposition _pos;

	GEAR_R ctrlsettextcolor _color;
	GEAR_N ctrlsettextcolor _color;
	GEAR_1 ctrlsettextcolor _color;
	GEAR_2 ctrlsettextcolor _color;
	GEAR_3 ctrlsettextcolor _color;
	GEAR_4 ctrlsettextcolor _color;
	GEAR_5 ctrlsettextcolor _color;

	GEAR_R ctrlsetfade 1;
	GEAR_N ctrlsetfade 1;
	GEAR_1 ctrlsetfade 1;
	GEAR_2 ctrlsetfade 1;
	GEAR_3 ctrlsetfade 1;
	GEAR_4 ctrlsetfade 1;
	GEAR_5 ctrlsetfade 1;

	GEAR_R ctrlcommit 0;
	GEAR_N ctrlcommit 0;
	GEAR_1 ctrlcommit 0;
	GEAR_2 ctrlcommit 0;
	GEAR_3 ctrlcommit 0;
	GEAR_4 ctrlcommit 0;
	GEAR_5 ctrlcommit 0;

	GEAR_R ctrlsettext "data\ui_variometer_ca.paa";
	
	//--- Display again after load
	_this spawn {scriptName "fn_variometer.sqf: Load restart";
		_load = [] spawn {scriptName "fn_variometer.sqf: Load detection";
			disableserialization;
			waituntil {false};
		};
		waituntil {scriptdone _load || isnull IND_DISPLAY};
		_this spawn FLAY_fnc_variometer;
	};
	

	// onEachFrame 1.63+
	while { true } do {
	
		_vehicle = vehicle player;
		if (_vehicle != player) then 
		{
			_gear = _vehicle getVariable ["FLAY_cars_gear",0];
			_throttle = _vehicle getVariable ["FLAY_cars_throttle",0];
			_clutch = _vehicle getVariable ["FLAY_cars_clutch",0];
			
			GEAR_R ctrlsetfade ( if (_gear == -1) then { 1-_clutch - 0.3 } else { 1 } );
			GEAR_N ctrlsetfade ( if (_gear ==  0) then { 1-_clutch - 0.3 } else { 1 } );
			GEAR_1 ctrlsetfade ( if (_gear ==  1) then { 1-_clutch - 0.3 } else { 1 } );
			GEAR_2 ctrlsetfade ( if (_gear ==  2) then { 1-_clutch - 0.3 } else { 1 } );
			GEAR_3 ctrlsetfade ( if (_gear ==  3) then { 1-_clutch - 0.3 } else { 1 } );
			GEAR_4 ctrlsetfade ( if (_gear ==  4) then { 1-_clutch - 0.3 } else { 1 } );
			GEAR_5 ctrlsetfade ( if (_gear ==  5) then { 1-_clutch - 0.3 } else { 1 } );
			
			GEAR_R ctrlcommit 0.1 * (1-_clutch);
			GEAR_N ctrlcommit 0.1 * (1-_clutch);
			GEAR_1 ctrlcommit 0.1 * (1-_clutch);
			GEAR_2 ctrlcommit 0.1 * (1-_clutch);
			GEAR_3 ctrlcommit 0.1 * (1-_clutch);
			GEAR_4 ctrlcommit 0.1 * (1-_clutch);
			GEAR_5 ctrlcommit 0.1 * (1-_clutch);
		};
		sleep 0.1;
	};
};