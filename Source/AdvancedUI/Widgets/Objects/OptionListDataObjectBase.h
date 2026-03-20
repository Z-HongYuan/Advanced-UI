// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OptionListDataObjectBase.generated.h"

/*宏,能够方便的构造Getter和Setter*/
#define LIST_DATA_ACCESSOR(DataTyp,PropertyName) \
	FORCEINLINE DataTyp Get##PropertyName() const { return PropertyName;} \
	FORCEINLINE void Set##PropertyName(DataTyp In##PropertyName) {PropertyName = In##PropertyName;}

/**
 * 提供给设置界面使用的数据对象基类,这是最基础的类,只提供必要的成员变量
 */
UCLASS()
class ADVANCEDUI_API UOptionListDataObjectBase : public UObject
{
	GENERATED_BODY()

public:
	/*Getter和Setter,使用宏方法来执行批量处理*/
	LIST_DATA_ACCESSOR(FName, DataID);
	LIST_DATA_ACCESSOR(FText, DataDisplayText);
	LIST_DATA_ACCESSOR(FText, DataDescriptionText);
	LIST_DATA_ACCESSOR(FText, DisabledText);
	LIST_DATA_ACCESSOR(TSoftObjectPtr<UTexture2D>, SoftDescriptionImg);
	LIST_DATA_ACCESSOR(UOptionListDataObjectBase*, ParentDataObject);

	/*这个只是在C++端的触发器,方便子类覆写,需要在初始化的时候执行任何事件*/
	void InitDataObject();
	virtual void OnDataObjectInited();

	/*这两个函数基本上无用,如果作为Items的话,将不会有任何子类,但是在数据集合对象里面却有用*/
	virtual TArray<UOptionListDataObjectBase*> GetChildDataObjectArray() const { return TArray<UOptionListDataObjectBase*>(); }
	virtual bool HasChildDataObject() const { return false; }

private:
	FName DataID;
	FText DataDisplayText;
	FText DataDescriptionText;
	FText DisabledText;
	TSoftObjectPtr<UTexture2D> SoftDescriptionImg;
	UPROPERTY(Transient)
	TObjectPtr<UOptionListDataObjectBase> ParentDataObject;
};

#undef LIST_DATA_ACCESSOR
