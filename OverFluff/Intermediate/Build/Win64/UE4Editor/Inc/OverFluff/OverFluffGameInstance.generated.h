// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FBlueprintSessionResult;
class APlayerController;
#ifdef OVERFLUFF_OverFluffGameInstance_generated_h
#error "OverFluffGameInstance.generated.h already included, missing '#pragma once' in OverFluffGameInstance.h"
#endif
#define OVERFLUFF_OverFluffGameInstance_generated_h

#define OverFluff_Source_OverFluff_OverFluffGameInstance_h_13_DELEGATE \
struct _Script_OverFluff_eventOnSearchSessionsComplete_Parms \
{ \
	TArray<FBlueprintSessionResult> Results; \
}; \
static inline void FOnSearchSessionsComplete_DelegateWrapper(const FScriptDelegate& OnSearchSessionsComplete, TArray<FBlueprintSessionResult> const& Results) \
{ \
	_Script_OverFluff_eventOnSearchSessionsComplete_Parms Parms; \
	Parms.Results=Results; \
	OnSearchSessionsComplete.ProcessDelegate<UObject>(&Parms); \
}


#define OverFluff_Source_OverFluff_OverFluffGameInstance_h_18_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execRequestJoinSession) \
	{ \
		P_GET_OBJECT(APlayerController,Z_Param_PlayerController); \
		P_GET_PROPERTY(UNameProperty,Z_Param_SessionName); \
		P_GET_STRUCT_REF(FBlueprintSessionResult,Z_Param_Out_SearchResultBP); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RequestJoinSession(Z_Param_PlayerController,Z_Param_SessionName,Z_Param_Out_SearchResultBP); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRequestFindSessions) \
	{ \
		P_GET_OBJECT(APlayerController,Z_Param_PlayerController); \
		P_GET_UBOOL(Z_Param_bIsLAN); \
		P_GET_UBOOL(Z_Param_bIsPresence); \
		P_GET_PROPERTY(UDelegateProperty,Z_Param_OnComplete); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RequestFindSessions(Z_Param_PlayerController,Z_Param_bIsLAN,Z_Param_bIsPresence,FOnSearchSessionsComplete(Z_Param_OnComplete)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRequestHostSession) \
	{ \
		P_GET_OBJECT(APlayerController,Z_Param_PlayerController); \
		P_GET_PROPERTY(UNameProperty,Z_Param_SessionName); \
		P_GET_UBOOL(Z_Param_bIsLAN); \
		P_GET_UBOOL(Z_Param_bIsPresence); \
		P_GET_PROPERTY(UIntProperty,Z_Param_MaxNumPlayers); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RequestHostSession(Z_Param_PlayerController,Z_Param_SessionName,Z_Param_bIsLAN,Z_Param_bIsPresence,Z_Param_MaxNumPlayers); \
		P_NATIVE_END; \
	}


#define OverFluff_Source_OverFluff_OverFluffGameInstance_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execRequestJoinSession) \
	{ \
		P_GET_OBJECT(APlayerController,Z_Param_PlayerController); \
		P_GET_PROPERTY(UNameProperty,Z_Param_SessionName); \
		P_GET_STRUCT_REF(FBlueprintSessionResult,Z_Param_Out_SearchResultBP); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RequestJoinSession(Z_Param_PlayerController,Z_Param_SessionName,Z_Param_Out_SearchResultBP); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRequestFindSessions) \
	{ \
		P_GET_OBJECT(APlayerController,Z_Param_PlayerController); \
		P_GET_UBOOL(Z_Param_bIsLAN); \
		P_GET_UBOOL(Z_Param_bIsPresence); \
		P_GET_PROPERTY(UDelegateProperty,Z_Param_OnComplete); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RequestFindSessions(Z_Param_PlayerController,Z_Param_bIsLAN,Z_Param_bIsPresence,FOnSearchSessionsComplete(Z_Param_OnComplete)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRequestHostSession) \
	{ \
		P_GET_OBJECT(APlayerController,Z_Param_PlayerController); \
		P_GET_PROPERTY(UNameProperty,Z_Param_SessionName); \
		P_GET_UBOOL(Z_Param_bIsLAN); \
		P_GET_UBOOL(Z_Param_bIsPresence); \
		P_GET_PROPERTY(UIntProperty,Z_Param_MaxNumPlayers); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RequestHostSession(Z_Param_PlayerController,Z_Param_SessionName,Z_Param_bIsLAN,Z_Param_bIsPresence,Z_Param_MaxNumPlayers); \
		P_NATIVE_END; \
	}


#define OverFluff_Source_OverFluff_OverFluffGameInstance_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOverFluffGameInstance(); \
	friend struct Z_Construct_UClass_UOverFluffGameInstance_Statics; \
public: \
	DECLARE_CLASS(UOverFluffGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/OverFluff"), NO_API) \
	DECLARE_SERIALIZER(UOverFluffGameInstance)


#define OverFluff_Source_OverFluff_OverFluffGameInstance_h_18_INCLASS \
private: \
	static void StaticRegisterNativesUOverFluffGameInstance(); \
	friend struct Z_Construct_UClass_UOverFluffGameInstance_Statics; \
public: \
	DECLARE_CLASS(UOverFluffGameInstance, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/OverFluff"), NO_API) \
	DECLARE_SERIALIZER(UOverFluffGameInstance)


#define OverFluff_Source_OverFluff_OverFluffGameInstance_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOverFluffGameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOverFluffGameInstance) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOverFluffGameInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOverFluffGameInstance); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOverFluffGameInstance(UOverFluffGameInstance&&); \
	NO_API UOverFluffGameInstance(const UOverFluffGameInstance&); \
public:


#define OverFluff_Source_OverFluff_OverFluffGameInstance_h_18_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOverFluffGameInstance(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOverFluffGameInstance(UOverFluffGameInstance&&); \
	NO_API UOverFluffGameInstance(const UOverFluffGameInstance&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOverFluffGameInstance); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOverFluffGameInstance); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOverFluffGameInstance)


#define OverFluff_Source_OverFluff_OverFluffGameInstance_h_18_PRIVATE_PROPERTY_OFFSET
#define OverFluff_Source_OverFluff_OverFluffGameInstance_h_15_PROLOG
#define OverFluff_Source_OverFluff_OverFluffGameInstance_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	OverFluff_Source_OverFluff_OverFluffGameInstance_h_18_PRIVATE_PROPERTY_OFFSET \
	OverFluff_Source_OverFluff_OverFluffGameInstance_h_18_RPC_WRAPPERS \
	OverFluff_Source_OverFluff_OverFluffGameInstance_h_18_INCLASS \
	OverFluff_Source_OverFluff_OverFluffGameInstance_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define OverFluff_Source_OverFluff_OverFluffGameInstance_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	OverFluff_Source_OverFluff_OverFluffGameInstance_h_18_PRIVATE_PROPERTY_OFFSET \
	OverFluff_Source_OverFluff_OverFluffGameInstance_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	OverFluff_Source_OverFluff_OverFluffGameInstance_h_18_INCLASS_NO_PURE_DECLS \
	OverFluff_Source_OverFluff_OverFluffGameInstance_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID OverFluff_Source_OverFluff_OverFluffGameInstance_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
