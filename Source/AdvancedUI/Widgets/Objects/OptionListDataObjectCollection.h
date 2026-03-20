// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OptionListDataObjectBase.h"
#include "OptionListDataObjectCollection.generated.h"

/**
 * 选项列表数据对象集合
 * 能够添加并且保存其拥有的子类,并且自身还包含数据
 */
UCLASS()
class ADVANCEDUI_API UOptionListDataObjectCollection : public UOptionListDataObjectBase
{
	GENERATED_BODY()

public:
	void AddChildDataObject(UOptionListDataObjectBase* InChildDataObject);

	virtual TArray<UOptionListDataObjectBase*> GetChildDataObjectArray() const override;
	virtual bool HasChildDataObject() const override;

private:
	UPROPERTY(Transient)
	TArray<UOptionListDataObjectBase*> ChildDataObjectArray;
};
