_glider = (_this select 0);

private ["_glider","_v","_speed","_altitude","_vSpeedAvg","_anim","_airborne","_soundSource","_prevSoundSource"];

FLAY_HangGlider_fnc_Airborne = compile preprocessFile "\FLAY\FLAY_HangGlider\hangglider\scripts\fn_airborne.sqf";
FLAY_HangGlider_fnc_Ground = compile preprocessFile "\FLAY\FLAY_HangGlider\hangglider\scripts\fn_ground.sqf";

FLAY_HangGlider_EH_AirborneKeyDown = compile preprocessFile "\FLAY\FLAY_HangGlider\hangglider\scripts\ev_airborneKeyDown.sqf";
FLAY_HangGlider_EH_AirborneKeyUp = compile preprocessFile "\FLAY\FLAY_HangGlider\hangglider\scripts\ev_airborneKeyUp.sqf";
FLAY_HangGlider_EH_GroundKeyDown = compile preprocessFile "\FLAY\FLAY_HangGlider\hangglider\scripts\ev_groundKeyDown.sqf";
FLAY_HangGlider_EH_GroundKeyUp = compile preprocessFile "\FLAY\FLAY_HangGlider\hangglider\scripts\ev_groundKeyUp.sqf";
FLAY_HangGlider_EH_GetIn = compile preprocessFile "\FLAY\FLAY_HangGlider\hangglider\scripts\ev_getIn.sqf";
FLAY_HangGlider_EH_GetOut = compile preprocessFile "\FLAY\FLAY_HangGlider\hangglider\scripts\ev_getOut.sqf";

_glider addEventHandler ["fired", {addCamShake [3, 0.25, 75];}];
_glider setVehicleLock "LOCKED";

// EXPERIMENTAL - assemble / disassemble
//[_glider, "FLAY.craft.ui.pos_assemble","Disassemble Hang Glider","FLAY\FLAY_HangGlider\hangglider\scripts\ev_disassemble.sqf"] execVM "FLAY\FLAY_HangGlider\hangglider\scripts\fn_assemble.sqf";

_glider addAction ["Disassemble", "FLAY\FLAY_HangGlider\hangglider\scripts\ev_disassemble.sqf", [], -1, false, true, "", "backpack player == ''"];

[_glider] spawn {

	private ["_glider","_v","_speed","_altitude","_anim","_airborne"];
	
	_glider = (_this select 0);
			
	_camShakeTimeout = 0;
	
	// swoop effect
	_trail1 = "#particlesource" createVehicleLocal (getpos _glider);
	_trail1 attachto [_glider,[0,0,0],"swoop"];
	_trail1 setParticleRandom [0.2, [0.05, 0.05, 0.05], [0, 0, 0], 0, 0, [0, 0, 0, 0], 0, 0];

	
	while { alive _glider } do {
		
		if (vehicle player == _glider) then {
						
			_v = velocity _glider;
			
			_speed = sqrt((_v select 0)^2+(_v select 1)^2+(_v select 2)^2);
			_altitude = (getPosATL _glider) select 2; //_glider animationPhase "LandingGearDamper";
			
			if (_speed > 5 and time > _camShakeTimeout) then {
				addCamShake [_speed / 100, 15, _speed / 4];
				_camShakeTimeout = time + 5;
			};
			
			_landAnim = "HangGlider_PilotLand";
			_stopAnim = "AmovPercMstpSnonWnonDnon";
			_pilotAnim = "HangGlider_Pilot";
			_swoopAnim = "HangGlider_PilotSwoop";
			_posASL = getPosASL _glider;
			_xy = [_posASL select 0, _posASL select 1];
			_altitudeASL = _posASL select 2;
			_trail1 setdropinterval 0;
			
			if (_altitudeASL < 5) then {
				if (surfaceIsWater _xy) then {
					if (animationState player != _swoopAnim) then {
						player playMoveNow _swoopAnim;
						_glider animate ["FireGeoPilotHide", 1];
					};
					if ( _altitudeASL < 1.9) then {
						_intensity = 1;
						_interval = 0.01;
						_trail1 setdropinterval _interval;
						_trail1 setParticleParams [
							["\A3\data_f\ParticleEffects\Universal\Universal.p3d", 16, 13, 3, 0],
							"", "Billboard", 1, 1.0*_intensity, 
							[0,0,0], _v, 0, 1, 0.79, 0.18, [0.5, 1+_intensity/1.7], 
							[[1, 1, 1, 0.04*_intensity],[1, 1, 1, 0.14*_intensity],[1, 1, 1, 0.05*_intensity], [1, 1, 1, 0]], [1000], 100, 0.01, "", "", "",360
						];
					};
				} else {
					if (animationState player == _swoopAnim) then {
						player playMove _pilotAnim;
						_glider animate ["FireGeoPilotHide", 0];
					};
				};
			} else {
				if (animationState player == _swoopAnim) then {
					player playMove _pilotAnim;
					_glider animate ["FireGeoPilotHide", 0];
				};
			};
			
			if (_altitude < 2) then {
				
				_landing = _glider getVariable ["FLAY.hangglider.state.landing", false];
				
				if (_landing and (_speed < 5)) then {
					player playAction "CarryHangGliderGesture";
					player switchMove "AmovPercMstpSnonWnonDnon";
					
					[_glider] call FLAY_HangGlider_fnc_Ground;
				};
				
				if (abs(_glider animationPhase "PilotPitch") > 0.8) then {
					[_glider, "DRIVER", driver _glider] call FLAY_HangGlider_EH_GetOut;
				};
				
				if (abs(_glider animationPhase "PilotBank") > 0.8) then {
					[_glider, "DRIVER", driver _glider] call FLAY_HangGlider_EH_GetOut;
				};

				if ((animationState player != _stopAnim) and (_speed < 1)) then {
					if (not _landing) then {
						player playMoveNow _stopAnim;
					};
				};
								
				sleep 0.05;
			} else {
				sleep 1;	
			};
			

			
		} else {
			sleep 5;
		};
	};
};