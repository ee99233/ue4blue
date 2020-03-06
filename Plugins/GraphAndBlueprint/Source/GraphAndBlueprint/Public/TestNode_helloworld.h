#pragma once
#include "CoreMinimal.h"
#include "GraphEditor.h"
#include "EdGraph/EdGraphNode.h"
#include "TestNode_helloworld.generated.h"

UCLASS()
class UTest_Node_Helloworld :public UEdGraphNode
{
	GENERATED_BODY()
public:
	UTest_Node_Helloworld() {};

	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;

	virtual void AllocateDefaultPins() override;
};