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

_glider addEventHandler ["fired", {addCamShake [3, 0.25, 75];}];
_glider addEventHandler ["GetIn", {[_this select 0] call FLAY_HangGlider_EH_GetIn;}];
_glider addEventHandler ["GetOut", {[_this select 0] call FLAY_HangGlider_EH_GetOut;}]; 

//[_glider] spawn {
//	[_this select 0] call FLAY_HangGlider_fnc_VapourTrails;
//};

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
		["Sound_VarioUp01", [0,0,0], [], 0],
		["Sound_VarioUp05", [0,0,0], [], 0],
		["Sound_VarioUp10", [0,0,0], [], 0],
		["Sound_VarioUp15", [0,0,0], [], 0],
		["Sound_VarioUp20", [0,0,0], [], 0],
		["Sound_VarioUp25", [0,0,0], [], 0],
		["Sound_VarioUp30", [0,0,0], [], 0],
		["Sound_VarioUp35", [0,0,0], [], 0],
		["Sound_VarioUp40", [0,0,0], [], 0]
	];
	
	_index = 9;
	_prevIndex = 9;
	_count = 0;
	_vSpeedAvg = 0;
	_soundSource = objNull;
	
	while { alive _glider } do {
		
		if (vehicle player == _glider) then {
			
			sleep 0.1;
			
			_v = velocity _glider;
			
			_speed = sqrt((_v select 0)^2+(_v select 1)^2+(_v select 2)^2);
			_altitude = _glider animationPhase "FeetDamper";
			
			_count = _count + 1;
			if (_count < 10) then {
				_vSpeedCur = _v select 2;
				_vSpeedAvg = _vSpeedAvg + _vSpeedCur;
			} else {
				_vSpeedAvg = _vSpeedAvg / 10.0;
								
				_index = 9;
				
				if (_vSpeedAvg < -5) then {
					_index = 8;
					hint "-5";
				};
				if (_vSpeedAvg > 0.1) then {
					_index = 10;
					hint "0.1";
				};
				if (_vSpeedAvg > 0.5) then {
					_index = 11;
					hint "0.5";
				};
				if (_vSpeedAvg > 1.0) then {
					_index = 12;
					hint "1.0";
				};
				if (_vSpeedAvg > 1.5) then {
					_index = 13;
					hint "1.5";
				};
				if (_vSpeedAvg > 2.0) then {
					_index = 14;
					hint "2.0";
				};
				if (_vSpeedAvg > 3.0) then {
					_index = 15;
					hint "3.0";
				};
				if (_vSpeedAvg > 4.0) then {
					_index = 16;
					hint "4.0";
				};
				if (_vSpeedAvg > 5.0) then {
					_index = 17;
					hint "5.0";
				};
				if (_vSpeedAvg > 6.0) then {
					_index = 18;
					hint "6.0";
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
			
			//if (vehicle player == _glider and _altitude > 2) then {
				//_anim = "HangGlider_Pilot";
				//if (animationState player != _anim) then {
				//	player playAction "ResetGesture";
				//	player switchMove _anim;
				//	_glider animate ["PilotPosY", 0];
				//	_glider animate ["PilotPosZ", 0];
				//};
			//} else {
			//	_anim = "AmovPercMstpSlowWrflDnon";
			//	if ((animationState player != _anim) and (_speed < 0.1) and (vehicle player == _glider)) then {
			//		_airborne = _glider getVariable ["FLAY_HangGlider_airborne", false];
			//		if (not _airborne) then {
			//			//player switchMove _anim;
			//		};
			//	};
			//};
			
		} else {
			sleep 5;
		};
	};
	hint "dead";
	player sidechat "end";
};