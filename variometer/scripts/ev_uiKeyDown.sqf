disableserialization;

_ctrl = _this select 0;
_dikCode = _this select 1;
_isShiftKeyPressed = _this select 2;
_isCtrlKeyPressed = _this select 3;
_isAltKeyPressed = _this select 4;
  
_left = actionKeys "TurnLeft";
_right = actionKeys "TurnRight";
_up = actionKeys "MoveForward";
_down = actionKeys "MoveBack";
_tab = [0x0f];
_space = [0x39];
_caps = [0x3A];
_ctrl = [0x1D,0x9D];
_handled=false;

if (_dikCode in _caps) then {
	_dialog = findDisplay 3000;
	if (not dialog) then {
		_isDialogVisible = createDialog "FLAY_RscVarioDialog";
		ctrlSetFocus ((findDisplay 3000) displayCtrl 3002);
		((findDisplay 3000) displayCtrl 3002) ctrlMapCursor ["Move", "Arrow"];
	};
	_handled=true;
};