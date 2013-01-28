//(_this select 0) addAction ["Launch","\FLAY\FLAY_HangGlider\scripts\launch.sqf"];
_glider = (_this select 0);
//_glider setVehicleLock "LOCKED";
_id1 = _glider addAction ["Pickup","\FLAY\FLAY_HangGlider\scripts\pickup.sqf", _glider, 100, true, true, "", "driver _target != player"];
_glider setVariable ["idPickup", _id1];

fLift = compile preprocessFile "\FLAY\FLAY_HangGlider\scripts\lift.sqf";
fVRot2d = compile preprocessFile "\FLAY\FLAY_HangGlider\scripts\fn_rotatevector2d.sqf";

_markerstr = createMarker["thermal1",[4000,4000]];
_markerstr setMarkerShape "ELLIPSE";
_markerstr setMarkerType "Arrow";
_markerstr setMarkerBrush "FDiagonal";
_markerstr setMarkerSize [200,200];
_markerstr setMarkerText "Thermal";
_markerstr setMarkerColor "ColorBlue";

_glider addEventHandler ["fired", {addCamShake [3, 0.25, 75];}];
_glider addEventHandler ["GetIn", {hint "GetIn";[_this select 2,_this select 1,_this select 0] execVM "\FLAY\FLAY_HangGlider\scripts\pickup.sqf";}]; 
 