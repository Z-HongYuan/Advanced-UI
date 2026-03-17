// Copyright © 2026 鸿源z. All Rights Reserved.


#include "AdvancedUIManager.h"

#include "AdvancedUI/Widgets/AdvancedActivatableWidget.h"
#include "AdvancedUI/Widgets/AdvancedPrimaryLayoutWidget.h"
#include "Engine/AssetManager.h"
#include "Widgets/CommonActivatableWidgetContainer.h"


bool UAdvancedUIManager::ShouldCreateSubsystem(UObject* Outer) const
{
	//避免了专用服务器
	return !IsRunningDedicatedServer();
}

void UAdvancedUIManager::RegisterPrimaryLayoutWidget(UAdvancedPrimaryLayoutWidget* InWidget)
{
	if (!InWidget) return;
	PrimaryLayoutWidget = InWidget;
}

UAdvancedPrimaryLayoutWidget* UAdvancedUIManager::GetPrimaryLayoutWidget() const
{
	if (PrimaryLayoutWidget.IsValid()) return PrimaryLayoutWidget.Get();
	return nullptr;
}

void UAdvancedUIManager::PushSoftWidgetToStackAsync(const FGameplayTag& InStackTag, TSoftClassPtr<UAdvancedActivatableWidget> InWidgetClass,
                                                    TFunction<void(EAsyncState, UAdvancedActivatableWidget*)> InPushStateCallback) const
{
	if (!InWidgetClass) return;

	/*加载软路径引用*/
	UAssetManager::Get().GetStreamableManager().RequestAsyncLoad(
		InWidgetClass.ToSoftObjectPath(),

		/*资源加载完成后调用Lambda*/
		FStreamableDelegate::CreateLambda([InWidgetClass,this,InStackTag, /*传递到下一层*/InPushStateCallback]()-> void
			{
				if (!InWidgetClass) return;

				/*添加控件到栈内*/
				UAdvancedActivatableWidget* WidgetInstance = PrimaryLayoutWidget->GetWidgetStackByTag(InStackTag)->AddWidget<UAdvancedActivatableWidget>(
					InWidgetClass.Get(),

					/*添加完成后调用传递的状态回调函数*/
					[InPushStateCallback](UAdvancedActivatableWidget& Widget)-> void
					{
						InPushStateCallback(EAsyncState::OnCreate, &Widget);
					});

				/*Lambda执行完成后,调用一次推送完成状态回调函数*/
				InPushStateCallback(EAsyncState::OnPushed, WidgetInstance);
			}
		)
	);
}
