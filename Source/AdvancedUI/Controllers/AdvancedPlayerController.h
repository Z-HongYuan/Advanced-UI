// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AdvancedPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ADVANCEDUI_API AAdvancedPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	// ~ Begin APlayerController Interface
	virtual void OnPossess(APawn* aPawn) override;
	// ~ End APlayerController Interface
};
