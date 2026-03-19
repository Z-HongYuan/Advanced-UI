// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/**
 * 用于确定弹窗类型枚举,例如OK类型的弹窗,或者YesNo类型的弹窗
 */
UENUM(BlueprintType)
enum class EConfirmPopType : uint8
{
	Ok, //确定
	YesNo, //是/否
	OKCancel, //确定/取消
	None UMETA(Hidden)
};

/*
 * 用于判断弹窗按钮类型枚举,用于判断玩家在弹窗中点击的按钮类型
 */
UENUM(BlueprintType)
enum class EConfirmPopButtonType : uint8
{
	Confirm, //确定
	Cancel, //取消
	Close, //关闭
	None UMETA(Hidden)
};
