// FLAY_HangGlider_fnc_Airborne
_glider = (_this select 0);

_KeyDownHandlerId = _glider getVariable ["FLAY_HangGlider_KeyDownHandlerId", -1];
if (_KeyDownHandlerId != -1) then {
	(findDisplay 46) displayRemoveEventHandler ["KeyDown", _KeyDownHandlerId];
};

_KeyUpHandlerId = _glider getVariable ["FLAY_HangGlider_KeyUpHandlerId", -1];
if (_KeyUpHandlerId != -1) then {
	(findDisplay 46) displayRemoveEventHandler ["KeyUp", _KeyUpHandlerId];
};

_KeyDownHandlerId = (findDisplay 46) displayAddEventHandler ["KeyDown","_this call FLAY_HangGlider_EH_AirborneKeyDown"];
_KeyUpHandlerId = (findDisplay 46) displayAddEventHandler ["KeyUp","_this call FLAY_HangGlider_EH_AirborneKeyUp"];

_glider setVariable ["FLAY_HangGlider_KeyDownHandlerId", _KeyDownHandlerId];
_glider setVariable ["FLAY_HangGlider_KeyUpHandlerId", _KeyUpHandlerId];


_glider setVariable ["FLAY_HangGlider_airborne", true];
_glider setVariable ["FLAY.hangglider.state.landing", false];
_glider animate ["LandingGear", 0.15];
_glider setVectorUp (vectorUp _glider);

_glider animate ["HarnessAnchorHide",0];
_glider animate ["HarnessStrapsHide",0];

_glider animate ["pilotposz",-0.05]; 
_glider animate ["pilotposy",0.05]; 
_glider animate ["gliderpitch", 5];

FLAY_HangGlider_BlockSpaceKeyUntilReleased = true;