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
	//************************************
	// Method:    FtestGraphScemaAction
	// FullName:  FtestGraphScemaAction::FtestGraphScemaAction
	// Access:    public 
	// Returns:   
	// Qualifier: :FEdGraphSchemaAction(InNodeCategory, InMenuDesc, InToolTip, InGrouping, InKeywords, InSectionID)
	// Parameter: FText InNodeCategory 节点种类
	// Parameter: FText InMenuDesc 节点菜单名字
	// Parameter: FText InToolTip 节点描述
	// Parameter: const int32 InGrouping
	// Parameter: FText InKeywords
	// Parameter: int32 InSectionID
	//************************************
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
	//连接两个节点
	virtual const FPinConnectionResponse CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const override;



private:
	virtual class FConnectionDrawingPolicy* CreateConnectionDrawingPolicy(int32 InBackLayerID, int32 InFrontLayerID, float InZoomFactor, const FSlateRect& InClippingRect, class FSlateWindowElementList& InDrawElements, class UEdGraph* InGraphObj) const override;

};