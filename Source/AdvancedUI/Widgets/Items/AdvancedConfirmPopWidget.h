// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AdvancedUI/Data/AdvancedUIType.h"
#include "AdvancedUI/Widgets/AdvancedActivatableWidget.h"
#include "AdvancedConfirmPopWidget.generated.h"

class UDynamicEntryBox;
class UCommonTextBlock;

/*
 * 用于弹窗界面的按钮信息,用于创建按钮
 * 用于在UAdvancedConfirmPopInfoObject控件信息中保存按钮信息
 */
USTRUCT(BlueprintType)
struct FConfirmPopButtonInfo
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EConfirmPopButtonType ConfirmPopButtonType = EConfirmPopButtonType::None;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText ButtonTextToDisplay;
};

/*
 * Runtime 创建的弹窗信息对象
 * 部件根据这个信息对象来创建对应的弹窗类型和弹窗内容
 */
UCLASS(Abstract)
class ADVANCEDUI_API UAdvancedConfirmPopInfoObject : public UObject
{
	GENERATED_BODY()

public:
	static UAdvancedConfirmPopInfoObject* CreatePopInfoForOK(const FText& InPopTitleText, const FText& InPopContentText);
	static UAdvancedConfirmPopInfoObject* CreatePopInfoForYesNo(const FText& InPopTitleText, const FText& InPopContentText);
	static UAdvancedConfirmPopInfoObject* CreatePopInfoForOKCancel(const FText& InPopTitleText, const FText& InPopContentText);


	UPROPERTY(Transient)
	FText PopTitleText;

	UPROPERTY(Transient)
	FText PopContentText;

	UPROPERTY(Transient)
	TArray<FConfirmPopButtonInfo> ButtonInfos;
};

/**
 * 弹窗界面
 */
UCLASS(Abstract)
class ADVANCEDUI_API UAdvancedConfirmPopWidget : public UAdvancedActivatableWidget
{
	GENERATED_BODY()

public:
	/*
	 * 这个函数用于初始化弹窗界面,传入弹窗信息对象,弹窗信息对象会根据这个对象来创建弹窗界面
	 */
	void InitConfirmPop(UAdvancedConfirmPopInfoObject* InConfirmPopInfoObject, TFunction<void(EConfirmPopButtonType)> InButtonClickCallback);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	TMap<EConfirmPopButtonType, FText> ButtonTexts;

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> CommonTextBlock_Title; //标题文本框
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> CommonTextBlock_Content; //内容文本框
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UDynamicEntryBox> DynamicEntryBox_Buttons; //按钮列表,用于动态创建按钮
};
