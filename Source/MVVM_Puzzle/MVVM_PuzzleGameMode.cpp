// Copyright Epic Games, Inc. All Rights Reserved.

#include "MVVM_PuzzleGameMode.h"
#include "MVVM_PuzzlePlayerController.h"
#include "MVVM_PuzzlePawn.h"

AMVVM_PuzzleGameMode::AMVVM_PuzzleGameMode()
{
	// no pawn by default
	DefaultPawnClass = AMVVM_PuzzlePawn::StaticClass();
	// use our own player controller class
	PlayerControllerClass = AMVVM_PuzzlePlayerController::StaticClass();
}
