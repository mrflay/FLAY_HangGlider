/*ArmA 2 flares, by Maddmatt
*/
_v=_this select 0;
_flares=[];
_emmiters=[];

_muzzzlevel=30; 

_vel=velocity _v;

_relpos=_v modeltoworld [0,0,0]; //(_v selectionposition format["flare_launcher%1",_i]);
_dirpos=_v modeltoworld [0,1,0]; //(_v selectionposition format["flare_launcher%1_dir",_i]);


//_flare="Bo_ClusterGrenades" createvehiclelocal _relpos;
_flare = _this select 1;

_dirpos=[(_dirpos select 0) - (_relpos select 0),(_dirpos select 1) - (_relpos select 1),(_dirpos select 2) - (_relpos select 2)];

//Calculate vehocity to launch flare at
_div=abs(_dirpos select 0)+abs(_dirpos select 1)+abs(_dirpos select 2);
_flarevel=[(_dirpos select 0)/_div*_muzzzlevel,(_dirpos select 1)/_div*_muzzzlevel,(_dirpos select 2)/_div*_muzzzlevel];
_vvel=velocity _v;


//_flare setvelocity [(_flarevel select 0) + (_vvel select 0),(_flarevel select 1) + (_vvel select 1),(_flarevel select 2) + (_vvel select 2)];

_flares=_flares+[_flare];

_sm = "#particlesource" createVehicleLocal getpos _flare;
_sm setParticleRandom [0.5, [0.3, 0.3, 0.3], [0.5, 0.5, 0.5], 0, 0.3, [0, 0, 0, 0], 0, 0,360];
_sm setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 8,0],
		"", "Billboard", 1, 3, [0, 0, 0],
		[0,0,0], 1, 1, 0.80, 0.5, [0.3,4],
		[[0.2,0.2,0.2,0.6], [0.1,0.1,0.1,0.4], [0.1,0.1,0.1,0]],[1],0.1,0.1,"","",_flare];			
_sm setdropinterval 0.01;

_sp = "#particlesource" createVehicleLocal getpos _flare;
_sp setParticleParams [
	[
		"\A3\data_f\ParticleEffects\Universal\Universal",
		16, // nth
		10, // index
		32, // count
		1   // loop
	],
	"", // ?
	"Billboard",
	1, // timerperiod
	0.25, // lifetime
	[0, 0, 0], // pos
	[0,0,0], // movevelocity
	1, // rotationVel
	1, // weight
	0.8, // volume
	0.5, // rubbing
	[0.15,0], // scale
	[
		[1,0.8,0.8,-80],
		[1,0.8,0.8,-80],
		[0,0,0,0]
	], // color
	[1], // animspeed
	0.1, // randdirPeriod
	0.1, // randdirintensity
	"", // ontimerscript
	"", // destroyscript
	_flare, // follow
	360 // angle
];

_sp setParticleRandom [
	0.25, // lifetime
	[0.01,0.02,0.01], // position
	[0.01,0.01,0.01], // movevel
	0, // rotationvel
	0.06, // scale
	[0.1,0.1,0.1,0], // color
	0, // randdirperiod
	0, // randdirintensity
	1 // angle
];

_sp setdropinterval 0.0025;

_li = "#lightpoint" createVehicleLocal getpos _flare;
_li setLightBrightness 0.2;
_li setLightAmbient[0.8, 0.6, 0.2];
_li setLightColor[1, 0.5, 0.2];
_li lightAttachObject [_flare, [0,0,0]];

_emmiters=_emmiters+[_sm,_sp,_li];

(_emmiters + _flares) spawn {
	sleep 10 + random 1;
	{deletevehicle _x} foreach _this;
};	
