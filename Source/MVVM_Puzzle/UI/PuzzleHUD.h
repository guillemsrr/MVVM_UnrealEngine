// Fill out your copyright notice in the Description page of Project Settings.

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

protected:
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UUserWidget> ScoreWidgetClass;

private:
	UPROPERTY()
	UUserWidget* ScoreWidget;
};
