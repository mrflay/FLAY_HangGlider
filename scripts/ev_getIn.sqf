private ["_glider","_trolley","_animData","_actionId"];

_glider = (_this select 0);
_actionId = (_this select 1);

_trolley = "FLAY_HiddenTrolley" createVehicleLocal (getpos player);
_trolley setPosASL (getPosASL player);

player moveInDriver _trolley;
player setVariable ["FLAY_HangGlider_PlaybackDone", false];

BIS_fnc_UnitPlaySimple = compile preprocessFile "\FLAY\FLAY_HangGlider\scripts\fn_UnitPlaySimpleAnim.sqf";
_animData = [[0,getPosASL player,getDir player],[2,getPosASL _glider, getDir player]];
[_trolley, _animData, [player, "FLAY_HangGlider_PlaybackDone"], true, false, 0, 0] spawn BIS_fnc_UnitPlaySimple;

player switchMove "AmovPknlMrunSnonWnonDf";

[_glider, _trolley] spawn {
	private ["_glider","_trolley","_playbackDone"];
	_glider = _this select 0;
	_trolley = _this select 1;
	_playbackDone = false;
	
	while { not _playbackDone } do {
		_playbackDone = player getVariable ["FLAY_HangGlider_PlaybackDone", false];
	};
	moveOut player;
	player moveInDriver _glider;
	_glider setVectorUp [0,0,1];
	player switchMove "AmovPknlMstpSnonWnonDnon_AinvPknlMstpSnonWnonDnon";
	player playAction "CarryHangGliderGesture";
	sleep 1;
	player switchMove "AmovPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon";
	deleteVehicle _trolley;
	
	0=[_glider] spawn {
		private ["_glider","_actionId"];
		_glider = _this select 0;
		_glider setVehicleLock "UNLOCKED";

		_actionId = _glider getVariable ["FLAY_HangGlider_GetInActionId", -1];
		if (_actionId != -1) then {
			_glider removeAction _actionId;
			_glider setVariable ["FLAY_HangGlider_GetInActionId", -1];
		};

		//_actionId = player addAction [ "Get Out", "\FLAY\FLAY_HangGlider\scripts\ev_getOut.sqf" ];
		
		[_glider] call FLAY_HangGlider_fnc_Ground;
	};
	
};
