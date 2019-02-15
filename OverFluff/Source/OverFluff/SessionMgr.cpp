#include "SessionMgr.h"

#include "OnlineSubsystemUtils.h"

USessionMgr* USessionMgr::Mgr = nullptr;

USessionMgr* USessionMgr::Get()
{
	if (Mgr == nullptr)
	{
		Mgr = NewObject<USessionMgr>();
	}

	return Mgr;
}

USessionMgr::USessionMgr(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	/** Bind function for CREATING a Session */
	OnCreateSessionCompleteDelegate = FOnCreateSessionCompleteDelegate::CreateUObject(this, &USessionMgr::OnCreateSessionComplete);
	OnStartSessionCompleteDelegate = FOnStartSessionCompleteDelegate::CreateUObject(this, &USessionMgr::OnStartOnlineGameComplete);

	/** Bind function for FINDING a Session */
	OnFindSessionsCompleteDelegate = FOnFindSessionsCompleteDelegate::CreateUObject(this, &USessionMgr::OnSearchSessionsComplete);

	/** Bind function for JOINING a Session */
	OnJoinSessionCompleteDelegate = FOnJoinSessionCompleteDelegate::CreateUObject(this, &USessionMgr::OnJoinSessionComplete);

	/** Bind function for JOINING a Session */
	OnDestroySessionCompleteDelegate = FOnDestroySessionCompleteDelegate::CreateUObject(this, &USessionMgr::OnDestroySessionComplete);
}

USessionMgr::~USessionMgr()
{
	SessionSearch = nullptr;
	Mgr = nullptr;
}

bool USessionMgr::CreateSession(const UWorld* World, TSharedPtr<const FUniqueNetId> UserId, FName SessionName, bool bIsLAN, bool bIsPresence, int32 MaxNumPlayers, TFunction<void()> OnSuccess)
{
	if (IOnlineSubsystem* const OnlineSubsystem = IOnlineSubsystem::Get())
	{
		IOnlineSessionPtr SessionInterface = OnlineSubsystem->GetSessionInterface();
		if (SessionInterface.IsValid() && UserId.IsValid())
		{
			TSharedPtr<class FOnlineSessionSettings> SessionSettings = MakeShareable(new FOnlineSessionSettings());

			SessionSettings->bIsLANMatch = bIsLAN;
			SessionSettings->bUsesPresence = bIsPresence;
			SessionSettings->bIsDedicated = false;
			SessionSettings->NumPublicConnections = MaxNumPlayers;
			SessionSettings->NumPrivateConnections = 0;
			SessionSettings->bAllowInvites = true;
			SessionSettings->bAllowJoinInProgress = true;
			SessionSettings->bShouldAdvertise = true;
			SessionSettings->bAllowJoinViaPresence = true;
			SessionSettings->bAllowJoinViaPresenceFriendsOnly = false;
			
			// Set the session map
			SessionSettings->Set(SETTING_MAPNAME, FString("OverFluffMap"), EOnlineDataAdvertisementType::ViaOnlineService);

			// Set the session name
			FOnlineSessionSetting compoundSessionName;
			compoundSessionName.AdvertisementType = EOnlineDataAdvertisementType::ViaOnlineService;
			compoundSessionName.Data = *SessionName.ToString();
			SessionSettings->Settings.Add(FName("SESSION_NAME"), compoundSessionName);

			// Set the delegate to the Handle of the SessionInterface
			OnCreateSessionCompleteDelegateHandle = SessionInterface->AddOnCreateSessionCompleteDelegate_Handle(OnCreateSessionCompleteDelegate);
			OnCreateSuccess = OnSuccess;

			return SessionInterface->CreateSession(*UserId, SessionName, *SessionSettings);
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, TEXT("No OnlineSubsytem found!"));
	}

	return false;
}

void USessionMgr::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("OnCreateSessionComplete %s, %d"), *SessionName.ToString(), bWasSuccessful));

	if (IOnlineSubsystem* const OnlineSubsystem = IOnlineSubsystem::Get())
	{
		IOnlineSessionPtr SessionInterface = OnlineSubsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			// Clear the SessionComplete delegate handle, since we finished this call
			SessionInterface->ClearOnCreateSessionCompleteDelegate_Handle(OnCreateSessionCompleteDelegateHandle);
			if (bWasSuccessful)
			{
				// Set the StartSession delegate handle
				OnStartSessionCompleteDelegateHandle = SessionInterface->AddOnStartSessionCompleteDelegate_Handle(OnStartSessionCompleteDelegate);

				// Our StartSessionComplete delegate should get called after this
				SessionInterface->StartSession(SessionName);
			}
		}
	}
}

void USessionMgr::OnStartOnlineGameComplete(FName SessionName, bool bWasSuccessful)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("OnStartSessionComplete %s, %d"), *SessionName.ToString(), bWasSuccessful));

	if (IOnlineSubsystem* const OnlineSubsystem = IOnlineSubsystem::Get())
	{
		IOnlineSessionPtr SessionInterface = OnlineSubsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			// Clear the delegate, since we are done with this call
			SessionInterface->ClearOnStartSessionCompleteDelegate_Handle(OnStartSessionCompleteDelegateHandle);
		}
	}

	if (bWasSuccessful)
	{
		OnCreateSuccess();
		SessionSearch = nullptr;
	}
}

bool USessionMgr::JoinSession(const UWorld* World, TSharedPtr<const FUniqueNetId> UserId, FName SessionName, const FOnlineSessionSearchResult& SearchResult, TFunction<void(IOnlineSessionPtr SessionInterface)> OnComplete)
{
	bool bSuccessful = false;

	if (IOnlineSubsystem* const OnlineSubsystem = IOnlineSubsystem::Get() /*Online::GetSubsystem(World)*/)
	{
		IOnlineSessionPtr SessionInterface = OnlineSubsystem->GetSessionInterface();
		if (SessionInterface.IsValid() && UserId.IsValid())
		{
			OnJoinSessionCompleteDelegateHandle = SessionInterface->AddOnJoinSessionCompleteDelegate_Handle(OnJoinSessionCompleteDelegate);
			OnJoinComplete = OnComplete;
			bSuccessful = SessionInterface->JoinSession(*UserId, SessionName, SearchResult);
		}
	}

	return bSuccessful;
}

void USessionMgr::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("OnJoinSessionComplete %s, %d"), *SessionName.ToString(), static_cast<int32>(Result)));

	if (IOnlineSubsystem* const OnlineSubsystem = IOnlineSubsystem::Get())
	{
		IOnlineSessionPtr SessionInterface = OnlineSubsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			SessionInterface->ClearOnJoinSessionCompleteDelegate_Handle(OnJoinSessionCompleteDelegateHandle);
			OnJoinComplete(SessionInterface);
		}
	}
}

void USessionMgr::SearchSessions(const UWorld* World, TSharedPtr<const FUniqueNetId> UserId, bool bIsLAN, bool bIsPresence, TFunction<void(TSharedPtr<class FOnlineSessionSearch>)> OnComplete)
{
	if (IOnlineSubsystem* const OnlineSubsystem = Online::GetSubsystem(World))
	{
		IOnlineSessionPtr SessionInterface = OnlineSubsystem->GetSessionInterface();

		if (!(SessionSearch.IsValid() && SessionSearch->SearchState == EOnlineAsyncTaskState::InProgress))
		{
			SessionSearch = MakeShareable(new FOnlineSessionSearch());
		}

		if (SessionInterface.IsValid() && UserId.IsValid() && SessionSearch.IsValid())
		{
			SessionSearch->bIsLanQuery = bIsLAN;
			SessionSearch->MaxSearchResults = 20;
			SessionSearch->PingBucketSize = 50;

			if (bIsPresence)
			{
				SessionSearch->QuerySettings.Set(SEARCH_PRESENCE, bIsPresence, EOnlineComparisonOp::Equals);
				SessionSearch->QuerySettings.Set(SEARCH_DEDICATED_ONLY, false, EOnlineComparisonOp::Equals);
			}

			TSharedRef<FOnlineSessionSearch> SearchSettingsRef = SessionSearch.ToSharedRef();
			OnFindSessionsCompleteDelegateHandle.Reset();
			OnFindSessionsCompleteDelegateHandle = SessionInterface->AddOnFindSessionsCompleteDelegate_Handle(OnFindSessionsCompleteDelegate);
			OnSearchComplete = OnComplete;

			SessionInterface->FindSessions(*UserId, SearchSettingsRef);
		}
	}
	else
	{
		OnSearchSessionsComplete(false);
	}
}

void USessionMgr::OnSearchSessionsComplete(bool bWasSuccessful)
{
	//GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("OnSearchSessionsComplete bSuccess: %d"), bWasSuccessful));

	if (IOnlineSubsystem* const OnlineSubsystem = IOnlineSubsystem::Get())
	{
		IOnlineSessionPtr SessionInterface = OnlineSubsystem->GetSessionInterface();
		if (SessionInterface.IsValid() && SessionSearch.IsValid())
		{
			SessionInterface->ClearOnFindSessionsCompleteDelegate_Handle(OnFindSessionsCompleteDelegateHandle);

			GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Num Search Results: %d"), SessionSearch->SearchResults.Num()));

			if (SessionSearch->SearchResults.Num() > 0)
			{
				for (auto SearchResult : SessionSearch->SearchResults)
				{
					// Return/Display the search results here
					FString SessionName = SearchResult.Session.SessionSettings.Settings.FindRef("SESSION_NAME").Data.ToString();
					GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("Session Owner Id: %d | Sessionname: %s "), *(SearchResult.Session.OwningUserId->ToString()), *SessionName));
				}
			}

			OnSearchComplete(SessionSearch);
		}
	}
}


void USessionMgr::DestroySession(const UWorld * World, TSharedPtr<const FUniqueNetId> UserId, FName SessionName)
{
	if (IOnlineSubsystem* const OnlineSubsystem = IOnlineSubsystem::Get() /*Online::GetSubsystem(World)*/)
	{
		IOnlineSessionPtr SessionInterface = OnlineSubsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			OnDestroySessionCompleteDelegateHandle = SessionInterface->AddOnDestroySessionCompleteDelegate_Handle(OnDestroySessionCompleteDelegate);
			SessionInterface->DestroySession(SessionName);
		}
	}
}

void USessionMgr::OnDestroySessionComplete(FName SessionName, bool bWasSuccessful)
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, FString::Printf(TEXT("OnDestroySessionsComplete %s, bSuccess: %d"), *SessionName.ToString(), bWasSuccessful));

	if (IOnlineSubsystem* const OnlineSubsystem = IOnlineSubsystem::Get())
	{
		IOnlineSessionPtr SessionInterface = OnlineSubsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			SessionInterface->ClearOnDestroySessionCompleteDelegate_Handle(OnDestroySessionCompleteDelegateHandle);
		}
	}
}

void USessionMgr::UpdateSession()
{
	
}