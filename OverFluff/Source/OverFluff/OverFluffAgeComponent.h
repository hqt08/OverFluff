// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "OverFluffAgeComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTooFreakingOld);

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UOverFluffAgeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UOverFluffAgeComponent(const FObjectInitializer& ObjectInitializer);
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	float GetCurrentAge() const { return CurrentAge; }

	UFUNCTION(BlueprintCallable)
	float GetCurrentDilation() const { return CurrentDilation; }

	UFUNCTION()
	void OnRep_CurrentAge();

public:
	UPROPERTY(BlueprintAssignable)
	FOnTooFreakingOld OnTooFreakingOldDelegate;

private:
	void IncrementAge(const float Amt);

private:
	UPROPERTY(ReplicatedUsing = OnRep_CurrentAge)
	float CurrentAge = 0.0f;

	UPROPERTY(Replicated)
	float CurrentDilation = 1.0f;

	UPROPERTY(EditDefaultsOnly)
	float StandardScalingFactor = 1.0f;

	UPROPERTY(EditDefaultsOnly)
	float MaxAge = 100.0f;
};