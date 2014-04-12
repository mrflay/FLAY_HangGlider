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
	_glider animate ["pilotposz2",0.3];
	_k = 0.1;
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
	_glider animate ["GliderPitch",28];
};

if (_key in _down) then {
	_anims = ["hangglider_pilotland", "hangglider_pilotswoop"]; // case sensitive str compare in arrays
	if (not ((animationState player) in _anims)) then {
		_glider animate ["pilotposz",0];
		_glider animate ["pilotposy",0];
		//_glider animate ["pilotposz",-0.05];
		//_glider animate ["pilotposy",0.05];
		_glider animate ["HarnessStrapsHide", 1];
		_glider animate ["LandingGear", -0.40];
		_glider setVariable ["FLAY.hangglider.state.landing", true];
		player playAction "ResetGesture";
		//player playMoveNow (_anims select 0);
		player switchMove (_anims select 0);
	};
	_handled=true;
};

if (_key in _up) then {
	_anims = ["hangglider_pilot", "hangglider_pilotswoop"]; // case sensitive str compare in arrays
	if (not ((animationState player) in _anims)) then {
		_glider animate ["pilotposz",-0.05];
		_glider animate ["pilotposy",0.05]; 
		_glider animate ["gliderpitch", 5];
		_glider animate ["HarnessStrapsHide", 0];
		_glider animate ["LandingGear", 0.15];
		_glider setVariable ["FLAY.hangglider.state.landing", false];
		player playAction "ResetGesture";
		//player playMoveNow (_anims select 0);
		player switchMove (_anims select 0);
	};
	_handled=true;
};

if (_key in _left) then
{
	_glider animate ["pilotposx2",-0.1];
};

if (_key in _right) then
{
	_glider animate ["pilotposx2",0.1];
};

if (_key in _space) then
{	
	if (_shift) then {
		_wingsuit = "FLAY_WingSuit" createVehicle (getpos player);
		_wingsuit setpos (getpos player);
		moveout player; 
		player moveindriver _wingsuit;
		_wingsuit setVectorDir (vectorDir _glider);
		_wingsuit setDir (getDir _glider);
		_wingsuit setVelocity (velocity _glider);
		_handled = true;
	};
};

_handled;