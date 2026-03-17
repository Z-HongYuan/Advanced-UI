// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AdvancedFunctionLibrary.generated.h"

struct FGameplayTag;
class UAdvancedActivatableWidget;
/**
 * 函数库
 */
UCLASS()
class ADVANCEDUI_API UAdvancedFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "AdvancedUI")
	static TSoftClassPtr<UAdvancedActivatableWidget> GetWidgetClassByTag(
		UPARAM(meta = (Categories = "AdvancedTagUI")) FGameplayTag InTag);
};
