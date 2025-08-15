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

protected:
	AMVVM_PuzzleBlockGrid();
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<AMVVM_PuzzleBlock> PuzzleBlockClass;

	UPROPERTY(Category = Grid, VisibleDefaultsOnly, BlueprintReadOnly)
	class USceneComponent* DummyRoot;

	UPROPERTY(Category = Grid, VisibleDefaultsOnly, BlueprintReadOnly)
	class UTextRenderComponent* ScoreText;

	UPROPERTY(Category=Grid, EditAnywhere, BlueprintReadOnly)
	int32 Size;

	UPROPERTY(Category=Grid, EditAnywhere, BlueprintReadOnly)
	float BlockSpacing;

public:
	void TemplateIncreaseScore();
	void TemplateDecreaseScore();
	UFUNCTION()
	void ResetBlocks();

	FORCEINLINE class USceneComponent* GetDummyRoot() const
	{
		return DummyRoot;
	}

	FORCEINLINE class UTextRenderComponent* GetScoreText() const
	{
		return ScoreText;
	}

private:
	int32 Score;

	UPROPERTY()
	TArray<AMVVM_PuzzleBlock*> Blocks;

	void CreateBlocks();
	void UpdateScore() const;
};