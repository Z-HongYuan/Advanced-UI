// Copyright © 2026 鸿源z. All Rights Reserved.


#include "AdvancedGameplayTags.h"

#define UE_API ADVANCEDUI_API

namespace AdvancedGameplayTags
{
	UE_API UE_DEFINE_GAMEPLAY_TAG_COMMENT(AdvancedTagUI_Test, "AdvancedTagUI.Test", "UI的测试Tag")

	//在主界面中的栈Tag
	UE_API UE_DEFINE_GAMEPLAY_TAG_COMMENT(AdvancedTagUI_WidgetStack_Modal, "AdvancedTagUI.WidgetStack.Modal", "主界面中的模态栈Tag")
	UE_API UE_DEFINE_GAMEPLAY_TAG_COMMENT(AdvancedTagUI_WidgetStack_GameMenu, "AdvancedTagUI.WidgetStack.GameMenu", "主界面中的游戏菜单栈Tag")
	UE_API UE_DEFINE_GAMEPLAY_TAG_COMMENT(AdvancedTagUI_WidgetStack_GameHUD, "AdvancedTagUI.WidgetStack.GameHUD", "主界面中的游戏HUD栈Tag")
	UE_API UE_DEFINE_GAMEPLAY_TAG_COMMENT(AdvancedTagUI_WidgetStack_Frontend, "AdvancedTagUI.WidgetStack.Frontend", "主界面中的前台栈Tag")

	//任意键界面
	UE_API UE_DEFINE_GAMEPLAY_TAG_COMMENT(AdvancedTagUI_Widget_AnyKey, "AdvancedTagUI.Widget.AnyKey", "任意键界面的Tag")

	//主菜单界面
	UE_API UE_DEFINE_GAMEPLAY_TAG_COMMENT(AdvancedTagUI_Widget_MainMenu, "AdvancedTagUI.Widget.MainMenu", "主菜单界面的Tag")
}

#undef UE_API
