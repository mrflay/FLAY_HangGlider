scriptName "fn_enemyIndicator.sqf";
/*
	Author: Karel Moricky

	Description:
	Direction indicator (similar to one CWC-era military game)

	Parameter(s):
	_this select 0: OBJECT - object
	_this select 1: OBJECT - mempoint

	Returns:
	True
*/
_this spawn {
	disableserialization;
	
	_fadeOut = 1;
	_color = [1,0,0,1];
	_colorGreen = [0,1,0,1];
	_thresholdX = 0.1;
	_thresholdY = 0.1;
	
	17 cutrsc ["RscMissionScreen","plain"];
	waituntil {!isnull (uinamespace getvariable "BIS_RscMissionScreen")};
	uinamespace setvariable ["BIS_RscMissionScreen_dirIndicator",uinamespace getvariable "BIS_RscMissionScreen"];
	
	#define IND_DISPLAY	(uinamespace getvariable "BIS_RscMissionScreen_dirIndicator")
	#define IND_CONTROL	(1200)

	#define IND_W		(0.1045752)
	#define IND_H		(IND_W * 4/3)
	#define IND_COEF	(1.0)

	#define IND_SNDSRC	(IND_DISPLAY displayctrl (IND_CONTROL + 1))	
	#define IND_REPAIR	(IND_DISPLAY displayctrl (IND_CONTROL + 2))	
	#define IND_REFUEL	(IND_DISPLAY displayctrl (IND_CONTROL + 3))
	#define IND_GUNNER	(IND_DISPLAY displayctrl (IND_CONTROL + 4))	
	#define IND_CENTER	(IND_DISPLAY displayctrl (IND_CONTROL + 5))	

	//--- Init
	_pos = [
		(safezoneX + safezoneW / 2) - ((IND_W) * IND_COEF)/2,
		(safezoneY + safezoneH) - (IND_H) * IND_COEF,
		IND_W,
		IND_H
	];

	_centerPos = [
		(0.5) - ((IND_W/2) * IND_COEF)/8,
		(0.5) - ((IND_H/2) * IND_COEF)/8,
		IND_W/8,
		IND_H/8
	];	
	
	IND_SNDSRC ctrlsetposition _pos;
	IND_REPAIR ctrlsetposition _pos;
	IND_REFUEL ctrlsetposition _pos;
	IND_GUNNER ctrlsetposition _pos;
	IND_CENTER ctrlsetposition _centerPos;

	IND_SNDSRC ctrlsettextcolor _color;
	IND_REPAIR ctrlsettextcolor _color;
	IND_REFUEL ctrlsettextcolor _color;
	IND_GUNNER ctrlsettextcolor _color;
	IND_CENTER ctrlsettextcolor _colorGreen;

	IND_SNDSRC ctrlsetfade _fadeOut;
	IND_REPAIR ctrlsetfade _fadeOut;
	IND_REFUEL ctrlsetfade _fadeOut;
	IND_GUNNER ctrlsetfade _fadeOut;
	IND_CENTER ctrlsetfade _fadeOut;

	IND_SNDSRC ctrlcommit 0;
	IND_REPAIR ctrlcommit 0;
	IND_REFUEL ctrlcommit 0;
	IND_GUNNER ctrlcommit 0;
	IND_CENTER ctrlcommit 0;

	IND_SNDSRC ctrlsettext "ca\sounds\data\icon_soundsource_ca.paa";
	IND_REPAIR ctrlsettext "ca\modules_e\Functions\hints\img_icons\icon_repair_ca.paa";
	IND_REFUEL ctrlsettext "ca\modules_e\Functions\hints\img_icons\icon_refuel_ca.paa";
	IND_RELOAD ctrlsettext "ca\modules_e\Functions\hints\img_icons\icon_reload_ca.paa";
	IND_REAMMO ctrlsettext "ca\modules_e\Functions\hints\img_icons\icon_reammo_ca.paa";
	IND_GUNNER ctrlsettext "ca\modules_e\Functions\hints\img_icons\icon_gunner_ca.paa";
	IND_CENTER ctrlsettext "flay\flay_hangglider\data\ui_point_ca.paa";
	
	//--- Display again after load
	//_this spawn {scriptName "fn_enemyIndicator.sqf: Load restart";
	//	_load = [] spawn {scriptName "fn_enemyIndicator.sqf: Load detection";
	//		disableserialization;
	//		waituntil {false};
	//	};
	//	waituntil {scriptdone _load || isnull IND_DISPLAY};
	//	_this spawn FLAY_fnc_enemyIndicator;
	//};
	
	_vehicle = _this select 0;
	_mempoint = _this select 1;
	_modelPos = _vehicle selectionPosition _mempoint;
	_actionId=-1;
	// onEachFrame 1.63+
	while { true } do {
		_worldPos = _vehicle modelToWorld _modelPos;
		_screenPos = worldToScreen (_worldPos);
		if (count _screenPos == 0) then {
			IND_REPAIR ctrlsetfade 1;
			IND_REPAIR ctrlcommit 0;
		} else {
		
			_screenX = _screenPos select 0;
			_screenY = _screenPos select 1;
		
			_pos = [
				(_screenX) - ((IND_W) * IND_COEF)/2,
				(_screenY) - ((IND_H) * IND_COEF)/2,
				IND_W,
				IND_H
			];
			
			_screenCenterX = _centerPos select 0;
			_screenCenterY = _centerPos select 1;
			
			if ( (abs (_screenCenterX - _screenX) < _thresholdX) and (abs (_screenCenterY - _screenY) < _thresholdY)) then {
				IND_REPAIR ctrlsettextcolor _colorGreen;
				IND_REPAIR ctrlsetfade 0;
				_actionId = _vehicle getVariable ["FLAY_HangGlider_AssembleActionId", -1];
				if (_actionId == -1) then {
					_actionId = player addAction [
						"Assemble", "\FLAY\FLAY_HangGlider\scripts\ev_assemble.sqf"
					];			
					_vehicle setVariable ["FLAY_HangGlider_AssembleActionId", _actionId];
				};
			} else {
				IND_REPAIR ctrlsettextcolor _colorGreen;
				IND_REPAIR ctrlsetfade 0.5;
				_actionId = _vehicle getVariable ["FLAY_HangGlider_AssembleActionId", -1];
				if (_actionId != -1) then {
					player removeAction _actionId;
					_actionId = -1;
					_vehicle setVariable ["FLAY_HangGlider_AssembleActionId", _actionId];
				};
			};
	
			IND_REPAIR ctrlsetposition _pos;
			IND_REPAIR ctrlcommit 0;
		};
	};
};