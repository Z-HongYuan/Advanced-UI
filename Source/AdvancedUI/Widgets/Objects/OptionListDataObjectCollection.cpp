// Copyright © 2026 鸿源z. All Rights Reserved.


#include "OptionListDataObjectCollection.h"

void UOptionListDataObjectCollection::AddChildDataObject(UOptionListDataObjectBase* InChildDataObject)
{
	InChildDataObject->InitDataObject();

	InChildDataObject->SetParentDataObject(this);

	ChildDataObjectArray.Add(InChildDataObject);
}

TArray<UOptionListDataObjectBase*> UOptionListDataObjectCollection::GetChildDataObjectArray() const
{
	return ChildDataObjectArray;
}

bool UOptionListDataObjectCollection::HasChildDataObject() const
{
	return !ChildDataObjectArray.IsEmpty();
}
