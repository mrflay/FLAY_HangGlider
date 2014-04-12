// fn_moduleThermalLift.sqf

private ["_logic","_activated","_debug","_posATL","_debugArrow","_altitudeMin","_altitudeMax"];

_activated = [_this,2,true,[true]] call BIS_fnc_param;
if (not _activated) exitWith { 0 };

_logic = [_this,0,objNull,[objNull]] call BIS_fnc_param;
_debug = _logic getVariable ["Debug", false];

if (_debug) then {
	_thermalPosATL = getPosATL _logic;
	_thermalAltitudeMin = _logic getVariable ["AltitudeMin", 0];
	_thermalAltitudeMax = _logic getVariable ["AltitudeMax", 0];	
	_thermalStrength = _logic getVariable ["Strength", 0.1];
	_debugArrow = "FLAY_Thermal" createVehicleLocal _thermalPosATL;
	_logic setVariable ["DebugArrow", _debugArrow];
	if (_thermalStrength > 0) then {
		_thermalPosATL = getPosATL _debugArrow;
		_debugArrow setPosATL [_thermalPosATL select 0, _thermalPosATL select 1, _thermalAltitudeMin];
		_debugArrow animate ["SizeArrowRed", (_thermalAltitudeMax - _thermalAltitudeMin) * 0.5];
		_debugArrow animate ["HideArrowBlue", 1];
		_debugArrow animate ["HideArrowRed", 0];
	} else {
		_thermalPosATL = getPosATL _debugArrow;
		_debugArrow setPosATL [_thermalPosATL select 0, _thermalPosATL select 1, _thermalAltitudeMax];
		_debugArrow animate ["SizeArrowBlue", (_thermalAltitudeMax - _thermalAltitudeMin) * 0.5];
		_debugArrow animate ["HideArrowRed", 1];
		_debugArrow animate ["HideArrowBlue", 0];
	};	
};

// don't start lift script if it is already running
_mainLogic = missionNamespace getVariable ["flay.thermals.module", objNull];
if (not isNull _mainLogic) exitWith { diag_log "fn_moduleThermalLift: lift script already started"; };

diag_log "fn_moduleThermalLift: starting lift script";
missionNamespace setVariable ["flay.thermals.module", _logic];

_this spawn {
	
	private ["_done"];
	private ["_logic", "_units","_debug"];
	 
	_logic = [_this,0,objNull,[objNull]] call BIS_fnc_param;
	_units = [_this,1,[],[[]]] call BIS_fnc_param;
		
	// module params
	_debug = _logic getVariable ["Debug", false];
	_defaultStrength = _logic getVariable ["Strength", 0.1];
	_defaultRadiusHorz = _logic getVariable ["Radius", 500];
	_defaultFalloffCoeffHorz = _logic getVariable ["FalloffCoeffHorz", 1.5];
	_defaultFalloffCoeffVert = _logic getVariable ["FalloffCoeffVert", 1.5];
	_defaultAltitudeMin = _logic getVariable ["AltitudeMin", 0];
	_defualtAltitudeMax = _logic getVariable ["AltitudeMax", 600];
	_defaultSpeedMin = _logic getVariable ["SpeedMin", 18];
	_defaultSpeedMax = _logic getVariable ["SpeedMax", 200];
		
	// maximum radius too look for thermals
	_THERMAL_MAX_RADIUS = 1000;
	_RIDGE_MAX_RADIUS = 1000;
	
	_done = false;
	
	while { not _done } do {
	
		// make sure this loop is only run by main module
		_mainLogic = missionNamespace getVariable ["flay.thermals.module", objNull];
		if (_logic != _mainLogic) exitWith { diag_log "fn_moduleThermalLift: _logic != _mainLogic"; };
	
		// find all appropriate vehicles (FIXME: only checking player for now)
		_vehicles = [vehicle player];
		
		{
			_vehicle = _x;
			_speed = speed _vehicle;
			_altitudeATL = (getPosATL _vehicle) select 2;
			
			// FIXME: lift is only applied to FLAY_HangGlider at the moment
			if (_vehicle isKindOf "FLAY_HangGlider") then {
				_enableThermalLift = _vehicle getVariable ["FLAY.thermals.enable", true];
			
				// thermals don't affect the glider when it's in landing state
				_landing = _vehicle getVariable ["FLAY.hangglider.state.landing", false];
			
				// emulate thermal lift
				if (_enableThermalLift and not _landing) then {
					_strengthTotal = 0;
					
					// find the thermals affecting the vehicle
					_thermals = (position _vehicle) nearObjects ["FLAY_ModuleThermalLift", _THERMAL_MAX_RADIUS];
					
					{
						_thermal = _x;
						_thermalStrength = _thermal getVariable ["Strength", _defaultStrength];
						_thermalRadiusHorz = _thermal getVariable ["Radius", _defaultRadiusHorz];
						_thermalFalloffCoeffHorz = _thermal getVariable ["FalloffCoeffHorz", _defaultFalloffCoeffHorz];
						_thermalDistanceHorz = _vehicle distance _thermal; // horizontal (i.e. map) distance.
						_thermalAltitudeMin = _thermal getVariable ["AltitudeMin", _defaultAltitudeMin];
						_thermalAltitudeMax = _thermal getVariable ["AltitudeMax", _defualtAltitudeMax];
						_thermalSpeedMin = _thermal getVariable ["SpeedMin", _defaultSpeedMin];
						_thermalSpeedMax = _thermal getVariable ["SpeedMax", _defaultSpeedMax];
												
						_thermalRadiusVert = (_thermalAltitudeMax - _thermalAltitudeMin) / 2;
						_thermalFalloffCoeffVert = _thermal getVariable ["FalloffCoeffVert", _defaultFalloffCoeffVert];
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
					//hint format ["LIFT: str=%1", _strengthTotal];
					//addCamShake [1, 25, 15];
				};

			} else {
				// not a supported vehicle
			};
			
		} forEach _vehicles;
	
		sleep 0.05; 
	};
};

