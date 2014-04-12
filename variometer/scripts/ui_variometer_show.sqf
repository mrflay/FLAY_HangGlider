scriptName "ui_variometer_show.sqf";
/*
	Author: mrflay

	Description:
	

	Parameter(s):
	_this select 0: OBJECT - unit
	
	Variable(s):
	
	FLAY.variometer.power.on
	FLAY.variometer.display.on
	FLAY.variometer.audio.on
	FLAY.variometer.audio.sink_threshold
	FLAY.variometer.audio.climb_threshold
	FLAY.variometer.model.position

	Returns:
	None
*/
_this spawn {
	disableserialization;
		
	_unit = _this select 0;
	_unitHasVario = ("FLAY_Variometer" in weapons _unit);
	_vehicleHasVario = ("FLAY_Variometer" in (weapons (vehicle _unit))); // in cargo?
	
	//if (not _unitHasVario and not _vehicleHasVario) exitWith {
	//	player sidechat "no variometer in unit or vehicle inventory";
	//};
	
	if (_unit == player) then {

		55 cutRsc ["FLAY_RscVarioScreen","plain"];
		waitUntil {!isNull (uiNamespace getVariable "FLAY_RscVarioScreen")};
				
		#define UI_DISPLAY	(uiNamespace getVariable "FLAY_RscVarioScreen")
		#define UI_CONTROL	(4000)

		#define UI_WIDTH	(0.7)
		#define UI_HEIGHT	(UI_WIDTH * 4/3)
		#define UI_LAYER(x)	(UI_DISPLAY displayctrl (UI_CONTROL + (x)))
		
		#define DECIMAL(x,n) (str(round((x)*(10^(n)))/(10^(n))))
	};
	
	#define AUDIO_OFF       9
	#define AUDIO_SINK      8
	#define INDICATOR_OFF   2
	
	_index = AUDIO_OFF;
	_prevIndex = AUDIO_OFF;
	_layer = INDICATOR_OFF;
	_prevLayer = INDICATOR_OFF;
	_vSpeedAvg = 0;
	_timeout = 0;
	_soundSource = objNull;
	
	_soundSourceArray = [
		["Sound_VarioDn01", [0,0,0], [], 0], // not used
		["Sound_VarioDn01", [0,0,0], [], 0], // - "" -
		["Sound_VarioDn01", [0,0,0], [], 0], // - "" -
		["Sound_VarioDn01", [0,0,0], [], 0], // - "" -
		["Sound_VarioDn01", [0,0,0], [], 0], // - "" -
		["Sound_VarioDn01", [0,0,0], [], 0], // - "" -
		["Sound_VarioDn01", [0,0,0], [], 0], // - "" -
		["Sound_VarioDn01", [0,0,0], [], 0], // - "" -
		["Sound_VarioDn01", [0,0,0], [], 0], // sink sound (only this is used)
		["Sound_Silence",   [0,0,0], [], 0], // not used
		["Sound_VarioUp02", [0,0,0], [], 0], // climb sounds ...
		["Sound_VarioUp04", [0,0,0], [], 0], 
		["Sound_VarioUp06", [0,0,0], [], 0],
		["Sound_VarioUp08", [0,0,0], [], 0],
		["Sound_VarioUp10", [0,0,0], [], 0],
		["Sound_VarioUp12", [0,0,0], [], 0],
		["Sound_VarioUp14", [0,0,0], [], 0],
		["Sound_VarioUp16", [0,0,0], [], 0],
		["Sound_VarioUp18", [0,0,0], [], 0],
		["Sound_VarioUp20", [0,0,0], [], 0],
		["Sound_VarioUp22", [0,0,0], [], 0],
		["Sound_VarioUp24", [0,0,0], [], 0],
		["Sound_VarioUp26", [0,0,0], [], 0],
		["Sound_VarioUp28", [0,0,0], [], 0],
		["Sound_VarioUp30", [0,0,0], [], 0],
		["Sound_VarioUp32", [0,0,0], [], 0],
		["Sound_VarioUp34", [0,0,0], [], 0],
		["Sound_VarioUp36", [0,0,0], [], 0],
		["Sound_VarioUp38", [0,0,0], [], 0],
		["Sound_VarioUp40", [0,0,0], [], 0]
	];
	
	_unit setVariable ["FLAY.variometer.power.on", true];
	_powerOn = true;
	
	// FIXME: find out how to hide the controls in the ui config.
	for [{_i=1}, {_i<30}, {_i=_i+1}] do { UI_LAYER(_i) ctrlSetFade 1; UI_LAYER(_i) ctrlCommit 0; };
	
	//while { alive _unit and (_unitHasVario or _vehicleHasVario) and _powerOn} do {
	while { alive _unit and _powerOn} do {
		
		sleep 0.05;
		
		_vehicle = vehicle _unit;
		_unitHasVario = ("FLAY_Variometer" in weapons _unit);
		_vehicleHasVario = ("FLAY_Variometer" in (weapons (vehicle _unit))); // cargo?
	
		//if (not _unitHasVario and not _vehicleHasVario) exitWith {
		//	player sidechat "no variometer in unit or vehicle inventory";
		//};
				
		_audioSinkTld = _vehicle getVariable ["FLAY.variometer.audio.sink_threshold", -1.5];
		_audioClimbTld = _vehicle getVariable ["FLAY.variometer.audio.climb_threshold", 0.15];
		
		_layer = INDICATOR_OFF;
		_index = AUDIO_OFF;

		_velocity = velocity (_vehicle);		
		_speed = _velocity call BIS_fnc_magnitude;
		_vSpeedAvg = _velocity select 2;
		
		if (_vSpeedAvg < 0) then {
			_layer = (1 + round (abs _vSpeedAvg * 5)) min 26;
			_index = AUDIO_SINK;
			if (_vSpeedAvg > _audioSinkTld) then { _index = AUDIO_OFF };
		};
		
		if (_vSpeedAvg > 0) then {
			_layer = (1 + round (_vSpeedAvg * 5)) min 26;
			_index = (9 + round (2 * _vSpeedAvg)) min 18;
			if (_vSpeedAvg < _audioClimbTld) then { _index = AUDIO_OFF };
		};
		
		_altitudeATL = (getPosATL _vehicle) select 2;
		_altitudeASL = (getPosASL _vehicle) select 2;
		_temperature = 22 - (22 / 3000) * _altitudeASL; // a made up temperature used only for display
		
		// only display ui for the player unit (sounds are played for all units)
		if (_unit == player) then {
			UI_LAYER(31) ctrlSetText DECIMAL(_vSpeedAvg, 1);
			UI_LAYER(32) ctrlSetText DECIMAL(_altitudeATL, 0);
			UI_LAYER(33) ctrlSetText DECIMAL(_speed * 60.0 * 60.0 / 1000.0, 0);
			UI_LAYER(31) ctrlCommit 0;
			UI_LAYER(32) ctrlCommit 0;
			UI_LAYER(33) ctrlCommit 0;
			// update climb indicator if vertical speed has changed since last iteration.
			if (_prevLayer != _layer) then {
				UI_LAYER(_prevLayer) ctrlsetfade 1;
				UI_LAYER(_prevLayer) ctrlcommit 0;
				if ((abs _vSpeedAvg) >= 0.1) then {
					UI_LAYER(_layer) ctrlsetfade 0;
					UI_LAYER(_layer) ctrlcommit 0;
				};
				// mask upper or lower part of indicator display
				if (_vSpeedAvg > 0) then {
					UI_LAYER(27) ctrlSetFade 0;
					UI_LAYER(28) ctrlSetFade 1;
				} else {
					UI_LAYER(27) ctrlSetFade 1;
					UI_LAYER(28) ctrlSetFade 0;				
				};
				UI_LAYER(27) ctrlCommit 0;
				UI_LAYER(28) ctrlCommit 0;				
				_prevLayer = _layer;
			};
		};
		
		_audioOn = _unit getVariable ["FLAY.variometer.audio.on", true];
		 
		if (time > _timeout and _audioOn) then {
			if (_prevIndex != _index) then {
				if (not (isNull _soundSource)) then {
					deleteVehicle _soundSource;
				};
				if (_index != AUDIO_OFF) then {
					_soundSource = createSoundSource (_soundSourceArray select _index);
					_soundSource attachTo [_vehicle, [0,0,0], "FLAY.variometer.model.position"]; // TODO: consider the case when not in a vehicle, etc.
				};
				_prevIndex = _index;
			};
			_timeout = time + 0.7;
		};
		if (not _audioOn) then {
			if (not (isNull _soundSource)) then {
				deleteVehicle _soundSource;
			};
		};
		
		_powerOn = _unit getVariable ["FLAY.variometer.power.on", true];
		_powerOn = _powerOn and _vehicle != _unit; // power off when exiting vehicle
	};
	
	_unit setVariable ["FLAY.variometer.power.on", false];
	if (not (isNull _soundSource)) then {
		deleteVehicle _soundSource;
	};
	
	if (_unit == player) then {
		55 cutRsc ["FLAY_Default","plain"];
	};
};