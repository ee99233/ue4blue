#include "SMyGraphNode.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/SOverlay.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Layout/SBorder.h"


void SMyGraphhellowNode::Construct(const FArguments &arg, UTest_Node_Helloworld *hellownode)
{
	GraphNode = hellownode;
	this->SetCursor(EMouseCursor::Hand);
	this->UpdateGraphNode();
}

void SMyGraphhellowNode::UpdateGraphNode()
{
	//throw std::logic_error("The method or operation is not implemented.");
	InputPins.Empty();
	OutputPins.Empty();
	
	RightNodeBox.Reset();
	LeftNodeBox.Reset();
	this->GetOrAddSlot(ENodeZone::Center)
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[

			SAssignNew(box,SBox)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SBorder)
.BorderBackgroundColor_Lambda([&]())
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(SOverlay)

					+ SOverlay::Slot()
					[
						SNew(SHorizontalBox)

						+ SHorizontalBox::Slot()
						.HAlign(HAlign_Left)
						.VAlign(VAlign_Fill)
						.FillWidth(1.0f)
						[
							SAssignNew(LeftNodeBox,SVerticalBox)
						]
						
					+ SHorizontalBox::Slot()
						.HAlign(HAlign_Right)
						.VAlign(VAlign_Fill)
						.FillWidth(1.0f)
						[
							SAssignNew(RightNodeBox,SVerticalBox)
						]

					]
					
				]
			]


		];
	box->SetWidthOverride(300.f);
	box->SetHeightOverride(300.f);
	
}

void SMyGraphhellowNode::CreatePinWidgets()
{
	//throw std::logic_error("The method or operation is not implemented.");
}

