_target = (_this select 0);
_caller = (_this select 1);
_actionId = (_this select 2);
_params = (_this select 3);
_bag = _params select 0;

_bagPosATL = getPosATL _bag;

player sidechat "take bag";

//_bagLauncher = "FLAY_HangGlider_BagLauncher" createVehicle _bagPosATL;
//_bagLauncher setPosATL _bagPosATL;

_vehicleClass = _bag getVariable ["FLAY.HangGlider.ClassName", "FLAY_HangGlider"];
_caller setVariable ["FLAY.HangGlider.ClassName", "FLAY_HangGlider"];

_bagPosATL = getPosATL _bag;
_bag setPosASL [-1000,-1000,-1000];
_bag setDammage 1;

deleteVehicle _bag;

player addWeapon "FLAY_HangGlider_BagLauncher";
player selectWeapon "FLAY_HangGlider_BagLauncher";

