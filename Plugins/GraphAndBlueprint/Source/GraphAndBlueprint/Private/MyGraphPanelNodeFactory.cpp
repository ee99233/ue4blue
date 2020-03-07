#include "MyGraphPanelNodeFactory.h"
#include "TestNode_helloworld.h"
#include "SMyGraphNode.h"


FMyGraphPanelNodeFactory::FMyGraphPanelNodeFactory()
{

}

TSharedPtr<class SGraphNode> FMyGraphPanelNodeFactory::CreateNode(class UEdGraphNode* Node) const
{
	if (UTest_Node_Helloworld* makenode = Cast<UTest_Node_Helloworld>(Node))
	{ 
		return SNew(SMyGraphhellowNode, makenode);
	}
	return NULL;
}
