class CfgPatches
{
	class FLAY_Thermals_Module
	{
		requiredaddons[] = {"A3_Modules_F"};
		requiredversion = 0.1;
		units[] = {"FLAY_ModuleThermalLift","FLAY_ModuleRidgeLift"};
	};
};

class CfgFunctions
{
	class FLAY_Modules
	{
		tag = "FLAY";
		class Thermals
		{
			file = "FLAY\FLAY_HangGlider\thermals\modules\functions";
			class moduleThermalLift {};
		};
		class Ridge
		{
			file = "FLAY\FLAY_HangGlider\thermals\modules\functions";
			class moduleRidgeLift {};
		};
	};
};

class CfgFactionClasses
{
	class NO_CATEGORY;
	class FLAY: NO_CATEGORY
	{
		displayName = "FLAY";
	};
};

class CfgVehicles 
{
	class Logic;
	class Module_F: Logic
	{
		class ArgumentsBaseUnits
		{
			class Units;
		};
		class ModuleDescription;
	};
	class FLAY_ModuleThermalLift: Module_F
	{
		scope = 2;
		displayName = "Thermal Lift";
		category = "FLAY";
		author = "mrflay";
		function = "FLAY_fnc_moduleThermalLift";
		isGlobal = 0;
		isPersistent = 0;
		isTriggerActivated = 0;
		class Arguments: ArgumentsBaseUnits
		{
			class Units: Units{};
			class Debug
  			{
				displayName = "Debug";
				description = "Enable debugging"; 
				typeName = "BOOL";
				class values
				{
					class Yes
					{
						name = "$STR_lib_info_yes";
						value = 1;
						default = 0;
					};
					class No
					{
						name = "$STR_lib_info_no";
						value = 0;
						default = 1;
					};
				};
			};
			class Strength
  			{
				displayName = "Strength";
				description = "Strength"; 
				typeName = "NUMBER";
				defaultValue = 0.1;
			};
			class Radius
  			{
				displayName = "Radius";
				description = "Maximum range the thermal will have effect"; 
				typeName = "NUMBER";
				defaultValue = 500;
			};
			class FalloffCoeffHorz
  			{
				displayName = "Falloff Coeff (Horz)";
				description = "Horizontal Falloff Coeff"; 
				typeName = "NUMBER";
				defaultValue = 1.5;
			};
			class FalloffCoeffVert
  			{
				displayName = "Falloff Coeff (Vert)";
				description = "Vertical Falloff Coeff"; 
				typeName = "NUMBER";
				defaultValue = 1.5;
			};			
			class AltitudeMin
  			{
				displayName = "Min altitude";
				description = "Minimum altitude thermal will have effect (meters)"; 
				typeName = "NUMBER";
				defaultValue = 0.1;
			};
			class AltitudeMax
  			{
				displayName = "Max altitude";
				description = "Maxiumum altitude thermal will have effect (meters)"; 
				typeName = "NUMBER";
				defaultValue = 600;
			};			
			class SpeedMin
  			{
				displayName = "Min speed";
				description = "Thermal will not effect vehicles travelling slower than this"; 
				typeName = "NUMBER";
				defaultValue = 18;
			};
			class SpeedMax
  			{
				displayName = "Max speed";
				description = "Thermal will not effect vehicles travelling faster than this"; 
				typeName = "NUMBER";
				defaultValue = 200;
			};			
		};
					
		class ModuleDescription: ModuleDescription
		{
			description = "Thermal lift effect"; // Short description, will be formatted as structured text
	 		position = 1; // Position is taken into effect
			direction = 0; // Direction is taken into effect
		};
	};	
	class FLAY_ModuleRidgeLift: Module_F
	{
		scope = 2;
		displayName = "Ridge Lift";
		category = "FLAY";
		author = "pumpkin";
		function = "FLAY_fnc_moduleRidgeLift";
		isGlobal = 0;
		isPersistent = 0;
		isTriggerActivated = 0;
		class Arguments: ArgumentsBaseUnits
		{
			class Units: Units{};
			class Debug
  			{
				displayName = "Debug";
				description = "Enable debugging"; 
				typeName = "BOOL";
				class values
				{
					class Yes
					{
						name = "$STR_lib_info_yes";
						value = 1;
						default = 0;
					};
					class No
					{
						name = "$STR_lib_info_no";
						value = 0;
						default = 1;
					};
				};
			};
			class WindDirection
  			{
				displayName = "Wind direction";
				description = "Wind direction in degrees (-1 = windDir)"; 
				typeName = "NUMBER";
				defaultValue = -1;
			};
			class WindEffect
			{
				displayName = "Wind effect";
				description = "Force of the wind effect"; 
				typeName = "NUMBER";
				defaultValue = 400 / 90;
			};
			class GradientEffect
			{
				displayName = "Gradient effect";
				description = "approximate angle of the faces producing maximum effect of wind."; 
				typeName = "NUMBER";
				defaultValue = 40;
			};
			class NumberOfFaces
			{
				displayName = "Number of faces";
				description = "Number of faces sampled for each strength coeff calculated"; 
				typeName = "NUMBER";
				defaultValue = 30;
			};
			class Sleep 
			{
				displayName = "Sleep";
				description = "Number of seconds to sleep between each iteration"; 
				typeName = "NUMBER";
				defaultValue = 0.1;			
			};
		};
		class ModuleDescription: ModuleDescription
		{
			description = "Ridge lift effect";
	 	 	position = 0; // Position is taken into effect
			direction = 1; // Direction is taken into effect
		};
	};
};

