// Copyright Epic Games, Inc. All Rights Reserved.

#include "MVVM_PuzzlePlayerController.h"

AMVVM_PuzzlePlayerController::AMVVM_PuzzlePlayerController()
{
	bShowMouseCursor = true;
	bEnableClickEvents = true;
	bEnableTouchEvents = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}
