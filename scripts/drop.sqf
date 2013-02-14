_s = 25;
_v = velocity player;
_glider = _this select 3;

_glider setpos [getpos player select 0, getpos player select 1, 1];
_glider enableSimulation true;
_glider setvectorup [0,0,1];
_glider setvelocity [(_v select 0) + _s * sin getdir _u, (_v select 1) + _s * cos getdir _u, (_v select 2) + 1];
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
player playAction "ResetGesture";