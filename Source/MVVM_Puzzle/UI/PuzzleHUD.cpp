// Copyright (c) Guillem Serra. All Rights Reserved.

#include "PuzzleHUD.h"

#include "Blueprint/UserWidget.h"

#include "Kismet/GameplayStatics.h"

#include "MVVM_Puzzle/ModelViews/MVVMPuzzleScore.h"

APuzzleHUD* APuzzleHUD::GetHUD(const UObject* WorldContextObject)
{
	APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	if (!PC)
	{
		return nullptr;
	}

	APuzzleHUD* HUD = PC->GetHUD<APuzzleHUD>();
	return HUD;
}

void APuzzleHUD::PreInitializeComponents()
{
	Super::PreInitializeComponents();
	ScoreViewModel = NewObject<UMVVMPuzzleScore>(this);
}

void APuzzleHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	ScoreWidget = CreateWidget<UUserWidget>(GetWorld(), ScoreWidgetClass);
}

void APuzzleHUD::BeginPlay()
{
	Super::BeginPlay();

	if (ensure(ScoreWidget))
	{
		ScoreWidget->AddToViewport();
	}
}