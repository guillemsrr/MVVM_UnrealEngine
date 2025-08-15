// Copyright (c) Guillem Serra. All Rights Reserved.

#include "MVVMPuzzleScore.h"

void UMVVMPuzzleScore::SetScore(int32 InScore)
{
	if (InScore < 0)
	{
		return;
	}

	if (UE_MVVM_SET_PROPERTY_VALUE(Score, InScore))
	{
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetScore);
	}
}

void UMVVMPuzzleScore::ResetScore()
{
	SetScore(0);
	OnResetRequested.Broadcast();
}

void UMVVMPuzzleScore::IncreaseScore()
{
	SetScore(Score + 1);
}

void UMVVMPuzzleScore::DecreaseScore()
{
	SetScore(Score - 1);
}