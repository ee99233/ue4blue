#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphSchema.h"
#include "TestGraphSchema.generated.h"


USTRUCT()
struct FtestGraphScemaAction :public FEdGraphSchemaAction
{
	GENERATED_BODY()
public:
	FtestGraphScemaAction() {};
	FtestGraphScemaAction(FText InNodeCategory, FText InMenuDesc, FText InToolTip, const int32 InGrouping, FText InKeywords = FText(), int32 InSectionID = 0)
		:FEdGraphSchemaAction(InNodeCategory, InMenuDesc, InToolTip, InGrouping, InKeywords, InSectionID)
	{}

	virtual UEdGraphNode* PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode = true);

	class UTest_Node_Helloworld* Testnode;
};

UCLASS(MinimalAPI)
class UMyGraphSchena :public UEdGraphSchema
{
	GENERATED_BODY()

public:
	virtual void GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const override;
};