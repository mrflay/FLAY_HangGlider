_bag = (_this select 0);
[_bag, "FLAY.craft.ui.pos_assemble","Assemble Hang Glider","FLAY\FLAY_HangGlider\scripts\ev_assemble.sqf"] execVM "FLAY\FLAY_HangGlider\scripts\fn_assemble.sqf";

_bag addAction ["Take Hang Glider Bag", "FLAY\FLAY_HangGlider\scripts\ev_takeHangGliderBag.sqf", [_bag]];