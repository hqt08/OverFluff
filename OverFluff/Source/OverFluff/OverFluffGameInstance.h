#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"
#include "Online.h"
#include "FindSessionsCallbackProxy.h"

#include "OverFluffGameInstance.generated.h"


DECLARE_DYNAMIC_DELEGATE_OneParam(FOnSearchSessionsComplete, const TArray<FBlueprintSessionResult>&, Results);

UCLASS(Blueprintable, BlueprintType)
class UOverFluffGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	/**
	*	Host a game session (see https://wiki.unrealengine.com/How_To_Use_Sessions_In_C%2B%2B)
	*	@Param		UserID			User that started the request
	*	@Param		SessionName		Name of the Session
	*	@Param		bIsLAN			Is this is LAN Game?
	*	@Param		bIsPresence		"Is the Session to create a presence Session"
	*	@Param		MaxNumPlayers	Number of Maximum allowed players on this "Session" (Server)
	*/
	UFUNCTION(BlueprintCallable)
	void RequestHostSession(const APlayerController* const PlayerController, FName SessionName, bool bIsLAN, bool bIsPresence, int32 MaxNumPlayers);

	UFUNCTION(BlueprintCallable)
	void RequestFindSessions(const APlayerController* const PlayerController, bool bIsLAN, bool bIsPresence, FOnSearchSessionsComplete OnComplete);

	UFUNCTION(BlueprintCallable)
	void RequestJoinSession(APlayerController* const PlayerController, FName SessionName, const FBlueprintSessionResult& SearchResultBP);
};
