_glider = _this select 3;
//_glider attachTo [player, [0,0,1.6]];
_glider enableSimulation false;
_glider setposatl [0,0,100];
_primaryWeapon = primaryWeapon player;
_glider setVariable ["primaryWeapon", _primaryWeapon];
player removeWeapon _primaryWeapon;
player addWeapon "HangGliderDummyWeapon";
player playAction "CarryHangGliderGesture";
_id2 = player addAction ["Drop","\FLAY\FLAY_HangGlider\scripts\drop.sqf", _glider, 100, true, true, ""];
_id3 = player addAction ["Launch", "\FLAY\FLAY_HangGlider\scripts\launch.sqf", _glider, 200, true, true, ""];
_glider setVariable ["idDrop", _id2];
_glider setVariable ["idLaunch", _id3];

_id1 = _glider getVariable "idPickup";
_glider removeAction _id1;