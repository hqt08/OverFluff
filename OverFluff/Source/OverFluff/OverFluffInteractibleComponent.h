// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "OverFluffInteractibleComponent.generated.h"

UENUM(BlueprintType)
enum class EInteractionType : uint8
{
	None,
	PickUpTreat,
	KeyInCode,
	FlickSwitch
};

UENUM(BlueprintType)
enum class EInteractionState : uint8
{
	None,
	Viewable,
	Interacting,
	Cancelled,
	Finished
};

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UOverFluffInteractibleComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UOverFluffInteractibleComponent(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintCallable)
	void ChangeInteractionState(const class AOverFluffPlayerController* const PlayerController, EInteractionState State);

private:
	UPROPERTY(EditDefaultsOnly)
	EInteractionType CurrentInteraction = EInteractionType::None;
};