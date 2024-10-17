// Copyright dh

using UnrealBuildTool;
using System.Collections.Generic;

public class rpgdemoEditorTarget : TargetRules
{
	public rpgdemoEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;

		ExtraModuleNames.AddRange( new string[] { "rpgdemo" } );
	}
}
