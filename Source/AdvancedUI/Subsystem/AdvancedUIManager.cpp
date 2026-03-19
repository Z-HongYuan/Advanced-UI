// Copyright © 2026 鸿源z. All Rights Reserved.


#include "AdvancedUIManager.h"

#include "AdvancedUI/Data/AdvancedGameplayTags.h"
#include "AdvancedUI/Data/AdvancedUIType.h"
#include "AdvancedUI/FunctionLibrary/AdvancedFunctionLibrary.h"
#include "AdvancedUI/Widgets/AdvancedActivatableWidget.h"
#include "AdvancedUI/Widgets/AdvancedPrimaryLayoutWidget.h"
#include "AdvancedUI/Widgets/Items/AdvancedConfirmPopWidget.h"
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

	UE_LOG(LogTemp, Warning, TEXT("PrimaryLayoutWidget is not valid"));
	return nullptr;
}

void UAdvancedUIManager::PushSoftWidgetToStackAsync(const FGameplayTag& InStackTag, TSoftClassPtr<UAdvancedActivatableWidget> InWidgetClass,
                                                    TFunction<void(EAsyncState, UAdvancedActivatableWidget*)> InPushStateCallback) const
{
	//这个是错误的,如果软引用没有加载,这个将会一直为空,所以这里会一直返回
	//或者增强逻辑就使用IsPending判断是否已经加载,未加载才走异步Loading,已加载的话直接推送页面
	// if (!InWidgetClass) return;

	if (InWidgetClass.IsNull()) return;

	/*加载软路径引用*/
	UAssetManager::Get().GetStreamableManager().RequestAsyncLoad(
		InWidgetClass.ToSoftObjectPath(),

		/*资源加载完成后调用Lambda*/
		FStreamableDelegate::CreateLambda([InWidgetClass,this,InStackTag, /*传递到下一层*/InPushStateCallback]()-> void
			{
				if (!InWidgetClass) return;

				/*添加控件到栈内*/
				UAdvancedActivatableWidget* WidgetInstance = GetPrimaryLayoutWidget()->GetWidgetStackByTag(InStackTag)->AddWidget<UAdvancedActivatableWidget>(
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

void UAdvancedUIManager::PushPopWidgetToStackAsync(EConfirmPopType InPopType, const FText& InPopTitle, const FText& InPopContent,
                                                   TFunction<void(EConfirmPopButtonType)> InButtonClickCallback) const
{
	/*根据弹窗的类型,调用对应的弹窗信息构建函数*/
	UAdvancedConfirmPopInfoObject* PopInfoObject;
	switch (InPopType)
	{
	case EConfirmPopType::Ok:
		PopInfoObject = UAdvancedConfirmPopInfoObject::CreatePopInfoForOK(InPopTitle, InPopContent);
		break;
	case EConfirmPopType::YesNo:
		PopInfoObject = UAdvancedConfirmPopInfoObject::CreatePopInfoForYesNo(InPopTitle, InPopContent);
		break;
	case EConfirmPopType::OKCancel:
		PopInfoObject = UAdvancedConfirmPopInfoObject::CreatePopInfoForOKCancel(InPopTitle, InPopContent);
		break;
	case EConfirmPopType::None:
		break;
	}

	/*
	 * 开始推送控件,使用之前的异步推送函数,并且在构建完成后调用初始化函数
	 * 固定推送控件到Modal栈内
	 * 使用开发者设置中的Tag-控件映射来获取具体使用的控件
	 */
	PushSoftWidgetToStackAsync(
		AdvancedGameplayTags::AdvancedTagUI_WidgetStack_Modal,
		UAdvancedFunctionLibrary::GetWidgetClassByTag(AdvancedGameplayTags::AdvancedTagUI_Widget_Pop),
		/*当控件创建成功后,直接初始化控件,并且能够将当前函数传入的回调绑定在按钮上*/
		[PopInfoObject, InButtonClickCallback](const EAsyncState InState, UAdvancedActivatableWidget* InPushedWidget)
		{
			if (InState == EAsyncState::OnCreate)
			{
				if (UAdvancedConfirmPopWidget* PopWidget = Cast<UAdvancedConfirmPopWidget>(InPushedWidget))
				{
					/*将回调传递到Widget中处理,绑定在按钮的点击函数中*/
					PopWidget->InitConfirmPop(PopInfoObject, InButtonClickCallback);
				}
			}
		}
	);
}
