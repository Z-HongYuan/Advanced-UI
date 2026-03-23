// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "AdvancedOptionListEntryBase.generated.h"

enum class EOptionDataChangeReason : uint8;
class UOptionListDataObjectBase;
class UCommonTextBlock;
/**
 * 这是用于在设置界面中显示选项的基础类
 */
UCLASS(Abstract)
class ADVANCEDUI_API UAdvancedOptionListEntryBase : public UCommonUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	//~IUserObjectListEntry interface.
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;

	/*这里是自己触发的函数,用于设置选项中的参数*/
	virtual void OnListItemObjectSet(UOptionListDataObjectBase* OptionListDataObjectBase);

	UFUNCTION()
	virtual void OnDataObjectChange(UOptionListDataObjectBase* DataObject, EOptionDataChangeReason Reason);

private:
	/*绑定的文本部件*/
	UPROPERTY(meta=(BindWidgetOptional))
	TObjectPtr<UCommonTextBlock> CommonTextBlock_EntryName;
};
