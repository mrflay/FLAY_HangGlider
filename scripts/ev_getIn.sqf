_glider = (_this select 0);

player sidechat "ev_onGetIn.sqf";
player sidechat str _glider;

[_glider] call FLAY_HangGlider_fnc_Ground;
