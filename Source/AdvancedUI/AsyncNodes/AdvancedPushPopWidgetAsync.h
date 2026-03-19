// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AdvancedUI/Data/AdvancedUIType.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AdvancedPushPopWidgetAsync.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPushPopWidgetOverDelegate, EConfirmPopButtonType, ButtonResult);

/**
 * 专门用于推送弹窗Pop的异步节点
 */
UCLASS()
class ADVANCEDUI_API UAdvancedPushPopWidgetAsync : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/*
	 * 静态函数,用于创建这个Node并且设置需要的初始值
	 */
	UFUNCTION(BlueprintCallable,
		meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", HidePin = "WorldContextObject", DisplayName = "Push Pop Widget To Stack Async"))
	static UAdvancedPushPopWidgetAsync* PushPopWidgetToStackAsync(
		UObject* WorldContextObject,
		EConfirmPopType InPopType,
		FText InPopTitle,
		FText InPopContent
	);

	/*激活函数*/
	virtual void Activate() override;

	UPROPERTY(BlueprintAssignable)
	FOnPushPopWidgetOverDelegate OnButtonClickResult;

private:
	EConfirmPopType CachePopType;
	FText CachePopTitle;
	FText CachePopContent;
};
