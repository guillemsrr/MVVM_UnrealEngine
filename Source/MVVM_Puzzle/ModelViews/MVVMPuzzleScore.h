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
	DECLARE_MULTICAST_DELEGATE(FOnResetRequested)

	FOnResetRequested OnResetRequested;

	UFUNCTION(BlueprintPure, FieldNotify)
	int32 GetScore() const
	{
		return Score;
	}

	void SetScore(int32 InScore);

	UFUNCTION(BlueprintCallable)
	void ResetScore();

	void IncreaseScore();
	void DecreaseScore();

private:
	UPROPERTY(FieldNotify, Getter, Setter)
	int32 Score = 0;
};