// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "OverFluffGameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCasualityBroken);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCasualityMaintained);

UCLASS(minimalapi)
class AOverFluffGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	AOverFluffGameState();

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnCasualityBroken OnCasualityBrokenDelegate;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnCasualityMaintained OnCasualityMaintainedDelegate;
};



