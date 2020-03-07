#include "k2NodeComplex.h"
#include "BlueprintActionDatabaseRegistrar.h"
#include "Internationalization/Text.h"
#include "EdGraphSchema_K2.h"
#include "Graph/K2NodeBPF.h"
#include "K2Node_CallFunction.h"
#include "EdGraph/EdGraphNode.h"
#include "K2Node.h"
#include "K2Node_IfThenElse.h"
#include "K2Node_ExecutionSequence.h"

FText UK2NodeComplex::GetTooltipText() const
{
	return FText::FromString(TEXT("ComplexNode"));
}

FText UK2NodeComplex::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return FText::FromString(TEXT("ComplexNodetitle"));
}

FText UK2NodeComplex::GetMenuCategory() const
{
	return FText::FromString(TEXT("ComplexNode"));

}

void UK2NodeComplex::GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const
{
	UClass* Actionkey = GetClass();
	if (ActionRegistrar.IsOpenForRegistration(Actionkey))
	{
		UBlueprintNodeSpawner* ubspawner = UBlueprintNodeSpawner::Create(Actionkey);
		ActionRegistrar.AddBlueprintAction(Actionkey, ubspawner);
	}
}

void UK2NodeComplex::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Exec,UEdGraphSchema_K2::PN_Execute);
	CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Boolean,FName("Condtional"));
	CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Boolean, FName("Other"));
	CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, FName("DO1"));
	CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, FName("DO2"));


}

void UK2NodeComplex::ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
	Super::ExpandNode(CompilerContext, SourceGraph);
	
	UK2Node_IfThenElse* ifelse = CompilerContext.SpawnIntermediateNode<UK2Node_IfThenElse>(this, SourceGraph);
	ifelse->AllocateDefaultPins();
	CompilerContext.MessageLog.NotifyIntermediateObjectCreation(ifelse, this);
	CompilerContext.MovePinLinksToIntermediate(*GetExecPin(), *ifelse->GetExecPin());
	CompilerContext.MovePinLinksToIntermediate(*GetfunPins("Condtional"), *GetfunOtherPins("Condition", ifelse));

	
	UK2Node_ExecutionSequence* sequece1 = CompilerContext.SpawnIntermediateNode<UK2Node_ExecutionSequence>(this, SourceGraph);
	sequece1->AllocateDefaultPins();
	CompilerContext.MessageLog.NotifyIntermediateObjectCreation(sequece1, this);
	ifelse->GetThenPin()->MakeLinkTo(sequece1->GetExecPin());

	UK2Node_ExecutionSequence* sequece2 = CompilerContext.SpawnIntermediateNode<UK2Node_ExecutionSequence>(this, SourceGraph);
	sequece1->AllocateDefaultPins();
	CompilerContext.MessageLog.NotifyIntermediateObjectCreation(sequece2, this);
	ifelse->GetElsePin()->MakeLinkTo(sequece2->GetExecPin());


	






}

UEdGraphPin* UK2NodeComplex::GetfunPins(FName name)
{

	for (int i = 0; i < Pins.Num(); i++)
	{
		if (Pins[i]->GetFName().IsEqual(name))
		{
			return Pins[i];
		}
	}
	return nullptr;
}

UEdGraphPin* UK2NodeComplex::GetfunOtherPins(FName name, UK2Node* node)
{

	for (int i = 0; i < node->Pins.Num(); i++)
	{
		if (node->Pins[i]->GetFName().IsEqual(name))
		{
			return node->Pins[i];
		}
	}
	return nullptr;

}
