disableserialization;
_key = _this select 1;
_left = actionKeys "TurnLeft";
_right = actionKeys "TurnRight";
_up = actionKeys "MoveForward";
_down = actionKeys "MoveBack";
_space = [0x39];
_handled=false;
_glider = vehicle player;
_v = velocity _glider;
_dir = vectorDir _glider;
hint str FLAY_HangGlider_AoA;
if (_key in _up) then
{
    if (animationState player != "HangGlider_Pilot3") then {
		//player switchMove "HangGlider_Pilot3";
	};
	_k = 0.1;
	_glider setVelocity [(_v select 0) + _k * (_dir select 0), (_v select 1) + _k * (_dir select 1), (_v select 2) + _k * (_dir select 2)];
    _handled=true;
};
if (_key in _down) then
{
	if (animationState player != "HangGlider_Pilot2") then {
		//player switchMove "HangGlider_Pilot2";
	};
	_k = -0.2;
	_glider setVelocity [(_v select 0) + _k * (_dir select 0), (_v select 1) + _k * (_dir select 1), (_v select 2) + _k * (_dir select 2)];
    _handled=true;
};

if (_key in _space) then
{	
	//_gliderDir = direction _glider;	
	//_gliderPos = getPosATL _glider;
	//moveOut player;
	//player action ["eject", _glider];
	//player setVelocity _v;
	//player setDir _gliderDir;
	//player setvariable ["bis_fnc_halo_now",true];
	//[player, _gliderPos select 2] exec "\ca\air2\halo\data\scripts\halo_init.sqs";
    _handled=true;
	_x = allUnits select 1;
	_x action ["useWeapon",_glider,gunner _glider,0];
};
_handled;