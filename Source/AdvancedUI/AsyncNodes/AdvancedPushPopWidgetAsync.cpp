// Copyright © 2026 鸿源z. All Rights Reserved.


#include "AdvancedPushPopWidgetAsync.h"

#include "AdvancedUI/Subsystem/AdvancedUIManager.h"

UAdvancedPushPopWidgetAsync* UAdvancedPushPopWidgetAsync::PushPopWidgetToStackAsync(UObject* WorldContextObject, EConfirmPopType InPopType, FText InPopTitle,
                                                                                    FText InPopContent)
{
	UAdvancedPushPopWidgetAsync* Node = NewObject<UAdvancedPushPopWidgetAsync>();
	if (!Node) return nullptr;

	Node->CachePopType = InPopType;
	Node->CachePopTitle = InPopTitle;
	Node->CachePopContent = InPopContent;

	Node->RegisterWithGameInstance(WorldContextObject);

	return Node;
}

void UAdvancedPushPopWidgetAsync::Activate()
{
	/*使用UIManager中的异步函数来推送Pop控件*/
	if (UAdvancedUIManager* UIManager = RegisteredWithGameInstance->GetSubsystem<UAdvancedUIManager>())
	{
		UIManager->PushPopWidgetToStackAsync(CachePopType, CachePopTitle, CachePopContent,
		                                     [this](EConfirmPopButtonType InButtonType)
		                                     {
			                                     OnButtonClickResult.Broadcast(InButtonType);
			                                     SetReadyToDestroy();
		                                     }
		);
	}
}
