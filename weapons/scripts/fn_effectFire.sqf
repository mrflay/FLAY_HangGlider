
_pos=_this select 0;

_emmiters=[];

_positions = [
	[_pos, [2 * cos (random 180), 2 * cos (random 180), 0]] call BIS_fnc_vectorAdd,
	[_pos, [2 * cos (random 180), 2 * cos (random 180), 0]] call BIS_fnc_vectorAdd,
	[_pos, [2 * cos (random 180), 2 * cos (random 180), 0]] call BIS_fnc_vectorAdd,
	[_pos, [2 * cos (random 180), 2 * cos (random 180), 0]] call BIS_fnc_vectorAdd
];

{
	//_sm = "#particlesource" createVehicleLocal [_x select 0, _x select 1, 0];
	//_sm setParticleRandom [0.5, [0.3, 0.3, 0.3], [0.5, 0.5, 0.5], 0, 0.3, [0, 0, 0, 0], 0, 0,360];
	//_sm setParticleParams [["\A3\data_f\ParticleEffects\Universal\Universal", 16, 12, 8,0],
	//		"", "Billboard", 1, 3, [0, 0, 0],
	//		[0,0,0], 1, 1, 0.80, 0.5, [0.3,4],
	//		[[0.2,0.2,0.2,0.6], [0.1,0.1,0.1,0.4], [0.1,0.1,0.1,0]],[1],0.1,0.1,"","",""];			
	//_sm setdropinterval 0.01;

	_sp = "#particlesource" createVehicleLocal [_x select 0, _x select 1, 0];
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
		0.6, // lifetime
		[0, 0, 0], // pos
		[0.2,0.7,0], // movevelocity
		0, // rotationVel
		0.045, // weight
		0.04, // volume
		0.05, // rubbing
		[0.65,0.05], // scale
		[
			[1,1,1,-1]
		], // color
		[0.5,1], // animspeed
		0, // randdirPeriod
		0, // randdirintensity
		"", // ontimerscript
		"", // destroyscript
		"", // follow
		360 // angle
	];

	_sp setParticleRandom [
		0.15, // lifetime
		[1.1,1.1,0.1], // position
		[0.05,0.15,0.05], // movevel
		10, // rotationvel
		0.1, // scale
		[0.1,0.1,0.1,0], // color
		0, // randdirperiod
		0, // randdirintensity
		360 // angle
	];

	_sp setdropinterval 0.005;	
	_sp setParticleCircle [1, [0,0,0]];
	//_sp setParticleFire [4,4,4];

	_emmiters=_emmiters+[_sp];

} forEach _positions;

_li = "#lightpoint" createVehicleLocal [_pos select 0, _pos select 1, 0];
_li setLightBrightness 0.2;
_li setLightAmbient[0.8, 0.5, 0.2];
_li setLightColor[1, 0.4, 0.2];
_li setLightAttenuation [0.9, 0.2, 0.2, 0.1];

_ss = createSoundSource ["Sound_Fire1",[_pos select 0, _pos select 1, 0],[], 0];

// this should be handled by set particle fire.
_trg=createTrigger["EmptyDetector",[_pos select 0, _pos select 1, 0]];
_trg setTriggerArea[8,8,0,false];
_trg setTriggerActivation["ANY","PRESENT",true];
_trg setTriggerStatements["this", "[this, thislist] call FLAY_fnc_triggerBurning;", ""]; 

(_emmiters + [_li,_ss,_trg]) spawn {
	sleep 10 + random 5;
	{deletevehicle _x} foreach _this;
};	
