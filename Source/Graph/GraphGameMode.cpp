// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GraphGameMode.h"
#include "GraphCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGraphGameMode::AGraphGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
