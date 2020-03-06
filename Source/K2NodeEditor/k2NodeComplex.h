#pragma once
#include "Engine.h"
#include "Graph/K2NodeBPF.h"
#include "K2Node.h"
#include "BlueprintFunctionNodeSpawner.h"
#include "EdGraph/EdGraph.h"
#include "KismetCompiler.h"
#include "k2NodeComplex.generated.h"


UCLASS()
class K2NODEEDITOR_API UK2NodeComplex :public UK2Node
{
	GENERATED_BODY()
public:
	virtual FText GetTooltipText() const override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetMenuCategory() const override;
	virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
	virtual void AllocateDefaultPins() override;
	virtual void ExpandNode(FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;

private:
	UEdGraphPin* GetfunPins(FName name);
	UEdGraphPin* GetfunOtherPins(FName name, UK2Node* node);

};
#pragma once
