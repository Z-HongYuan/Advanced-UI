// Copyright © 2026 鸿源z. All Rights Reserved.


#include "AdvancedRotator.h"

#include "CommonTextBlock.h"

void UAdvancedRotator::SetSelectedItemByFText(const FText& InTextOption)
{
	const int32 Index = TextLabels.IndexOfByPredicate(
		[InTextOption](const FText& TextItem)
		{
			return TextItem.EqualTo(InTextOption);
		});

	if (Index != INDEX_NONE)
	{
		SetSelectedItem(Index);
	}
	else
	{
		MyText->SetText(InTextOption);
	}
}
