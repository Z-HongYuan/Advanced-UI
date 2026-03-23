// Copyright © 2026 鸿源z. All Rights Reserved.


#include "OptionListDataRegistry.h"

#include "AdvancedListDataObjectString.h"
#include "OptionListDataObjectCollection.h"

void UOptionListDataRegistry::InitDataRegistry(ULocalPlayer* InLocalPlayer)
{
	InitGameplayCollectionTab();
	InitAudioCollectionTab();
	InitDisplayCollectionTab();
	InitControlCollectionTab();
}

TArray<UOptionListDataObjectBase*> UOptionListDataRegistry::GetOptionListDataObjectCollectionByID(const FName& InSelectedID) const
{
	//遍历方法
	// for (UOptionListDataObjectCollection* Element : OptionListDataObjectCollectionArray)
	// {
	// 	if (Element->GetDataID() == InSelectedID)
	// 	{
	// 		return Element;
	// 	}
	// }

	/*获取到集合指针*/
	UOptionListDataObjectCollection* const* FindResult = OptionListDataObjectCollectionArray.FindByPredicate([InSelectedID](UOptionListDataObjectCollection* Element)
	{
		return Element->GetDataID() == InSelectedID;
	});

	/*从集合指针中解引用,然后获取到集合指针中保存的所有数据对象*/
	return (*FindResult)->GetChildDataObjectArray();
}

void UOptionListDataRegistry::InitGameplayCollectionTab()
{
	//构造数据对象
	UOptionListDataObjectCollection* GameplayCollection = NewObject<UOptionListDataObjectCollection>();
	GameplayCollection->SetDataID(FName("GameplayCollection"));
	GameplayCollection->SetDataDisplayText(NSLOCTEXT("AdvancedUI", "GameplayButton", "游戏设置"));

	/*构建具体的数据对象类*/

	//游戏难度
	{
		UAdvancedListDataObjectString* Difficulty = NewObject<UAdvancedListDataObjectString>();
		Difficulty->SetDataID(FName("Difficulty"));
		Difficulty->SetDataDisplayText(NSLOCTEXT("AdvancedUI", "DifficultyButton", "游戏难度"));
		Difficulty->SetDataDescriptionText(NSLOCTEXT("AdvancedUI", "DifficultyDescription", "游戏难度"));
		Difficulty->SetDisabledText(NSLOCTEXT("AdvancedUI", "DifficultyDisabled", "游戏难度"));
		Difficulty->AddOption("Easy",NSLOCTEXT("AdvancedUI", "Easy", "简单"));
		Difficulty->AddOption("Normal",NSLOCTEXT("AdvancedUI", "Normal", "普通"));
		Difficulty->AddOption("Hard",NSLOCTEXT("AdvancedUI", "Hard", "困难"));
		Difficulty->AddOption("Hardest",NSLOCTEXT("AdvancedUI", "Hardest", "地狱"));

		GameplayCollection->AddChildDataObject(Difficulty);

		OptionListDataObjectCollectionArray.Add(GameplayCollection);
	}
	{
		UAdvancedListDataObjectValue* Difficulty = NewObject<UAdvancedListDataObjectValue>();
		Difficulty->SetDataID(FName("Difficulty"));
		Difficulty->SetDataDisplayText(NSLOCTEXT("AdvancedUI", "DifficultyButton", "游戏难度"));
		Difficulty->SetDataDescriptionText(NSLOCTEXT("AdvancedUI", "DifficultyDescription", "游戏难度"));
		Difficulty->SetDisabledText(NSLOCTEXT("AdvancedUI", "DifficultyDisabled", "游戏难度"));
		GameplayCollection->AddChildDataObject(Difficulty);

		OptionListDataObjectCollectionArray.Add(GameplayCollection);
	}
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
