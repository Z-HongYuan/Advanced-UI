// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AdvancedUIManager.generated.h"

enum class EConfirmPopButtonType : uint8;
enum class EConfirmPopType : uint8;
class UAdvancedActivatableWidget;
class UAdvancedPrimaryLayoutWidget;
struct FGameplayTag;

/*
 * 这个是添加Widget的异步状态枚举
 */
UENUM(BlueprintType)
enum class EAsyncState : uint8
{
	OnCreate, //创建成功后,可能需要初始化Widget时机
	OnPushed //添加成功后
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDescriptionChanged, UAdvancedButtonBase*, InButton, FText, NewDescription);

/**
 * 用于方便使用UI的子系统
 */
UCLASS()
class ADVANCEDUI_API UAdvancedUIManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	//避免专用服务器创建
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;

	void RegisterPrimaryLayoutWidget(UAdvancedPrimaryLayoutWidget* InWidget);
	UAdvancedPrimaryLayoutWidget* GetPrimaryLayoutWidget() const;

	/*
	 * 调用这个函数的时候,将会传递一个回调函数,回调函数将会被多次调用,其区分标志是推送状态
	 */
	void PushSoftWidgetToStackAsync(const FGameplayTag& InStackTag,
	                                TSoftClassPtr<UAdvancedActivatableWidget> InWidgetClass,
	                                TFunction<void(EAsyncState, UAdvancedActivatableWidget*)> InPushStateCallback) const;

	/*
	 * 添加异步推送Pop的函数,此函数用于在C++中推送弹窗
	 */
	void PushPopWidgetToStackAsync(EConfirmPopType InPopType,
	                               const FText& InPopTitle,
	                               const FText& InPopContent,
	                               TFunction<void(EConfirmPopButtonType)> InButtonClickCallback) const;

	UPROPERTY(BlueprintAssignable)
	FOnDescriptionChanged OnDescriptionChanged;

private:
	//在Widget中传入保存的引用
	UPROPERTY(Transient)
	TWeakObjectPtr<UAdvancedPrimaryLayoutWidget> PrimaryLayoutWidget;
};
