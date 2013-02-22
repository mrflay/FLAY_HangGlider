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
[_glider, "FLAY.craft.ui.pos_disassemble","Disassemble Hang Glider","FLAY\FLAY_HangGlider\scripts\ev_disassemble.sqf"] execVM "FLAY\FLAY_HangGlider\scripts\fn_assemble.sqf";

[_glider] spawn {
	[_this select 0] call FLAY_HangGlider_fnc_VapourTrails;
};

[_glider] spawn {

	private ["_glider","_v","_speed","_altitude","_vSpeedAvg","_anim","_airborne","_soundSource","_prevSoundSource"];
	
	_glider = (_this select 0);

	player sidechat "start";
		
	_soundSourceArray = [
		["Sound_VarioDn01", [0,0,0], [], 0],
		["Sound_VarioDn01", [0,0,0], [], 0],
		["Sound_VarioDn01", [0,0,0], [], 0],
		["Sound_VarioDn01", [0,0,0], [], 0],
		["Sound_VarioDn01", [0,0,0], [], 0],
		["Sound_VarioDn01", [0,0,0], [], 0],
		["Sound_VarioDn01", [0,0,0], [], 0],
		["Sound_VarioDn01", [0,0,0], [], 0],
		["Sound_VarioDn01", [0,0,0], [], 0],
		["Sound_Silence",   [0,0,0], [], 0],
		//["Sound_VarioUp01", [0,0,0], [], 0],
		["Sound_VarioUp02", [0,0,0], [], 0],
		//["Sound_VarioUp03", [0,0,0], [], 0],
		["Sound_VarioUp04", [0,0,0], [], 0],
		//["Sound_VarioUp05", [0,0,0], [], 0],
		["Sound_VarioUp06", [0,0,0], [], 0],
		//["Sound_VarioUp07", [0,0,0], [], 0],
		["Sound_VarioUp08", [0,0,0], [], 0],
		//["Sound_VarioUp09", [0,0,0], [], 0],
		["Sound_VarioUp10", [0,0,0], [], 0],
		//["Sound_VarioUp11", [0,0,0], [], 0],
		["Sound_VarioUp12", [0,0,0], [], 0],
		//["Sound_VarioUp13", [0,0,0], [], 0],
		["Sound_VarioUp14", [0,0,0], [], 0],
		//["Sound_VarioUp15", [0,0,0], [], 0],
		["Sound_VarioUp16", [0,0,0], [], 0],
		//["Sound_VarioUp17", [0,0,0], [], 0],
		["Sound_VarioUp18", [0,0,0], [], 0],
		//["Sound_VarioUp19", [0,0,0], [], 0],
		["Sound_VarioUp20", [0,0,0], [], 0],
		//["Sound_VarioUp21", [0,0,0], [], 0],
		["Sound_VarioUp22", [0,0,0], [], 0],
		//["Sound_VarioUp23", [0,0,0], [], 0],
		["Sound_VarioUp24", [0,0,0], [], 0],
		//["Sound_VarioUp25", [0,0,0], [], 0],
		["Sound_VarioUp26", [0,0,0], [], 0],
		//["Sound_VarioUp27", [0,0,0], [], 0],
		["Sound_VarioUp28", [0,0,0], [], 0],
		//["Sound_VarioUp29", [0,0,0], [], 0],
		["Sound_VarioUp30", [0,0,0], [], 0],
		//["Sound_VarioUp31", [0,0,0], [], 0],
		["Sound_VarioUp32", [0,0,0], [], 0],
		//["Sound_VarioUp33", [0,0,0], [], 0],
		["Sound_VarioUp34", [0,0,0], [], 0],
		//["Sound_VarioUp35", [0,0,0], [], 0],
		["Sound_VarioUp36", [0,0,0], [], 0],
		//["Sound_VarioUp37", [0,0,0], [], 0],
		["Sound_VarioUp38", [0,0,0], [], 0],
		//["Sound_VarioUp39", [0,0,0], [], 0],
		["Sound_VarioUp40", [0,0,0], [], 0]
	];
	
	_index = 9;
	_prevIndex = 9;
	_count = 0;
	_vSpeedAvg = 0;
	_soundSource = objNull;
	_camShakeTimeout = 0;
	
	while { alive _glider } do {
		
		if (vehicle player == _glider) then {
			
			sleep 0.2;
						
			_v = velocity _glider;
			
			_speed = sqrt((_v select 0)^2+(_v select 1)^2+(_v select 2)^2);
			_altitude = _glider animationPhase "FeetDamper";
			
			_count = _count + 1;
			if (_count < 5) then {
				_vSpeedCur = _v select 2;
				_vSpeedAvg = _vSpeedAvg + _vSpeedCur;
			} else {
				_vSpeedAvg = _vSpeedAvg / 10.0;
				_index = 9;
				
				if (_vSpeedAvg < -1) then {
					_index = 8;
				};
				if (_vSpeedAvg > 0.1) then {
					_index = (10 + round (2 * _vSpeedAvg)) min 19;
				};
				
				if (_prevIndex != _index) then {
					if (not (isNull _soundSource)) then {
						detach _soundSource;
						deleteVehicle _soundSource;
					};
					if (_index != 9) then {
						_soundSource = createSoundSource (_soundSourceArray select _index);
						_soundSource attachTo [_glider, [0,0,0], "pos_vario"];
					};
					_prevIndex = _index;
				};
				
				_count = 0;
				_vSpeedAvg = 0;
			};
			
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