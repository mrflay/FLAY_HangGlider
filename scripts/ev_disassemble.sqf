player sidechat "hang glider disassembled";


_target = _this select 0;
_caller = _this select 1;
_actionId = _this select 2;
_params = _this select 3;
_glider = _params select 0;

_vehicleClass = typeOf _glider;

_gliderPosATL = getPosATL _glider;
_glider setPosASL [-1000,-1000,-1000];
_glider setDammage 1;

_bag = "FLAY_HangGlider_Bag" createVehicle _gliderPosATL;
_bag setPosATL _gliderPosATL;
_bag setVariable ["FLAY.HangGlider.ClassName", _vehicleClass];

sleep 1;
deleteVehicle _glider;

_target removeAction _actionId;