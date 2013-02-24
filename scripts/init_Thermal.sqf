_thermal = (_this select 0);

//#def5ne _GET(name,value) (_thermal getVariable [(name),(value)])
//#define _SET(name,value) (_thermal setVariable [(name),(value)])
//#define _DEF(name,value) ()

//_DEF("FLAY.HangGlider.lift.thermal.strength", 0.2);
//_DEF("FLAY.HangGlider.lift.thermal.radius", 300);
//_DEF("FLAY.HangGlider.lift.thermal.falloff_coeff_horz", 1.5);
//_DEF("FLAY.HangGlider.lift.thermal.falloff_coeff_vert", 1.5);
//_DEF("FLAY.HangGlider.lift.thermal.altitude_min", 10);
//_DEF("FLAY.HangGlider.lift.thermal.altitude_max", 300);
//_DEF("FLAY.HangGlider.lift.thermal.speed_min", 10);
//_DEF("FLAY.HangGlider.lift.thermal.speed_max", 100);

_thermal setVectorUp [0,0,1];
