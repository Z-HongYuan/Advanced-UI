// Copyright © 2026 鸿源z. All Rights Reserved.


#include "AdvancedButtonBase.h"

#include "CommonTextBlock.h"
#include "AdvancedUI/Subsystem/AdvancedUIManager.h"

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

void UAdvancedButtonBase::NativeOnCurrentTextStyleChanged()
{
	Super::NativeOnCurrentTextStyleChanged();

	if (CommonTextBlock_ButtonText && GetCurrentTextStyleClass())
		CommonTextBlock_ButtonText->SetStyle(GetCurrentTextStyleClass());
}

void UAdvancedButtonBase::NativeOnHovered()
{
	Super::NativeOnHovered();

	const UAdvancedUIManager* AdvancedUIManager = GetGameInstance()->GetSubsystem<UAdvancedUIManager>();
	if (AdvancedUIManager && !ButtonDescriptionText.IsEmpty())
	{
		AdvancedUIManager->OnDescriptionChanged.Broadcast(this, ButtonDescriptionText);
	}
}

void UAdvancedButtonBase::NativeOnUnhovered()
{
	Super::NativeOnUnhovered();

	if (const UAdvancedUIManager* AdvancedUIManager = GetGameInstance()->GetSubsystem<UAdvancedUIManager>())
	{
		AdvancedUIManager->OnDescriptionChanged.Broadcast(this, FText::GetEmpty());
	}
}
