// Copyright © 2026 鸿源z. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OptionListDataRegistry.generated.h"

class UOptionListDataObjectCollection;

/**
 * 注册表,用于保存所有数据对象集合
 * 这个类只是创建并且保存集合的集合
 */
UCLASS()
class ADVANCEDUI_API UOptionListDataRegistry : public UObject
{
	GENERATED_BODY()

public:
	/*为选项卡注册数据对象*/
	void InitDataRegistry(ULocalPlayer* InLocalPlayer);

	const TArray<UOptionListDataObjectCollection*>& GetOptionListDataObjectCollectionArray() const
	{
		return OptionListDataObjectCollectionArray;
	}

private:
	//初始化游戏,音效,显示,控制四个选项卡
	void InitGameplayCollectionTab();
	void InitAudioCollectionTab();
	void InitDisplayCollectionTab();
	void InitControlCollectionTab();

	UPROPERTY(Transient)
	TArray<UOptionListDataObjectCollection*> OptionListDataObjectCollectionArray;
};
