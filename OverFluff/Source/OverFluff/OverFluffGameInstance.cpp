#include "OverFluffGameInstance.h"

#include "GameFramework/PlayerState.h"
#include "GameFramework/PlayerController.h"

#include "SessionMgr.h"

void UOverFluffGameInstance::RequestHostSession(const APlayerController* const PlayerController, FName SessionName, bool bIsLAN, bool bIsPresence, int32 MaxNumPlayers)
{
	if (PlayerController)
	{
		if (const APlayerState* const PlayerState = PlayerController->PlayerState)
		{
			if (USessionMgr* const SessionMgr = USessionMgr::Get())
			{
				TFunction<void()> OnSuccess = [this]() { UGameplayStatics::OpenLevel(GetWorld(), "OverFluffMap", true, "listen"); };

				const TSharedPtr<const FUniqueNetId>& NetId = PlayerState->UniqueId.GetUniqueNetId();
				SessionMgr->CreateSession(NetId, SessionName, bIsLAN, bIsPresence, MaxNumPlayers, OnSuccess);
			}
		}
	}
}

void UOverFluffGameInstance::RequestFindSessions(const APlayerController* const PlayerController, bool bIsLAN, bool bIsPresence, FOnSearchSessionsComplete OnComplete)
{
	if (PlayerController)
	{
		if (const APlayerState* const PlayerState = PlayerController->PlayerState)
		{
			if (USessionMgr* const SessionMgr = USessionMgr::Get())
			{
				TFunction<void(TSharedPtr<class FOnlineSessionSearch>)> OnSearchComplete = [this, OnComplete](TSharedPtr<class FOnlineSessionSearch> Sessions)
				{
					if (Sessions.IsValid())
					{
						// NOTE: We require this wrapper so that the callback function can be defined dynamically in BP
						TArray<struct FBlueprintSessionResult> BPSessionResults;
						for (auto SearchResult : Sessions->SearchResults)
						{
							struct FBlueprintSessionResult SessionResult;
							SessionResult.OnlineResult = SearchResult;
							BPSessionResults.Emplace(SessionResult);
						}

						OnComplete.ExecuteIfBound(BPSessionResults);
					}
				};

				SessionMgr->SearchSessions(PlayerState->UniqueId.GetUniqueNetId(), bIsLAN, bIsPresence, OnSearchComplete);
			}
		}
	}
}

void UOverFluffGameInstance::RequestJoinSession(APlayerController* const PlayerController, FName SessionName, const FBlueprintSessionResult& SearchResultBP)
{
	if (PlayerController)
	{
		if (const APlayerState* const PlayerState = PlayerController->PlayerState)
		{
			if (USessionMgr* const SessionMgr = USessionMgr::Get())
			{
				TFunction<void(IOnlineSessionPtr SessionInterface)> OnJoinComplete = [PlayerController, &SessionName](IOnlineSessionPtr SessionInterface)
				{
					if (SessionInterface.IsValid())
					{
						FString TravelURL;
						if (PlayerController && SessionInterface->GetResolvedConnectString(SessionName, TravelURL))
						{
							PlayerController->ClientTravel(TravelURL, ETravelType::TRAVEL_Absolute);
						}
					}
				};

				SessionMgr->JoinSession(PlayerState->UniqueId.GetUniqueNetId(), SessionName, SearchResultBP.OnlineResult, OnJoinComplete);
			}
		}
	}
}