#include "TestGraphSchema.h"
#include "TestNode_helloworld.h"
#include "EdGraph\EdGraph.h"
#include "ScopedTransaction.h"
#include "EdGraph/EdGraphNode.h"
#include "MyConnectionDrawingPolicy.h"
#define LOCTEXT_NAMESPACE "TestGraphScenma"

void UMyGraphSchena::GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const
{

	TSharedPtr<FtestGraphScemaAction> NewNodeAction(
		new FtestGraphScemaAction(LOCTEXT("A", "Grap Node"),
			LOCTEXT("Desc", "MytestAA"),
			LOCTEXT("NewGraphText", "Add a Node"),
			0));

	NewNodeAction->Testnode = NewObject<UTest_Node_Helloworld>(ContextMenuBuilder.OwnerOfTemporaries);
	ContextMenuBuilder.AddAction(NewNodeAction);

}


const FPinConnectionResponse UMyGraphSchena::CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const
{
	
	return FPinConnectionResponse(CONNECT_RESPONSE_BREAK_OTHERS_A, TEXT("Not implemented by this schema"));
}

class FConnectionDrawingPolicy* UMyGraphSchena::CreateConnectionDrawingPolicy(int32 InBackLayerID, int32 InFrontLayerID, float InZoomFactor, const FSlateRect& InClippingRect, class FSlateWindowElementList& InDrawElements, class UEdGraph* InGraphObj) const
{
	return  new  FMyConnectionDrawingPolicy(InBackLayerID, InFrontLayerID, InZoomFactor, InClippingRect, InDrawElements, InGraphObj);
}

UEdGraphNode * FtestGraphScemaAction::PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode)
{
	UEdGraphNode* UedresultNode = nullptr;
	if (Testnode != nullptr)
	{
		const FScopedTransaction Translation(LOCTEXT("FF", "Hell:NewNode"));

		ParentGraph->Modify();
		if (FromPin != nullptr)
		{
			FromPin->Modify();
		}

		Testnode->Rename(nullptr, ParentGraph);
		ParentGraph->AddNode(Testnode, true, bSelectNewNode);
		Testnode->CreateNewGuid();
		Testnode->PostPlacedNewNode();
		Testnode->AllocateDefaultPins();
		Testnode->AutowireNewNode(FromPin);

		Testnode->NodePosX = Location.X;
		Testnode->NodePosY = Location.Y;

		Testnode->SetFlags(RF_Transactional);

		UedresultNode = Testnode;
	}

	return UedresultNode;
}


#undef LOCTEXT_NAMESAPCE