private ["_target","_caller","_actionId","_params"];
private ["_item","_type","_anim","_glider","_vehicleClass"];

_target = _this select 0;
_caller = _this select 1;
_actionId = _this select 2;
_params = _this select 3;

_callerPosATL = getPosATL _caller;

_item = currentWeapon _caller;
_type = getNumber (configFile >> "cfgWeapons" >> _item >> "type");
_anim = "AmovPknlMstpSnonWnonDnon";

switch _type do {
  case 1 : { _anim = "AmovPknlMstpSlowWrflDnon"; };
  case 2 : { _anim = "AmovPknlMstpSlowWpstDnon"; };
  case 4 : { _anim = "AmovPknlMstpSlowWlnrDnon"; };
  default  { _anim = "AmovPknlMstpSnonWnonDnon"; };
};

_caller playMoveNow _anim;

sleep 1;

_caller playAction "PutDown";
playSound3D ["a3\sounds_f\characters\stances\change_binoculars_to_unarmed.wss", _caller];

_vehicleClass = _caller getVariable ["FLAY.HangGlider.ClassName", "FLAY_HangGlider"];
_glider = _vehicleClass createVehicle _callerPosATL;
_glider  setPosATL (_caller modelToWorld [0,1,0]);
_glider setDir (getDir _caller);

removeBackpack _caller;

_target removeAction _actionId;