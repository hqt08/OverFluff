// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "OverFluffMovementComponent.generated.h"

class AOverFluffDilationBlob;
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

	void SetShooting(bool bShooting);

protected:
	//BEGIN UCharacterMovementComponent Interface
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	virtual bool ClientUpdatePositionAfterServerUpdate() override;
	virtual void PerformMovement(float DeltaTime) override;
	virtual void UpdateFromCompressedFlags(uint8 Flags) override;
	//END UCharacterMovementComponent Interface

private:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

public:
	// For Warp Shooting Ability
	uint8 bWantsToShoot : 1;

private:
	bool bIsMoving = false;
	FVector TargetLoc;
	const float Speed = 10.0f;

	UPROPERTY(EditAnywhere)
	float DilationFactor = 0.2f;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AOverFluffDilationBlob> BlobClass;

	TWeakObjectPtr<AOverFluffDilationBlob> CurrentBlob;

	TMap<WaypointNode, WaypointPath> SearchFrontier;
	TMap<WaypointNode, WaypointPath> SPT; //ShortestPathTree
};

class FSavedMove_WarpShoot : public FSavedMove_Character
{
public:

	typedef FSavedMove_Character Super;

	///@brief Resets all saved variables.
	virtual void Clear() override;

	///@brief Store input commands in the compressed flags.
	virtual uint8 GetCompressedFlags() const override;

	///@brief This is used to check whether or not two moves can be combined into one.
	///Basically you just check to make sure that the saved variables are the same.
	virtual bool CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* Character, float MaxDelta) const override;

	///@brief Sets up the move before sending it to the server. 
	virtual void SetMoveFor(ACharacter* Character, float InDeltaTime, FVector const& NewAccel, class FNetworkPredictionData_Client_Character & ClientData) override;
	///@brief Sets variables on character movement component before making a predictive correction.
	virtual void PrepMoveFor(class ACharacter* Character) override;

	uint8 bSavedWantsToShoot : 1;
};

