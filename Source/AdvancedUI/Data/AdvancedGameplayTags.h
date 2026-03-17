// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once
#include "NativeGameplayTags.h"

#define UE_API ADVANCEDUI_API

namespace AdvancedGameplayTags
{
	UE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(AdvancedTagUI_Test);

	//在主界面中的栈Tag
	UE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(AdvancedTagUI_WidgetStack_Modal);
	UE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(AdvancedTagUI_WidgetStack_GameMenu);
	UE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(AdvancedTagUI_WidgetStack_GameHUD);
	UE_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(AdvancedTagUI_WidgetStack_Frontend);
}

#undef UE_API
