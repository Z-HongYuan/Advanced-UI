// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AdvancedOptionListEntryBase.h"
#include "AdvancedOptionListEntryString.generated.h"

enum class EOptionDataChangeReason : uint8;
class UAdvancedListDataObjectString;
class UAdvancedRotator;
class UAdvancedButtonBase;
/**
 * 用于展示String的选项列表选项
 */
UCLASS()
class ADVANCEDUI_API UAdvancedOptionListEntryString : public UAdvancedOptionListEntryBase
{
	GENERATED_BODY()

public:
	virtual void OnListItemObjectSet(UOptionListDataObjectBase* OptionListDataObjectBase) override;

protected:
	virtual void NativeOnInitialized() override;

	virtual void OnDataObjectChange(UOptionListDataObjectBase* DataObject, EOptionDataChangeReason Reason) override;

private:
	/*绑定按钮事件*/
	UFUNCTION()
	void OnPreviousClicked();
	UFUNCTION()
	void OnNextClicked();

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UAdvancedButtonBase> AdvancedButton_Previous;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UAdvancedButtonBase> AdvancedButton_Next;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UAdvancedRotator> AdvancedRotator_ActiveOption;

	UPROPERTY()
	TObjectPtr<UAdvancedListDataObjectString> CacheAdvancedListDataObjectString;
};
