// Copyright © 2026 鸿源z. All Rights Reserved.


#include "AdvancedTabListWidget.h"

#include "AdvancedButtonBase.h"

void UAdvancedTabListWidget::RequestRegisterTab(FName InButtonID, FText InDisplayText)
{
	/*调用内部的注册函数*/
	RegisterTab(InButtonID, TabButtonEntryWidgetClass, nullptr);

	/*设置其文本*/
	if (UAdvancedButtonBase* Button = Cast<UAdvancedButtonBase>(GetTabButtonBaseByID(InButtonID)))
	{
		Button->SetButtonText(InDisplayText);
	}
}
