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

if (_speed > 5) then {
	_sprinting = true;
};

_speedWalk = 0.8;
_speedRun = 6;
_speedSprint = 7.0;
_speedLaunch = 11.0;
_maxSpeed = _speedWalk;

if (_running) then {
	_maxSpeed = _speedRun;
};

if (_sprinting) then {
	_maxSpeed = _speedSprint;
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
		_k = 1.0;
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
		_k = 1.0;
	};
	if (_speed > _maxSpeed) then {
		_k = 0;
	};
	
	_dFx = 0;
	_dFy = 0;
	_dLx = _k * (sin _dirLeft);
	_dLy = _k * (cos _dirLeft);
	
	_glider setVelocity [(_v select 0) + (_dFx + _dLx), (_v select 1) + (_dFy + _dLy), (_v select 2) + _k * (_dir select 2)];
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
		_k = 1.0;
	};
	if (_speed > _maxSpeed) then {
		_k = 0;
	};
	
	_dFx = 0;
	_dFy = 0;
	_dRx = _k * (sin _dirRight);
	_dRy = _k * (cos _dirRight);
	
	_glider setVelocity [(_v select 0) + (_dFx + _dRx), (_v select 1) + (_dFy + _dRy), (_v select 2) + _k * (_dir select 2)];
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
		_k = -1.0;
	};
	if (_speed > _maxSpeed) then {
		_k = 0;
	};
	
	_glider setVelocity [(_v select 0) + _k * (_dir select 0), (_v select 1) + _k * (_dir select 1), (_v select 2) + _k * (_dir select 2)];
    _handled=true;
};

if (_key in _space) then
{
	// When the glider is airborne, space is used to switch into landing pose. This prevents the switch 
	// from triggering immedietly if space is pressed during takeoff (it is cleared in the KeyUp event handler).
	if (_glider getVariable ["FLAY_HangGlider_BlockSpaceKeyUntilReleased", false]) exitWith { true; };
	
	_anim = "HangGlider_Pilot";
	if (animationState player != _anim) then {
		_glider animate ["PilotPosY", 0];
		_glider animate ["PilotPosZ", 0];
		player playAction "ResetGesture";
		player switchMove _anim;
	};
	_k = 3;
	if (_speed > _speedLaunch) then {
		_k = 0;
	};	
	_glider setVelocity [(_v select 0) + _k * (_dir select 0), (_v select 1) + _k * (_dir select 1), (_v select 2) + _k * (_dir select 2) + 1.0];
	_glider setVariable ["FLAY_HangGlider_airborne", true];
	[_glider] call FLAY_HangGlider_fnc_Airborne;
	_glider setVariable ["FLAY_HangGlider_BlockSpaceKeyUntilReleased", true];
	_handled=true;
};

_handled;