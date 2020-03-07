#pragma once

#include "CoreMinimal.h"
#include "ConnectionDrawingPolicy.h"


static const FLinearColor DefaultWirtingColor(1.0f, 0.f, 0.f);
class FMyConnectionDrawingPolicy :public FConnectionDrawingPolicy
{
public:
	//************************************
	// Method:    FMyConnectionDrawingPolicy
	// FullName:  FMyConnectionDrawingPolicy::FMyConnectionDrawingPolicy
	// Access:    private 
	// Returns:   
	// Qualifier:
	// Parameter: int32 InBackLayerID ���ߵ�id
	// Parameter: int32 InFrontLayerID ��ͷ��id
	// Parameter: float InZoomFactor ��ͼzoom
	// Parameter: const FSlateRect & InClippingRect �ӿ�
	// Parameter: class FSlateWindowElementList & InDrawElements ���Ƶ�Ԫ��
	// Parameter: class UEdGraph * InGraphObj
	//************************************

	FMyConnectionDrawingPolicy(int32 InBackLayerID, 
		int32 InFrontLayerID, 
		float InZoomFactor, 
		const FSlateRect& InClippingRect,
		class FSlateWindowElementList& InDrawElements,
		 class UEdGraph* InGraphObj);


	virtual void DrawConnection(int32 LayerId, const FVector2D& Start, const FVector2D& End, const FConnectionParams& Params) override;

protected:
	UEdGraph* EdGraphobj;
	TMap<UEdGraphNode*, int32> EdNodeWidgetMap;

public:
	virtual void DetermineWiringStyle(UEdGraphPin* OutputPin, UEdGraphPin* InputPin, FConnectionParams& Params) override;


};
