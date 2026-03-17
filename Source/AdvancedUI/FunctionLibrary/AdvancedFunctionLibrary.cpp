// Copyright © 2026 鸿源z. All Rights Reserved.


#include "AdvancedFunctionLibrary.h"

#include "AdvancedUI/DevelopmentSettings/AdvancedUISettings.h"

TSoftClassPtr<UAdvancedActivatableWidget> UAdvancedFunctionLibrary::GetWidgetClassByTag(FGameplayTag InTag)
{
	const UAdvancedUISettings* Settings = GetDefault<UAdvancedUISettings>();
	if (!Settings) return nullptr;
	if (!Settings->WidgetMap.Contains(InTag)) return nullptr;

	return Settings->WidgetMap.FindRef(InTag);
}
