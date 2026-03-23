// Copyright © 2026 鸿源z. All Rights Reserved.


#include "OptionListDataObjectBase.h"

void UOptionListDataObjectBase::NotifyDataObjectChange(UOptionListDataObjectBase* DataObject, EOptionDataChangeReason Reason)
{
	OnDataObjectChange.Broadcast(DataObject, Reason);
}

void UOptionListDataObjectBase::InitDataObject()
{
	OnDataObjectInited();
}

void UOptionListDataObjectBase::OnDataObjectInited()
{
}
