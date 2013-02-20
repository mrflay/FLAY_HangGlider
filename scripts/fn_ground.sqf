// FLAY_HangGlider_fnc_Airborne
_glider = (_this select 0);

//_airborne = _glider getVariable ["FLAY_HangGlider_airborne", false];
//if (not _airborne) then {
//};

_KeyDownHandlerId = _glider getVariable ["FLAY_HangGlider_KeyDownHandlerId", -1];
if (_KeyDownHandlerId != -1) then {
	(findDisplay 46) displayRemoveEventHandler ["KeyDown", _KeyDownHandlerId];
};

_KeyUpHandlerId = _glider getVariable ["FLAY_HangGlider_KeyUpHandlerId", -1];
if (_KeyUpHandlerId != -1) then {
	(findDisplay 46) displayRemoveEventHandler ["KeyUp", _KeyUpHandlerId];
};

_KeyDownHandlerId = (findDisplay 46) displayAddEventHandler ["KeyDown","_this call FLAY_HangGlider_EH_GroundKeyDown"];
_KeyUpHandlerId = (findDisplay 46) displayAddEventHandler ["KeyUp","_this call FLAY_HangGlider_EH_GroundKeyUp"];

_glider setVariable ["FLAY_HangGlider_KeyDownHandlerId", _KeyDownHandlerId];
_glider setVariable ["FLAY_HangGlider_KeyUpHandlerId", _KeyUpHandlerId];

_glider animate ["PilotPosY",0.5];
_glider animate ["PilotPosZ",-0.1];


//player switchMove "AmovPercMstpSlowWrflDnon";
//player switchMove "AmovPknlMstpSlowWrflDnon";

_glider setVariable ["FLAY_HangGlider_airborne", false];

_glider animate ["FeetStabilizer", 1];
_glider setVectorUp (vectorUp _glider);

