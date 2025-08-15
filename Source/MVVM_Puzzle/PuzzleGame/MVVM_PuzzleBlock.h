// Copyright (c) Guillem Serra. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MVVM_PuzzleBlock.generated.h"

UCLASS(minimalapi, Abstract)
class AMVVM_PuzzleBlock : public AActor
{
	GENERATED_BODY()

	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* DummyRoot;

	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* BlockMesh;

public:
	AMVVM_PuzzleBlock();

	bool bIsActive;

	UPROPERTY(EditDefaultsOnly)
	class UMaterial* BaseMaterial;

	UPROPERTY(EditDefaultsOnly)
	class UMaterialInstance* BlueMaterial;

	UPROPERTY(EditDefaultsOnly)
	class UMaterialInstance* OrangeMaterial;

	UPROPERTY()
	class AMVVM_PuzzleBlockGrid* OwningGrid;

	UFUNCTION()
	void BlockClicked(UPrimitiveComponent* ClickedComp, FKey ButtonClicked);

	UFUNCTION()
	void OnFingerPressedBlock(ETouchIndex::Type FingerIndex, UPrimitiveComponent* TouchedComponent);

	void HandleClicked();

	void Highlight(bool bOn);

public:
	FORCEINLINE class USceneComponent* GetDummyRoot() const
	{
		return DummyRoot;
	}

	FORCEINLINE class UStaticMeshComponent* GetBlockMesh() const
	{
		return BlockMesh;
	}
};