// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"

#include "MVVMPuzzleScore.generated.h"


UCLASS()
class MVVM_PUZZLE_API UMVVMPuzzleScore : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, FieldNotify)
	int32 GetScore() const
	{
		return Score;
	}

	UFUNCTION(BlueprintCallable)
	void SetScore(int32 InScore);

	UFUNCTION(BlueprintCallable)
	void ResetScore();

private:
	UPROPERTY(FieldNotify, Getter, Setter)
	int32 Score = 0;
};