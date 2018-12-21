// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OverFluffWaypoint.generated.h"

UCLASS(Blueprintable)
class AOverFluffWaypoint : public AActor
{
	GENERATED_BODY()

public:
	AOverFluffWaypoint();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	const TArray<const AOverFluffWaypoint*>& GetNeighbors() const { return Neighbors; }

private:
	UPROPERTY(EditAnywhere, Category = "Waypoints")
	TArray<const AOverFluffWaypoint*> Neighbors;
};

