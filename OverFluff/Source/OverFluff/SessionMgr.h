#pragma once

#include "CoreMinimal.h"
#include "OverFluffGameInstance.h"

#include "SessionMgr.generated.h"

UCLASS()
class USessionMgr : public UObject
{
	GENERATED_BODY()

public:
	// Singleton Pattern
	static USessionMgr* Get();
	USessionMgr(const FObjectInitializer& ObjectInitializer);
	~USessionMgr();

	bool CreateSession(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, bool bIsLAN, bool bIsPresence, int32 MaxNumPlayers, TFunction<void()> OnSuccess);

	bool JoinSession(TSharedPtr<const FUniqueNetId> UserId, FName SessionName, const FOnlineSessionSearchResult& SearchResult, TFunction<void(IOnlineSessionPtr SessionInterface)> OnComplete);

	void DestroySession();

	void SearchSessions(TSharedPtr<const FUniqueNetId> UserId, bool bIsLAN, bool bIsPresence, TFunction<void(TSharedPtr<class FOnlineSessionSearch>)> OnComplete);

	void UpdateSession();

private:
	virtual void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
	void OnStartOnlineGameComplete(FName SessionName, bool bWasSuccessful);

	void OnSearchSessionsComplete(bool bWasSuccessful);

	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

private:
	static USessionMgr* Mgr;

	TSharedPtr<class FOnlineSessionSearch> SessionSearch = nullptr;

	/* Delegate called when session created */
	FOnCreateSessionCompleteDelegate OnCreateSessionCompleteDelegate;
	/* Delegate called when session started */
	FOnStartSessionCompleteDelegate OnStartSessionCompleteDelegate;
	/** Delegate for searching for sessions */
	FOnFindSessionsCompleteDelegate OnFindSessionsCompleteDelegate;
	/** Delegate for joining a session */
	FOnJoinSessionCompleteDelegate OnJoinSessionCompleteDelegate;

	/** Handles to registered delegates for creating/starting a session */
	FDelegateHandle OnCreateSessionCompleteDelegateHandle;
	FDelegateHandle OnStartSessionCompleteDelegateHandle;
	/** Handle to registered delegate for searching a session */
	FDelegateHandle OnFindSessionsCompleteDelegateHandle;
	/** Handle to registered delegate for joining a session */
	FDelegateHandle OnJoinSessionCompleteDelegateHandle;

	/* Callback functions */
	TFunction<void()> OnCreateSuccess;
	TFunction<void(TSharedPtr<class FOnlineSessionSearch>)> OnSearchComplete;
	TFunction<void(IOnlineSessionPtr SessionInterface)> OnJoinComplete;
};
