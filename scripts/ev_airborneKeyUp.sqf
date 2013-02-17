disableserialization;
_key = _this select 1;
_shift = _this select 2;
_left = actionKeys "TurnLeft";
_right = actionKeys "TurnRight";
_up = actionKeys "MoveForward";
_down = actionKeys "MoveBack";
_space = [0x39];
_handled=false;
_glider = vehicle player;

if (_glider == player) exitWith { false; };

if (_key in _space) then
{

};

_handled;