private ["_units","_emitter","_x"];

_trigger = _this select 0;
_units = _this select 1;

{
	// skip air units
	if (((getPos _x) select 2) < 2)  then {
		_fire = '#particlesource' createVehicleLocal (getPos _x); 
		_smoke = '#particlesource' createVehicleLocal (getPos _x); 
		if (_x isKindOf "Man") then {
			_fire setParticleClass 'MediumDestructionFire';
			_fire attachto [_x, [0,0,1]];			
			_smoke setParticleClass 'SmallDestructionSmoke';	
			//_smoke setParticleClass 'MediumSmoke';		
			_smoke attachto [_x, [0,0,1]];
		} else {
			_fire setParticleClass 'MediumDestructionFire';
			_fire attachto [_x, [0,1,0]];
			_smoke setParticleClass 'MediumDestructionSmoke';			
			_smoke attachto [_x, [0,1,0]];
		};
		
		_x allowFleeing 2;
		
		_fire setParticleFire [0,0,0];		
		_smoke setParticleFire [0,0,0];
					
		// fixme: innefficent
		[_x,_fire,_smoke] spawn {
			private ["_unit","_emitter","_timeout"];
			_unit = _this select 0;
			_fire = _this select 1;
			_smoke= _this select 2;
			_timeout = time + 10 + random 5;
			while { alive _unit and time < _timeout } do {
				_unit setDamage (damage _unit + 0.06);
				sleep 1;
			};
			deleteVehicle _fire;
			deleteVehicle _smoke;
		};	
	};
} foreach _units;