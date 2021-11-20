class CfgVehicles {
    class Logic;
    class Module_F: Logic
    {
        class AttributesBase
        {
            class Default;
            class Edit;
            class Combo;
            class Checkbox;
            class CheckboxNumber;
            class ModuleDescription;
            class Units;
        };
        class ModuleDescription;
    };
    
    class tts_lns_module : Module_F {
        author = "TheTimidShade";
        scope = 1;
        scopeCurator = 1;
        is3DEN = 0;
        displayName = "TheTimidShade's Module";
        vehicleClass = "Modules";
        category = "tts_lns_modules";
    };

    class tts_lns_moduleAddSiren : tts_lns_module {
        scope = 2;
        scopeCurator = 0; // module is not available in Zeus
        isDisposable = 1; // 1 if modules is to be disabled once it's activated (i.e., repeated trigger activation won't work)
        isGlobal = 0; // 0 for server only execution, 1 for global execution, 2 for persistent global execution
        isTriggerActivated = 1;
        displayName = "$STR_tts_lns_moduleAddSiren_title";
        icon = "tts_lns\icons\lns_icon_64px.paa";
        category = "tts_lns_modules";
        function = "tts_lns_fnc_moduleAddSiren";
        functionPriority = 2;
        
        class Attributes : AttributesBase {
            class SirenTypes : Edit {
                property = "tts_lns_moduleAddSiren_SirenTypes";
                displayName = "$STR_tts_lns_moduleAddSiren_sirenTypes";
                tooltip = "$STR_tts_lns_moduleAddSiren_sirenTypes_desc";
                typeName = "STRING";
                defaultValue = """Wail,Yelp,Phaser""";
            };
            class LightPatterns : Edit {
                property = "tts_lns_moduleAddSiren_LightPatterns";
                displayName = "$STR_tts_lns_moduleAddSiren_lightPatterns";
                tooltip = "$STR_tts_lns_moduleAddSiren_lightPatterns_desc";
                typeName = "STRING";
                defaultValue = """Alternating,DoubleFlash,RapidAlt""";
            };
            class LeftLightColour : Combo {
				property = "tts_lns_moduleAddSiren_LeftLightColour";
				displayName = "$STR_tts_lns_moduleAddSiren_leftLightColour";
				tooltip = "$STR_tts_lns_moduleAddSiren_leftLightColour_desc";
				typeName = "STRING";
				defaultValue = """red""";
				class Values
				{
					class Red {name = "$STR_tts_lns_moduleAddSiren_colour_red"; value = "red";};
					class Blue {name = "$STR_tts_lns_moduleAddSiren_colour_blue"; value = "blue";};
                    class Amber {name = "$STR_tts_lns_moduleAddSiren_colour_amber"; value = "amber";};
                    class Yellow {name = "$STR_tts_lns_moduleAddSiren_colour_yellow"; value = "yellow";};
                    class Green {name = "$STR_tts_lns_moduleAddSiren_colour_green"; value = "green";};
                    class White {name = "$STR_tts_lns_moduleAddSiren_colour_white"; value = "white";};
                    class Magenta {name = "$STR_tts_lns_moduleAddSiren_colour_magenta"; value = "magenta";};
                };
			};
            class RightLightColour : Combo {
				property = "tts_lns_moduleAddSiren_RightLightColour";
				displayName = "$STR_tts_lns_moduleAddSiren_rightLightColour";
				tooltip = "$STR_tts_lns_moduleAddSiren_rightLightColour_desc";
				typeName = "STRING";
				defaultValue = """blue""";
				class Values
				{
					class Red {name = "$STR_tts_lns_moduleAddSiren_colour_red"; value = "red";};
					class Blue {name = "$STR_tts_lns_moduleAddSiren_colour_blue"; value = "blue";};
                    class Amber {name = "$STR_tts_lns_moduleAddSiren_colour_amber"; value = "amber";};
                    class Yellow {name = "$STR_tts_lns_moduleAddSiren_colour_yellow"; value = "yellow";};
                    class Green {name = "$STR_tts_lns_moduleAddSiren_colour_green"; value = "green";};
                    class White {name = "$STR_tts_lns_moduleAddSiren_colour_white"; value = "white";};
                    class Magenta {name = "$STR_tts_lns_moduleAddSiren_colour_magenta"; value = "magenta";};
                };
			};
            class OffsetPreset : Combo {
				property = "tts_lns_moduleAddSiren_OffsetPreset";
				displayName = "$STR_tts_lns_moduleAddSiren_preset";
				tooltip = "$STR_tts_lns_moduleAddSiren_preset_desc";
				typeName = "STRING";
				defaultValue = """None""";
				class Values
				{
					class None {name = "$STR_tts_lns_moduleAddSiren_preset_none"; value = "None";};
                    class Offroad {name = "$STR_tts_lns_moduleAddSiren_preset_offroad"; value = "Offroad";};
                    class Van {name = "$STR_tts_lns_moduleAddSiren_preset_van"; value = "Van";};
                    class Hatchback {name = "$STR_tts_lns_moduleAddSiren_preset_hatchback"; value = "Hatchback";};
                    class Hunter {name = "$STR_tts_lns_moduleAddSiren_preset_hunter"; value = "Hunter";};
                    class Ifrit {name = "$STR_tts_lns_moduleAddSiren_preset_ifrit"; value = "Ifrit";};
                };
			};
            class LightBarOffset : Edit {
                property = "tts_lns_moduleAddSiren_LightBarOffset";
                displayName = "$STR_tts_lns_moduleAddSiren_lightBarOffset";
                tooltip = "$STR_tts_lns_moduleAddSiren_lightBarOffset_desc";
                typeName = "STRING";
                defaultValue = """[-0.035,0.02,0.6]""";
            };
            class LightCentreOffset : Edit {
                property = "tts_lns_moduleAddSiren_LightCentreOffset";
                displayName = "$STR_tts_lns_moduleAddSiren_lightCentreOffset";
                tooltip = "$STR_tts_lns_moduleAddSiren_lightCentreOffset_desc";
                typeName = "STRING";
                defaultValue = """0.4""";
            };
            class UseFakeLightBar : Checkbox {
				property = "tts_emission_moduleEmissionSettings_UseFakeLightBar";
				displayName = "$STR_tts_lns_moduleAddSiren_useFakeLightBar";
				tooltip = "$STR_tts_lns_moduleAddSiren_useFakeLightBar_desc";
				typeName = "BOOL";
				defaultValue = "false";
			};
            class ModuleDescription: ModuleDescription{};
        };

        class ModuleDescription: ModuleDescription
        {
            description = "$STR_tts_lns_moduleGiveCloak_desc";
        };
    };
}