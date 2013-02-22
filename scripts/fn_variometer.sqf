scriptName "fn_variometer.sqf";
/*
	Author: mrflay

	Description:
	 ...

	Parameter(s):
	_this select 0: OBJECT - unit

	Returns:
	True
*/
_this spawn {
	disableserialization;
		
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
			
	_unit = _this select 0;
	
	_index = 2;
	_prevIndex = 2;
	_count = 0;
	_vSpeedAvg = 0;
	
	UI_LAYER(1) ctrlsetfade 0;
	UI_LAYER(1) ctrlcommit 0;
	
	while { alive _unit } do {
		
		sleep 0.01;

		_velocity = velocity (vehicle _unit);
		
		_count = _count + 1;
		if (_count < 5) then {
			_vSpeedCur = _velocity select 2;
			_vSpeedAvg = _vSpeedAvg + _vSpeedCur;
		} else {
			_vSpeedAvg = _vSpeedAvg / _count;
			_index = 2;
			
			if (_vSpeedAvg < 0.5) then {
				_index = (28 + round (abs _vSpeedAvg)) min 52; // TODO define constants
			};
			
			if (_vSpeedAvg > 0.5) then {
				_index = (2 + round (_vSpeedAvg)) min 27; // TODO define constants
			};
			
			// round vspeed to two decimal places for display
			_vSpeedAvgText = str (round (_vSpeedAvg * (10 ^ 1)) / (10 ^ 1));
			
			UI_LAYER(200) ctrlSetText _vSpeedAvgText;
			UI_LAYER(200) ctrlCommit 0;
	
			UI_LAYER(_prevIndex) ctrlsetfade 1;
			UI_LAYER(_prevIndex) ctrlcommit 0;
			
			if ((abs _vSpeedAvg) >= 0.5) then {
				UI_LAYER(_index) ctrlsetfade 0;
				UI_LAYER(_index) ctrlcommit 0;
			};
			
			_prevIndex = _index;
			_count = 0;
			_vSpeedAvg = 0;
		};
	};	
	player sidechat "vario dead";
};