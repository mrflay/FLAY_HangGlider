_glider = _this select 0;

_KeyDownHandlerId = _glider getVariable "FLAY_HangGlider_KeyDownHandlerId";
_KeyUpHandlerId = _glider getVariable "FLAY_HangGlider_KeyUpHandlerId";

(findDisplay 46) displayRemoveEventHandler ["KeyDown", _KeyDownHandlerId];
(findDisplay 46) displayRemoveEventHandler ["KeyUp", _KeyUpHandlerId];
