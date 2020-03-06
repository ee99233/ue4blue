#include "TestGraphSchema.h"
#include "TestNode_helloworld.h"
#include "EdGraph\EdGraph.h"
#include "ScopedTransaction.h"
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