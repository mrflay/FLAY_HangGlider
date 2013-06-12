// fn_lift.sqf

_this spawn {
	
	private ["_done"];

	player sideChat "START lift.sqf";
	
	// maximum radius too look for thermals
	_THERMAL_MAX_RADIUS = 1000;
	_RIDGE_MAX_RADIUS = 1000;
	
	_done = false;
	
	while { not _done } do {
	
		// find all appropriate vehicles (FIXME: only checking player for now)
		_vehicles = [vehicle player];
		
		{
			_vehicle = _x;
			_speed = speed _vehicle;
			_altitudeATL = (getPosATL _vehicle) select 2;
			
			// FIXME: lift is only applied to FLAY_HangGlider at the moment
			if (_vehicle isKindOf "FLAY_HangGlider") then {
				_enableThermalLift = _vehicle getVariable ["FLAY.HangGlider.lift.thermal.enable", true];
				_enableRidgeLift = _vehicle getVariable ["FLAY.HangGlider.lift.ridge.enable", false];
				_enableWaveLift = _vehicle getVariable ["FLAY.HangGlider.lift.wave.enable", false];
				_enableWindGusts = _vehicle getVariable ["FLAY.HangGlider.lift.gusts.enable", false];
				_enableTurbulence = _vehicle getVariable ["FLAY.HangGlider.lift.turbulence.enable", false];
			
				// thermals don't affect the glider when it's in landing state
				_landing = _vehicle getVariable ["FLAY.hangglider.state.landing", false];
			
				// emulate thermal lift
				if (_enableThermalLift and not _landing) then {
					_strengthTotal = 0;
					
					// find the thermals affecting the vehicle
					_thermals = (position _vehicle) nearObjects ["FLAY_Thermal", _THERMAL_MAX_RADIUS];
					
					{
						_thermal = _x;
						_thermalStrength = _thermal getVariable ["FLAY.HangGlider.lift.thermal.strength", 0.1];
						_thermalRadiusHorz = _thermal getVariable ["FLAY.HangGlider.lift.thermal.radius", 500];
						_thermalFalloffCoeffHorz = _thermal getVariable ["FLAY.HangGlider.lift.thermal.falloff_coeff_horz", 1.5];
						_thermalDistanceHorz = _vehicle distance _thermal; // horizontal (i.e. map) distance.
						_thermalAltitudeMin = _thermal getVariable ["FLAY.HangGlider.lift.thermal.altitude_min", 20];
						_thermalAltitudeMax = _thermal getVariable ["FLAY.HangGlider.lift.thermal.altitude_max", 600];
						_thermalSpeedMin = _thermal getVariable ["FLAY.HangGlider.lift.thermal.speed_min", 18];
						_thermalSpeedMax = _thermal getVariable ["FLAY.HangGlider.lift.thermal.speed_max", 200];
												
						_thermalRadiusVert = (_thermalAltitudeMax - _thermalAltitudeMin) / 2;
						_thermalFalloffCoeffVert = _thermal getVariable ["FLAY.HangGlider.lift.thermal.falloff_coeff_vert", 1.5];
						_thermalDistanceVert = abs (_altitudeATL - (_thermalRadiusVert + _thermalAltitudeMin)); // vertical distance from the thermal "inflection" center.

						if (_thermalDistanceHorz < _thermalRadiusHorz 
								and _altitudeATL > _thermalAltitudeMin 
								and _altitudeATL < _thermalAltitudeMax
								and _speed > _thermalSpeedMin
								and _speed < _thermalSpeedMax) then {
							// TODO - take bank and pitch into account when calculating lift.
							_strengthHorz = 360^(-((_thermalDistanceHorz/(_thermalRadiusHorz))^_thermalFalloffCoeffHorz));
							_strengthVert = 360^(-((_thermalDistanceVert/(_thermalRadiusVert))^_thermalFalloffCoeffVert));
							_strengthTotal = _strengthTotal + _thermalStrength * (_strengthHorz + _strengthVert);
						};
						
						// make thermals visible if the variometer is on debug
						_unitHasVario = (driver _vehicle) getVariable ["FLAY.variometer.debug", false];
						if (_unitHasVario) then {
							if (_thermalStrength > 0) then {
								_thermalPosATL = getPosATL _thermal;
								_thermal setPosATL [_thermalPosATL select 0, _thermalPosATL select 1, _thermalAltitudeMin];
								_thermal animate ["SizeArrowRed", (_thermalAltitudeMax - _thermalAltitudeMin) * 0.5];
								_thermal animate ["HideArrowBlue", 1];
								_thermal animate ["HideArrowRed", 0];
							} else {
								_thermalPosATL = getPosATL _thermal;
								_thermal setPosATL [_thermalPosATL select 0, _thermalPosATL select 1, _thermalAltitudeMax];
								_thermal animate ["SizeArrowBlue", (_thermalAltitudeMax - _thermalAltitudeMin) * 0.5];
								_thermal animate ["HideArrowRed", 1];
								_thermal animate ["HideArrowBlue", 0];
							};
						} else {
							_thermal animate ["HideArrowRed", 1];
							_thermal animate ["HideArrowBlue", 1];
						};
					
					} forEach _thermals;

					_vdir = vectorDir _vehicle;
					_vup = vectorUp _vehicle;
					_velocity = velocity _vehicle;
					_vehicle setVelocity [(_velocity select 0) + _strengthTotal * (_vdir select 0), (_velocity select 1) + _strengthTotal * (_vdir select 1), (_velocity select 2) + 6 * _strengthTotal * (_vup select 2)];
					//hint format ["LIFT: str=%1", _strengthTotal];
					//addCamShake [1, 25, 15];
				};
				
				if (_enableRidgeLift) then {
					_strengthTotal = 0;
					// find the thermals affecting the vehicle
					_ridges = (position _vehicle) nearObjects ["FLAY_Ridge", _RIDGE_MAX_RADIUS];
					
					{
						_ridge = _x;
						//_axis = _ridge getVariable ["FLAY.HangGlider.lift.debug.axis", objNull];
						//if (isNull _axis) then {
						//	_axis = "FLAY_ArrowFwdGreen" createVehicleLocal (getPos _ridge);
						//	_axis setPosASL (getPosASL _ridge);
						//	_axis setVectorDir wind;
						//	_ridge setVariable ["FLAY.HangGlider.lift.debug.axis", _axis];
						//};
						//_axis setVectorDir wind;
						_sfcNrml = surfaceNormal (getPos _ridge);
						_windX = wind select 0;
						_windY = wind select 1;
						_nrmlX = _sfcNrml select 0;
						_nrmlY = _sfcNrml select 1;
						
						_wind0 = [[0,0], wind] call BIS_fnc_dirTo;
						_nrml0 = [[0,0], _sfcNrml] call BIS_fnc_dirTo;
						_theta = [wind, _sfcNrml] call BIS_fnc_dirTo;
						
						_nrmlStrength = sqrt(_nrmlX^2+_nrmlY^2);
						_windStrength = sqrt(_windX^2+_windY^2);
												
						_strengthVert = 360^(-(((_vehicle distance _ridge)/100)^1.5));
						_strengthHorz = 360^(-((_altitudeATL/100)^1.5));
						_strengthTotal = _strengthTotal + (_strengthVert + _strengthHorz) * cos(_nrmlStrength) * _windStrength;
						
						hint format ["theta=%1, add=%2, nrml=%3, wind=%4, pow=%5", _theta, abs(_theta) < 90, _nrmlStrength, _windStrength, _strengthTotal];
						
						if (abs (_theta) < 90) then {
							_ridgePosATL = getPosATL _ridge;
							_ridge setPosATL [_ridgePosATL select 0, _ridgePosATL select 1, 15];
							_ridge animate ["SizeArrowRed", _strength * 5];
							_ridge animate ["HideArrowBlue", 1];
							_ridge animate ["HideArrowRed", 0];
							_ridge setVectorUp [0,0,1];
						} else {
							_ridgePosATL = getPosATL _ridge;
							_ridge setPosATL [_ridgePosATL select 0, _ridgePosATL select 1, 15];
							_ridge animate ["SizeArrowBlue", _strength * 5];
							_ridge animate ["HideArrowRed", 1];
							_ridge animate ["HideArrowBlue", 0];
							_ridge setVectorUp [0,0,1];
						};
												
					} forEach _ridges;
					
					_vdir = vectorDir _vehicle;
					_vup = vectorUp _vehicle;
					_velocity = velocity _vehicle;
					_vehicle setVelocity [(_velocity select 0) + _strengthTotal * (_vdir select 0), (_velocity select 1) + _strengthTotal * (_vdir select 1), (_velocity select 2) + 6 * _strengthTotal * (_vup select 2)];

				};
				
			} else {
				// not a supported vehicle
			};
			
		} forEach _vehicles;
	
		sleep 0.05; 
	};
	
	player sideChat "END lift.sqf";
};

