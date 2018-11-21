// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "OverFluffGameMode.h"
#include "OverFluffPlayerController.h"
#include "OverFluffCharacter.h"
#include "UObject/ConstructorHelpers.h"

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