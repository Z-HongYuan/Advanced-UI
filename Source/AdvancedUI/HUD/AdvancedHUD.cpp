// Copyright © 2026 鸿源z. All Rights Reserved.


#include "AdvancedHUD.h"

#include "Blueprint/UserWidget.h"


void AAdvancedHUD::BeginPlay()
{
	Super::BeginPlay();

	//构建主要的控件
	if (PrimaryWidgetClass)
	{
		PrimaryWidget = CreateWidget<UUserWidget>(GetWorld(), PrimaryWidgetClass);
		PrimaryWidget->AddToViewport();
	}
}

void AAdvancedHUD::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	//释放主要的控件
	if (PrimaryWidget) PrimaryWidget->RemoveFromParent();

	Super::EndPlay(EndPlayReason);
}
