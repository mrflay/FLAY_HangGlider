disableserialization;
_key = (_this select 1);
_shift = (_this select 2);

_left = actionKeys "TurnLeft";
_right = actionKeys "TurnRight";
_up = actionKeys "MoveForward";
_down = actionKeys "MoveBack";
_space = [0x39];
_handled=false;
_glider = vehicle player;
_v = velocity _glider;
_dir = vectorDir _glider;

if (_glider == player) exitWith { false; };
if (_glider getVariable ["FLAY_HangGlider_BlockSpaceKeyUntilReleased", false]) exitWith { true; };

_airborne = _glider getVariable ["FLAY_HangGlider_airborne", false];
if (not _airborne) exitWith { false };

_speed = sqrt((_v select 0)^2+(_v select 1)^2+(_v select 2)^2);

if (_key in _up) then
{
	_k = 0.05;
	if (_speed > 30) then {
		_k = 0;
	};	
	_glider setVelocity [(_v select 0) + _k * (_dir select 0), (_v select 1) + _k * (_dir select 1), (_v select 2) + _k * (_dir select 2)];
    _handled=true;
};

if (_key in _down) then
{
	_k = -0.2;
	if (speed _glider < 0.1) then {
		_k = 0;
	};
	_glider setVelocity [(_v select 0) + _k * (_dir select 0), (_v select 1) + _k * (_dir select 1), (_v select 2) + _k * (_dir select 2)];
    _handled=true;
	_glider animate ["GliderPitch",45];
};

if (_key in _space) then
{	
	_anim = "HangGlider_PilotLand";
	if (animationState player != _anim) then {
		_glider animate ["PilotPosY", 0];
		_glider animate ["PilotPosZ", 0];
		player playAction "ResetGesture";
		player switchMove _anim;
	};
	_k = -0.2;
	if (_speed < 8) then {
		_k = 0;
	};
	_glider setVelocity [(_v select 0) + _k * (_dir select 0), (_v select 1) + _k * (_dir select 1), (_v select 2) + _k * (_dir select 2)];
	_glider setVariable ["FLAY_HangGlider_BlockSpaceKeyUntilReleased", true];
	_glider setVariable ["FLAY_HangGlider_airborne", false];
	_glider animate ["FeetStabilizer", 1];
	_glider animate ["HideHarness",0];
	[_glider] call FLAY_HangGlider_fnc_Ground;
	_handled=true;
};

_handled;