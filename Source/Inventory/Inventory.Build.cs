using UnrealBuildTool;

public class Inventory : ModuleRules
{
    public Inventory(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new string[] {"Inventory/Public",
                                                  "Inventory/Public/GUI",
                                                  "Inventory/Public/Item"});

        PrivateIncludePaths.AddRange(new string[] {"Inventory/Private",
                                                   "Inventory/Private/GUI",
                                                   "Inventory/Private/Item"});

        PublicDependencyModuleNames.AddRange(new string[] {"Core", "InputCore"});

        PrivateDependencyModuleNames.AddRange(new string[] { "CoreUObject",	"Engine",	"Slate", "SlateCore", "RPGModuleBase" });

        DynamicallyLoadedModuleNames.AddRange(new string[] {});
    }
}
