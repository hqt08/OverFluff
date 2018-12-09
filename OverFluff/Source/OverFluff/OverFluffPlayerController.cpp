// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "OverFluffPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "OverFluffCharacter.h"
#include "Engine/World.h"
#include "UnrealNetwork.h"
#include "DrawDebugHelpers.h"
#include "NavigationPath.h"
#include "GameFramework/PawnMovementComponent.h"

AOverFluffPlayerController::AOverFluffPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
	bReplicates = true;
}

void AOverFluffPlayerController::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AOverFluffPlayerController, CurrentLocation);
	DOREPLIFETIME(AOverFluffPlayerController, CurrentRotation);
}

void AOverFluffPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}

	/*if (GetNetMode() == NM_Client)
	{
		if (APawn* const Pawn = GetPawn())
		{
			if (UPawnMovementComponent* const MovementComponent = Pawn->GetMovementComponent())
			{
				if (MovementComponent->IsMovingOnGround())
				{
					SERVER_ValidateMovement();
				}
			}
		}
	}*/
}

void AOverFluffPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AOverFluffPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &AOverFluffPlayerController::OnSetDestinationReleased);

	// support touch devices 
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AOverFluffPlayerController::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AOverFluffPlayerController::MoveToTouchLocation);

	InputComponent->BindAction("ResetVR", IE_Pressed, this, &AOverFluffPlayerController::OnResetVR);
}

void AOverFluffPlayerController::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AOverFluffPlayerController::MoveToMouseCursor()
{
	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	{
		if (AOverFluffCharacter* MyPawn = Cast<AOverFluffCharacter>(GetPawn()))
		{
			if (MyPawn->GetCursorToWorld())
			{
				UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, MyPawn->GetCursorToWorld()->GetComponentLocation());
			}
		}
	}
	else
	{
		// Trace to see what is under the mouse cursor
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);

		if (Hit.bBlockingHit)
		{
			// We hit something, move there
			SetNewMoveDestination(Hit.ImpactPoint);
			SERVER_SetNewMoveDestination(Hit.ImpactPoint);
		}
	}
}

void AOverFluffPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SERVER_SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void AOverFluffPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

bool AOverFluffPlayerController::SERVER_SetNewMoveDestination_Validate(const FVector DestLocation)
{
	return true;
}

void AOverFluffPlayerController::SERVER_SetNewMoveDestination_Implementation(const FVector DestLocation)
{
	APawn* const Pawn = GetPawn();
	if (Pawn)
	{
		float const Distance = FVector::Dist(DestLocation, Pawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
			
			if (UNavigationPath* const NavPath = UAIBlueprintHelperLibrary::GetCurrentPath(this))
			{
				for (auto P : NavPath->PathPoints)
				{
					DrawDebugSphere(GetWorld(), P, 10, 12, FColor::Red, true, 5.0f);
				}
			}
		}
	}
}

bool AOverFluffPlayerController::SERVER_ValidateMovement_Validate()
{
	return true;
}

void AOverFluffPlayerController::SERVER_ValidateMovement_Implementation()
{
	if (APawn* const Pawn = GetPawn())
	{
		CurrentLocation = Pawn->GetActorLocation();
		CurrentRotation = Pawn->GetActorRotation();
	}
}

void AOverFluffPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void AOverFluffPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}

void AOverFluffPlayerController::OnRep_CurrentLocation()
{
	// Do client-side movement correction OnRep
	if (APawn* const Pawn = GetPawn())
	{
		if (Pawn->GetActorLocation() != CurrentLocation)
		{
			Pawn->SetActorLocation(CurrentLocation);
		}
	}
}

void AOverFluffPlayerController::OnRep_CurrentRotation()
{
	// Do client-side movement correction OnRep
	if (APawn* const Pawn = GetPawn())
	{
		if (Pawn->GetActorRotation() != CurrentRotation)
		{
			Pawn->SetActorRotation(CurrentRotation);
		}
	}
}