// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AdvancedUI/Widgets/AdvancedActivatableWidget.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AdvancedPushSoftWidgetAsync.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPushSoftWidgetDelegate, UAdvancedActivatableWidget*, PushedWidget);

/**
 * 专门用于蓝图中异步添加Widget的节点
 */
UCLASS()
class ADVANCEDUI_API UAdvancedPushSoftWidgetAsync : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/*
	 * 静态函数,用于创建这个Node并且设置需要的初始值
	 * 专门用于蓝图中异步添加Widget的节点
	 */
	UFUNCTION(BlueprintCallable,
		meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", HidePin = "WorldContextObject", DisplayName = "Push Soft Widget To Stack Async"))
	static UAdvancedPushSoftWidgetAsync* PushSoftWidgetToStackAsync(
		UObject* WorldContextObject,
		APlayerController* InPlayerController,
		UPARAM(meta = (GameplayTagFilter = "AdvancedTagUI"))FGameplayTag InStackTag,
		TSoftClassPtr<UAdvancedActivatableWidget> InWidgetClass,
		bool bFocusWidget = true
	);

	/*
	 * 这个是节点的实现逻辑,实际执行的逻辑
	 */
	/*~ Begin UBlueprintAsyncActionBase Interface*/
	virtual void Activate() override;
	/*~ End UBlueprintAsyncActionBase Interface*/

	/*
	 * 这里是节点触发的蓝图委托
	 */
	UPROPERTY(BlueprintAssignable)
	FOnPushSoftWidgetDelegate OnCreated;

	UPROPERTY(BlueprintAssignable)
	FOnPushSoftWidgetDelegate OnPushed;

private:
	TWeakObjectPtr<APlayerController> CachePlayerController;
	FGameplayTag CacheStackTag;
	TSoftClassPtr<UAdvancedActivatableWidget> CacheWidgetClass;
	bool bCacheFocusWidget;
};
