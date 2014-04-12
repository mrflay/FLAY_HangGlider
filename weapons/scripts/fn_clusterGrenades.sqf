
_ammo = _this select 4;
_isCluAmmo = isText (configFile >> "CfgAmmo" >> _ammo >> "FLAY_clu_ammo");
if (not _isCluAmmo) exitWith { 
	diag_log format ["fn_clusterGrenades: %1 not a cluster grenade", _ammo]; 
};

_this spawn {
	
	private ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile"];
	
	_unit = _this select 0;
	_weapon = _this select 1;
	_muzzle = _this select 2;
	_mode = _this select 3;
	_ammo = _this select 4;
	_magazine = _this select 5;
	_projectile = _this select 6;
	_vehicle = vehicle _unit;
	
	_clu_ammo = getText (configFile >> "CfgAmmo" >> _ammo >> "FLAY_clu_ammo");
	_clu_type = getNumber (configFile >> "CfgAmmo" >> _ammo >> "FLAY_clu_type");
	_clu_interval = getNumber (configFile >> "CfgAmmo" >> _ammo >> "FLAY_clu_interval");
	_clu_radius = getNumber (configFile >> "CfgAmmo" >> _ammo >> "FLAY_clu_radius");
	_clu_count = getNumber (configFile >> "CfgAmmo" >> _ammo >> "FLAY_clu_count");
	_clu_delay = getNumber (configFile >> "CfgAmmo" >> _ammo >> "FLAY_clu_delay");
	_clu_delayVar = getNumber (configFile >> "CfgAmmo" >> _ammo >> "FLAY_clu_delayVar");
		
	_isValid = false;	
	if (_clu_type == 1) then {
		_clu_mineAmmo = getText (configFile >> "CfgVehicles" >> _clu_ammo >> "ammo");
		_isValid = isClass (configFile >> "CfgAmmo" >> _clu_mineAmmo);
	} else {
		_isValid = isClass (configFile >> "CfgAmmo" >> _clu_ammo);
	};
	if (not _isValid) exitWith {
		diag_log format ["fn_clusterGrenades: %1 not valid ammo (type=%2)", _clu_ammo, _clu_type];
	};
	
	playSound3D ["a3\sounds_f\weapons\Grenades\handgrenade_drops\handg_drop_dirt_1.wss", _projectile];
	sleep 0;
		
	if (_clu_type == 1) then {
	    _posATL = getPosATL _projectile;
		while { alive _projectile } do {			
			_p = getPosATL _projectile;
			if (_p select 2 > 0) then { 
				_posATL = [_p select 0, _p select 1, 0];
			};
			sleep 0.1;
		};
		"Chemlight_red" createVehicle _posATL;
		"SmokeShellRed" createVehicle _posATL;
		for [{_i=0}, {_i<_clu_count}, {_i=_i+1}] do {			
			_grenade = createMine [_clu_ammo, _posATL, [], _clu_radius];
		};
	};

	if (_clu_type == 0) then {
		_posATL = getPosATL _projectile;
		while { alive _projectile } do {			
			_p = getPosATL _projectile;
			if (_p select 2 > 0) then { 
				_posATL = [_p select 0, _p select 1, 0];
			};
			sleep 0.1;
		};		
		for [{_i=0}, {_i<_clu_count}, {_i=_i+1}] do {
			_grenade = createVehicle [_clu_ammo, _posATL, [], _clu_radius, "NONE"];
			sleep (_clu_delay + random _clu_delayVar);
		};
	};
	
	if (_clu_type == 3) then {
		sleep 0.5;
		playSound3D ["a3\sounds_f\weapons\smokeshell\smoke_3.wss", _projectile, true, getPosASL _projectile, 0.9, 0.65, 100];
		[_vehicle, _projectile] call FLAY_fnc_effectFireTrail;
	    _posATL = getPosATL _projectile;
		while { alive _projectile } do {			
			_p = getPosATL _projectile;
			if (_p select 2 > 0) then { 
				_posATL = [_p select 0, _p select 1, 0];
			};
			sleep 0.1;
		};
		[_posATL] call FLAY_fnc_effectFire;
	};	
};
