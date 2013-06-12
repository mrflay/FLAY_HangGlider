
class CfgPatches
{
	class FLAY_HangGlider_UI
	{
		units[] = {};
		requiredVersion = 0.1;
		//requiredAddons[] = {"CAData","CAUI"};
		requiredAddons[] = {};
	};
};


// ===========================================================================
// DIALOGS
// ===========================================================================

#define HINT(BTN) ("hint " + BTN)

class RscText;
class RscPicture;
class RscStructuredText;
class FLAY_VarioGauge: RscPicture
{
	x = "(call compile (profilenamespace getvariable ['IGUI_GRID_VARIO_X',str (safezoneX + 0.01)]))";
	y = "(call compile (profilenamespace getvariable ['IGUI_GRID_VARIO_Y',str (safezoneY + safezoneH - (0.4 * 4 / 3) - 0.01)]))";
	w = "(call compile (profilenamespace getvariable ['IGUI_GRID_VARIO_W',str (0.4)]))";
	h = "(call compile (profilenamespace getvariable ['IGUI_GRID_VARIO_H',str (0.4 * 4 / 3)]))";
	fade = 1;
};

class RscTitles
{
	class FLAY_Default
	{
		idd = -1;
		movingEnable = 0;
		duration = 0;
		fadein = 0;
		fadeout = 0;
	};
	class FLAY_RscVarioScreen
	{
		idd = -1;
		enableSimulation=1;
		movingEnable=1;
		duration = 1e+011;
		fadein = 0;
		onLoad = "uinamespace setvariable ['FLAY_RscVarioScreen',_this select 0];";
		onUnload = "uinamespace setvariable ['FLAY_RscVarioScreen',nil];";
		class ControlsBackground
		{
			class Background: RscPicture {
				idc = 4000;
				style = 48;
				
				x = "(call compile (profilenamespace getvariable ['IGUI_GRID_VARIO_X',str (safezoneX + 0.01)]))";
				y = "(call compile (profilenamespace getvariable ['IGUI_GRID_VARIO_Y',str (safezoneY + safezoneH - (0.4 * 4 / 3) - 0.01)]))";
				w = "(call compile (profilenamespace getvariable ['IGUI_GRID_VARIO_W',str (0.4)]))";
				h = "(call compile (profilenamespace getvariable ['IGUI_GRID_VARIO_H',str (0.4 * 4 / 3)]))";

				text = "FLAY\FLAY_HangGlider\data\vario_big\background_ca.paa";
				color[] = {1, 1, 1, 0.5};
				colorActive[] = {1, 1, 1, 0};
				colorBackground[] = {1,1,1,0.5};
				colorText[] = {1,1,1,1};
				colorSelection[] = {0,0,0,0.4};
				colorBar[] = {0,0,0,1};
				colorFrame[] = {0,0,0,1};
			};
		};
		class Controls {
			class Hit_1: FLAY_VarioGauge {
				idc = 4001;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario01_ca.paa";
			};
			class Hit_2: FLAY_VarioGauge {
				idc = 4002;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario02_ca.paa";
			};
			class Hit_3: FLAY_VarioGauge {
				idc = 4003;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario03_ca.paa";
			};
			class Hit_4: FLAY_VarioGauge {
				idc = 4004;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario04_ca.paa";
			};
			class Hit_5: FLAY_VarioGauge {
				idc = 4005;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario05_ca.paa";
			};
			class Hit_6: FLAY_VarioGauge {
				idc = 4006;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario06_ca.paa";
			};
			class Hit_7: FLAY_VarioGauge {
				idc = 4007;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario07_ca.paa";
			};
			class Hit_8: FLAY_VarioGauge {
				idc = 4008;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario08_ca.paa";
			};
			class Hit_9: FLAY_VarioGauge {
				idc = 4009;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario09_ca.paa";
			};
			class Hit_10: FLAY_VarioGauge {
				idc = 4010;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario10_ca.paa";
			};
			class Hit_11: FLAY_VarioGauge {
				idc = 4011;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario11_ca.paa";
			};
			class Hit_12: FLAY_VarioGauge {
				idc = 4012;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario12_ca.paa";
			};
			class Hit_13: FLAY_VarioGauge {
				idc = 4013;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario13_ca.paa";
			};
			class Hit_14: FLAY_VarioGauge {
				idc = 4014;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario14_ca.paa";
			};
			class Hit_15: FLAY_VarioGauge {
				idc = 4015;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario15_ca.paa";
			};
			class Hit_16: FLAY_VarioGauge {
				idc = 4016;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario16_ca.paa";
			};
			class Hit_17: FLAY_VarioGauge {
				idc = 4017;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario17_ca.paa";
			};
			class Hit_18: FLAY_VarioGauge {
				idc = 4018;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario18_ca.paa";
			};
			class Hit_19: FLAY_VarioGauge {
				idc = 4019;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario19_ca.paa";
			};
			class Hit_20: FLAY_VarioGauge {
				idc = 4020;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario20_ca.paa";
			};
			class Hit_21: FLAY_VarioGauge {
				idc = 4021;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario21_ca.paa";
			};
			class Hit_22: FLAY_VarioGauge {
				idc = 4022;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario22_ca.paa";
			};
			class Hit_23: FLAY_VarioGauge {
				idc = 4023;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario23_ca.paa";
			};
			class Hit_24: FLAY_VarioGauge {
				idc = 4024;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario24_ca.paa";
			};
			class Hit_25: FLAY_VarioGauge {
				idc = 4025;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario25_ca.paa";
			};
			class Hit_26: FLAY_VarioGauge {
				idc = 4026;
				text = "FLAY\FLAY_HangGlider\data\vario_big\vario26_ca.paa";
			};
			class Hit_27: FLAY_VarioGauge {
				idc = 4027;
				text = "FLAY\FLAY_HangGlider\data\vario_big\maskdn_ca.paa";
			};
			class Hit_28: FLAY_VarioGauge {
				idc = 4028;
				text = "FLAY\FLAY_HangGlider\data\vario_big\maskup_ca.paa";
			};
			class Hit_29: FLAY_VarioGauge {
				idc = 4029;
			};
			class Hit_30: FLAY_VarioGauge {
				idc = 4030;
			};			
			class VarioText: RscText {
				idc = 4031;
				colorText[] = {1,1,1,1};
				x = -0.45;
				y = 1.01;
				w = 0.1;
				size = 0.06;
			};
			class AltText: RscText {
				idc = 4032;
				colorText[] = {1,1,1,1};
				x = -0.485;
				y = 1.125;
				w = 0.1;
				size = 0.014;
			};
			class SpeedText: RscText {
				idc = 4033;
				x = -0.485;
				y = 1.16;
				w = 0.1;
				size = 0.014;
			};
			class TempText: RscText {
				idc = 4034;
				x = -0.485;
				y = 1.16;
				w = 0.1;
				size = 0.014;
			};			
		};
	};
};