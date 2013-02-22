player sidechat "hang glider assembled";

_target = _this select 0;
_caller = _this select 1;
_actionId = _this select 2;
_params = _this select 3;
_bag = _params select 0;

_bagPosATL = getPosATL _bag;
_bag setPosASL [-1000,-1000,-1000];
_bag setDammage 1;

_vehicleClass = _bag getVariable ["FLAY.HangGlider.ClassName", "FLAY_HangGlider"];
_glider = _vehicleClass createVehicle _bagPosATL;
_glider setPosATL _bagPosATL;

sleep 1;
deleteVehicle _bag;

_target removeAction _actionId;