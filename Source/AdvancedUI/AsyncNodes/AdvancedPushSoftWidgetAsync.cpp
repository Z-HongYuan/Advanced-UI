// Copyright © 2026 鸿源z. All Rights Reserved.


#include "AdvancedPushSoftWidgetAsync.h"

#include "AdvancedUI/Subsystem/AdvancedUIManager.h"

UAdvancedPushSoftWidgetAsync* UAdvancedPushSoftWidgetAsync::PushSoftWidgetToStackAsync(UObject* WorldContextObject, APlayerController* InPlayerController, FGameplayTag InStackTag,
                                                                                       TSoftClassPtr<UAdvancedActivatableWidget> InWidgetClass, bool bFocusWidget)
{
	//如果Widget无效就返回空
	if (InWidgetClass.IsNull()) return nullptr;

	UAdvancedPushSoftWidgetAsync* Node = NewObject<UAdvancedPushSoftWidgetAsync>();
	Node->CachePlayerController = InPlayerController;
	Node->CacheStackTag = InStackTag;
	Node->CacheWidgetClass = InWidgetClass;
	Node->bCacheFocusWidget = bFocusWidget;

	//这里注册之后,父类的GI引用也会注册有效
	Node->RegisterWithGameInstance(WorldContextObject);

	return Node;
}

void UAdvancedPushSoftWidgetAsync::Activate()
{
	if (!RegisteredWithGameInstance.IsValid()) return;
	const UAdvancedUIManager* UISubsystem = RegisteredWithGameInstance->GetSubsystem<UAdvancedUIManager>();
	if (!UISubsystem) return;

	UISubsystem->PushSoftWidgetToStackAsync(CacheStackTag, CacheWidgetClass,
	                                        [this](const EAsyncState InPushState, UAdvancedActivatableWidget* InPushWidget)
	                                        {
		                                        switch (InPushState)
		                                        {
		                                        case EAsyncState::OnCreate:
			                                        InPushWidget->SetOwningPlayer(CachePlayerController.Get());
			                                        OnCreated.Broadcast(InPushWidget);
			                                        break;
		                                        case EAsyncState::OnPushed:
			                                        OnPushed.Broadcast(InPushWidget);
			                                        if (bCacheFocusWidget)
			                                        {
				                                        if (UWidget* FocusTarget = InPushWidget->GetDesiredFocusTarget())
					                                        FocusTarget->SetFocus();
			                                        }
			                                        SetReadyToDestroy();
			                                        break;
		                                        }
	                                        }
	);
}
