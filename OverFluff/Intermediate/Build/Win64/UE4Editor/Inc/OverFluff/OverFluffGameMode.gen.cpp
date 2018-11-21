// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OverFluff/OverFluffGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOverFluffGameMode() {}
// Cross Module References
	OVERFLUFF_API UClass* Z_Construct_UClass_AOverFluffGameMode_NoRegister();
	OVERFLUFF_API UClass* Z_Construct_UClass_AOverFluffGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_OverFluff();
// End Cross Module References
	void AOverFluffGameMode::StaticRegisterNativesAOverFluffGameMode()
	{
	}
	UClass* Z_Construct_UClass_AOverFluffGameMode_NoRegister()
	{
		return AOverFluffGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AOverFluffGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOverFluffGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_OverFluff,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOverFluffGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "OverFluffGameMode.h" },
		{ "ModuleRelativePath", "OverFluffGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOverFluffGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOverFluffGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AOverFluffGameMode_Statics::ClassParams = {
		&AOverFluffGameMode::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x008802A8u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AOverFluffGameMode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AOverFluffGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AOverFluffGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AOverFluffGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AOverFluffGameMode, 2436669345);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AOverFluffGameMode(Z_Construct_UClass_AOverFluffGameMode, &AOverFluffGameMode::StaticClass, TEXT("/Script/OverFluff"), TEXT("AOverFluffGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOverFluffGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
