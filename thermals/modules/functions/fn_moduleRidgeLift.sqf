/*

 FN_SOARING.SQF © Pumpkin v2.0
 -----------------------------
 Simulation of soaring flying

 parameter(s) :  nul = [ scalar: wind_direction (optional), boolean : debug message (optional)] execVM "fn_soaring.sqf"

 note :
 the order of parameters is inconsequential
 TODO (MAYBE) :
 - check surfaces type to simulate thermal - CONS: very dependant on the map/island
 - weight/calculate the coef. with command "windStr" result

*/

private ["_logic", "_units", "_activated"];
 
_logic = [_this,0,objNull,[objNull]] call BIS_fnc_param;
_units = [_this,1,[],[[]]] call BIS_fnc_param;
_activated = [_this,2,true,[true]] call BIS_fnc_param;

missionNamespace setVariable ["flay.thermals.module", _logic];

if (not _activated) exitWith { 0 };

_debug = _logic getVariable ["Debug", false];
_windazt = _logic getVariable ["WindDirection", objNull];


// force of the wind effect: calculated using a cosine function with altitude reduced to an angle of 0 to 90 °
// alt = 0 => cos 0 = 1 : max power effect; alt = 400 => ~cos 90 = 0 : no wind effect;
// decreasing altitude = less wind effect & fly more difficult
_windeffect = _logic getVariable ["WindEffect", 400 / 90];

// approximate angle of the faces producing maximum effect of wind; increasing = less wind effect & fly more difficult
_gradienteffect = _logic getVariable ["GradientEffect", 40];

// nb faces sampled for each strengh coef calculated
_nbfaces = _logic getVariable ["NumberOfFaces", 30];

// number of seconds to sleep between each iteration.
_delay = _logic getVariable ["Sleep", 0.1];

// just inits (sometimes I don't like "private" declarations :D )
_cnt = 0;
_vertangavg = 0;
_strcoefavg = 0;
_vertangTotal = 0;
_strengthTotal = 0;
_wind = 0;
_msg = "";


for [{_infinite = 0},{_infinite <= 1},{_infinite = _infinite + 1}] do {

    _vehicle = vehicle player;

    posPlyer2D = [getpos player select 0, getpos player select 1];

    _vect = surfaceNormal posPlyer2D;
    _vectx = _vect select 0;
    _vecty = _vect select 1;
    _vectz = _vect select 2;
    _normv = sqrt (_vectx * _vectx + _vecty * _vecty + _vectz * _vectz);

    // rem : normal vector for a horizontal plane = [0,0,1]
    // rem : V.V' = ||V||.||V'||cos(a)
    // V' = (0, 0 , 1) => x*0 + y*0 + z*1 = sqrt(x² + y² + z²) * sqrt(0² + 0² + 1²) * cos(a)
    // => z = sqrt(x² + y² + z²) * cos(a) => cos(a) = z / sqrt(x² + y² + z²)
    _angv = acos (_vectz / _normv);
    // sum vertical angles for average angle
    _vertangavg = (_vertangavg + _angv);

    // direction of face in degrees
    _angf = _vectx atan2 _vecty;
    if (_angf <= 0) then { _angf = 360 + _angf };

    // "natural" wind or "artificial wind"
    if (_windazt == -1) then { _wind = windDir } else { _wind = _windazt};

    //>> FOR DEBUG >>
    if (_debug) then {
        _msg = format["<t color='#ffff00' size='0.8'>Altitude ASL:<t/><br/><t color='#ffffff' size='1'>%1<t/><br/>", getposasl player select 2];
        _msg = _msg + format["<t color='#ffff00' size='0.8'>Altitude ATL:<t/><br/><t color='#ffffff' size='1'>%1<t/><br/>", getposatl player select 2];
    };
    //<< FOR DEBUG <<

    _strcoef = abs (((360 - abs (_wind - _angf + 180)) / 180) - 1);

    // sampling counter
    _cnt = _cnt + 1;
    // sum coefs for average coef
    _strcoefavg = (_strcoefavg + _strcoef);

    // multiples faces samplings for smoother transitions, updated every 10 faces
    // 1st sampling :  ... {n-30 . n-20 . n-10} . n . n+10 . n+20 . n+30 ...
    // 2nd sampling :  ... n-30 . {n-20 . n-10 . n} . n+10 . n+20 . n+30 ...
    // 3rd sampling :  ... n-30 . n-20 . {n-10 . n . n+10} . n+20 . n+30 ...
    // and so on...
    if  (_cnt == _nbfaces) then {
        _cnt = _nbfaces - 10;
        _strcoefavg = (_strcoefavg / _nbfaces) * _cnt;
        _vertangavg = (_vertangavg / _nbfaces) * _cnt;
        //  value "0.4" sets to be near the values of mrflay. ratio "0.4" depends of time set for the "sleep" (end of loop) : + "sleep" time is high, + ratio must be high
        // (should perhaps calculate a relationship between the two number) AND depends too of the number of surfaces sampled (the more sampled, the higher the ration must be)
        _strengthTotal = (_strcoefavg / _cnt - 0.5) * 0.4;

        // weighting by the vertical angle
        _vertangTotal = (_vertangavg / _cnt) / _gradienteffect;
        _strengthTotal = (_strengthTotal * _vertangTotal) * cos ((getposATL player select 2) / _windeffect);
    };

    _soaring = true;
    if (not ((vehicle player) isKindOf "FLAY_HangGlider")) then {_soaring = false};
    if (getPosATL player select 2 < 10) then {_soaring = false};
    // find the thermals affecting the vehicle
    // maximum radius too look for thermals
    _THERMAL_MAX_RADIUS = 1000;
    _thermals = (position vehicle player) nearObjects ["FLAY_Thermal", _THERMAL_MAX_RADIUS];
    {
        _thermal = _x;
        _thermalRadiusHorz = _thermal getVariable ["FLAY.HangGlider.lift.thermal.radius", 500];
        if ((vehicle player distance _thermal) <= _thermalRadiusHorz) then {_soaring = false};
        //>> FOR DEBUG >>
        if ( _debug and ((vehicle player distance _thermal) <= _thermalRadiusHorz) ) then {_msg = _msg + "<t color='#ff0000' size='1.5'>thermal influence<t/><br/>"};
        //<< FOR DEBUG <<
    } forEach _thermals;

    //>> FOR DEBUG >>
    if (_debug) then {
        //_msg = _msg + format["<t color='#808080' size='0.8'>wind effect :<t/><br/><t color='#808080' size='1'>%1<t/><br/>", cos ((getposATL player select 2) / _windeffect)];
        //_msg = _msg + format["<t color='#808080' size='0.8'>face effect :<t/><br/><t color='#808080' size='1'>%1<t/><br/>", _vertangTotal];
        _msg = _msg + format["<t color='#ffff00' size='1'>strenghTotal :<t/><br/><t color='#ff4000' size='2'>%1<t/><br/>", _strengthTotal];
        hintsilent parseText _msg;
    };
    //<< FOR DEBUG <<

    if (_soaring) then {
        _vdir = vectorDir _vehicle;
        _vup = vectorUp _vehicle;
        _velocity = velocity _vehicle;
        _vehicle setVelocity [(_velocity select 0) + _strengthTotal * (_vdir select 0), (_velocity select 1) + _strengthTotal * (_vdir select 1), (_velocity select 2) + 6 * _strengthTotal * (_vup select 2)];
    };

    // !! if modif. "sleep" time=> modif. "_strengthTotal" ratio of 0.4
    sleep _delay;
    _infinite = 0;
};  