// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "OverFluffInteractionComponent.h"

#include "UnrealNetwork.h"

#include "MapMgr.h"
#include "OverFluffCharacter.h"
#include "OverFluffDilationBlob.h"
#include "OverFluffGameMode.h"
#include "OverFluffPlayerController.h"

UOverFluffInteractionComponent::UOverFluffInteractionComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bReplicates = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UOverFluffInteractionComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UOverFluffInteractionComponent, CurrentInteraction);
	DOREPLIFETIME(UOverFluffInteractionComponent, CurrentState);
	DOREPLIFETIME(UOverFluffInteractionComponent, CurrentActor);
}

void UOverFluffInteractionComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UOverFluffInteractionComponent::ChangeInteractionState(EInteractionType InteractionType, AActor* InteractibleActor, EInteractionState State)
{
	if (InteractibleActor)
	{
		if (CurrentInteraction == InteractionType)
		{
			SERVER_ChangeInteractionState(InteractionType, State, InteractibleActor);
		}
		else
		{
			// Resolve/Terminate previous interaction if relevant

			SERVER_ChangeInteractionState(InteractionType, State, InteractibleActor);
		}
	}	
}

bool UOverFluffInteractionComponent::SERVER_ChangeInteractionState_Validate(EInteractionType InteractionType, EInteractionState State, AActor* InteractibleActor)
{
	return true;
}

void UOverFluffInteractionComponent::SERVER_ChangeInteractionState_Implementation(EInteractionType InteractionType, EInteractionState State, AActor* InteractibleActor)
{
	CurrentInteraction = InteractionType;
	CurrentState = State;
	CurrentActor = InteractibleActor;

	// Server-side
	OnInteractionStateChangedDelegate.Broadcast(CurrentInteraction, CurrentState, CurrentActor);
}

void UOverFluffInteractionComponent::OnRep_CurrentState()
{

}

EInteractionState UOverFluffInteractionComponent::GetNextState(EInteractionType InteractionType)
{
	switch (CurrentState)
	{
		case EInteractionState::None:
			return EInteractionState::Viewable;
		case EInteractionState::Viewable:
			return EInteractionState::Interacting;
		case EInteractionState::Interacting:
			return EInteractionState::Finished;
		case EInteractionState::Finished:
			return EInteractionState::Viewable;
		default:
			return EInteractionState::None;
	}
}