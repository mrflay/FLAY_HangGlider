class CfgPatches
{
	class FLAY_HangGlider_Weapons
	{
		units[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"FLAY_HangGlider_Core"};
	};
};

class cfgFunctions
{
	class FLAY_HangGlider_Weapons
	{
		tag = "FLAY";
		class Weapons
		{
			file = "FLAY\FLAY_HangGlider\weapons\scripts";
			class clusterGrenades {};
			class effectFire {};
			class effectFireTrail {};
			class triggerBurning {};
		};
	};
}

// ===========================================================================
// WEAPONS
// ===========================================================================

class cfgWeapons
{
    class Default;
	class RocketPods;
	class HangGliderBombs: RocketPods
	{
		scope = 1;
		displayName = "Bombs";
		cursorAim = "EmptyCursor";
		cursor = "EmptyCursor";
		cursorSize = 1;
		autoFire = 0;
		sound[] = {"",10.0,1};
		magazines[] = {"2Rnd_Bomb_HE","3Rnd_ClusterBombs"};
		reloadTime = 1;
		magazineReloadTime = 1;
		dispersion = 0.015;
		minRange = 1;
		minRangeProbab = 0.8;
		midRange = 50;
		midRangeProbab = 0.7;
		maxRange = 150;
		maxRangeProbab = 0.1;
		autoReload = 1;
		canLock = 0;
	};
	class HangGliderGrenades: HangGliderBombs
	{
		scope = 1;
		displayName = "Grenades";
		magazines[] = {"3Rnd_ClusterGrenades","6Rnd_Molotov"};
		reloadTime = 0.5;
		magazineReloadTime = 1;		
	};
	class HangGliderMines: HangGliderBombs
	{
		scope = 1;
		displayName = "Mines";
		magazines[] = {"3Rnd_ClusterATMines","3Rnd_ClusterAPMines"};
	};	
	class launch_RPG32_F;
	class FLAY_HangGlider_BagLauncher: launch_RPG32_F
	{
		scope = 2;
		displayName = "FLAY Hang Glider Bag";
		model = "FLAY\FLAY_HangGlider\FLAY_HangGlider_Bag.p3d";
		cursorAim = "EmptyCursor";
		cursor = "EmptyCursor";
		modelOptics = "-";
		sound[] = {"",10.0,1,1400};
		drySound[] = {"",0.0001,1,10};
		reloadMagazineSound[] = {"",0.00031622776,1,20};
		soundFly[] = {"",100.0,1.5,700};
		class Library
		{
			libTextDesc = "FLAY Hang Glider Bag";
		};
		descriptionShort = "FLAY Hang Glider Bag";
	};
};

// ===========================================================================
// MAGAZINES
// ===========================================================================

class CfgMagazines
{
	class Default;
	class CA_Magazine: Default {};
	class VehicleMagazine: CA_Magazine {};
	class 2Rnd_Bomb_HE: VehicleMagazine
	{
		scope = 2;
		displayName = "MK-10B HE";
		displayNameShort = "MK-10B HE";		
		ammo = "Bo_50_HE";
		count = 2;
		initSpeed = 1;
		maxLeadSpeed = 200;
		nameSound = "grenade";
	};
	class 3Rnd_ClusterGrenades: VehicleMagazine
	{
		scope = 2;
		displayName = "CLU-8G";
		displayNameShort = "CLU-8G";	
		ammo = "Bo_ClusterGrenades";
		count = 3;
		initSpeed = 1;
		maxLeadSpeed = 200;
		nameSound = "grenade";
	};
	class 3Rnd_ClusterBombs: VehicleMagazine
	{
		scope = 2;
		displayName = "CLU-12B HE";
		displayNameShort = "CLU-12B HE";		
		ammo = "Bo_ClusterBombs";
		count = 3;
		initSpeed = 1;
		maxLeadSpeed = 200;
		nameSound = "grenade";
	};		
	class 3Rnd_ClusterATMines: VehicleMagazine
	{
		scope = 2;
		displayName = "CLU-AT";
		displayNameShort = "CLU-AT Mine";
		ammo = "Bo_ClusterATMines";
		count = 3;
		initSpeed = 1;
		maxLeadSpeed = 200;
		nameSound = "grenade";
	};	
	class 3Rnd_ClusterAPMines: VehicleMagazine
	{
		scope = 2;
		displayName = "CLU-AP";
		displayNameShort = "CLU-AP Mine";
		ammo = "Bo_ClusterAPMines";
		count = 3;
		initSpeed = 1;
		maxLeadSpeed = 200;
		nameSound = "grenade";
	};
	class 6Rnd_Molotov: VehicleMagazine
	{
		scope = 2;
		displayName = "Molotov";
		displayNameShort = "Molotov";
		ammo = "Bo_Molotov";
		count = 6;
		initSpeed = 1;
		maxLeadSpeed = 200;
		nameSound = "grenade";
	};	
};

// ===========================================================================
// AMMO
// ===========================================================================

class CfgAmmo
{
    class Default;
	class BombCore {};
	class Bo_50_HE: BombCore
	{
		hit = 100;
		indirectHit = 20;
		indirectHitRange = 10;
		cost = 1000;
		irLock = 0;
		laserLock = 0;
		maxControlRange = 10;
		maneuvrability = 16.0;
		sideAirFriction = 0.1;
		simulation = "shotRocket";
		maxSpeed = 100;
		timeToLive = 120;
		initTime = 0;
		thrustTime = 0;
		thrust = 0;
		soundHit1[] = {"A3\Sounds_F\weapons\Explosion\expl_big_1",5.0118723,1,2400};
		soundHit2[] = {"A3\Sounds_F\weapons\Explosion\expl_big_2",5.0118723,1,2400};
		soundHit3[] = {"A3\Sounds_F\weapons\Explosion\expl_big_3",5.0118723,1,2400};
		soundHit4[] = {"A3\Sounds_F\weapons\Explosion\expl_shell_1",5.0118723,1,2400};
		soundHit5[] = {"A3\Sounds_F\weapons\Explosion\expl_shell_2",5.0118723,1,2400};
		multiSoundHit[] = {"soundHit1",0.2,"soundHit2",0.2,"soundHit3",0.2,"soundHit4",0.2,"soundHit5",0.2};
		explosionSoundEffect = "DefaultExplosion";
		model = "\A3\weapons_f\Ammo\UGL_slug";
		proxyShape = "\A3\weapons_f\Ammo\UGL_slug";
		//CraterEffects = "BombCrater";
		//explosionEffects = "BombExplosion";
		CraterEffects = "HERocketCrater";
		explosionEffects = "HERocketExplosion";
		whistleDist = 24;
	};
	// cluster grenades
	class mini_Grenade;
	class FLAY_clu_grenade: mini_Grenade {
		explosionTime = 0;
		timeToLive = 2;
		fuseDistance = 0;	
	};
	class Bo_ClusterBase: Bo_50_HE
	{
		hit = 0;
		indirectHit = 0;
		indirectHitRange = 0;
		soundHit[] = {"",1,1};				
		multiSoundHit[] = {};
		cost = 1;
		whistleDist = 0;		
		//model = "\A3\Weapons_f\ammo\mini_frag";
		//proxyShape = "\A3\Weapons_f\ammo\mini_frag";
		CraterEffects = "NoCrater";
		explosionEffects = "NoExplosion";	
		explosive = 0;
		
		FLAY_clu_ammo = "FLAY_clu_grenade";
		FLAY_clu_type = 0;
		FLAY_clu_interval = 1;	
		FLAY_clu_radius = 8;
		FLAY_clu_count = 10;
		FLAY_clu_delay = 0.1;
		FLAY_clu_delayVar = 0.1;		
	};	
	class Bo_ClusterGrenades: Bo_ClusterBase
	{	
		FLAY_clu_ammo = "FLAY_clu_grenade";
		FLAY_clu_interval = 0;	
		FLAY_clu_radius = 10;
		FLAY_clu_count = 10;
		FLAY_clu_delay = 0.1;
		FLAY_clu_delayVar = 0.1;		
	};
	class Bo_ClusterBombs: Bo_ClusterBase
	{	
		FLAY_clu_ammo = "R_TBG32V_F";
		FLAY_clu_interval = 0;	
		FLAY_clu_radius = 0;
		FLAY_clu_count = 1;
		FLAY_clu_delay = 0;
		FLAY_clu_delayVar = 0;		
	};	
	class Bo_ClusterATMines: Bo_ClusterBase
	{		
		FLAY_clu_ammo = "ATMine";
		FLAY_clu_type = 1;
		FLAY_clu_interval = 0;	
		FLAY_clu_radius = 8;
		FLAY_clu_count = 5;
		FLAY_clu_delay = 0.1;
		FLAY_clu_delayVar = 0.1;		
	};	
	class Bo_ClusterAPMines: Bo_ClusterBase
	{		
		FLAY_clu_ammo = "APERSBoundingMine";
		FLAY_clu_type = 1;
		FLAY_clu_interval = 0;	
		FLAY_clu_radius = 10;
		FLAY_clu_count = 8;
		FLAY_clu_delay = 0.1;
		FLAY_clu_delayVar = 0.1;		
	};	
	class Bo_Molotov: Bo_ClusterBase
	{		
		model = "\A3\Weapons_f\ammo\mini_frag";
		proxyShape = "\A3\Weapons_f\ammo\mini_frag";	
		FLAY_clu_ammo = "G_20mm_HE";
		FLAY_clu_type = 3;
		soundHit[] = {"FLAY\FLAY_HangGlider\weapons\sounds\hit_glass_01",1,1,200};
	};
};

class cfgVehicles
{
	class Sound;
	class Sound_Fire1: Sound
	{
		scope = 1;
		sound = "FLAY_Sound_Fire1";
		displayName = "Fire 1";
	};
	class Sound_Fire2: Sound
	{
		scope = 1;
		sound = "FLAY_Sound_Fire2";
		displayName = "Fire 2";
	};
	class Sound_DropGrenade: Sound
	{
		scope = 1;
		sound = "FLAY_Sound_DropGrenade";
		displayName = "Drop Grenade";
	};
	class Sound_DropSmoke: Sound
	{
		scope = 1;
		sound = "FLAY_Sound_DropSmoke";
		displayName = "Drop Smoke";
	};
	class Sound_BreakGlass: Sound
	{
		scope = 1;
		sound = "FLAY_Sound_BreakGlass";
		displayName = "Break Glass";
	};	
};

class CfgSFX
{
	access = 2;
	class FLAY_Sound_Fire1
	{
		sounds[] = {"sound1"};
		name = "FLAY_Sound_Fire1";
		sound1[] = {"a3\sounds_f\sfx\fire1_loop",1,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};
	};
	class FLAY_Sound_Fire2
	{
		sounds[] = {"sound1"};
		name = "FLAY_Sound_Fire2";
		sound1[] = {"FLAY\FLAY_HangGlider\weapons\sounds\fire",1,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};	
	};		
	class FLAY_Sound_DropGrenade
	{
		sounds[] = {"sound1"};
		name = "FLAY_Sound_DropGrenade";
		sound1[] = {"a3\sounds_f\weapons\Grenades\handgrenade_drops\handg_drop_dirt_1",1,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};	
	};	
	class FLAY_Sound_DropSmoke
	{
		sounds[] = {"sound1"};
		name = "FLAY_Sound_DropSmoke";
		sound1[] = {"a3\sounds_f\weapons\smokeshell\smoke_3",1,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};	
	};	
	class FLAY_Sound_BreakGlass
	{
		sounds[] = {"sound1"};
		name = "FLAY_Sound_BreakGlass";
		sound1[] = {"FLAY\FLAY_HangGlider\weapons\sounds\hit_glass_01",1,1,300,1.0,0,0,0};
		empty[] = {"",0,0,0,0,0,0,0};	
	};	
};