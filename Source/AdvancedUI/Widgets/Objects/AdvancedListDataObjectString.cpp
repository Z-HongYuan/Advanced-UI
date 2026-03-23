// Copyright © 2026 鸿源z. All Rights Reserved.


#include "AdvancedListDataObjectString.h"

#include "AdvancedUI/Data/AdvancedUIType.h"

void UAdvancedListDataObjectString::OnDataObjectInited()
{
	if (!OptionStringArray.IsEmpty() && !OptionTextArray.IsEmpty())
	{
		CurrentStringValue = OptionStringArray[0];
		if (!GetTextFromStringArray(CurrentStringValue, CurrentDisplayText))
			CurrentDisplayText = OptionTextArray[0];
	}
}

bool UAdvancedListDataObjectString::GetTextFromStringArray(const FString& InString, FText& OutText) const
{
	if (OptionStringArray.IsEmpty())
		return false;

	int32 Index = OptionStringArray.IndexOfByKey<FString>(InString);

	if (OptionTextArray.IsValidIndex(Index))
		OutText = OptionTextArray[Index];

	// OutText = OptionTextArray[OptionStringArray.IndexOfByKey<FString>(InString)];
	return true;
}

void UAdvancedListDataObjectString::SelectThePreviousOption()
{
	if (OptionStringArray.IsEmpty() || OptionTextArray.IsEmpty()) return;

	const int32 CurrentIndex = OptionStringArray.IndexOfByKey<FString>(CurrentStringValue);
	int32 NextIndex = CurrentIndex - 1;

	//设置索引
	OptionStringArray.IsValidIndex(NextIndex) ? CurrentStringValue = OptionStringArray[NextIndex] : CurrentStringValue = OptionStringArray.Last();
	GetTextFromStringArray(CurrentStringValue, CurrentDisplayText);

	NotifyDataObjectChange(this, EOptionDataChangeReason::PlayerModification);
}

void UAdvancedListDataObjectString::SelectTheNextOption()
{
	if (OptionStringArray.IsEmpty() || OptionTextArray.IsEmpty()) return;

	const int32 CurrentIndex = OptionStringArray.IndexOfByKey<FString>(CurrentStringValue);
	int32 NextIndex = CurrentIndex + 1;

	//设置索引
	OptionStringArray.IsValidIndex(NextIndex) ? CurrentStringValue = OptionStringArray[NextIndex] : CurrentStringValue = OptionStringArray[0];
	GetTextFromStringArray(CurrentStringValue, CurrentDisplayText);

	NotifyDataObjectChange(this, EOptionDataChangeReason::PlayerModification);
}
