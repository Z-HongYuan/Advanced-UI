// Copyright © 2026 鸿源z. All Rights Reserved.


#include "AdvancedOptionsWidget.h"

#include "AdvancedTabListWidget.h"
#include "ICommonInputModule.h"
#include "AdvancedUI/Widgets/Objects/OptionListDataObjectCollection.h"
#include "AdvancedUI/Widgets/Objects/OptionListDataRegistry.h"
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

void UAdvancedOptionsWidget::NativeOnActivated()
{
	Super::NativeOnActivated();

	/*在激活的时候就根据树形数据对象来创建对应的Buttons,并给按钮设置上文本
	 * 构建数据集合的集合,并且根据集合来请求创建Button
	 */
	for (UOptionListDataObjectCollection* Element : GetOrCreateOptionListDataRegistry()->GetOptionListDataObjectCollectionArray())
	{
		if (!Element) continue;
		FName DataID = Element->GetDataID();
		if (AdvancedTabListWidget_Options->GetTabButtonBaseByID(DataID)) continue;//这个代表着已经创建过了
		AdvancedTabListWidget_Options->RequestRegisterTab(DataID, Element->GetDataDisplayText());
	}
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

UOptionListDataRegistry* UAdvancedOptionsWidget::GetOrCreateOptionListDataRegistry()
{
	if (OptionListDataRegistry)
	{
		return OptionListDataRegistry;
	}

	OptionListDataRegistry = NewObject<UOptionListDataRegistry>();
	OptionListDataRegistry->InitDataRegistry(GetOwningLocalPlayer());


	return OptionListDataRegistry;
}
