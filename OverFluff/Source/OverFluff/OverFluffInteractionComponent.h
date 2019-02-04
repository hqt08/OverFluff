// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "OverFluffInteractibleComponent.h"

#include "OverFluffInteractionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnInteractionStateChanged, EInteractionType, InteractionType, EInteractionState, State, AActor*, InteractibleActor);

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UOverFluffInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UOverFluffInteractionComponent(const FObjectInitializer& ObjectInitializer);
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	void ChangeInteractionState(EInteractionType InteractionType, AActor* InteractibleActor, EInteractionState State);

	UFUNCTION(Server, Reliable, WithValidation)
	void SERVER_ChangeInteractionState(EInteractionType InteractionType, EInteractionState State, AActor* InteractibleActor);

	UFUNCTION()
	void OnRep_CurrentState();

private:
	EInteractionState GetNextState(EInteractionType InteractionType);

public:
	UPROPERTY(BlueprintAssignable)
	FOnInteractionStateChanged OnInteractionStateChangedDelegate;

private:
	UPROPERTY(Replicated)
	EInteractionType CurrentInteraction = EInteractionType::None;

	UPROPERTY(ReplicatedUsing = OnRep_CurrentState)
	EInteractionState CurrentState = EInteractionState::None;

	UPROPERTY(Replicated)
	AActor* CurrentActor;
};