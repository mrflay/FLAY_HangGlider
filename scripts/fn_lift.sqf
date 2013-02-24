
_this spawn {

	private ["_done"];

	player sideChat "START lift.sqf";
	
	// maximum radius too look for thermals
	_THERMAL_MAX_RADIUS = 1000;
	
	_done = false;
	
	while { not _done } do {
	
		// find all appropriate vehicles (FIXME - only checking player for now)
		_vehicles = [vehicle player];
		
		{
			_vehicle = _x;
			_speed = speed _vehicle;
			_altitudeATL = (getPosATL _vehicle) select 2;
			
			// FIXME - lift is limit to FLAY_HangGlider for now
			if (_vehicle isKindOf "FLAY_HangGlider") then {
				_enableThermalLift = _vehicle getVariable ["FLAY.HangGlider.lift.thermal.enable", false];
				_enableHillLift = _vehicle getVariable ["FLAY.HangGlider.lift.ridge.enable", false];
				_enableWaveLift = _vehicle getVariable ["FLAY.HangGlider.lift.wave.enable", false];
				_enableWindGusts = _vehicle getVariable ["FLAY.HangGlider.lift.gusts.enable", false];
				_enableTurbulence = _vehicle getVariable ["FLAY.HangGlider.lift.turbulence.enable", false];
			
				// emulate thermal lift
				if (_enableThermalLift) then {
					_strengthTotal = 0;
					
					// find the thermals affecting the vehicle
					_thermals = (position _vehicle) nearObjects ["FLAY_Thermal", _THERMAL_MAX_RADIUS];
					
					{
						_thermal = _x;
						_thermalStrength = _thermal getVariable ["FLAY.HangGlider.lift.thermal.strength", 0.2];
						_thermalRadiusHorz = _thermal getVariable ["FLAY.HangGlider.lift.thermal.radius", 300];
						_thermalFalloffCoeffHorz = _thermal getVariable ["FLAY.HangGlider.lift.thermal.falloff_coeff_horz", 1.5];
						_thermalDistanceHorz = _vehicle distance _thermal; // horizontal (i.e. map) distance.
						_thermalAltitudeMin = _thermal getVariable ["FLAY.HangGlider.lift.thermal.altitude_min", 0];
						_thermalAltitudeMax = _thermal getVariable ["FLAY.HangGlider.lift.thermal.altitude_max", 3000];
						_thermalSpeedMin = _thermal getVariable ["FLAY.HangGlider.lift.thermal.speed_min", 0];
						_thermalSpeedMax = _thermal getVariable ["FLAY.HangGlider.lift.thermal.speed_max", 1000];
												
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
					
					} forEach _thermals;

					_vdir = vectorDir _vehicle;
					_vup = vectorUp _vehicle;
					_velocity = velocity _vehicle;
					_vehicle setVelocity [(_velocity select 0) + _strengthTotal * (_vdir select 0), (_velocity select 1) + _strengthTotal * (_vdir select 1), (_velocity select 2) + 6 * _strengthTotal * (_vup select 2)];
					hint format ["LIFT: str=%1", _strengthTotal];
					//addCamShake [1, 25, 15];
				};
			} else {
				// not a supported vehicle
			};
			
		} forEach _vehicles;
	
		sleep 0.1; 
	};
	
	player sideChat "END lift.sqf";
};

