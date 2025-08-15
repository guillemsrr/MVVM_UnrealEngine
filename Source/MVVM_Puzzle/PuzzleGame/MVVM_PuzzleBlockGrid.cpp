// Copyright (c) Guillem Serra. All Rights Reserved.

#include "MVVM_PuzzleBlockGrid.h"
#include "MVVM_PuzzleBlock.h"
#include "Components/TextRenderComponent.h"
#include "Engine/World.h"
#include "MVVM_Puzzle/UI/PuzzleHUD.h"
#include "MVVM_Puzzle/ModelViews/MVVMPuzzleScore.h"
#include "GameFramework/PlayerController.h"

#define LOCTEXT_NAMESPACE "PuzzleBlockGrid"

AMVVM_PuzzleBlockGrid::AMVVM_PuzzleBlockGrid()
{
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	ScoreText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("ScoreText0"));
	ScoreText->SetRelativeLocation(FVector(200.f, 0.f, 0.f));
	ScoreText->SetRelativeRotation(FRotator(90.f, 0.f, 0.f));
	ScoreText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Score: {0}"), FText::AsNumber(0)));
	ScoreText->SetupAttachment(DummyRoot);

	Size = 3;
	BlockSpacing = 300.f;
}

void AMVVM_PuzzleBlockGrid::BeginPlay()
{
	Super::BeginPlay();

	const int32 NumBlocks = Size * Size;

	for (int32 BlockIndex = 0; BlockIndex < NumBlocks; BlockIndex++)
	{
		const float XOffset = (BlockIndex / Size) * BlockSpacing; // Divide by dimension
		const float YOffset = (BlockIndex % Size) * BlockSpacing; // Modulo gives remainder

		const FVector BlockLocation = FVector(XOffset, YOffset, 0.f) + GetActorLocation();
		AMVVM_PuzzleBlock* NewBlock = GetWorld()->SpawnActor<AMVVM_PuzzleBlock>(
			PuzzleBlockClass,
			BlockLocation,
			FRotator(0, 0, 0));
		if (NewBlock != nullptr)
		{
			NewBlock->OwningGrid = this;
		}
	}
}

void AMVVM_PuzzleBlockGrid::AddScore()
{
	Score++;

	ScoreText->SetText(FText::Format(LOCTEXT("ScoreFmt", "Score: {0}"), FText::AsNumber(Score)));

	APuzzleHUD* HUD = APuzzleHUD::GetHUD(this);
	if (HUD)
	{
		HUD->GetScoreViewModel()->SetScore(Score);
	}
}

#undef LOCTEXT_NAMESPACE