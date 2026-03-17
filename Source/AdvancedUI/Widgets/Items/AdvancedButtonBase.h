// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "AdvancedButtonBase.generated.h"

class UCommonTextBlock;
/**
 * 用于本项目的基础按钮
 */
UCLASS(Abstract)
class ADVANCEDUI_API UAdvancedButtonBase : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	//是否需要按钮显示文本
	UPROPERTY(Editanywhere, BlueprintReadWrite, Category = "AdvancedUI")
	bool bIsUpperButtonText = false;

	//按钮显示文本
	UPROPERTY(Editanywhere, BlueprintReadWrite, Category = "AdvancedUI")
	FText ButtonDisplayText;

	//按钮描述文本,在屏幕下方详细说明位置中显示
	UPROPERTY(Editanywhere, BlueprintReadWrite, Category = "AdvancedUI")
	FText ButtonDescriptionText;

	UFUNCTION(BlueprintCallable)
	void SetButtonText(const FText& InText);

protected:
	//预构建
	virtual void NativePreConstruct() override;

	//按钮提供的文本样式改变函数,需要覆写
	virtual void NativeOnCurrentTextStyleChanged() override;
	
	//悬停和离开的函数,覆写用于广播描述文本
	virtual void NativeOnHovered() override;
	virtual void NativeOnUnhovered() override;

private:
	//可选绑定 按钮的文本控件
	UPROPERTY(meta=(BindWidgetOptional))
	TObjectPtr<UCommonTextBlock> CommonTextBlock_ButtonText;
};
