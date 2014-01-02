disableserialization;

_key = _this select 1;
_shift = _this select 2;
_left = actionKeys "TurnLeft";
_right = actionKeys "TurnRight";
_up = actionKeys "MoveForward";
_down = actionKeys "MoveBack";
_toggleVarioKeys = actionKeys "User1";

_space = [0x39];
_handled=false;
_glider = vehicle player;

if (_glider == player) exitWith { false; };

if (_key in _up) then
{
	_glider animate ["pilotposz2",0];
};

if (_key in _left) then
{
	_glider animate ["pilotposx2",0];
};

if (_key in _right) then
{
	_glider animate ["pilotposx2",0];
};

if (_key in _down) then
{
	_glider animate ["GliderPitch",0];
};

if (_key in _space) then
{
	_glider setVariable ["FLAY_HangGlider_BlockSpaceKeyUntilReleased", false];
};

if (_key in _toggleVarioKeys) then {
	_varioOn = player getVariable ["FLAY.variometer.power.on", false];
	if (_varioOn) then {
		player setVariable ["FLAY.variometer.power.on", false];
	} else {
		[player] execVM "flay\flay_hangglider\variometer\scripts\ui_variometer_show.sqf";
	};
	_handled = true;
};

_handled;