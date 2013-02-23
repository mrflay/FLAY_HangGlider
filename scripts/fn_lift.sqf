
_this spawn {

	private ["_done"];

	player sideChat "START lift.sqf";
	
	_THERMAL_MAX_RADIUS = 1000;
	
	//addCamShake [1, 25, 15];
	_done = false;
	
	while { not _done } do {
	
		// find all appropriate vehicles (FIXME - only checking player for now)
		_vehicles = [vehicle player];
		
		{
			_vehicle = _x;
			
			// FIXME - lift is limit to FLAY_HangGlider for now
			if (_vehicle isKindOf "FLAY_HangGlider") then {
				_enableThermalLift = _vehicle getVariable ["FLAY.HangGlider.lift.thermal.enable", false];
				_enableHillLift = _vehicle getVariable ["FLAY.HangGlider.lift.hill.enable", false];
				_enableWaveLift = _vehicle getVariable ["FLAY.HangGlider.lift.wave.enable", false];
				_enableWindGusts = _vehicle getVariable ["FLAY.HangGlider.lift.gusts.enable", false];
			
				// emulate thermal lift
				if (_enableThermalLift) then {
					//hint "LIFT: ENABLED";
					// find the thermals affecting the vehicle
					_thermals = (position _vehicle) nearObjects ["FLAY_Thermal", _THERMAL_MAX_RADIUS];
					
					{
						_thermal = _x;
						_thermalStrength = _thermal getVariable ["FLAY.HangGlider.lift.thermal.strength", 0];
						_thermalRadius = _thermal getVariable ["FLAY.HangGlider.lift.thermal.radius", 0];
						_thermalDistance = _vehicle distance _thermal; // horizontal (i.e. map) distance.
						
						hint format ["LIFT: str=%1, rad=%2, dst=%3", _thermalStrength, _thermalRadius, _thermalDistance];
						
						if (_thermalDistance < _thermalRadius) then {
							hint "LIFT: applying thermal";
							_strength = 360^(-((_thermalDistance/(2*_thermalRadius))^2.5));
							_strength = _thermalStrength * _strength;
							_vdir = vectorDir _vehicle;
							_vup = vectorUp _vehicle;
							_velocity = velocity _vehicle;
							// TODO - take bank and pitch into account when calculating lift.
							_vehicle setVelocity [(_velocity select 0) + _strength * (_vdir select 0), (_velocity select 1) + _strength * (_vdir select 1), (_velocity select 2) + 6 * _strength * (_vup select 2)];
						};
					
					} forEach _thermals;
				};
			} else {
				// not a hangglider
				player sidechat "LIFT: not a hangglider";
			};
			
		} forEach _vehicles;
	
		sleep 0.5; 
	};
	
	player sideChat "END lift.sqf";
};

