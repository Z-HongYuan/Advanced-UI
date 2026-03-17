// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "AdvancedPrimaryLayoutWidget.generated.h"

class UCommonActivatableWidgetContainerBase;

/**
 * 主要的布局RootWidget
 */
UCLASS(Abstract)
class ADVANCEDUI_API UAdvancedPrimaryLayoutWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	/*
	 * 其实这两个函数也没啥必要公开给蓝图,因为大概率会使用异步Node来推送控件
	 */
	UFUNCTION(BlueprintCallable, Category = "AdvancedPrimaryLayoutWidget")
	void RegisterWidgetStack(
		UPARAM(meta = (Categories = "AdvancedTagUI"))const FGameplayTag InTag,
		UCommonActivatableWidgetContainerBase* InWidgetStack);

	UFUNCTION(BlueprintCallable, Category = "AdvancedPrimaryLayoutWidget")
	UCommonActivatableWidgetContainerBase* GetWidgetStackByTag(const FGameplayTag& InTag) const;

protected:
	//初始化的时候就注册所有栈,并且将自身注册到子系统中
	virtual void NativeOnInitialized() override;

private:
	//保存的栈引用,使用Map快速查找
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
