_target = _this select 0;
_caller = _this select 1;
_actionId = _this select 2;
_params = _this select 3;

_callerPosATL = getPosATL _caller;

_vehicleClass = _caller getVariable ["FLAY.HangGlider.ClassName", "FLAY_HangGlider"];
_glider = _vehicleClass createVehicle _callerPosATL;
_glider setPosATL _callerPosATL;
_glider setDir (getDir _caller);

removeBackpack _caller;

_target removeAction _actionId;