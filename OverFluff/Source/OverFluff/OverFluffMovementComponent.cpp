// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "OverFluffMovementComponent.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "UnrealNetwork.h"
#include "DrawDebugHelpers.h"
#include "NavigationPath.h"

#include "OverFluffCharacter.h"
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
	if (GetOwnerRole() != ROLE_Authority)
	{   
		// Main place where the local "blackhole time dilation" effect is happening
		Velocity = DilationFactor * Velocity;
	}

	Super::PerformMovement(DeltaTime);
}

void UOverFluffMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	if (GetOwnerRole() == ROLE_Authority)
	{
		Super::RequestDirectMove(MoveVelocity, bForceMaxSpeed);
	}
	else
	{
		Super::RequestDirectMove(MoveVelocity * DilationFactor, bForceMaxSpeed);
	}
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