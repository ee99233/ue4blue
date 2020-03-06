#include "..\Public\TestNode_helloworld.h"

FText UTest_Node_Helloworld::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return FText::FromString("hello world");
}

void UTest_Node_Helloworld::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, "HelloNodeInput", FName(), TEXT("In"));
	CreatePin(EGPD_Output, "HelloNodeOutpunt", FName(), TEXT("Out"));
	CreatePin(EGPD_MAX, "hellownodemax", FName(), TEXT("Max"));
}
