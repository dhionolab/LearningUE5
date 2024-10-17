// Copyright dh

using UnrealBuildTool;
using System.Collections.Generic;

public class rpgdemoTarget : TargetRules
{
	public rpgdemoTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "rpgdemo" } );
	}
}
