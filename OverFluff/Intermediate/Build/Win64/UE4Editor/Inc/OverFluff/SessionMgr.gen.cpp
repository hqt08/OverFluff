// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OverFluff/SessionMgr.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSessionMgr() {}
// Cross Module References
	OVERFLUFF_API UClass* Z_Construct_UClass_USessionMgr_NoRegister();
	OVERFLUFF_API UClass* Z_Construct_UClass_USessionMgr();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_OverFluff();
// End Cross Module References
	void USessionMgr::StaticRegisterNativesUSessionMgr()
	{
	}
	UClass* Z_Construct_UClass_USessionMgr_NoRegister()
	{
		return USessionMgr::StaticClass();
	}
	struct Z_Construct_UClass_USessionMgr_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USessionMgr_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OverFluff,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USessionMgr_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SessionMgr.h" },
		{ "ModuleRelativePath", "SessionMgr.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USessionMgr_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USessionMgr>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USessionMgr_Statics::ClassParams = {
		&USessionMgr::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x000000A0u,
		nullptr, 0,
		nullptr, 0,
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_USessionMgr_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_USessionMgr_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USessionMgr()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USessionMgr_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USessionMgr, 1055472056);
	static FCompiledInDefer Z_CompiledInDefer_UClass_USessionMgr(Z_Construct_UClass_USessionMgr, &USessionMgr::StaticClass, TEXT("/Script/OverFluff"), TEXT("USessionMgr"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USessionMgr);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
