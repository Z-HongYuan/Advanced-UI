// Copyright © 2026 鸿源z. All Rights Reserved.


#include "AdvancedPlayerController.h"

#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

void AAdvancedPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	//查询场景中的电影摄像机Actor,并且设置为当前控制器的目标
	TArray<AActor*> OutActorArray;
	UGameplayStatics::GetAllActorsOfClassWithTag(this, ACameraActor::StaticClass(), FName("Default"), OutActorArray);
	if (!OutActorArray.IsEmpty())
	{
		SetViewTarget(OutActorArray[0]);
	}
}
