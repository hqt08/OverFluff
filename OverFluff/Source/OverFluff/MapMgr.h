#pragma once

#include "CoreMinimal.h"

#include "MapTile.h"
#include "OverFluffGameInstance.h"

#include "MapMgr.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLevelSpawned);

USTRUCT()
struct FMapEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> MapActor;

	UPROPERTY(EditAnywhere)
	float Weight;
};

UCLASS(EditInlineNew, DefaultToInstanced, BlueprintType, Blueprintable)
class UMapMgr : public UObject
{
	GENERATED_BODY()

public:
	UMapMgr(const FObjectInitializer & ObjectInitializer);

	UFUNCTION(BlueprintCallable)
	void CreateMap(UWorld* World, const float HeightPerTile, const float WidthPerTile, const int32 TotalTilesX, const int32 TotalTilesY);

	UFUNCTION(BlueprintCallable)
	AMapTileActor* QueryForCurrentTile(const class AOverFluffCharacter* const Character) const;

public:
	UPROPERTY(BlueprintAssignable)
	FOnLevelSpawned OnLevelSpawnedDelegate;

private:
	const float GetTotalWeight();
	TSubclassOf<AActor> RollForTile();

private:
	UPROPERTY(EditDefaultsOnly)
	TArray<FMapEntry> MapEntries;

	UPROPERTY(EditDefaultsOnly)
	bool bDefineStartPoint = false;

	UPROPERTY(EditDefaultsOnly, meta = (EditCondition = "bDefineStartPoint"))
	FVector StartPoint;

	bool FoundTotalWeight = false;
	float CachedTotalWeight = 0.0f;
};