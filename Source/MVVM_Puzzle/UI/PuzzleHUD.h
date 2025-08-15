// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PuzzleHUD.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class MVVM_PUZZLE_API APuzzleHUD : public AHUD
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
	static APuzzleHUD* GetHUD(const UObject* WorldContextObject);

protected:
	virtual void PreInitializeComponents() override;
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintPure, Category="MVVM|Score")
	class UMVVMPuzzleScore* GetScoreViewModel() const
	{
		return ScoreViewModel;
	}

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> ScoreWidgetClass;

private:
	UPROPERTY()
	UUserWidget* ScoreWidget;

	UPROPERTY()
	class UMVVMPuzzleScore* ScoreViewModel;
};