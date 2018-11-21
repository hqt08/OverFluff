// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OverFluff/OverFluffPlayerController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOverFluffPlayerController() {}
// Cross Module References
	OVERFLUFF_API UClass* Z_Construct_UClass_AOverFluffPlayerController_NoRegister();
	OVERFLUFF_API UClass* Z_Construct_UClass_AOverFluffPlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_OverFluff();
// End Cross Module References
	void AOverFluffPlayerController::StaticRegisterNativesAOverFluffPlayerController()
	{
	}
	UClass* Z_Construct_UClass_AOverFluffPlayerController_NoRegister()
	{
		return AOverFluffPlayerController::StaticClass();
	}
	struct Z_Construct_UClass_AOverFluffPlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOverFluffPlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_OverFluff,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOverFluffPlayerController_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "OverFluffPlayerController.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "OverFluffPlayerController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOverFluffPlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOverFluffPlayerController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AOverFluffPlayerController_Statics::ClassParams = {
		&AOverFluffPlayerController::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x008002A4u,
		nullptr, 0,
		nullptr, 0,
		"Game",
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AOverFluffPlayerController_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AOverFluffPlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AOverFluffPlayerController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AOverFluffPlayerController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AOverFluffPlayerController, 1032419014);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AOverFluffPlayerController(Z_Construct_UClass_AOverFluffPlayerController, &AOverFluffPlayerController::StaticClass, TEXT("/Script/OverFluff"), TEXT("AOverFluffPlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOverFluffPlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
