// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DeveloperSettings.h"
#include "AdvancedUISettings.generated.h"

class UAdvancedActivatableWidget;
/**
 * 这里是保存引用的开发者设置
 */
UCLASS(config = Game, defaultconfig, meta = (DisplayName = "Advanced UI Settings"))
class ADVANCEDUI_API UAdvancedUISettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	/*
	 * 这是之前的想法,直接挨个设置,但是这样会比较麻烦
	 */
	// UPROPERTY(EditDefaultsOnly, Config, Category = "AdvancedUI", DisplayName="根控件类")
	// TSubclassOf<UUserWidget> PrimaryWidgetClass;

	// UPROPERTY(EditDefaultsOnly, Config, Category = "AdvancedUI", DisplayName="任意键类")
	// TSoftClassPtr<UAdvancedActivatableWidget> AnyKeyClass;

	/*
	 * 使用TMap来保存映射的Tag和Widget
	 */
	UPROPERTY(EditAnywhere, Config, Category = "AdvancedUI", DisplayName="控件映射", meta = (ForceInlineRow, Categories = "AdvancedUI"))
	TMap<FGameplayTag, TSoftClassPtr<UAdvancedActivatableWidget>> WidgetMap;
};
