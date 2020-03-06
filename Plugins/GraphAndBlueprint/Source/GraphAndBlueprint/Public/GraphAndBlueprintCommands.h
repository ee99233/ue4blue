// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "GraphAndBlueprintStyle.h"

class FGraphAndBlueprintCommands : public TCommands<FGraphAndBlueprintCommands>
{
public:

	FGraphAndBlueprintCommands()
		: TCommands<FGraphAndBlueprintCommands>(TEXT("GraphAndBlueprint"), NSLOCTEXT("Contexts", "GraphAndBlueprint", "GraphAndBlueprint Plugin"), NAME_None, FGraphAndBlueprintStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};