// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UEPythonCatalog : ModuleRules
{
	public UEPythonCatalog(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
