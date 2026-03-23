// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "AdvancedUserSetting.generated.h"

/**
 * 用于保存在前端设置的属性
 */
UCLASS()
class ADVANCEDUI_API UAdvancedUserSetting : public UGameUserSettings
{
	GENERATED_BODY()

public:
	static UAdvancedUserSetting* Get() { return Cast<UAdvancedUserSetting>(GetGameUserSettings()); }

private:
	UPROPERTY(Config)
	FString GameDifficulty;
};
