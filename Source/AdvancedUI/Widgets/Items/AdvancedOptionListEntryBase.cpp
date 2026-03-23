// Copyright © 2026 鸿源z. All Rights Reserved.


#include "AdvancedOptionListEntryBase.h"

#include "CommonTextBlock.h"
#include "AdvancedUI/Widgets/Objects/OptionListDataObjectBase.h"

void UAdvancedOptionListEntryBase::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	/*接口上的父版本需要完全限定符,不能使用Super::*/
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	if (UOptionListDataObjectBase* OptionListDataObjectBase = Cast<UOptionListDataObjectBase>(ListItemObject))
	{
		OnListItemObjectSet(OptionListDataObjectBase);
		if (!OptionListDataObjectBase->OnDataObjectChange.IsBoundToObject(this))
			OptionListDataObjectBase->OnDataObjectChange.AddUObject(this, &UAdvancedOptionListEntryBase::OnDataObjectChange);
	}
}

void UAdvancedOptionListEntryBase::OnListItemObjectSet(UOptionListDataObjectBase* OptionListDataObjectBase)
{
	/*设置文本*/
	if (CommonTextBlock_EntryName)
	{
		CommonTextBlock_EntryName->SetText(OptionListDataObjectBase->GetDataDisplayText());
	}
}

void UAdvancedOptionListEntryBase::OnDataObjectChange(UOptionListDataObjectBase* DataObject, EOptionDataChangeReason Reason)
{
}
