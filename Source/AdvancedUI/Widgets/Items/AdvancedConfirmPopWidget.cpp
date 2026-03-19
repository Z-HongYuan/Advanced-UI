// Copyright © 2026 鸿源z. All Rights Reserved.


#include "AdvancedConfirmPopWidget.h"

#include "AdvancedButtonBase.h"
#include "CommonTextBlock.h"
#include "ICommonInputModule.h"
#include "Components/DynamicEntryBox.h"

UAdvancedConfirmPopInfoObject* UAdvancedConfirmPopInfoObject::CreatePopInfoForOK(const FText& InPopTitleText, const FText& InPopContentText)
{
	if (UAdvancedConfirmPopInfoObject* InfoObject = NewObject<UAdvancedConfirmPopInfoObject>())
	{
		InfoObject->PopTitleText = InPopTitleText;
		InfoObject->PopContentText = InPopContentText;

		//创建一个确定按钮信息,并且添加到动态框中,如果这个按钮需要本地化,需要使用宏来包裹
		FConfirmPopButtonInfo OKButtonInfo;
		OKButtonInfo.ButtonTextToDisplay = NSLOCTEXT("AdvancedUI", "OKButton", "确定");
		OKButtonInfo.ConfirmPopButtonType = EConfirmPopButtonType::Close;
		InfoObject->ButtonInfos.Add(OKButtonInfo);

		return InfoObject;
	}
	return nullptr;
}

UAdvancedConfirmPopInfoObject* UAdvancedConfirmPopInfoObject::CreatePopInfoForYesNo(const FText& InPopTitleText, const FText& InPopContentText)
{
	if (UAdvancedConfirmPopInfoObject* InfoObject = NewObject<UAdvancedConfirmPopInfoObject>())
	{
		InfoObject->PopTitleText = InPopTitleText;
		InfoObject->PopContentText = InPopContentText;

		FConfirmPopButtonInfo YesButtonInfo;
		YesButtonInfo.ButtonTextToDisplay = NSLOCTEXT("AdvancedUI", "YesButton", "好的");
		YesButtonInfo.ConfirmPopButtonType = EConfirmPopButtonType::Confirm;
		InfoObject->ButtonInfos.Add(YesButtonInfo);

		FConfirmPopButtonInfo NoButtonInfo;
		NoButtonInfo.ButtonTextToDisplay = NSLOCTEXT("AdvancedUI", "NoButton", "取消");
		NoButtonInfo.ConfirmPopButtonType = EConfirmPopButtonType::Cancel;
		InfoObject->ButtonInfos.Add(NoButtonInfo);

		return InfoObject;
	}
	return nullptr;
}

UAdvancedConfirmPopInfoObject* UAdvancedConfirmPopInfoObject::CreatePopInfoForOKCancel(const FText& InPopTitleText, const FText& InPopContentText)
{
	if (UAdvancedConfirmPopInfoObject* InfoObject = NewObject<UAdvancedConfirmPopInfoObject>())
	{
		InfoObject->PopTitleText = InPopTitleText;
		InfoObject->PopContentText = InPopContentText;

		FConfirmPopButtonInfo OKButtonInfo;
		OKButtonInfo.ButtonTextToDisplay = NSLOCTEXT("AdvancedUI", "OKButton", "确定");
		OKButtonInfo.ConfirmPopButtonType = EConfirmPopButtonType::Confirm;
		InfoObject->ButtonInfos.Add(OKButtonInfo);

		FConfirmPopButtonInfo CancelButtonInfo;
		CancelButtonInfo.ButtonTextToDisplay = NSLOCTEXT("AdvancedUI", "CancelButton", "取消");
		CancelButtonInfo.ConfirmPopButtonType = EConfirmPopButtonType::Cancel;
		InfoObject->ButtonInfos.Add(CancelButtonInfo);

		return InfoObject;
	}
	return nullptr;
}

void UAdvancedConfirmPopWidget::InitConfirmPop(UAdvancedConfirmPopInfoObject* InConfirmPopInfoObject, TFunction<void(EConfirmPopButtonType)> InButtonClickCallback)
{
	//有一个无效就退出
	if (!(InConfirmPopInfoObject && CommonTextBlock_Title && CommonTextBlock_Content && DynamicEntryBox_Buttons)) return;

	CommonTextBlock_Title->SetText(InConfirmPopInfoObject->PopTitleText);
	CommonTextBlock_Content->SetText(InConfirmPopInfoObject->PopContentText);

	/*清除旧的按钮和按钮委托,使用模版函数*/
	if (DynamicEntryBox_Buttons->GetNumEntries() != 0)
	{
		DynamicEntryBox_Buttons->Reset<UAdvancedButtonBase>(
			[](const UAdvancedButtonBase& InButton)
			{
				InButton.OnClicked().Clear();
			},
			false);
	}

	//创建新的按钮集合,并且绑定事件
	for (const FConfirmPopButtonInfo& ButtonInfo : InConfirmPopInfoObject->ButtonInfos)
	{
		FDataTableRowHandle ClickAction;
		switch (ButtonInfo.ConfirmPopButtonType)
		{
		//移除这一段逻辑,因为在Pop中弹窗总是会Close
		// case EConfirmPopButtonType::Confirm:
		// 	ClickAction = ICommonInputModule::GetSettings().GetDefaultClickAction();
		// 	break;
		case EConfirmPopButtonType::Cancel:
			ClickAction = ICommonInputModule::GetSettings().GetDefaultBackAction();
			break;
		case EConfirmPopButtonType::Close:
			ClickAction = ICommonInputModule::GetSettings().GetDefaultBackAction();
		default: ;
		}

		UAdvancedButtonBase* AddButton = DynamicEntryBox_Buttons->CreateEntry<UAdvancedButtonBase>();
		AddButton->SetButtonText(ButtonInfo.ButtonTextToDisplay);
		AddButton->SetTriggeringInputAction(ClickAction);

		/*将每个按钮都绑定移除Widget的功能,意味着无论如何,只要按下按钮就会移除Widget*/
		AddButton->OnClicked().AddLambda(
			[InButtonClickCallback, ButtonInfo,this]()
			{
				/*在按钮按下后将会调用这个传递的回调函数,参数为按钮自带的按钮类型,例如这个将会Close/Confirm之类的信息*/
				InButtonClickCallback(ButtonInfo.ConfirmPopButtonType);

				DeactivateWidget();
			});
	}

	if (DynamicEntryBox_Buttons->GetNumEntries() != 0)
	{
		/*聚焦向最后一个按钮,一般是No或者否之类的含义*/
		DynamicEntryBox_Buttons->GetAllEntries().Last()->SetFocus();
	}
}
