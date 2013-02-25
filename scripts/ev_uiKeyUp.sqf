disableserialization;

_key = _this select 1;
_shift = _this select 2;
_left = actionKeys "TurnLeft";
_right = actionKeys "TurnRight";
_up = actionKeys "MoveForward";
_down = actionKeys "MoveBack";
_tab = [0x0f];
_space = [0x39];
_handled=false;

if (_key in _tab) then
{
	hint "tab pressed";
	_dialog = findDisplay 3000;
	if (not dialog) then
	{
		_isDialogVisible = createDialog "Test";
		ctrlSetFocus ((findDisplay 3000) displayCtrl 3002);
		((findDisplay 3000) displayCtrl 3002) ctrlMapCursor ["Move", "Pointer"];
		//((findDisplay 300) closeDisplay 0);
	} else {
		closeDialog 3000;
	};
	_handled=true;
};