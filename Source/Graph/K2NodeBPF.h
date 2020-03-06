// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "K2NodeBPF.generated.h"


UCLASS()
class GRAPH_API UK2NodeBPF:public UBlueprintFunctionLibrary
{
  GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable)
		static bool TestA(UObject* anyobject);
};