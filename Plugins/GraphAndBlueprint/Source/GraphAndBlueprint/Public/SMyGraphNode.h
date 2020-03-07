#pragma once
#include "CoreMinimal.h"
#include "SGraphNode.h"
#include "TestNode_helloworld.h"


class SMyGraphhellowNode :public SGraphNode
{
public:
	SLATE_BEGIN_ARGS(SMyGraphhellowNode)
	{}

	SLATE_END_ARGS()

	void Construct(const FArguments &arg,UTest_Node_Helloworld *hellownode);
	


	virtual void UpdateGraphNode() override;
	virtual void CreatePinWidgets() override;
private:
	TSharedPtr<class SBox> box;
};