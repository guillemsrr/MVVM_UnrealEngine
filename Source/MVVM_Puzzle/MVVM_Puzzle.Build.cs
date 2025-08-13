// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MVVM_Puzzle : ModuleRules
{
	public MVVM_Puzzle(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
