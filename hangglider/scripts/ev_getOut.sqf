// FLAY_HangGlider_EH_GetOut

if ((count _this) < 3) exitWith { player sidechat "getOut params < 3"; };

_glider = _this select 0;
_position = _this select 1;
_unit = _this select 2;

if (_position == "DRIVER" and _unit == player) then {

	_KeyDownHandlerId = _glider getVariable ["FLAY_HangGlider_KeyDownHandlerId", -1];
	if (_KeyDownHandlerId != -1) then {
		(findDisplay 46) displayRemoveEventHandler ["KeyDown", _KeyDownHandlerId];
	};

	_KeyUpHandlerId = _glider getVariable ["FLAY_HangGlider_KeyUpHandlerId", -1];
	if (_KeyUpHandlerId != -1) then {
		(findDisplay 46) displayRemoveEventHandler ["KeyUp", _KeyUpHandlerId];
	};

	_unit playAction "ResetGesture";
	
	moveOut _unit;
	
	_unit setPosASL [getPosASL _glider select 0, getPosASL _glider select 1, getPosASL _glider select 2];
	_unit setDir (getDir _glider);
	
	_item = currentWeapon _unit;
	_type = getNumber (configFile >> "cfgWeapons" >> _item >> "type");
	_anim = "AmovPknlMstpSnonWnonDnon";

	switch _type do {
	  case 1 : { _anim = "AmovPknlMstpSlowWrflDnon"; };
	  case 2 : { _anim = "AmovPknlMstpSlowWpstDnon"; };
	  case 4 : { _anim = "AmovPknlMstpSlowWlnrDnon"; };
	  default  { _anim = "AmovPknlMstpSnonWnonDnon"; };
	};

	_unit switchMove _anim;	
	
	_glider animate ["LandingGear", 0.15];
	_glider setVectorUp (vectorUp _glider);
	_glider setVehicleLock "LOCKED";
	
};