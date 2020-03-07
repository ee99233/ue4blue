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
	// Parameter: int32 InBackLayerID 白线的id
	// Parameter: int32 InFrontLayerID 箭头的id
	// Parameter: float InZoomFactor 蓝图zoom
	// Parameter: const FSlateRect & InClippingRect 视口
	// Parameter: class FSlateWindowElementList & InDrawElements 绘制的元素
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
