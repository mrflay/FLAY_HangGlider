private ["_glider","_trolley","_animData","_actionId"];

_glider = (_this select 0);
_actionId = (_this select 1);

player moveInDriver _glider;
player playAction "CarryHangGliderGesture";
player switchMove "AmovPercMstpSnonWnonDnon";
_glider setvectorup [0,0,1];
[_glider] call FLAY_HangGlider_fnc_Ground;
if (true) exitWith {};

//_trolley = "FLAY_HiddenTrolley" createVehicleLocal (getpos player);
//_trolley setPosASL (getPosASL player);

_trolley = player;

//player moveInDriver _trolley;
player setVariable ["FLAY_HangGlider_PlaybackDone", false];

_p = getPosATL player;
_q = getPosATL _glider;

_dist = sqrt (((_q select 0)-(_p select 0))^2 + ((_q select 1)-(_p select 1))^2 + ((_q select 2)-(_p select 2))^2);
_time = (_dist / 2);

FLAY_fnc_UnitPlaySimpleAnim = compile preprocessFile "\FLAY\FLAY_HangGlider\scripts\fn_UnitPlaySimpleAnim.sqf";
_endpos = getPosATL _glider;
_endpos = [_endpos select 0, _endpos select 1, 0];
_animData = [[0, getPosATL player, getDir player],[_time, _endpos, getDir player]];
[_trolley, _animData, [player, "FLAY_HangGlider_PlaybackDone"], true, false, 0, 0] spawn FLAY_fnc_UnitPlaySimpleAnim;

player playMove "AmovPknlMrunSnonWnonDf";

[_glider, _trolley] spawn {
	private ["_glider","_trolley","_playbackDone"];
	_glider = _this select 0;
	_trolley = _this select 1;
	_playbackDone = false;
	_glider enablesimulation false;
	while { not _playbackDone } do {
		_playbackDone = player getVariable ["FLAY_HangGlider_PlaybackDone", false];
	};
	//moveOut player;
	player attachTo [_glider, [0,0,-1.2]];
	_glider animate ["FeetStabilizer", 0.9];
	_glider setVectorUp [0,0,1];
	player playMoveNow "AmovPknlMstpSnonWnonDnon_AinvPknlMstpSnonWnonDnon";
	sleep 2;
	player playMove "AmovPknlMstpSnonWnonDnon_AmovPercMstpSnonWnonDnon";
	sleep 2;
	_glider animate ["HarnessHide", 1];
	detach player;
	player moveInDriver _glider;
	player playAction "CarryHangGliderGesture";
	player switchMove "AmovPercMstpSnonWnonDnon";
	_glider enablesimulation true;
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
