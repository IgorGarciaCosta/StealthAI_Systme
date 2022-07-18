// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class StealthAI_Systme : ModuleRules
{
	public StealthAI_Systme(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "GameplayTasks" });
	}
}
