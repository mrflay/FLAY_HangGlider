class CfgPatches
{
	class FLAY_Variometer
	{
		units[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {};
	};
};

class cfgWeapons
{
    class Default;
	class ItemCore;
	class FLAY_Variometer: ItemCore
	{
		scope=2;
		displayName="Variometer";
		picture="\FLAY\FLAY_HangGlider\variometer\items\item_vario.paa";
		descriptionShort="Visual and acoustic vario display with adjustable sink alarm tone.";
		class ItemInfo
		{
			mass = 1;
		};		
	};	
};
