player sideChat "START lift.sqf";
_triggers = (position player) nearObjects ["EmptyDetector", 1000];
{
  _trigger = _x;
  player sideChat str getPos _trigger;
  _tpos = getPos _trigger;
  _ppos = getPos player;
  _dist = _tpos distance _ppos;
  player sideChat "dist";
  player sideChat str _dist;

  _radius = (triggerArea _trigger) select 0;
  player sideChat "radius";
  player sideChat str _radius;
  addCamShake [1, 25, 15];
  while {_dist < _radius + 200} do {
	_ppos = getPosATL player;
	if ((_ppos select 2) > 1) then {
		_strength = 360^(-((_dist/(2*_radius))^2.5));
		_dist = _tpos distance _ppos;
		_u=vehicle player;
		_v=velocity _u; 
		_up=vectorUp _u;
		_dir=vectorDir _u;
		_k=0.2*_strength;
		hintsilent str _k;
		_u setVelocity [(_v select 0) + _k * (_dir select 0), (_v select 1) + _k * (_dir select 1), (_v select 2) + 6 * _k * (_up select 2)];
	};
	sleep 0.1;		
  };
  
} forEach _triggers;

player sideChat "END lift.sqf"