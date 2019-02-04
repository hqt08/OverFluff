// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "OverFluffGameMode.generated.h"

UCLASS(minimalapi)
class AOverFluffGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AOverFluffGameMode();

public:
	UFUNCTION(BlueprintCallable)
	void CreateMap(const float HeightPerTile, const float WidthPerTile, const int32 TotalTilesX, const int32 TotalTilesY);

	UFUNCTION(BlueprintCallable)
	class UMapMgr* GetMapManager() const { return MapManager; }

private:
	UPROPERTY(EditAnywhere, Instanced)
	class UMapMgr* MapManager;
};



