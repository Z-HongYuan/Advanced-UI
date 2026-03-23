// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AdvancedItemsMapAsset.generated.h"

/**
 * 用于保存数据对象与Widget之间的映射关系
 */
UCLASS()
class ADVANCEDUI_API UAdvancedItemsMapAsset : public UDataAsset
{
	GENERATED_BODY()

public:

public:
	// 保存数据对象与Widget之间的映射关系,一般要做一个Getter和Setter,并且通过父子级关系来查找
	UPROPERTY(EditDefaultsOnly)
	TMap<
		TSubclassOf<class UOptionListDataObjectBase>,
		TSubclassOf<class UAdvancedOptionListEntryBase>
	> OptionListDataObjectToWidgetMap;
};
