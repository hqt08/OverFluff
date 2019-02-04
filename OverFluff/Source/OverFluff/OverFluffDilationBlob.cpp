// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "OverFluffDilationBlob.h"

#include "OverFluffCharacter.h"

AOverFluffDilationBlob::AOverFluffDilationBlob()
{
	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void AOverFluffDilationBlob::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}
