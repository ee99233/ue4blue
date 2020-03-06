#include "K2NodeSimple.h"
#include "BlueprintActionDatabaseRegistrar.h"
#include "Internationalization/Text.h"
#include "EdGraphSchema_K2.h"
#include "Graph/K2NodeBPF.h"
#include "K2Node_CallFunction.h"
#include "EdGraph/EdGraphNode.h"
#include "K2Node.h"

FText UK2NodeSimple::GetTooltipText() const
{
	return FText::FromString(TEXT("SimpleNode"));
}

FText UK2NodeSimple::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return FText::FromString(TEXT("simplenodetitle"));
}

FText UK2NodeSimple::GetMenuCategory() const
{
	return FText::FromString(TEXT("Simplenode"));
	
}

void UK2NodeSimple::GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const
{
	UClass* Actionkey = GetClass();
	if (ActionRegistrar.IsOpenForRegistration(Actionkey))
	{
		UBlueprintNodeSpawner* ubspawner = UBlueprintNodeSpawner::Create(Actionkey);
		ActionRegistrar.AddBlueprintAction(Actionkey, ubspawner);
	}
}

void UK2NodeSimple::AllocateDefaultPins()
{
	CreatePin(EGPD_Input,UEdGraphSchema_K2::PC_Exec,UEdGraphSchema_K2::PN_Execute);
	CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Exec, UEdGraphSchema_K2::PN_Then);
	CreatePin(EGPD_Input, UEdGraphSchema_K2::PC_Object, "anyobject")->PinType.PinSubCategoryObject=UObject::StaticClass();
	CreatePin(EGPD_Output, UEdGraphSchema_K2::PC_Boolean,"ReturnValue");
}

 void UK2NodeSimple::ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph)
{
	Super::ExpandNode(CompilerContext, SourceGraph);

	UK2Node_CallFunction* simplefun = CompilerContext.SpawnIntermediateNode<UK2Node_CallFunction>(this, SourceGraph);
	simplefun->SetFromFunction(UK2NodeBPF::StaticClass()->FindFunctionByName(GET_MEMBER_NAME_CHECKED(UK2NodeBPF, TestA)));
	simplefun->AllocateDefaultPins();
	CompilerContext.MessageLog.NotifyIntermediateObjectCreation(simplefun, this);
	CompilerContext.MovePinLinksToIntermediate(*GetExecPin(), *simplefun->GetExecPin());
	CompilerContext.MovePinLinksToIntermediate(*GetfunPins(UEdGraphSchema_K2::PN_Then), *GetfunOtherPins(UEdGraphSchema_K2::PN_Then, simplefun));
	CompilerContext.MovePinLinksToIntermediate(*GetfunPins("anyobject"), *GetfunOtherPins("anyobject",simplefun));
	CompilerContext.MovePinLinksToIntermediate(*GetfunPins("ReturnValue"), *GetfunOtherPins("ReturnValue",simplefun));

	
	
}

 UEdGraphPin* UK2NodeSimple::GetfunPins(FName name)
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

 UEdGraphPin* UK2NodeSimple::GetfunOtherPins(FName name, UK2Node* node)
 {

	 for (int i = 0; i <node->Pins.Num(); i++)
	 {
		 if (node->Pins[i]->GetFName().IsEqual(name))
		 {
			 return node->Pins[i];
		 }
	 }
	 return nullptr;

 }
