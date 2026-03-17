// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AdvancedHUD.generated.h"

/**
 * 用于生成控件
 * 挂载UI的Root Widget
 */
UCLASS(Abstract)
class ADVANCEDUI_API AAdvancedHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AdvancedUI")
	TSubclassOf<UUserWidget> PrimaryWidgetClass;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	UPROPERTY(Transient)
	TObjectPtr<UUserWidget> PrimaryWidget;
};
