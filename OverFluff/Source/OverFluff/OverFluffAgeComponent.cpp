// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "OverFluffAgeComponent.h"

#include "UnrealNetwork.h"

#include "MapMgr.h"
#include "OverFluffCharacter.h"
#include "OverFluffDilationBlob.h"
#include "OverFluffGameMode.h"
#include "OverFluffPlayerController.h"

UOverFluffAgeComponent::UOverFluffAgeComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bReplicates = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UOverFluffAgeComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UOverFluffAgeComponent, CurrentAge);
	DOREPLIFETIME(UOverFluffAgeComponent, CurrentDilation);
}

void UOverFluffAgeComponent::IncrementAge(const float Amt)
{
	if (GetOwnerRole() == ROLE_Authority)
	{
		CurrentAge += Amt;

		if (CurrentAge >= MaxAge)
		{
			// DEAD!
			OnTooFreakingOldDelegate.Broadcast();
		}
	}
}

void UOverFluffAgeComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (GetOwnerRole() == ROLE_Authority)
	{
		if (const AOverFluffGameMode* const GameMode = Cast<AOverFluffGameMode>(GetWorld()->GetAuthGameMode()))
		{
			if (const UMapMgr* const MapMgr = GameMode->GetMapManager())
			{
				if (const AOverFluffCharacter* const Character = Cast<AOverFluffCharacter>(GetOwner()))
				{
					if (AMapTileActor* const MapTile = MapMgr->QueryForCurrentTile(Character))
					{
						CurrentDilation = MapTile->GetMapTileDilation();
					}
				}
			}
		}

		const float AdjustedAmt = DeltaTime * StandardScalingFactor * CurrentDilation;
		IncrementAge(AdjustedAmt);
	}
}

void UOverFluffAgeComponent::OnRep_CurrentAge()
{
	if (CurrentAge >= MaxAge)
	{
		// DEAD!
		OnTooFreakingOldDelegate.Broadcast();
	}
}