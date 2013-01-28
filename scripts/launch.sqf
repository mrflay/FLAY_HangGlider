_s = 0.0;
_v = velocity player;
_p = getpos player;
_d = getdir player;
_glider = _this select 3;
_glider setpos [_p select 0, _p select 1, (_p select 2) + 1.1];
_glider setdir _d;
//_glider setVehicleLock "UNLOCKED";
player playAction "CarryHangGliderResetGesture";
player moveInDriver _glider;
_glider enableSimulation true;
_u = vehicle player;
_u setvectorup [0,0,1];
_d = vectorDir _u;
_u setvelocity [(_v select 0) + _s * (_d select 0), (_v select 1) + _s * (_d select 1), (_v select 2)];
addCamShake [2, 25, 10];
_id1 = _glider getVariable "idDrop";
_id2 = _glider getVariable "idLaunch";
player removeAction _id1;
player removeAction _id2;
_id3 = _glider addAction ["Pickup","\FLAY\FLAY_HangGlider\scripts\pickup.sqf", _glider, 100, true, true, "", "driver _target != player"];
_glider setVariable ["idPickup", _id3];

_primaryWeapon = _glider getVariable "primaryWeapon";
player removeWeapon "HangGliderDummyWeapon";
player addWeapon _primaryWeapon;
_glider setVariable ["primaryWeapon",""];

keyspressed=compile preprocessFile "\FLAY\FLAY_HangGlider\scripts\keyspressed.sqf";
handlerId = (findDisplay 46) displayAddEventHandler ["KeyDown","_this call keyspressed"];

_glider addEventHandler ["GetOut", {hint "GetOut";(findDisplay 46) displayRemoveEventHandler ["KeyDown",handlerId]}];

