// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CombatFlow : ModuleRules
{
	public CombatFlow(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput",
			"GameplayTags",
			"GameplayTasks"
		});
	}
}
