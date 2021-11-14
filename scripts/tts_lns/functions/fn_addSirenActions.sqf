/*
	Author: TheTimidShade

	Description:
		Adds siren/light actions + handles adding of actions for JIP players

	Parameters:
		0: OBJECT - Vehicle to add actions to

	Returns:
		NOTHING

*/

params [
	["_vehicle", objNull, [objNull]]
];

if (isNull _vehicle) exitWith {};

if (!(_vehicle getVariable ["tts_lns_hasSirenActions", false])) then // only add action if the vehicle doesn't already have it
{ 
	private _sirenActionIDs = [];
	
	// toggle lights on/off
	_sirenActionIDs pushBack (_vehicle addAction ["Toggle light bar", {
		params ["_target", "_caller", "_actionId", "_arguments"];

		if (_target getVariable ["tts_lns_lightsOn", false]) then {
			_target setVariable ["tts_lns_lightsOn", false, true];
			hint "Lights: Off";
		} else {
			_target setVariable ["tts_lns_lightsOn", true, true];
			[_target] remoteExec ["tts_lns_fnc_turnLightsOn", 0, false];
			hint "Lights: On";
		};
	},
	[], 6, false, false, "", "driver _target == _this && _target getVariable ['tts_lns_hasSiren', false] && count (_target getVariable ['tts_lns_patternTypes', ['Alternating']]) > 0"]);

	// cycle light pattern
	_sirenActionIDs pushBack (_vehicle addAction ["Cycle light bar pattern", {
		params ["_target", "_caller", "_actionId", "_arguments"];
		
		_target setVariable ["tts_lns_lightMode", ((_target getVariable ["tts_lns_lightMode", 0])+1) % count (_target getVariable ['tts_lns_patternTypes', ["Alternating"]]), true];
		hint ("Light Mode: " + (_target getVariable ['tts_lns_patternTypes', ["Alternating"]])#(_target getVariable ["tts_lns_lightMode", 0]));
	},
	[], 6, false, false, "", "driver _target == _this && _target getVariable ['tts_lns_hasSiren', false] && count (_target getVariable ['tts_lns_patternTypes', ['Alternating']]) > 1"]);

	// toggle siren on/off
	_sirenActionIDs pushBack (_vehicle addAction ["Toggle siren", {
		params ["_target", "_caller", "_actionId", "_arguments"];

		if (_target getVariable ["tts_lns_sirenOn", false]) then {
			_target setVariable ["tts_lns_sirenOn", false, true];
			hint "Siren: Off";
		} else {
			_target setVariable ["tts_lns_sirenOn", true, true];
			[_target] remoteExec ["tts_lns_fnc_turnSirenOn", 0, false];
			hint "Siren: On";
		};
	},
	[], 6, false, false, "", "driver _target == _this && _target getVariable ['tts_lns_hasSiren', false] && count (_target getVariable ['tts_lns_sirenTypes', ['Wail']]) > 0"]);

	// cycle siren
	_sirenActionIDs pushBack (_vehicle addAction ["Cycle siren mode", {
		params ["_target", "_caller", "_actionId", "_arguments"];

		_target setVariable ["tts_lns_sirenMode", ((_target getVariable ["tts_lns_sirenMode", 0])+1) % count (_target getVariable ['tts_lns_sirenTypes', ['Wail']]), true];
		hint ("Siren Mode: " + (_target getVariable ['tts_lns_sirenTypes', ['Wail']])#(_target getVariable ["tts_lns_sirenMode", 0]));
	},
	[], 6, false, false, "", "driver _target == _this && _target getVariable ['tts_lns_hasSiren', false] && count (_target getVariable ['tts_lns_sirenTypes', ['Wail']]) > 1"]);
	
	_vehicle setVariable ["tts_lns_hasSirenActions", true];
	_vehicle setVariable ["tts_lns_sirenActionIDs", _sirenActionIDs]; // store action IDs so they can be removed later
};