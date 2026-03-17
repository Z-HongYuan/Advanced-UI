// Copyright © 2026 鸿源z. All Rights Reserved.


#include "AdvancedButtonBase.h"

#include "CommonTextBlock.h"

void UAdvancedButtonBase::SetButtonText(const FText& InText)
{
	if (CommonTextBlock_ButtonText && !InText.IsEmpty())
		CommonTextBlock_ButtonText->SetText(bIsUpperButtonText ? InText.ToUpper() : InText);
}

void UAdvancedButtonBase::NativePreConstruct()
{
	Super::NativePreConstruct(); 

	SetButtonText(ButtonDisplayText);
}
