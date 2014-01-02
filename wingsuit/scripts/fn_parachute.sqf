_w=vehicle player;
_dir=getdir _w;
_d=vectordir _w;
_v=velocity _w;
_p=getposasl _w;

moveout player;
deleteVehicle _w;

player setPosASL _p;
player setdir _dir;
player setvectordir _d;
player setvelocity _v;

playsound "FLAY_ParachuteOpening";

if (speed _w > 100) then {
	playsound "FLAY_ParachuteOpeningPain";
};

// remove wingsuit effect
if (!isNil {flay_wingsuit_ppRadialBlur}) then {
    ppeffectdestroy flay_wingsuit_ppRadialBlur;
};

player addbackpack "b_parachute";
player action ["openparachute", player]; // use script instead?

[(vehicle player), 50, 10] call bis_fnc_setPitchBank;

// handle landing
[] spawn {
	private ["_timeout", "_wingsuit", "_speed"];
	_timeout = time + 120;
	_wingsuit = (vehicle player);
	while { time < _timeout } do {
		_altitude = (getposatl _wingsuit) select 2;
		if (_altitude < 0.25) then {
			_timeout = 0;
			_speed = speed _wingsuit;
			moveout player;
			if (_speed > 10) then {
				playsound "FLAY_ParachuteLandingPain";
			};
		};
		sleep 0.1;
	};
};

flay_wingsuit_DynamicBlur = ppeffectcreate ["DynamicBlur",464];
flay_wingsuit_DynamicBlur ppEffectEnable true;
flay_wingsuit_DynamicBlur ppEffectAdjust [8.0];
flay_wingsuit_DynamicBlur ppEffectCommit 0;

//sleep 0.5;

flay_wingsuit_DynamicBlur ppEffectAdjust [0.0];
flay_wingsuit_DynamicBlur ppEffectCommit 2;

sleep 4;

ppeffectdestroy flay_wingsuit_DynamicBlur;
