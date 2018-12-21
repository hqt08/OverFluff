// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "OverFluffPlayerController.generated.h"

UCLASS(Blueprintable, BlueprintType)
class AOverFluffPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AOverFluffPlayerController();

protected:
	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();

	void SetNewMoveDestination(const FVector DestLocation);

	///** Navigate player to the given world location. */
	UFUNCTION(reliable, server, WithValidation)
	void SERVER_SetNewMoveDestination(const FVector DestLocation);

	UFUNCTION(reliable, server, WithValidation)
	void SERVER_ValidateMovement();

	UFUNCTION()
	void OnRep_CurrentLocation();

	UFUNCTION()
	void OnRep_CurrentRotation();

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	UPROPERTY(ReplicatedUsing = OnRep_CurrentLocation)
	FVector CurrentLocation;

	UPROPERTY(ReplicatedUsing = OnRep_CurrentRotation)
	FRotator CurrentRotation;

	UPROPERTY(EditAnywhere)
	float ClickInterval = 0.5f;

	float CurrentClickTime = 0.0f;

	const bool bCheckMovementRep = false;
};



