#pragma once
#include "CoreMinimal.h"
#include "EdGraphUtilities.h"


class GRAPHANDBLUEPRINT_API FMyGraphPanelNodeFactory :public FGraphPanelNodeFactory
{

public:
	FMyGraphPanelNodeFactory();


	virtual TSharedPtr<class SGraphNode> CreateNode(class UEdGraphNode* Node) const override;

};