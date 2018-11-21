// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OverFluff/OverFluffGameInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOverFluffGameInstance() {}
// Cross Module References
	OVERFLUFF_API UFunction* Z_Construct_UDelegateFunction_OverFluff_OnSearchSessionsComplete__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_OverFluff();
	ONLINESUBSYSTEMUTILS_API UScriptStruct* Z_Construct_UScriptStruct_FBlueprintSessionResult();
	OVERFLUFF_API UClass* Z_Construct_UClass_UOverFluffGameInstance_NoRegister();
	OVERFLUFF_API UClass* Z_Construct_UClass_UOverFluffGameInstance();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	OVERFLUFF_API UFunction* Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController_NoRegister();
	OVERFLUFF_API UFunction* Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession();
	OVERFLUFF_API UFunction* Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_OverFluff_OnSearchSessionsComplete__DelegateSignature_Statics
	{
		struct _Script_OverFluff_eventOnSearchSessionsComplete_Parms
		{
			TArray<FBlueprintSessionResult> Results;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Results_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Results;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Results_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OverFluff_OnSearchSessionsComplete__DelegateSignature_Statics::NewProp_Results_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UDelegateFunction_OverFluff_OnSearchSessionsComplete__DelegateSignature_Statics::NewProp_Results = { UE4CodeGen_Private::EPropertyClass::Array, "Results", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(_Script_OverFluff_eventOnSearchSessionsComplete_Parms, Results), METADATA_PARAMS(Z_Construct_UDelegateFunction_OverFluff_OnSearchSessionsComplete__DelegateSignature_Statics::NewProp_Results_MetaData, ARRAY_COUNT(Z_Construct_UDelegateFunction_OverFluff_OnSearchSessionsComplete__DelegateSignature_Statics::NewProp_Results_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_OverFluff_OnSearchSessionsComplete__DelegateSignature_Statics::NewProp_Results_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "Results", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FBlueprintSessionResult, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_OverFluff_OnSearchSessionsComplete__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OverFluff_OnSearchSessionsComplete__DelegateSignature_Statics::NewProp_Results,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_OverFluff_OnSearchSessionsComplete__DelegateSignature_Statics::NewProp_Results_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_OverFluff_OnSearchSessionsComplete__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "OverFluffGameInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_OverFluff_OnSearchSessionsComplete__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_OverFluff, "OnSearchSessionsComplete__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00120000, sizeof(_Script_OverFluff_eventOnSearchSessionsComplete_Parms), Z_Construct_UDelegateFunction_OverFluff_OnSearchSessionsComplete__DelegateSignature_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UDelegateFunction_OverFluff_OnSearchSessionsComplete__DelegateSignature_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_OverFluff_OnSearchSessionsComplete__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_OverFluff_OnSearchSessionsComplete__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_OverFluff_OnSearchSessionsComplete__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_OverFluff_OnSearchSessionsComplete__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	void UOverFluffGameInstance::StaticRegisterNativesUOverFluffGameInstance()
	{
		UClass* Class = UOverFluffGameInstance::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "RequestFindSessions", &UOverFluffGameInstance::execRequestFindSessions },
			{ "RequestHostSession", &UOverFluffGameInstance::execRequestHostSession },
			{ "RequestJoinSession", &UOverFluffGameInstance::execRequestJoinSession },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics
	{
		struct OverFluffGameInstance_eventRequestFindSessions_Parms
		{
			const APlayerController* PlayerController;
			bool bIsLAN;
			bool bIsPresence;
			FScriptDelegate OnComplete;
		};
		static const UE4CodeGen_Private::FDelegatePropertyParams NewProp_OnComplete;
		static void NewProp_bIsPresence_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsPresence;
		static void NewProp_bIsLAN_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsLAN;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerController_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::NewProp_OnComplete = { UE4CodeGen_Private::EPropertyClass::Delegate, "OnComplete", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(OverFluffGameInstance_eventRequestFindSessions_Parms, OnComplete), Z_Construct_UDelegateFunction_OverFluff_OnSearchSessionsComplete__DelegateSignature, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::NewProp_bIsPresence_SetBit(void* Obj)
	{
		((OverFluffGameInstance_eventRequestFindSessions_Parms*)Obj)->bIsPresence = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::NewProp_bIsPresence = { UE4CodeGen_Private::EPropertyClass::Bool, "bIsPresence", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(OverFluffGameInstance_eventRequestFindSessions_Parms), &Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::NewProp_bIsPresence_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::NewProp_bIsLAN_SetBit(void* Obj)
	{
		((OverFluffGameInstance_eventRequestFindSessions_Parms*)Obj)->bIsLAN = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::NewProp_bIsLAN = { UE4CodeGen_Private::EPropertyClass::Bool, "bIsLAN", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(OverFluffGameInstance_eventRequestFindSessions_Parms), &Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::NewProp_bIsLAN_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::NewProp_PlayerController_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::NewProp_PlayerController = { UE4CodeGen_Private::EPropertyClass::Object, "PlayerController", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(OverFluffGameInstance_eventRequestFindSessions_Parms, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::NewProp_PlayerController_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::NewProp_PlayerController_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::NewProp_OnComplete,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::NewProp_bIsPresence,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::NewProp_bIsLAN,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::NewProp_PlayerController,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "OverFluffGameInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOverFluffGameInstance, "RequestFindSessions", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(OverFluffGameInstance_eventRequestFindSessions_Parms), Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics
	{
		struct OverFluffGameInstance_eventRequestHostSession_Parms
		{
			const APlayerController* PlayerController;
			FName SessionName;
			bool bIsLAN;
			bool bIsPresence;
			int32 MaxNumPlayers;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MaxNumPlayers;
		static void NewProp_bIsPresence_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsPresence;
		static void NewProp_bIsLAN_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsLAN;
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_SessionName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerController_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::NewProp_MaxNumPlayers = { UE4CodeGen_Private::EPropertyClass::Int, "MaxNumPlayers", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(OverFluffGameInstance_eventRequestHostSession_Parms, MaxNumPlayers), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::NewProp_bIsPresence_SetBit(void* Obj)
	{
		((OverFluffGameInstance_eventRequestHostSession_Parms*)Obj)->bIsPresence = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::NewProp_bIsPresence = { UE4CodeGen_Private::EPropertyClass::Bool, "bIsPresence", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(OverFluffGameInstance_eventRequestHostSession_Parms), &Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::NewProp_bIsPresence_SetBit, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::NewProp_bIsLAN_SetBit(void* Obj)
	{
		((OverFluffGameInstance_eventRequestHostSession_Parms*)Obj)->bIsLAN = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::NewProp_bIsLAN = { UE4CodeGen_Private::EPropertyClass::Bool, "bIsLAN", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(OverFluffGameInstance_eventRequestHostSession_Parms), &Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::NewProp_bIsLAN_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::NewProp_SessionName = { UE4CodeGen_Private::EPropertyClass::Name, "SessionName", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(OverFluffGameInstance_eventRequestHostSession_Parms, SessionName), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::NewProp_PlayerController_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::NewProp_PlayerController = { UE4CodeGen_Private::EPropertyClass::Object, "PlayerController", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(OverFluffGameInstance_eventRequestHostSession_Parms, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::NewProp_PlayerController_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::NewProp_PlayerController_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::NewProp_MaxNumPlayers,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::NewProp_bIsPresence,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::NewProp_bIsLAN,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::NewProp_SessionName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::NewProp_PlayerController,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "OverFluffGameInstance.h" },
		{ "ToolTip", "Host a game session (see https://wiki.unrealengine.com/How_To_Use_Sessions_In_C%2B%2B)\n@Param          UserID                  User that started the request\n@Param          SessionName             Name of the Session\n@Param          bIsLAN                  Is this is LAN Game?\n@Param          bIsPresence             \"Is the Session to create a presence Session\"\n@Param          MaxNumPlayers   Number of Maximum allowed players on this \"Session\" (Server)" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOverFluffGameInstance, "RequestHostSession", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(OverFluffGameInstance_eventRequestHostSession_Parms), Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession_Statics
	{
		struct OverFluffGameInstance_eventRequestJoinSession_Parms
		{
			const APlayerController* PlayerController;
			FName SessionName;
			FBlueprintSessionResult SearchResultBP;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SearchResultBP_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SearchResultBP;
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_SessionName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PlayerController_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PlayerController;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession_Statics::NewProp_SearchResultBP_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession_Statics::NewProp_SearchResultBP = { UE4CodeGen_Private::EPropertyClass::Struct, "SearchResultBP", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000008000182, 1, nullptr, STRUCT_OFFSET(OverFluffGameInstance_eventRequestJoinSession_Parms, SearchResultBP), Z_Construct_UScriptStruct_FBlueprintSessionResult, METADATA_PARAMS(Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession_Statics::NewProp_SearchResultBP_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession_Statics::NewProp_SearchResultBP_MetaData)) };
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession_Statics::NewProp_SessionName = { UE4CodeGen_Private::EPropertyClass::Name, "SessionName", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(OverFluffGameInstance_eventRequestJoinSession_Parms, SessionName), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession_Statics::NewProp_PlayerController_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession_Statics::NewProp_PlayerController = { UE4CodeGen_Private::EPropertyClass::Object, "PlayerController", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(OverFluffGameInstance_eventRequestJoinSession_Parms, PlayerController), Z_Construct_UClass_APlayerController_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession_Statics::NewProp_PlayerController_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession_Statics::NewProp_PlayerController_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession_Statics::NewProp_SearchResultBP,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession_Statics::NewProp_SessionName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession_Statics::NewProp_PlayerController,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "OverFluffGameInstance.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UOverFluffGameInstance, "RequestJoinSession", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04420401, sizeof(OverFluffGameInstance_eventRequestJoinSession_Parms), Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UOverFluffGameInstance_NoRegister()
	{
		return UOverFluffGameInstance::StaticClass();
	}
	struct Z_Construct_UClass_UOverFluffGameInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOverFluffGameInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_OverFluff,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UOverFluffGameInstance_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UOverFluffGameInstance_RequestFindSessions, "RequestFindSessions" }, // 2795095136
		{ &Z_Construct_UFunction_UOverFluffGameInstance_RequestHostSession, "RequestHostSession" }, // 863872752
		{ &Z_Construct_UFunction_UOverFluffGameInstance_RequestJoinSession, "RequestJoinSession" }, // 2525094537
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOverFluffGameInstance_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "OverFluffGameInstance.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "OverFluffGameInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOverFluffGameInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOverFluffGameInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UOverFluffGameInstance_Statics::ClassParams = {
		&UOverFluffGameInstance::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000000A8u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_UOverFluffGameInstance_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UOverFluffGameInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOverFluffGameInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UOverFluffGameInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UOverFluffGameInstance, 991037634);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UOverFluffGameInstance(Z_Construct_UClass_UOverFluffGameInstance, &UOverFluffGameInstance::StaticClass, TEXT("/Script/OverFluff"), TEXT("UOverFluffGameInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOverFluffGameInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
