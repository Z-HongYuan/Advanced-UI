// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AdvancedPlayerController.generated.h"

/**
 * 在特定事件中设置摄像机目标的类
 */
UCLASS(Abstract)
class ADVANCEDUI_API AAdvancedPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	// ~ Begin APlayerController Interface
	virtual void OnPossess(APawn* aPawn) override;
	// ~ End APlayerController Interface
};
