// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MVVM_PuzzleBlockGrid.generated.h"

class AMVVM_PuzzleBlock;

UCLASS(minimalapi)
class AMVVM_PuzzleBlockGrid : public AActor
{
	GENERATED_BODY()

	UPROPERTY(Category = Grid, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* DummyRoot;

	UPROPERTY(Category = Grid, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UTextRenderComponent* ScoreText;

public:
	AMVVM_PuzzleBlockGrid();

	int32 Score;

	UPROPERTY(Category=Grid, EditAnywhere, BlueprintReadOnly)
	int32 Size;

	UPROPERTY(Category=Grid, EditAnywhere, BlueprintReadOnly)
	float BlockSpacing;

protected:
	// Begin AActor interface
	virtual void BeginPlay() override;
	// End AActor interface

	UPROPERTY(EditAnywhere)
	TSubclassOf<AMVVM_PuzzleBlock> PuzzleBlockClass;

public:
	void AddScore();

	FORCEINLINE class USceneComponent* GetDummyRoot() const
	{
		return DummyRoot;
	}

	FORCEINLINE class UTextRenderComponent* GetScoreText() const
	{
		return ScoreText;
	}
};