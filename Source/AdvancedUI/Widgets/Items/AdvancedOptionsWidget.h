// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AdvancedUI/Widgets/AdvancedActivatableWidget.h"
#include "AdvancedOptionsWidget.generated.h"

class UAdvancedTabListWidget;
class UOptionListDataRegistry;
/**
 * 用于构建设置选项界面的基类
 * 选项界面
 */
UCLASS(Abstract)
class ADVANCEDUI_API UAdvancedOptionsWidget : public UAdvancedActivatableWidget
{
	GENERATED_BODY()

protected:
	/*原生初始化*/
	virtual void NativeOnInitialized() override;
	virtual void NativeOnActivated() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "AdvancedUI|ButtonActions", meta = (RowType = "/Script/CommonUI.CommonInputActionDataBase"))
	FDataTableRowHandle ResetAction;

	FUIActionBindingHandle ResetActionBindHandle;

	void OnResetActionTriggered();
	void OnBackActionTriggered();

	/*这个是设置界面中绑定的顶部按钮组,使用数据对象进行构建*/
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UAdvancedTabListWidget> AdvancedTabListWidget_Options;

	/*这里是构建的数据对象,其中包含了在设置界面顶部显示的选项卡*/
	UPROPERTY(Transient)
	TObjectPtr<UOptionListDataRegistry> OptionListDataRegistry;
	UOptionListDataRegistry* GetOrCreateOptionListDataRegistry();
};
