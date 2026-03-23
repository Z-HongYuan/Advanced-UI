// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonListView.h"
#include "AdvancedListView.generated.h"

class UAdvancedItemsMapAsset;
/**
 * 自定义的视口列表,使用自己的数据对象来构建对应的Widget
 */
UCLASS()
class ADVANCEDUI_API UAdvancedListView : public UCommonListView
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AdvancedUI, meta = (DisplayName = "AdvancedItemsMapAsset"))
	TObjectPtr<UAdvancedItemsMapAsset> AdvancedItemsMapAsset;
	
	virtual UUserWidget& OnGenerateEntryWidgetInternal(UObject* Item, TSubclassOf<UUserWidget> DesiredEntryClass, const TSharedRef<STableViewBase>& OwnerTable) override;
};
