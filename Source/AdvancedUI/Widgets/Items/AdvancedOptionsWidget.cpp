// Copyright © 2026 鸿源z. All Rights Reserved.


#include "AdvancedOptionsWidget.h"

#include "AdvancedListView.h"
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

	if (AdvancedTabListWidget_Options)
	{
		AdvancedTabListWidget_Options->OnTabSelected.AddUniqueDynamic(this, &UAdvancedOptionsWidget::OnTabSelectionChanged);
	}
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
		if (AdvancedTabListWidget_Options->GetTabButtonBaseByID(DataID)) continue; //这个代表着已经创建过了
		AdvancedTabListWidget_Options->RequestRegisterTab(DataID, Element->GetDataDisplayText());
	}
}

void UAdvancedOptionsWidget::OnTabSelectionChanged(FName TabId)
{
	/*触发后根据数据更新选项卡*/

	//屏幕上打印ID
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("TabId:%s"), *TabId.ToString()));

	/*当某个选项卡被选中之后,获取到代表的所有数据选项,然后构建其对应的Widget*/
	TArray<UOptionListDataObjectBase*> DataObjectArray = GetOrCreateOptionListDataRegistry()->GetOptionListDataObjectCollectionByID(TabId);

	/*传递数据对象数组到ListView中进行处理*/
	AdvancedListView_OptionsList->SetListItems(DataObjectArray);
	AdvancedListView_OptionsList->RequestRefresh();

	/*如果项目不为0的话,就导航到第一个选项*/
	if (AdvancedListView_OptionsList->GetNumItems() != 0)
	{
		AdvancedListView_OptionsList->NavigateToIndex(0);
		AdvancedListView_OptionsList->SetSelectedIndex(0);
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
