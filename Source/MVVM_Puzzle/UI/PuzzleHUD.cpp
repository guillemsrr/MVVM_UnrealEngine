// Fill out your copyright notice in the Description page of Project Settings.

#include "PuzzleHUD.h"

#include "Blueprint/UserWidget.h"

void APuzzleHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	ScoreWidget = CreateWidget<UUserWidget>(GetWorld(), ScoreWidgetClass);
}

void APuzzleHUD::BeginPlay()
{
	Super::BeginPlay();

	ScoreWidget->AddToViewport();
}