// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "OverFluffWaypoint.h"

#include "OverFluffCharacter.h"

AOverFluffWaypoint::AOverFluffWaypoint()
{
	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AOverFluffWaypoint::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}
