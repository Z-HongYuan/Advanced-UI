// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AdvancedUI/Widgets/AdvancedActivatableWidget.h"
#include "AdvancedOptionsWidget.generated.h"

/**
 * 用于构建设置选项界面的基类
 */
UCLASS(Abstract)
class ADVANCEDUI_API UAdvancedOptionsWidget : public UAdvancedActivatableWidget
{
	GENERATED_BODY()

protected:
	/*原生初始化*/
	virtual void NativeOnInitialized() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "AdvancedUI|ButtonActions", meta = (RowType = "/Script/CommonUI.CommonInputActionDataBase"))
	FDataTableRowHandle ResetAction;

	FUIActionBindingHandle ResetActionBindHandle;

	void OnResetActionTriggered();
	void OnBackActionTriggered();
};
