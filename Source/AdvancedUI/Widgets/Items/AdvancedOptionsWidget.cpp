// Copyright © 2026 鸿源z. All Rights Reserved.


#include "AdvancedOptionsWidget.h"

#include "ICommonInputModule.h"
#include "Input/CommonUIInputTypes.h"

void UAdvancedOptionsWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (!ResetAction.IsNull())
	{
		/*注册自己的输入按钮到输入动作中,将会在ButtonAction框中展示出来,保存的变量是为了动态的移除和添加Button*/
		ResetActionBindHandle = RegisterUIActionBinding(FBindUIActionArgs(
			ResetAction,
			true,
			FSimpleDelegate::CreateUObject(this, &UAdvancedOptionsWidget::OnResetActionTriggered)
		));
	}

	/*绑定默认的动作行为,如果这里处理了,在Widget中就不需要勾选显示默认的返回操作了*/
	ResetActionBindHandle = RegisterUIActionBinding(FBindUIActionArgs(
		ICommonInputModule::GetSettings().GetDefaultBackAction(),
		true,
		FSimpleDelegate::CreateUObject(this, &UAdvancedOptionsWidget::OnBackActionTriggered)
	));
}

void UAdvancedOptionsWidget::OnResetActionTriggered()
{
	/*触发后重置所有的参数*/
}

void UAdvancedOptionsWidget::OnBackActionTriggered()
{
	/*触发后返回*/
	DeactivateWidget();
}
