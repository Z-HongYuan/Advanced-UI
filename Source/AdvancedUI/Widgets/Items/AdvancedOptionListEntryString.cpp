// Copyright © 2026 鸿源z. All Rights Reserved.


#include "AdvancedOptionListEntryString.h"

#include "AdvancedButtonBase.h"
#include "AdvancedRotator.h"
#include "AdvancedUI/Widgets/Objects/AdvancedListDataObjectString.h"

void UAdvancedOptionListEntryString::OnListItemObjectSet(UOptionListDataObjectBase* OptionListDataObjectBase)
{
	Super::OnListItemObjectSet(OptionListDataObjectBase);

	CacheAdvancedListDataObjectString = Cast<UAdvancedListDataObjectString>(OptionListDataObjectBase);
	if (CacheAdvancedListDataObjectString)
	{
		AdvancedRotator_ActiveOption->PopulateTextLabels(CacheAdvancedListDataObjectString->GetOptionTextArray());
		// AdvancedRotator_ActiveOption->ShiftTextLeft();
		// AdvancedRotator_ActiveOption->ShiftTextRight();
		// AdvancedRotator_ActiveOption->SetSelectedItem();
		AdvancedRotator_ActiveOption->SetSelectedItemByFText(CacheAdvancedListDataObjectString->GetCurrentDisplayText());
	}
}


void UAdvancedOptionListEntryString::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (AdvancedButton_Previous && AdvancedButton_Next)
	{
		AdvancedButton_Previous->OnClicked().AddUObject(this, &UAdvancedOptionListEntryString::OnPreviousClicked);
		AdvancedButton_Next->OnClicked().AddUObject(this, &UAdvancedOptionListEntryString::OnNextClicked);
	}
}

void UAdvancedOptionListEntryString::OnDataObjectChange(UOptionListDataObjectBase* DataObject, EOptionDataChangeReason Reason)
{
	AdvancedRotator_ActiveOption->SetSelectedItemByFText(CacheAdvancedListDataObjectString->GetCurrentDisplayText());
}

void UAdvancedOptionListEntryString::OnPreviousClicked()
{
	if (CacheAdvancedListDataObjectString) CacheAdvancedListDataObjectString->SelectThePreviousOption();
}

void UAdvancedOptionListEntryString::OnNextClicked()
{
	if (CacheAdvancedListDataObjectString) CacheAdvancedListDataObjectString->SelectTheNextOption();
}
