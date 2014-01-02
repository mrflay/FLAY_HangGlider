_glider = _this select 0;
_caller = _this select 1;
_actionId = _this select 2;

_gliderPosATL = getPosATL _glider;
_glider setPosASL [-1000,-1000,-1000];
_glider setDammage 1;

_vehicleClass = typeOf _glider;
_caller setVariable ["FLAY.HangGlider.ClassName", _vehicleClass];

_caller addBackpack "FLAY_HangGlider_Bag";
player addAction ["Assemble Hang Glider","FLAY\FLAY_HangGlider\hangglider\scripts\ev_assemble.sqf",[], -1, false, true, "", "backpack player == 'FLAY_HangGlider_Bag'"];

sleep 1;
deleteVehicle _glider;
