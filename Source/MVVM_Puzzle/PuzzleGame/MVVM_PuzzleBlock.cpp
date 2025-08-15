// Copyright (c) Guillem Serra. All Rights Reserved.

#include "MVVM_PuzzleBlock.h"
#include "MVVM_PuzzleBlockGrid.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInstance.h"

AMVVM_PuzzleBlock::AMVVM_PuzzleBlock()
{
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh0"));
	BlockMesh->SetRelativeScale3D(FVector(1.f, 1.f, 0.25f));
	BlockMesh->SetRelativeLocation(FVector(0.f, 0.f, 25.f));
	BlockMesh->SetupAttachment(DummyRoot);
	BlockMesh->OnClicked.AddDynamic(this, &AMVVM_PuzzleBlock::BlockClicked);
	BlockMesh->OnInputTouchBegin.AddDynamic(this, &AMVVM_PuzzleBlock::OnFingerPressedBlock);
}

void AMVVM_PuzzleBlock::BlockClicked(UPrimitiveComponent* ClickedComp, FKey ButtonClicked)
{
	HandleClicked();
}

void AMVVM_PuzzleBlock::OnFingerPressedBlock(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent)
{
	HandleClicked();
}

void AMVVM_PuzzleBlock::HandleClicked()
{
	if (!bIsActive)
	{
		bIsActive = true;

		BlockMesh->SetMaterial(0, OrangeMaterial);

		if (OwningGrid != nullptr)
		{
			OwningGrid->AddScore();
		}
	}
}

void AMVVM_PuzzleBlock::Highlight(bool bOn)
{
	if (bIsActive)
	{
		return;
	}

	if (bOn)
	{
		BlockMesh->SetMaterial(0, BaseMaterial);
	}
	else
	{
		BlockMesh->SetMaterial(0, BlueMaterial);
	}
}