<SETUP>

This project should run out of the box with Unreal Engine 4.21 (fork it at https://github.com/EpicGames/UnrealEngine), with one exception 
I customized to allow for simple more useful online subsystem BP functions. Add this to the engine code respectively for the game to run:

In Engine\Plugins\Online\OnlineSubsystemUtils\Source\OnlineSubsystemUtils\Classes\FindSessionsCallbackProxy.h(52):

/* Tammi Tay - 11/13/2018 - Static session search get helper for blueprint read */
UFUNCTION(BlueprintPure, Category = "Online|Session")
static FString GetSessionProperty(const FBlueprintSessionResult& Result, const FName& RefKey);

In Engine\Plugins\Online\OnlineSubsystemUtils\Source\OnlineSubsystemUtils\Private\FindSessionsCallbackProxy.cpp(116):

/* Tammi Tay - 11/13/2018 - Static session search get helper for blueprint read */
FString UFindSessionsCallbackProxy::GetSessionProperty(const FBlueprintSessionResult& Result, const FName& RefKey)
{
	return Result.OnlineResult.Session.SessionSettings.Settings.FindRef(RefKey).Data.ToString();
}

<LOBBY>

LobbyMap.umap is the starting map for you to setup a custom multiplayer session where you type in your own session name, or join an exising
online session. Have fun!
