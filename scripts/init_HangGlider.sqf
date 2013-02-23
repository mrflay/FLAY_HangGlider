_glider = (_this select 0);

private ["_glider","_v","_speed","_altitude","_vSpeedAvg","_anim","_airborne","_soundSource","_prevSoundSource"];

FLAY_HangGlider_fnc_Airborne = compile preprocessFile "\FLAY\FLAY_HangGlider\scripts\fn_airborne.sqf";
FLAY_HangGlider_fnc_Ground = compile preprocessFile "\FLAY\FLAY_HangGlider\scripts\fn_ground.sqf";
FLAY_HangGlider_fnc_VapourTrails = compile preprocessFile "\FLAY\FLAY_HangGlider\scripts\fn_vapourTrails.sqf";

FLAY_HangGlider_EH_AirborneKeyDown = compile preprocessFile "\FLAY\FLAY_HangGlider\scripts\ev_airborneKeyDown.sqf";
FLAY_HangGlider_EH_AirborneKeyUp = compile preprocessFile "\FLAY\FLAY_HangGlider\scripts\ev_airborneKeyUp.sqf";
FLAY_HangGlider_EH_GroundKeyDown = compile preprocessFile "\FLAY\FLAY_HangGlider\scripts\ev_groundKeyDown.sqf";
FLAY_HangGlider_EH_GroundKeyUp = compile preprocessFile "\FLAY\FLAY_HangGlider\scripts\ev_groundKeyUp.sqf";
FLAY_HangGlider_EH_GetIn = compile preprocessFile "\FLAY\FLAY_HangGlider\scripts\ev_getIn.sqf";
FLAY_HangGlider_EH_GetOut = compile preprocessFile "\FLAY\FLAY_HangGlider\scripts\ev_getOut.sqf";

FLAY_HangGlider_IndicatorCounter = -1;

_glider addEventHandler ["fired", {addCamShake [3, 0.25, 75];}];
//_glider addEventHandler ["GetIn", {[_this select 0] call FLAY_HangGlider_EH_GetIn;}];
_glider addEventHandler ["GetOut", FLAY_HangGlider_EH_GetOut]; 
_glider setVehicleLock "LOCKED";

// EXPERIMENTAL - assemble / disassemble
//[_glider, "FLAY.craft.ui.pos_assemble","Disassemble Hang Glider","FLAY\FLAY_HangGlider\scripts\ev_disassemble.sqf"] execVM "FLAY\FLAY_HangGlider\scripts\fn_assemble.sqf";

// TEMPORARY - testing "Get In" animation.
_glider addAction ["Get In", "FLAY\FLAY_HangGlider\scripts\ev_getIn.sqf"];

[_glider] spawn {
	[_this select 0] call FLAY_HangGlider_fnc_VapourTrails;
};

[_glider] spawn {

	private ["_glider","_v","_speed","_altitude","_anim","_airborne"];
	
	_glider = (_this select 0);

	player sidechat "start";
			
	_camShakeTimeout = 0;
	
	while { alive _glider } do {
		
		if (vehicle player == _glider) then {
			
			sleep 0.2;
						
			_v = velocity _glider;
			
			_speed = sqrt((_v select 0)^2+(_v select 1)^2+(_v select 2)^2);
			_altitude = _glider animationPhase "FeetDamper";
			
			// TODO - Camera shake
			if (_speed > 5 and time > _camShakeTimeout) then {
				addCamShake [_speed / 50, 15, _speed / 2];
				_camShakeTimeout = time + 5;
			};
			
			if (_altitude < 2) then {
				_landAnim = "HangGlider_PilotLand";
				_stopAnim = "AmovPercMstpSlowWrflDnon";
				_airborne = _glider getVariable ["FLAY_HangGlider_airborne", false];
				if ((animationState player != _stopAnim) and (_speed < 0.1)) then {
					if (not _airborne) then {
						player switchMove _stopAnim;
					};
				} else {
					// enable ground movement
					if (not _airborne) then {
						[_glider] call FLAY_HangGlider_fnc_Ground;
					};
				};
			};
			
		} else {
			sleep 5;
		};
	};
	hint "dead";
	player sidechat "end";
};