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

// TODO - separate to other script
_airborne = _glider getVariable ["FLAY_HangGlider_airborne", false];
if (_airborne) exitWith { false };

_running = _shift; // eg. enable running if shift key is pressed.
_sprinting = false;

_speed = sqrt((_v select 0)^2+(_v select 1)^2+(_v select 2)^2);
_altitude = _glider animationPhase "FeetDamper";
hint str format ["speed=%1 alt=%2", str (round _speed), str (round _altitude)];
if (_speed > 5) then {
	_sprinting = true;
};

_speedWalk = 0.8;
_speedRun = 6.5;
_speedSprint = 8.0;
_speedLaunch = 11.0;
_maxSpeed = _speedWalk;

if (_running) then {
	_maxSpeed = _speedRun;
};

if (_sprinting) then {
	_maxSpeed = _speedSprint;
};

if ((_key in _up) and (_key in _left)) then {
	player sidechat "both up and left pressed";
};

if (_key in _up) then
{
	_anim = "AmovPercMwlkSlowWrflDf";
	if (_running) then {
		_anim = "AmovPercMrunSlowWrflDf";
	};
	if (_sprinting) then {
		_anim = "SprintBaseDf";
	};
	
	if (animationState player != _anim and _speed > 0) then {
		player switchMove _anim;
	};

	_k = 0.1;
	if (_speed < 1.0) then {
		_k = 0.8;
	};
	if (_speed > _maxSpeed) then {
		_k = 0;
	};
	_glider setVelocity [(_v select 0) + _k * (_dir select 0), (_v select 1) + _k * (_dir select 1), (_v select 2) + _k * (_dir select 2)];
    _handled=true;
};

if (_key in _left) then
{
	_anim = "AmovPercMwlkSlowWrflDl";
	if (_running) then {
		_anim = "AmovPercMrunSlowWrflDl";
	};
	
	if (animationState player != _anim and _speed > 0) then {
		player switchMove _anim;
	};
	
	_dirLeft = (getdir _glider) - 90;
	_k = 0.1;
	
	if (_speed < 1.0) then {
		_k = 0.8;
	};
	if (_speed > _maxSpeed) then {
		_k = 0;
	};
	
	_glider setVelocity [(_v select 0) + _k * sin _dirLeft, (_v select 1) + _k * cos _dirLeft, (_v select 2) + _k * (_dir select 2)];
    _handled=true;
};

if (_key in _right) then
{
	_anim = "AmovPercMwlkSlowWrflDr";
	if (_running) then {
		_anim = "AmovPercMrunSlowWrflDr";
	};
	
	if (animationState player != _anim and _speed > 0) then {
		player switchMove _anim;
	};
	
	_dirRight = (getdir _glider) + 90;
	_k = 0.1;
	
	if (_speed < 1.0) then {
		_k = 0.8;
	};
	if (_speed > _maxSpeed) then {
		_k = 0;
	};
	
	_glider setVelocity [(_v select 0) + _k * sin _dirRight, (_v select 1) + _k * cos _dirRight, (_v select 2) + _k * (_dir select 2)];
    _handled=true;
};

if (_key in _down) then
{
	_anim = "AmovPercMwlkSlowWrflDb";
	if (_running) then {
		_anim = "AmovPercMrunSlowWrflDb";
	};
	
	if (animationState player != _anim and _speed > 0) then {
		player switchMove _anim;
	};
	
	_k = -0.2;
	if (_speed < 1.0) then {
		_k = -0.8;
	};
	if (_speed > _maxSpeed) then {
		_k = 0;
	};
	
	_glider setVelocity [(_v select 0) + _k * (_dir select 0), (_v select 1) + _k * (_dir select 1), (_v select 2) + _k * (_dir select 2)];
    _handled=true;
};

if (_key in _space) then
{
    _handled=true;
	if (_glider getVariable ["FLAY_HangGlider_BlockSpaceKeyUntilReleased", false]) exitWith { true; };
	
	_anim = "HangGlider_Pilot";
	if (animationState player != _anim) then {
		_glider animate ["PilotPosY", 0];
		_glider animate ["PilotPosZ", 0];
		player playAction "ResetGesture";
		player switchMove _anim;
	};
	_k = 1.5;
	if (_speed > _speedLaunch) then {
		_k = 0;
	};	
	_glider setVelocity [(_v select 0) + _k * (_dir select 0), (_v select 1) + _k * (_dir select 1), (_v select 2) + _k * (_dir select 2) + 1.0];
	_glider setVariable ["FLAY_HangGlider_airborne", true];
	[_glider] call FLAY_HangGlider_fnc_Airborne;
	_glider setVariable ["FLAY_HangGlider_BlockSpaceKeyUntilReleased", true];
};

_handled;