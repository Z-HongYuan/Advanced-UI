// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonTabListWidgetBase.h"
#include "AdvancedTabListWidget.generated.h"

class UAdvancedButtonBase;
/**
 * 用于在设置界面使用的选项卡切换器
 */
UCLASS(Abstract)
class ADVANCEDUI_API UAdvancedTabListWidget : public UCommonTabListWidgetBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AdvancedUI", meta=(AllowPrivateAccess = true))
	int32 DebugMaxIndex = 3;

	/*正常要做一个数据有效性验证,但是这里没做 搜索 ValidateCompiledDefault*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AdvancedUI", meta=(AllowPrivateAccess = true))
	TSubclassOf<UAdvancedButtonBase> TabButtonEntryWidgetClass;
};
