// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "OverFluffMovementComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "UnrealNetwork.h"
#include "DrawDebugHelpers.h"
#include "NavigationPath.h"

#include "OverFluffAgeComponent.h"
#include "OverFluffCharacter.h"
#include "OverFluffDilationBlob.h"
#include "OverFluffPlayerController.h"
#include "OverFluffWaypoint.h"

WaypointPath::WaypointPath()
{
	if (WaypointStart != nullptr && WaypointEnd != nullptr)
	{
		Weight = CalculatePathWeight(*WaypointStart, *WaypointEnd);
	}
}

float WaypointPath::CalculatePathWeight(const AOverFluffWaypoint & WaypointA, const AOverFluffWaypoint & WaypointB)
{
	return 1.0f;
}

UOverFluffMovementComponent::UOverFluffMovementComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = true;
	bIgnoreClientMovementErrorChecksAndCorrection = true; //NOTE: Switching this on for now until I can stablize the predication taking into account the local "blackhole time dilation" effect
}

void UOverFluffMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bIsMoving)
	{
		if (AOverFluffCharacter* const Pawn = Cast<AOverFluffCharacter>(GetPawnOwner()))
		{
			FVector CurrentLoc = Pawn->GetActorLocation();
			if (CurrentLoc == TargetLoc)
			{
				bIsMoving = false;
			}
			else
			{
				FVector Heading = (TargetLoc - CurrentLoc).GetSafeNormal();
				Pawn->SetActorLocation(CurrentLoc + Heading*Speed);
			}
		}
	}
}

void UOverFluffMovementComponent::SetMoveToLocation(const FVector& Loc)
{
	TargetLoc = Loc;
	bIsMoving = true;
}

TArray<WaypointPath> UOverFluffMovementComponent::FindPath(const AOverFluffWaypoint & WaypointA, const AOverFluffWaypoint & WaypointB)
{
	TArray<WaypointPath> PathFound;

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AOverFluffWaypoint::StaticClass(), FoundActors);
	const int32 NumWaypoints = FoundActors.Num();

	SearchFrontier.Empty();
	SearchFrontier.Reserve(NumWaypoints);
	SPT.Empty();
	SPT.Reserve(NumWaypoints);

	TArray<WaypointNode> PQ;
	WaypointNode InitialNode;
	InitialNode.Waypoint = &WaypointA;
	PQ.HeapPush(InitialNode, WaypointNodePredicate());

	while (PQ.Num() > 0)
	{
		WaypointNode CurrentNode;
		PQ.HeapPop(CurrentNode, WaypointNodePredicate());

		// Move node from frontier to SPT
		if (SearchFrontier.Contains(CurrentNode))
		{
			SPT.Emplace(CurrentNode, SearchFrontier[CurrentNode]);
		}

		// Exit if target found
		if (CurrentNode.Waypoint == &WaypointB)
		{
			// Work backwards from target on SPT to find shortest path
			WaypointNode NextNode = CurrentNode;
			while (NextNode.Waypoint != &WaypointA)
			{
				WaypointPath CurrentPath = SPT[NextNode];
				PathFound.Insert(CurrentPath, 0);

				NextNode.Waypoint = CurrentPath.WaypointStart;
			}

			break;
		}

		// Relax the edges, for each edge connected to current node
		for (const auto NeighborWP : CurrentNode.Waypoint->GetNeighbors())
		{
			if (NeighborWP)
			{
				float NewCost = CurrentNode.Weight + WaypointPath::CalculatePathWeight(*CurrentNode.Waypoint, *NeighborWP);
				WaypointNode NeighborNode;
				NeighborNode.Waypoint = NeighborWP;
				NeighborNode.Weight = 1000000.0f;

				if (auto WPPtr = PQ.FindByPredicate([NeighborWP](const WaypointNode& WP)
				{
					return WP.Waypoint == NeighborWP;
				}))
				{
					NeighborNode.Weight = WPPtr->Weight;
				}

				if (!SearchFrontier.Contains(NeighborNode))
				{
					NeighborNode.Weight = NewCost;

					PQ.Emplace(NeighborNode);

					WaypointPath NeighborPath;
					NeighborPath.WaypointStart = CurrentNode.Waypoint;
					NeighborPath.WaypointEnd = NeighborNode.Waypoint;
					NeighborPath.Weight = NewCost;
					SearchFrontier.Emplace(NeighborNode, NeighborPath);
				}
				else if (NewCost < NeighborNode.Weight && !SPT.Contains(NeighborNode))
				{
					NeighborNode.Weight = NewCost;

					PQ.HeapSort(WaypointNodePredicate());

					WaypointPath NeighborPath;
					NeighborPath.WaypointStart = CurrentNode.Waypoint;
					NeighborPath.WaypointEnd = NeighborNode.Waypoint;
					NeighborPath.Weight = NewCost;
					SearchFrontier.Emplace(NeighborNode, NeighborPath);
				}
			}
		}
	}

	return PathFound;
}

void UOverFluffMovementComponent::DrawPath(const AOverFluffWaypoint* WaypointA, const AOverFluffWaypoint* WaypointB)
{
	if (WaypointA && WaypointB)
	{
		TArray<WaypointPath> Path = FindPath(*WaypointA, *WaypointB);
		for (const auto& p : Path)
		{
			if (p.WaypointStart && p.WaypointEnd)
			{
				FVector LinkStart = p.WaypointStart->GetActorLocation();
				FVector LinkEnd = p.WaypointEnd->GetActorLocation();

				DrawDebugLine(
					GetWorld(),
					LinkStart,
					LinkEnd,
					FColor(255, 0, 0),
					true, 30, 0,
					12.333
				);
			}
		}
	}
}

void UOverFluffMovementComponent::ReplayMovementFrames()
{
	FNetworkPredictionData_Client_Character* ClientData = GetPredictionData_Client_Character();
	if (!ClientData)
	{
		return;
	}

	TArray<FSavedMovePtr>& SavedMoves = ClientData->SavedMoves;
}

void UOverFluffMovementComponent::PerformMovement(float DeltaTime)
{
	if (const AOverFluffCharacter* const Pawn = Cast<AOverFluffCharacter>(GetOwner()))
	{
		if (const AOverFluffPlayerController* const PlayerController = Cast<AOverFluffPlayerController>(Pawn->GetController()))
		{
			if (!PlayerController->IsLocalPlayerController())
			{
				if (const UOverFluffAgeComponent* const AgeComponent = Pawn->FindComponentByClass<UOverFluffAgeComponent>())
				{
					// Main place where the local "blackhole time dilation" effect is happening
					Velocity = AgeComponent->GetCurrentDilation() * Velocity;
				}
			}
		}
	}

	Super::PerformMovement(DeltaTime);
}

void UOverFluffMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	/*if (GetOwnerRole() == ROLE_Authority)
	{*/
		Super::RequestDirectMove(MoveVelocity, bForceMaxSpeed);
	/*}
	else
	{
		Super::RequestDirectMove(MoveVelocity * DilationFactor, bForceMaxSpeed);
	}*/
}

void UOverFluffMovementComponent::CalcVelocity(float DeltaTime, float Friction, bool bFluid, float BrakingDeceleration)
{
	Super::CalcVelocity(DeltaTime, Friction, bFluid, BrakingDeceleration);
}

bool UOverFluffMovementComponent::ClientUpdatePositionAfterServerUpdate()
{
	ReplayMovementFrames();

	return Super::ClientUpdatePositionAfterServerUpdate();
}

/** UOverFluffMovementComponent - Custom Ability Hooks **/
void UOverFluffMovementComponent::SetShooting(bool bShooting)
{
	bWantsToShoot = bShooting;

	if (bWantsToShoot)
	{
		if (AOverFluffCharacter* const Pawn = Cast<AOverFluffCharacter>(GetPawnOwner()))
		{
			if (const APlayerController* const PlayerController = Cast<APlayerController>(Pawn->GetController()))
			{
				FHitResult Hit;
				PlayerController->GetHitResultUnderCursor(ECC_Visibility, false, Hit);

				if (Hit.bBlockingHit)
				{
					if (!CurrentBlob.IsValid())
					{
						FActorSpawnParameters SpawnParams;
						SpawnParams.Instigator = Pawn;
						CurrentBlob = Pawn->GetWorld()->SpawnActor<AOverFluffDilationBlob>(BlobClass.Get(), Hit.Location, FRotator::ZeroRotator, SpawnParams);
						CurrentBlob->SetOwner(CurrentBlob.Get());
					}
					else
					{
						CurrentBlob->SetActorLocation(Hit.Location);
					}
				}
			}
		}

	}
}

void UOverFluffMovementComponent::UpdateFromCompressedFlags(uint8 Flags)
{
	Super::UpdateFromCompressedFlags(Flags);

	//The Flags parameter contains the compressed input flags that are stored in the saved move.
	//UpdateFromCompressed flags simply copies the flags from the saved move into the movement component.
	//It basically just resets the movement component to the state when the move was made so it can simulate from there.
	bWantsToShoot = (Flags&FSavedMove_Character::FLAG_Custom_0) != 0;
}

/** FSavedMove_WarpShoot - Custom WarpShoot Ability **/
void FSavedMove_WarpShoot::SetMoveFor(ACharacter* Character, float InDeltaTime, FVector const& NewAccel, class FNetworkPredictionData_Client_Character& ClientData)
{
	Super::SetMoveFor(Character, InDeltaTime, NewAccel, ClientData);

	UOverFluffMovementComponent* CharMov = Cast<UOverFluffMovementComponent>(Character->GetCharacterMovement());
	if (CharMov)
	{
		//This is literally just the exact opposite of UpdateFromCompressed flags. We're taking the input
		//from the player and storing it in the saved move.
		bSavedWantsToShoot = CharMov->bWantsToShoot;
	}
}

void FSavedMove_WarpShoot::PrepMoveFor(class ACharacter* Character)
{
	Super::PrepMoveFor(Character);
}

void FSavedMove_WarpShoot::Clear()
{
	Super::Clear();

	//Clear variables back to their default values.
	bSavedWantsToShoot = false;
}

//This is where we compress the flags saved in SetMoveFor. We're basically just ORing a bunch of them together.
uint8 FSavedMove_WarpShoot::GetCompressedFlags() const
{
	uint8 Result = Super::GetCompressedFlags();

	if (bSavedWantsToShoot)
	{
		Result |= FLAG_Custom_0;
	}

	return Result;
}

bool FSavedMove_WarpShoot::CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* Character, float MaxDelta) const
{
	//This pretty much just tells the engine if it can optimize by combining saved moves. There doesn't appear to be
	//any problem with leaving it out, but it seems that it's good practice to implement this anyways.
	if (bSavedWantsToShoot != ((FSavedMove_WarpShoot*)&NewMove)->bSavedWantsToShoot)
	{
		return false;
	}

	return Super::CanCombineWith(NewMove, Character, MaxDelta);
}