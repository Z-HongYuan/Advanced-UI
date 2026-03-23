// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonRotator.h"
#include "AdvancedRotator.generated.h"

/**
 * 用于处理手柄输入的选择器,能够从循环显示选项
 */
UCLASS(Abstract)
class ADVANCEDUI_API UAdvancedRotator : public UCommonRotator
{
	GENERATED_BODY()

public:
	/*设置选中索引代表的文本*/
	void SetSelectedItemByFText(const FText& InTextOption);
};
