// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GraphAndBlueprintCommands.h"

#define LOCTEXT_NAMESPACE "FGraphAndBlueprintModule"

void FGraphAndBlueprintCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "GraphAndBlueprint", "Bring up GraphAndBlueprint window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
