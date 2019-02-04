// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OverFluffDilationBlob.generated.h"

UCLASS(Blueprintable)
class AOverFluffDilationBlob : public AActor
{
	GENERATED_BODY()

public:
	AOverFluffDilationBlob();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere)
	float DilationWeight = 0.2f;

	UPROPERTY(EditAnywhere)
	float DilationRadius = 500.0f;
};

