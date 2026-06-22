// DedicatedM.Build.cs

using UnrealBuildTool;

public class DedicatedM : ModuleRules
{
	public DedicatedM(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			// Initial Dependencies
			"Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput",

			// Inventory Plugin
			"InventoryPlugin",
		});

		PrivateDependencyModuleNames.AddRange(new string[] 
		{  
			// "DedicatedM",		// 내 프로젝트 경로, 헤더파일 경로 탐색용
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
