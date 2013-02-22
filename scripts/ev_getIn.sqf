private ["_glider","_trolley","_animData","_actionId"];

_glider = (_this select 0);
_actionId = (_this select 1);

_trolley = "FLAY_HiddenTrolley" createVehicleLocal (getpos player);
_trolley setPosASL (getPosASL player);

player moveInDriver _trolley;
player setVariable ["FLAY_HangGlider_PlaybackDone", false];

_p = getPosATL player;
_q = getPosATL _glider;

_dist = sqrt (((_q select 0)-(_p select 0))^2 + ((_q select 1)-(_p select 1))^2 + ((_q select 2)-(_p select 2))^2);
_time = (_dist / 2);

FLAY_fnc_UnitPlaySimpleAnim = compile preprocessFile "\FLAY\FLAY_HangGlider\scripts\fn_UnitPlaySimpleAnim.sqf";
_animData = [[0, getPosATL player, getDir player],[_time, getPosATL _glider, getDir player]];
[_trolley, _animData, [player, "FLAY_HangGlider_PlaybackDone"], true, false, 0, 0] spawn FLAY_fnc_UnitPlaySimpleAnim;

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
