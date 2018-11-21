// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class OverFluff : ModuleRules
{
	public OverFluff(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule", "OnlineSubsystem", "OnlineSubsystemUtils" });

        /** Custom Online Settings */
        DynamicallyLoadedModuleNames.Add("OnlineSubsystemNull");
    }
}
