// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "OverFluffInteractibleComponent.h"

#include "UnrealNetwork.h"

#include "MapMgr.h"
#include "OverFluffCharacter.h"
#include "OverFluffDilationBlob.h"
#include "OverFluffGameMode.h"
#include "OverFluffInteractionComponent.h"
#include "OverFluffPlayerController.h"

UOverFluffInteractibleComponent::UOverFluffInteractibleComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UOverFluffInteractibleComponent::ChangeInteractionState(const AOverFluffPlayerController* const PlayerController, EInteractionState State)
{
	if (PlayerController)
	{
		if (const AOverFluffCharacter* const Character = Cast<AOverFluffCharacter>(PlayerController->GetPawn()))
		{
			if (UOverFluffInteractionComponent* const InteractionComponent = Character->FindComponentByClass<UOverFluffInteractionComponent>())
			{
				InteractionComponent->ChangeInteractionState(CurrentInteraction, GetOwner(), State);
			}
		}
	}
}