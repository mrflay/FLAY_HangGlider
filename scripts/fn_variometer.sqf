scriptName "fn_variometer.sqf";
/*
	Author: mrflay

	Description:
	 ...

	Parameter(s):
	_this select 0: OBJECT - unit
	
	Variable(s):
	FLAY.variometer.visible
	FLAY.veriometer.audio.on
	FLAY.variometer.audio.sink
	FLAY.variometer.audio.climb
	FLAY.variometer.audio.threshold

	Returns:
	True
*/
_this spawn {
	disableserialization;
	
	_unit = _this select 0;
	
	if (_unit == player) then {
	
		17 cutRsc ["RscMissionScreen","plain"];
		waitUntil {!isNull (uiNamespace getVariable "BIS_RscMissionScreen")};
		uiNamespace setVariable ["FLAY_RscMissionScreen_Variometer", uinamespace getvariable "BIS_RscMissionScreen"];
		
		#define UI_DISPLAY	(uiNamespace getVariable "FLAY_RscMissionScreen_Variometer")
		#define UI_CONTROL	(1100)

		#define UI_WIDTH	(0.7)
		#define UI_HEIGHT	(UI_WIDTH * 4/3)
		#define UI_LAYER(x)	(UI_DISPLAY displayctrl (UI_CONTROL + (x)))
		#define UI_FLYTEC	(UI_LAYER(1))
		
		#define UI_SETUP(x,pos,img) \
				UI_LAYER(x) ctrlsetposition (pos); \
				UI_LAYER(x) ctrlsettextcolor [1,1,1,1]; \
				UI_LAYER(x) ctrlsetfade 1; \
				UI_LAYER(x) ctrlcommit 0; \
				UI_LAYER(x) ctrlsettext (img);
			
		_uiPos = [
			(safezoneX + 0.01),
			(safezoneY + safezoneH) - (UI_HEIGHT) - 0.01,
			UI_WIDTH,
			UI_HEIGHT
		];
		
		_uiVSpeedPos = [
			(_uiPos select 0) - 0.07,
			(_uiPos select 1) + 0.275,
			(_uiPos select 2),
			(_uiPos select 3)
		];
		
		// background
		UI_SETUP( 1, _uiPos, "FLAY\FLAY_HangGlider\data\flytec3040L2_ca.paa");
		
		// up indicators
		UI_SETUP( 2, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario01_ca.paa");
		UI_SETUP( 3, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario02_ca.paa");
		UI_SETUP( 4, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario03_ca.paa");
		UI_SETUP( 5, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario04_ca.paa");
		UI_SETUP( 6, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario05_ca.paa");	
		UI_SETUP( 7, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario06_ca.paa");	
		UI_SETUP( 8, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario07_ca.paa");	
		UI_SETUP( 9, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario08_ca.paa");	
		UI_SETUP(10, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario09_ca.paa");	
		UI_SETUP(11, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario10_ca.paa");	
		UI_SETUP(12, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario11_ca.paa");	
		UI_SETUP(13, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario12_ca.paa");	
		UI_SETUP(14, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario13_ca.paa");	
		UI_SETUP(15, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario14_ca.paa");	
		UI_SETUP(16, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario15_ca.paa");	
		UI_SETUP(17, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario16_ca.paa");	
		UI_SETUP(18, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario17_ca.paa");	
		UI_SETUP(19, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario18_ca.paa");	
		UI_SETUP(20, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario19_ca.paa");	
		UI_SETUP(21, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario20_ca.paa");	
		UI_SETUP(22, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario21_ca.paa");	
		UI_SETUP(23, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario22_ca.paa");	
		UI_SETUP(24, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario23_ca.paa");	
		UI_SETUP(25, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario24_ca.paa");	
		UI_SETUP(26, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario25_ca.paa");	
		UI_SETUP(27, _uiPos, "FLAY\FLAY_HangGlider\data\vario\vario26_ca.paa");
		
		// down indicators
		UI_SETUP(28, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn01_ca.paa");
		UI_SETUP(29, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn02_ca.paa");
		UI_SETUP(30, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn03_ca.paa");
		UI_SETUP(31, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn04_ca.paa");
		UI_SETUP(32, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn05_ca.paa");	
		UI_SETUP(33, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn06_ca.paa");	
		UI_SETUP(34, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn07_ca.paa");	
		UI_SETUP(35, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn08_ca.paa");	
		UI_SETUP(36, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn09_ca.paa");	
		UI_SETUP(37, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn10_ca.paa");	
		UI_SETUP(38, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn11_ca.paa");	
		UI_SETUP(39, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn12_ca.paa");	
		UI_SETUP(40, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn13_ca.paa");	
		UI_SETUP(41, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn14_ca.paa");	
		UI_SETUP(42, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn15_ca.paa");	
		UI_SETUP(43, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn16_ca.paa");	
		UI_SETUP(44, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn17_ca.paa");	
		UI_SETUP(45, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn18_ca.paa");	
		UI_SETUP(46, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn19_ca.paa");	
		UI_SETUP(47, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn20_ca.paa");	
		UI_SETUP(48, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn21_ca.paa");	
		UI_SETUP(49, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn22_ca.paa");	
		UI_SETUP(50, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn23_ca.paa");	
		UI_SETUP(51, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn24_ca.paa");	
		UI_SETUP(52, _uiPos, "FLAY\FLAY_HangGlider\data\vario\varioDn25_ca.paa");	
		
		UI_SETUP(200, _uiVSpeedPos, "");
		UI_LAYER(200) ctrlSetFade 0;
		UI_LAYER(200) ctrlCommit 0;

		UI_LAYER(1) ctrlsetfade 0;
		UI_LAYER(1) ctrlcommit 0;
	
	};
	
	_index = 9;
	_prevIndex = 9;
	_layer = 2;
	_prevLayer = 2;
	_count = 0;
	_vSpeedAvg = 0;
	_timeout = 0;
	_soundSource = objNull;
	
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
	
	while { alive _unit } do {
		
		sleep 0.05;

		_vehicle = vehicle _unit;
		_velocity = velocity (_vehicle);
		
		_layer = 2;
		_index = 9;
		
		_vSpeedAvg = _velocity select 2;
		
		if (_vSpeedAvg < -0.5) then {
			_layer = (28 + round (abs _vSpeedAvg * 5)) min 52; // TODO define constants
			_index = 8;
		};
		
		if (_vSpeedAvg > 0.5) then {
			_layer = (2 + round (_vSpeedAvg * 5)) min 27; // TODO define constants
			_index = (10 + round (2 * _vSpeedAvg)) min 19;
		};
		
		// round vspeed to two decimal places for display
		_vSpeedAvgText = str (round (_vSpeedAvg * (10 ^ 1)) / (10 ^ 1));
		
		// only display ui for player
		if (_unit == player) then {
			UI_LAYER(200) ctrlSetText _vSpeedAvgText;
			UI_LAYER(200) ctrlCommit 0;
			
			if (_prevLayer != _layer) then {
				UI_LAYER(_prevLayer) ctrlsetfade 1;
				UI_LAYER(_prevLayer) ctrlcommit 0;
				if ((abs _vSpeedAvg) >= 0.1) then {
					UI_LAYER(_layer) ctrlsetfade 0;
					UI_LAYER(_layer) ctrlcommit 0;
				};
				_prevLayer = _layer;
			};
		};
		
		if (time > _timeout) then {
			if (_prevIndex != _index) then {
				if (not (isNull _soundSource)) then {
					deleteVehicle _soundSource;
				};
				if (_index != 9) then {
					_soundSource = createSoundSource (_soundSourceArray select _index);
					_soundSource attachTo [_vehicle, [0,0,0], "FLAY.equipment.variometer.position"]; // TODO - consider the case when not in a vehicle, etc.
				};
				_prevIndex = _index;
			};
			_timeout = time + 1.0;
		};		
		
	};
};