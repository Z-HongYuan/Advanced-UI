// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "AdvancedPrimaryLayoutWidget.generated.h"

class UCommonActivatableWidgetContainerBase;

/**
 * 主要的布局Widget
 */
UCLASS(Abstract)
class ADVANCEDUI_API UAdvancedPrimaryLayoutWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AdvancedPrimaryLayoutWidget")
	void RegisterWidgetStack(
		UPARAM(meta = (Categories = "AdvancedTagUI"))const FGameplayTag InTag,
		UCommonActivatableWidgetContainerBase* InWidgetStack);

	UFUNCTION(BlueprintCallable, Category = "AdvancedPrimaryLayoutWidget")
	UCommonActivatableWidgetContainerBase* GetWidgetStackByTag(const FGameplayTag& InTag) const;

protected:
	//初始化的时候就注册所有栈
	virtual void NativeOnInitialized() override;

private:
	UPROPERTY(Transient)
	TMap<FGameplayTag, UCommonActivatableWidgetContainerBase*> WidgetStacks;

	/*
	 * 教程中是使用蓝图绑定的,但是这里使用C++进行绑定,因为这个大概率是不会改变的
	 */
	UPROPERTY(Transient, meta=(BindWidget))
	UCommonActivatableWidgetContainerBase* Stack_Modal;
	UPROPERTY(Transient, meta=(BindWidget))
	UCommonActivatableWidgetContainerBase* Stack_GameMenu;
	UPROPERTY(Transient, meta=(BindWidget))
	UCommonActivatableWidgetContainerBase* Stack_GameHUD;
	UPROPERTY(Transient, meta=(BindWidget))
	UCommonActivatableWidgetContainerBase* Stack_Frontend;
};
