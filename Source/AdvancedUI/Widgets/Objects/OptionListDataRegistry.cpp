// Copyright © 2026 鸿源z. All Rights Reserved.


#include "OptionListDataRegistry.h"

#include "OptionListDataObjectCollection.h"

void UOptionListDataRegistry::InitDataRegistry(ULocalPlayer* InLocalPlayer)
{
	InitGameplayCollectionTab();
	InitAudioCollectionTab();
	InitDisplayCollectionTab();
	InitControlCollectionTab();
}

void UOptionListDataRegistry::InitGameplayCollectionTab()
{
	//构造数据对象
	UOptionListDataObjectCollection* GameplayCollection = NewObject<UOptionListDataObjectCollection>();
	GameplayCollection->SetDataID(FName("GameplayCollection"));
	GameplayCollection->SetDataDisplayText(NSLOCTEXT("AdvancedUI", "GameplayButton", "游戏设置"));

	OptionListDataObjectCollectionArray.Add(GameplayCollection);
}

void UOptionListDataRegistry::InitAudioCollectionTab()
{
	//构造数据对象
	UOptionListDataObjectCollection* AudioCollection = NewObject<UOptionListDataObjectCollection>();
	AudioCollection->SetDataID(FName("AudioCollection"));
	AudioCollection->SetDataDisplayText(NSLOCTEXT("AdvancedUI", "AudioButton", "音效设置"));

	OptionListDataObjectCollectionArray.Add(AudioCollection);
}

void UOptionListDataRegistry::InitDisplayCollectionTab()
{
	//构造数据对象
	UOptionListDataObjectCollection* DisplayCollection = NewObject<UOptionListDataObjectCollection>();
	DisplayCollection->SetDataID(FName("DisplayCollection"));
	DisplayCollection->SetDataDisplayText(NSLOCTEXT("AdvancedUI", "DisplayButton", "显示设置"));

	OptionListDataObjectCollectionArray.Add(DisplayCollection);
}

void UOptionListDataRegistry::InitControlCollectionTab()
{
	//构造数据对象
	UOptionListDataObjectCollection* ControlCollection = NewObject<UOptionListDataObjectCollection>();
	ControlCollection->SetDataID(FName("ControlCollection"));
	ControlCollection->SetDataDisplayText(NSLOCTEXT("AdvancedUI", "ControlButton", "控制设置"));

	OptionListDataObjectCollectionArray.Add(ControlCollection);
}
