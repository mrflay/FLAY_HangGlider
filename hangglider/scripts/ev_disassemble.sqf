private ["_glider","_caller","_actionId","_params"];
private ["_item","_type","_anim","_vehicleClass"];

_glider = _this select 0;
_caller = _this select 1;
_actionId = _this select 2;
_params = _this select 3;

// must not be inside the glider or in another vehicle.
if (count crew _glider > 0) exitWith { diag_log "cannot disassemble glider with crew inside"; };

_vehicleClass = typeOf _glider;
_caller setVariable ["FLAY.HangGlider.ClassName", _vehicleClass];

_item = currentWeapon _caller;
_type = getNumber (configFile >> "cfgWeapons" >> _item >> "type");
_anim = "AmovPknlMstpSnonWnonDnon";

switch _type do {
  case 1 : { _anim = "AmovPknlMstpSlowWrflDnon"; };
  case 2 : { _anim = "AmovPknlMstpSlowWpstDnon"; };
  case 4 : { _anim = "AmovPknlMstpSlowWlnrDnon"; };
  default  { _anim = "AmovPknlMstpSnonWnonDnon"; };
};

diag_log format ["ev_disassemble: caller=%1, item=%2, type=%3, anim=%4", _caller, _item, _type, _anim];

_caller playMoveNow _anim;

sleep 1;

_caller playAction "PutDown";
playSound3D ["a3\sounds_f\characters\stances\change_unarmed_to_binoculars.wss", _caller];

_gliderPosATL = getPosATL _glider;
_glider setPosASL [-1000,-1000,-1000];
_glider setDammage 1;

_caller addBackpack "FLAY_HangGlider_Bag";
_caller addAction ["Assemble Hang Glider","FLAY\FLAY_HangGlider\hangglider\scripts\ev_assemble.sqf",[], -1, false, true, "", "backpack _this == 'FLAY_HangGlider_Bag'"];

sleep 1;
deleteVehicle _glider;
