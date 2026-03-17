// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AdvancedUIManager.generated.h"

class UAdvancedActivatableWidget;
class UAdvancedPrimaryLayoutWidget;
struct FGameplayTag;

UENUM(BlueprintType)
enum class EAsyncState : uint8
{
	OnCreate, //创建成功后,可能需要初始化Widget时机
	OnPushed //添加成功后
};

/**
 * 用于方便使用UI的子系统
 */
UCLASS()
class ADVANCEDUI_API UAdvancedUIManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

	void RegisterPrimaryLayoutWidget(UAdvancedPrimaryLayoutWidget* InWidget);
	UAdvancedPrimaryLayoutWidget* GetPrimaryLayoutWidget() const;

	/*
	 * 调用这个函数的时候,将会传递一个回调函数,回调函数将会被多次调用,其区分标志是推送状态
	 */
	void PushSoftWidgetToStackAsync(const FGameplayTag& InStackTag,
	                                TSoftClassPtr<UAdvancedActivatableWidget> InWidgetClass,
	                                TFunction<void(EAsyncState, UAdvancedActivatableWidget*)> InPushStateCallback) const;

private:
	UPROPERTY(Transient)
	TWeakObjectPtr<UAdvancedPrimaryLayoutWidget> PrimaryLayoutWidget;
};
