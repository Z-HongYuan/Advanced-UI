// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AdvancedListDataObjectValue.h"
#include "AdvancedListDataObjectString.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDUI_API UAdvancedListDataObjectString : public UAdvancedListDataObjectValue
{
	GENERATED_BODY()

public:
	/*用于在设置数据对象的时候添加选项*/
	void AddOption(const FString& InOptionString, const FText& InOptionText)
	{
		OptionStringArray.Add(InOptionString);
		OptionTextArray.Add(InOptionText);
	}

	virtual void OnDataObjectInited() override;

	bool GetTextFromStringArray(const FString& InString, FText& OutText) const;

	//获取选项文本数组
	const TArray<FText>& GetOptionTextArray() const { return OptionTextArray; }

	//获取当前显示文本
	FText GetCurrentDisplayText() const { return CurrentDisplayText; }

	void SelectThePreviousOption();
	void SelectTheNextOption();
protected:
	TArray<FString> OptionStringArray;
	TArray<FText> OptionTextArray;
	FString CurrentStringValue;
	FText CurrentDisplayText;
};
