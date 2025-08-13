// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MVVM_PuzzleGameMode.generated.h"

/** GameMode class to specify pawn and playercontroller */
UCLASS(minimalapi, Abstract)
class AMVVM_PuzzleGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMVVM_PuzzleGameMode();
};



