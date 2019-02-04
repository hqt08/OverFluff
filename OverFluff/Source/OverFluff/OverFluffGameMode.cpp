// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "OverFluffGameMode.h"

#include "UObject/ConstructorHelpers.h"

#include "MapMgr.h"
#include "OverFluffPlayerController.h"
#include "OverFluffCharacter.h"

AOverFluffGameMode::AOverFluffGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AOverFluffPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/OverFluff/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AOverFluffGameMode::CreateMap(const float HeightPerTile, const float WidthPerTile, const int32 TotalTilesX, const int32 TotalTilesY)
{
	if (MapManager)
	{
		MapManager->CreateMap(GetWorld(), HeightPerTile, WidthPerTile, TotalTilesX, TotalTilesY);
	}
}
