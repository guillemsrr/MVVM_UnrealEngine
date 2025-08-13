// Copyright Epic Games, Inc. All Rights Reserved.

#include "MVVM_PuzzleGameMode.h"

#include "MVVM_Puzzle/Player/MVVM_PuzzlePawn.h"
#include "MVVM_Puzzle/Player/MVVM_PuzzlePlayerController.h"

AMVVM_PuzzleGameMode::AMVVM_PuzzleGameMode()
{
	DefaultPawnClass = AMVVM_PuzzlePawn::StaticClass();
	PlayerControllerClass = AMVVM_PuzzlePlayerController::StaticClass();
}
