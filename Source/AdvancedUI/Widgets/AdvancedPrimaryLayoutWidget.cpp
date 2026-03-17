// Copyright © 2026 鸿源z. All Rights Reserved.


#include "AdvancedPrimaryLayoutWidget.h"

#include "AdvancedUI/Data/AdvancedGameplayTags.h"
#include "AdvancedUI/Subsystem/AdvancedUIManager.h"

void UAdvancedPrimaryLayoutWidget::RegisterWidgetStack(const FGameplayTag InTag, UCommonActivatableWidgetContainerBase* InWidgetStack)
{
	if (IsDesignTime()) return;
	if (WidgetStacks.Contains(InTag)) return;
	if (!InWidgetStack) return;

	WidgetStacks.Add(InTag, InWidgetStack);
}

UCommonActivatableWidgetContainerBase* UAdvancedPrimaryLayoutWidget::GetWidgetStackByTag(const FGameplayTag& InTag) const
{
	if (!WidgetStacks.Contains(InTag)) return nullptr;

	return WidgetStacks.FindRef(InTag);
}

void UAdvancedPrimaryLayoutWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	RegisterWidgetStack(AdvancedGameplayTags::AdvancedTagUI_WidgetStack_Modal, Stack_Modal);
	RegisterWidgetStack(AdvancedGameplayTags::AdvancedTagUI_WidgetStack_GameMenu, Stack_GameMenu);
	RegisterWidgetStack(AdvancedGameplayTags::AdvancedTagUI_WidgetStack_GameHUD, Stack_GameHUD);
	RegisterWidgetStack(AdvancedGameplayTags::AdvancedTagUI_WidgetStack_Frontend, Stack_Frontend);

	//将自身注册到子系统中,子系统中也有方便函数接口
	GetWorld()->GetGameInstance()->GetSubsystem<UAdvancedUIManager>()->RegisterPrimaryLayoutWidget(this);
}
