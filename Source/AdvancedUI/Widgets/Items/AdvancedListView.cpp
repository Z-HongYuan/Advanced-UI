// Copyright © 2026 鸿源z. All Rights Reserved.


#include "AdvancedListView.h"

#include "AdvancedItemsMapAsset.h"
#include "AdvancedOptionListEntryBase.h"
#include "../Objects/OptionListDataObjectBase.h"

UUserWidget& UAdvancedListView::OnGenerateEntryWidgetInternal(UObject* Item, TSubclassOf<UUserWidget> DesiredEntryClass, const TSharedRef<STableViewBase>& OwnerTable)
{
	// return Super::OnGenerateEntryWidgetInternal(Item, DesiredEntryClass, OwnerTable);
	/*覆写这个函数,实现生成不同的Widget*/

	//获取数据资产
	// if (AdvancedItemsMapAsset && AdvancedItemsMapAsset->OptionListDataObjectToWidgetMap.Contains(Item->GetClass()))
	// {
	// 	return Super::OnGenerateEntryWidgetInternal(Item, AdvancedItemsMapAsset->OptionListDataObjectToWidgetMap.FindRef(Item->GetClass()), OwnerTable);
	// }
	// return Super::OnGenerateEntryWidgetInternal(Item, DesiredEntryClass, OwnerTable);
	// return nullptr;

	if (IsDesignTime())
	{
		return Super::OnGenerateEntryWidgetInternal(Item, DesiredEntryClass, OwnerTable);
	}
	TSubclassOf<UUserWidget> TempEntryWidgetClass = AdvancedItemsMapAsset->OptionListDataObjectToWidgetMap.Contains(Item->GetClass())
		                                                ? AdvancedItemsMapAsset->OptionListDataObjectToWidgetMap.FindRef(Item->GetClass())
		                                                : DesiredEntryClass;
	if (TempEntryWidgetClass)
	{
		return GenerateTypedEntry(TempEntryWidgetClass, OwnerTable);
	}
	return Super::OnGenerateEntryWidgetInternal(Item, DesiredEntryClass, OwnerTable);
}
