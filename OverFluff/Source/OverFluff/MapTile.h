#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

#include "MapTile.generated.h"

UENUM(BlueprintType)
enum class EMapTileType : uint8
{
	Desert,
	Grassland,
	Rocks
};

UCLASS()
class UMapTileData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	EMapTileType TileType;

	UPROPERTY(EditDefaultsOnly)
	float DilationFactor = 1.0f;
};

UCLASS()
class AMapTileActor : public AActor
{
	GENERATED_BODY()

public:
	float GetMapTileDilation();

private:
	UPROPERTY(EditDefaultsOnly)
	UMapTileData* Data;
};