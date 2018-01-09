using UnrealBuildTool;

public class RPGModuleBase : ModuleRules
{
  public RPGModuleBase(ReadOnlyTargetRules Target) : base(Target)
  {
    PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

    PublicIncludePaths.AddRange(new string[] {"RPGModuleBase/Public", "RPGModuleBase/Public/GUI"});

    PrivateIncludePaths.AddRange(new string[] {"Inventory/Private", "RPGModuleBase/Private/GUI"});

    PublicDependencyModuleNames.AddRange(new string[] {"Core", "InputCore"});

    PrivateDependencyModuleNames.AddRange(new string[] { "CoreUObject",	"Engine",	"Slate", "SlateCore" });

    DynamicallyLoadedModuleNames.AddRange(new string[] {});
  }
}
