// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MVVM_PuzzleBlock.generated.h"

UCLASS(minimalapi, Abstract)
class AMVVM_PuzzleBlock : public AActor
{
	GENERATED_BODY()

protected:
	AMVVM_PuzzleBlock();

public:
	UPROPERTY()
	class AMVVM_PuzzleBlockGrid* OwningGrid;

	void HandleClicked();
	void Highlight(bool bOn);
	void ResetBlock();

protected:
	UPROPERTY(EditDefaultsOnly)
	UMaterial* BaseMaterial;

	UPROPERTY(EditDefaultsOnly)
	UMaterialInstance* HighlightMaterial;

	UPROPERTY(EditDefaultsOnly)
	UMaterialInstance* SelectedMaterial;

	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USceneComponent* DummyRoot;

	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BlockMesh;

private:
	bool bIsActive;

	UFUNCTION()
	void BlockClicked(UPrimitiveComponent* ClickedComp, FKey ButtonClicked);

	UFUNCTION()
	void OnFingerPressedBlock(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent);
};