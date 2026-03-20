// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonTabListWidgetBase.h"
#include "AdvancedTabListWidget.generated.h"

class UAdvancedButtonBase;

/**
 * CommonUI提供的用于在设置界面使用的选项卡切换器
 * 自带左右控件的左右切换,并且拥有Trigger事件
 */
UCLASS(Abstract)
class ADVANCEDUI_API UAdvancedTabListWidget : public UCommonTabListWidgetBase
{
	GENERATED_BODY()

public:
	/*专门用于注册对应的Button类并且设置其文本*/
	void RequestRegisterTab(FName InButtonID, FText InDisplayText);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AdvancedUI", meta=(AllowPrivateAccess = true))
	int32 DebugMaxIndex = 3;

	/*正常要做一个数据有效性验证,但是这里没做 搜索 ValidateCompiledDefault*/
	/*用于在具体构建的时候,使用的Button类*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AdvancedUI", meta=(AllowPrivateAccess = true))
	TSubclassOf<UAdvancedButtonBase> TabButtonEntryWidgetClass;
};
