// Copyright Epic Games, Inc. All Rights Reserved.

#include "PythonWrapperHook.h"

#include "FMetaExtend.h"

#define LOCTEXT_NAMESPACE "FPythonWrapperHookModule"

void FPythonWrapperHookModule::StartupModule()
{
	FMetaExtend::AddBlueprintType();
	FMetaExtend::SetPropertyBlueprintVisible();
}

void FPythonWrapperHookModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FPythonWrapperHookModule, PythonWrapperHook)