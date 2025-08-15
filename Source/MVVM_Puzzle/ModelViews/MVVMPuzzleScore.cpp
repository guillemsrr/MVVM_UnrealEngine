// Copyright (c) Guillem Serra. All Rights Reserved.

#include "MVVMPuzzleScore.h"

void UMVVMPuzzleScore::SetScore(int32 InScore)
{
	if (UE_MVVM_SET_PROPERTY_VALUE(Score, InScore))
	{
		UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetScore);
	}
}

void UMVVMPuzzleScore::ResetScore()
{
	UE_MVVM_SET_PROPERTY_VALUE(Score, 0);
}