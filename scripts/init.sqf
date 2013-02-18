_glider = (_this select 0);

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

[_glider] spawn {
	[_this select 0] call FLAY_HangGlider_fnc_VapourTrails;
};

_soundSource = createSoundSource ["Sound_Vario1", [0,0,0], [], 0];
_soundSource attachTo [_glider, [0.5,0,0.2]];

[_glider] spawn {
	_glider = _this select 0;
	_counter = 2;
	player sidechat "start";
	
	while { alive _glider } do {
		sleep 0.5;
		_counter = _counter - 1;
		if (_counter <= 0) then {
			//if (not (isNull _soundSource)) then { deletevehicle _soundSource; };
			//_glider say2d "FLAY_VarioClimb1";
			_counter = 2;
		};
		_v = velocity _glider;
		_speed = sqrt((_v select 0)^2+(_v select 1)^2+(_v select 2)^2);
		_altitude = _glider animationPhase "FeetDamper";
		if (vehicle player == _glider and _altitude > 2) then {
			//_anim = "HangGlider_Pilot";
			//if (animationState player != _anim) then {
			//	player playAction "ResetGesture";
			//	player switchMove _anim;
			//	_glider animate ["PilotPosY", 0];
			//	_glider animate ["PilotPosZ", 0];
			//};
		} else {
			_anim = "AmovPercMstpSlowWrflDnon";
			if ((animationState player != _anim) and (_speed < 0.1) and (vehicle player == _glider)) then {
				_airborne = _glider getVariable ["FLAY_HangGlider_airborne", false];
				if (not _airborne) then {
					//player switchMove _anim;
				};
			};
		};
	};
	hint "dead";
	player sidechat "end";
};