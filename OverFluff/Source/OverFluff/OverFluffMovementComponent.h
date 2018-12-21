// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "OverFluffMovementComponent.generated.h"

class AOverFluffWaypoint;

/**
 * Custom Priority Queue for path finding algorithm
 */
struct WaypointNode
{
	explicit WaypointNode() {};

	float Weight = 1.0f;

	const AOverFluffWaypoint* Waypoint = nullptr;

	friend bool operator==(const WaypointNode& First, const WaypointNode& Second)
	{
		return First.Waypoint == Second.Waypoint;
	}

	friend uint32 GetTypeHash(const WaypointNode& Other)
	{
		return GetTypeHash(Other.Waypoint);
	}
};

struct WaypointPath
{
	explicit WaypointPath();

	float Weight = 1.0f;

	const AOverFluffWaypoint* WaypointStart = nullptr;
	const AOverFluffWaypoint* WaypointEnd = nullptr;

	static float CalculatePathWeight(const AOverFluffWaypoint& WaypointA, const AOverFluffWaypoint& WaypointB);

	friend bool operator==(const WaypointPath& First, const WaypointPath& Second)
	{
		return First.WaypointStart == Second.WaypointStart && First.WaypointEnd == Second.WaypointEnd && First.Weight == Second.Weight;
	}

	friend uint32 GetTypeHash(const WaypointPath& Other)
	{
		return GetTypeHash(Other.WaypointStart);
	}
};

struct WaypointNodePredicate
{
	bool operator()(const WaypointNode& A, const WaypointNode& B) const
	{
		return A.Weight < B.Weight;
	}
};

/**
 * Main Pathing Component
 */
UENUM(BlueprintType)
enum class EMovementType : uint8
{
	MT_Idle 	UMETA(DisplayName = "Idle"),
	MT_Moving 	UMETA(DisplayName = "Moving"),
	MT_Slowing	UMETA(DisplayName = "Slowing")
};

UCLASS(Blueprintable, BlueprintType)
class UOverFluffMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UOverFluffMovementComponent(const FObjectInitializer& ObjectInitializer);

	void SetMoveToLocation(const FVector& Loc);

	// Uses simple Dijkstra at the moment
	TArray<WaypointPath> FindPath(const AOverFluffWaypoint& WaypointA, const AOverFluffWaypoint& WaypointB);

	UFUNCTION(BlueprintCallable, Category = Debug)
	void DrawPath(const AOverFluffWaypoint* WaypointA, const AOverFluffWaypoint* WaypointB);

	// Make use of existing FSavedMove frames to do custom-time replay of movement
	void ReplayMovementFrames();

	virtual void CalcVelocity(float DeltaTime, float Friction, bool bFluid, float BrakingDeceleration) override;

protected:
	//BEGIN UCharacterMovementComponent Interface
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	virtual bool ClientUpdatePositionAfterServerUpdate() override;
	virtual void PerformMovement(float DeltaTime) override;
	//END UCharacterMovementComponent Interface

private:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

private:
	bool bIsMoving = false;
	FVector TargetLoc;
	const float Speed = 10.0f;
	const float DilationFactor = 0.2f;

	TMap<WaypointNode, WaypointPath> SearchFrontier;
	TMap<WaypointNode, WaypointPath> SPT; //ShortestPathTree
};


