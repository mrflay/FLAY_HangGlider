scriptName "fn_variometer.sqf";
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
	_unitHasVario = ("FLAY_Flytec3040_Variometer" in weapons _unit);
	_vehicleHasVario = ("FLAY_Flytec3040_Variometer" in (weapons (vehicle _unit))); // in cargo?
	
	if (not _unitHasVario and not _vehicleHasVario) exitWith {
		player sidechat "no variometer in unit or vehicle inventory";
	};
	
	if (_unit == player) then {

		17 cutRsc ["RscMissionScreen","plain"];
		waitUntil {!isNull (uiNamespace getVariable "BIS_RscMissionScreen")};
		uiNamespace setVariable ["FLAY_RscVarioScreen", uiNamespace getVariable "BIS_RscMissionScreen"];
				
		#define UI_DISPLAY	(uiNamespace getVariable "FLAY_RscVarioScreen")
		#define UI_CONTROL	(1100)

		#define UI_WIDTH	(0.7)
		#define UI_HEIGHT	(UI_WIDTH * 4/3)
		#define UI_LAYER(x)	(UI_DISPLAY displayctrl (UI_CONTROL + (x)))
		
		#define UI_SETUP(x,pos,img,opacity) \
				UI_LAYER(x) ctrlsetposition (pos); \
				UI_LAYER(x) ctrlsettextcolor [1,1,1,1]; \
				UI_LAYER(x) ctrlsetfade (1-(opacity)); \
				UI_LAYER(x) ctrlsettext (img); \
				UI_LAYER(x) ctrlcommit 0;
		
		#define UI_FONT(ctrl,fontName,fontHeight) \
				UI_LAYER(ctrl) ctrlSetFont (fontName); \
				UI_LAYER(ctrl) ctrlSetFontHeight (fontHeight); \
				UI_LAYER(ctrl) ctrlCommit 0;
		
		#define DECIMAL(x,n) (str(round((x)*(10^(n)))/(10^(n))))
				
		_uiBgPos = [
			(safezoneX + 0.01),
			(safezoneY + safezoneH) - (UI_HEIGHT) - 0.01,
			UI_WIDTH,
			UI_HEIGHT
		];
		
		_uiFgPos = [
			(_uiBgPos select 0),
			(_uiBgPos select 1),
			(_uiBgPos select 2),
			(_uiBgPos select 3)
		];		
		
		_uiVarioPos = [
			(_uiBgPos select 0) - 0.07,
			(_uiBgPos select 1) + 0.275,
			(_uiBgPos select 2),
			(_uiBgPos select 3)
		];
		
		_uiSpeedPos = [
			(_uiBgPos select 0) - 0.07,
			(_uiBgPos select 1) + 0.275,
			(_uiBgPos select 2),
			(_uiBgPos select 3)
		];

		_uiAltPos = [
			(_uiBgPos select 0) - 0.08,
			(_uiBgPos select 1) + 0.48,
			(_uiBgPos select 2),
			(_uiBgPos select 3)
		];

		_uiTempPos = [
			(_uiBgPos select 0) - 0.08,
			(_uiBgPos select 1) + 0.54,
			(_uiBgPos select 2),
			(_uiBgPos select 3)
		];		
		
		// background
		UI_SETUP( 1, _uiBgPos, "FLAY\FLAY_HangGlider\data\vario_big\background.paa", 1);	
		// indicators
		UI_SETUP( 2, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario01.paa", 0);
		UI_SETUP( 3, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario02.paa", 0);
		UI_SETUP( 4, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario03.paa", 0);
		UI_SETUP( 5, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario04.paa", 0);
		UI_SETUP( 6, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario05.paa", 0);	
		UI_SETUP( 7, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario06.paa", 0);	
		UI_SETUP( 8, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario07.paa", 0);	
		UI_SETUP( 9, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario08.paa", 0);	
		UI_SETUP(10, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario09.paa", 0);	
		UI_SETUP(11, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario10.paa", 0);	
		UI_SETUP(12, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario11.paa", 0);	
		UI_SETUP(13, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario12.paa", 0);	
		UI_SETUP(14, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario13.paa", 0);	
		UI_SETUP(15, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario14.paa", 0);	
		UI_SETUP(16, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario15.paa", 0);	
		UI_SETUP(17, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario16.paa", 0);	
		UI_SETUP(18, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario17.paa", 0);	
		UI_SETUP(19, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario18.paa", 0);	
		UI_SETUP(20, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario19.paa", 0);	
		UI_SETUP(21, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario20.paa", 0);	
		UI_SETUP(22, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario21.paa", 0);	
		UI_SETUP(23, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario22.paa", 0);	
		UI_SETUP(24, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario23.paa", 0);	
		UI_SETUP(25, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario24.paa", 0);	
		UI_SETUP(26, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario25.paa", 0);	
		UI_SETUP(27, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\vario26.paa", 0);
		// masks
		UI_SETUP(28, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\maskdn.paa",  0);
		UI_SETUP(29, _uiFgPos, "FLAY\FLAY_HangGlider\data\vario_big\maskup.paa",  0);
		// numeric display 
		UI_SETUP(200, _uiVarioPos, "", 1);
		UI_SETUP(201, _uiAltPos, "", 1);
		UI_SETUP(202, _uiTempPos, "" ,1);
		UI_SETUP(203, _uiSpeedPos, "", 0);
		
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
	
	while { alive _unit and (_unitHasVario or _vehicleHasVario) and _powerOn} do {
		
		sleep 0.05;
		
		_vehicle = vehicle _unit;
		_unitHasVario = ("FLAY_Flytec3040_Variometer" in weapons _unit);
		_vehicleHasVario = ("FLAY_Flytec3040_Variometer" in (weapons (vehicle _unit))); // cargo?
	
		if (not _unitHasVario and not _vehicleHasVario) exitWith {
			player sidechat "no variometer in unit or vehicle inventory";
		};
				
		_audioSinkTld = _vehicle getVariable ["FLAY.variometer.audio.sink_threshold", -1.5];
		_audioClimbTld = _vehicle getVariable ["FLAY.variometer.audio.climb_threshold", 0.15];
		
		_layer = INDICATOR_OFF;
		_index = AUDIO_OFF;

		_velocity = velocity (_vehicle);		
		_vSpeedAvg = _velocity select 2;
		
		if (_vSpeedAvg < 0) then {
			_layer = (2 + round (abs _vSpeedAvg * 5)) min 27;
			_index = AUDIO_SINK;
			if (_vSpeedAvg > _audioSinkTld) then { _index = AUDIO_OFF };
		};
		
		if (_vSpeedAvg > 0) then {
			_layer = (2 + round (_vSpeedAvg * 5)) min 27;
			_index = (10 + round (2 * _vSpeedAvg)) min 19;
			if (_vSpeedAvg < _audioClimbTld) then { _index = AUDIO_OFF };
		};
		
		_altitudeATL = (getPosATL _vehicle) select 2;
		_altitudeASL = (getPosASL _vehicle) select 2;
		_temperature = 22 - (22 / 3000) * _altitudeASL; // a made up temperature used only for display
		
		// only display ui for the player unit (sounds are played for all units)
		if (_unit == player) then {
			UI_LAYER(200) ctrlSetText DECIMAL(_vSpeedAvg, 1);
			UI_LAYER(201) ctrlSetText DECIMAL(_altitudeATL, 0);
			UI_LAYER(202) ctrlSetText DECIMAL(_temperature, 1);
			UI_LAYER(200) ctrlCommit 0;
			UI_LAYER(201) ctrlCommit 0;
			UI_LAYER(202) ctrlCommit 0;
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
					UI_LAYER(28) ctrlSetFade 0;
					UI_LAYER(29) ctrlSetFade 1;
				} else {
					UI_LAYER(28) ctrlSetFade 1;
					UI_LAYER(29) ctrlSetFade 0;				
				};
				UI_LAYER(28) ctrlCommit 0;
				UI_LAYER(29) ctrlCommit 0;				
				_prevLayer = _layer;
			};
		};
		
		_audioOn = _vehicle getVariable ["FLAY.variometer.audio.on", true];
		 
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
		
		_powerOn = _unit getVariable ["FLAY.variometer.power.on", true];
	};
	
	_unit setVariable ["FLAY.variometer.power.on", false];
	if (not (isNull _soundSource)) then {
		deleteVehicle _soundSource;
	};	
	17 cutRsc ["Default","plain"];
};