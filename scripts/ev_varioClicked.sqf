disableserialization;

_button = (_this select 0);
_hasVario = ('FLAY_Flytec3040_Variometer' in (weapons player) or 'FLAY_Flytec3040_Variometer' in (weapons (vehicle player)));
if (not (alive player) or (not _hasVario)) exitWith {
	player sidechat "ev_varioClicked: no vario";
};

_powerOn = player getVariable ['FLAY.variometer.power.on', false];
if (_powerOn) then {
	player setVariable ['FLAY.variometer.power.on', false];
	[player] execVM "\FLAY\FLAY_HangGlider\scripts\ui_variometer_hide.sqf";
} else {
	player setVariable ['FLAY.variometer.power.on', true];
	[player] execVM "FLAY\FLAY_HangGlider\scripts\ui_variometer_show.sqf";
};
