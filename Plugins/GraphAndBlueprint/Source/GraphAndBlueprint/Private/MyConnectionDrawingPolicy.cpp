#include "MyConnectionDrawingPolicy.h"
#include "Rendering/DrawElements.h"

FMyConnectionDrawingPolicy::FMyConnectionDrawingPolicy(int32 InBackLayerID, int32 InFrontLayerID, float InZoomFactor, const FSlateRect& InClippingRect, class FSlateWindowElementList& InDrawElements, class UEdGraph* InGraphObj)
	:FConnectionDrawingPolicy(InBackLayerID, InFrontLayerID, InZoomFactor, InClippingRect, InDrawElements),
	EdGraphobj(InGraphObj)
{

}

void FMyConnectionDrawingPolicy::DrawConnection(int32 LayerId, const FVector2D& Start, const FVector2D& End, const FConnectionParams& Params)
{
   const FVector2D line = End - Start;
   const FVector2D safenorml = line.GetSafeNormal();

   FSlateDrawElement::MakeDrawSpaceSpline(
	   DrawElementsList,
	   LayerId,
	   Start, safenorml,
	   End, safenorml,
	   Params.WireThickness
   );


}

void FMyConnectionDrawingPolicy::DetermineWiringStyle(UEdGraphPin* OutputPin, UEdGraphPin* InputPin, FConnectionParams& Params)
{
	Params.WireThickness = 5.5f;
	Params.WireColor = DefaultWirtingColor;
	if (HoveredPins.Num() > 0)
	{
		ApplyHoverDeemphasis(OutputPin, InputPin, Params.WireThickness, Params.WireColor);
	}
}

