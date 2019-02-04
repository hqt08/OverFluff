#include "MapMgr.h"

#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"

#include "OverFluffCharacter.h"

UMapMgr::UMapMgr(const FObjectInitializer & ObjectInitializer)
	:Super(ObjectInitializer)
{

}

void UMapMgr::CreateMap(UWorld* World, const float HeightPerTile, const float WidthPerTile, const int32 TotalTilesX, const int32 TotalTilesY)
{
	if (World)
	{
		for (int32 x = 0; x < TotalTilesX; ++x)
		{
			for (int32 y = 0; y < TotalTilesY; ++y)
			{
				TSubclassOf<AActor> FoundActor = RollForTile();
				if (FoundActor.Get())
				{
					FVector Origin;
					if (bDefineStartPoint)
					{
						// Use predefined start point
						Origin = StartPoint;
					}
					else
					{
						// Use Player as midpoint for dynamic tile spawn
						if (const APlayerController* const PlayerController = World->GetFirstPlayerController())
						{
							if (const APawn* const Pawn = PlayerController->GetPawn())
							{
								Origin = Pawn->GetActorLocation();
								Origin.X = Origin.X - 0.5f * (TotalTilesX - 1) * WidthPerTile;
								Origin.Y = Origin.Y - 0.5f * (TotalTilesY - 1) * HeightPerTile;
								Origin.Z = 0.0f;
							}
						}
					}

					const FVector WorldLocation = Origin + FVector(x*WidthPerTile, y*HeightPerTile, 0.0f);
					World->SpawnActor<AActor>(FoundActor.Get(), WorldLocation, FRotator::ZeroRotator);
				}
			}
		}

		// Rebuild navigation after generation map procedually
		// Not completely sure why unreal's default dynamic nav mesh rebuild doesn't handle this reliably
		if (UNavigationSystemV1* NavSys = Cast<UNavigationSystemV1>(World->GetNavigationSystem()))
		{
			NavSys->Build();
		}

		OnLevelSpawnedDelegate.Broadcast();
	}
}

const float UMapMgr::GetTotalWeight()
{
	if (FoundTotalWeight)
	{
		return CachedTotalWeight;
	}

	float TotalWeight = 0.0f;
	for (const auto& Entry : MapEntries)
	{
		TotalWeight += Entry.Weight;
	}

	FoundTotalWeight = true;
	CachedTotalWeight = TotalWeight;

	return TotalWeight;
}

TSubclassOf<AActor> UMapMgr::RollForTile()
{
	const float Roll = FMath::RandRange(0.0f, 1.0f) * GetTotalWeight();
	float CurrentWeight = 0.0f;
	TSubclassOf<AActor> FoundActor;
	int32 EntryIdx = 0;
	while (CurrentWeight < Roll && EntryIdx < MapEntries.Num())
	{
		CurrentWeight += MapEntries[EntryIdx].Weight;

		if (CurrentWeight >= Roll)
		{
			FoundActor = MapEntries[EntryIdx].MapActor;
			return FoundActor;
		}

		EntryIdx++;
	}

	return FoundActor;
}

AMapTileActor* UMapMgr::QueryForCurrentTile(const AOverFluffCharacter* const Character) const
{
	if (Character)
	{
		FCollisionQueryParams TraceParams(FName(TEXT("RV_Trace")), true, Character);
		TraceParams.bTraceComplex = true;
		TraceParams.bTraceAsyncScene = false;
		TraceParams.bReturnPhysicalMaterial = false;

		//Re-initialize hit info
		FHitResult HitResult(ForceInit);

		const FVector Origin = Character->GetActorLocation();
		const FVector End = Origin - Character->GetActorUpVector() * 100.0f;

		/*DrawDebugLine(
			GetWorld(),
			Origin,
			End,
			FColor(255, 0, 0),
			false, -1, 0,
			12.333
		);*/

		//call GetWorld() from within an actor extending class
		GetWorld()->LineTraceSingleByChannel(
			HitResult,
			Origin,
			End,
			ECC_Pawn, //collision channel
			TraceParams
		);

		if (HitResult.bBlockingHit)
		{
			if (AMapTileActor* const MapTile = Cast<AMapTileActor>(HitResult.GetActor()))
			{
				return MapTile;
			}
		}
	}

	return nullptr;
}