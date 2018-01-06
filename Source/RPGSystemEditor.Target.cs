// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class RPGSystemEditorTarget : TargetRules
{
	public RPGSystemEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.AddRange(new string[]{"RPGSystem", "Inventory", "RPGModuleBase"});
	}
}
