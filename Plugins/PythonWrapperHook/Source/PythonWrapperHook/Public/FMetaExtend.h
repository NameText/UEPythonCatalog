#pragma once

class FMetaExtend
{
public:

	static void AddBlueprintType();

	static void SetPropertyBlueprintVisible();

protected:
	
	static void SetPropertyBlueprintVisible(UStruct* Struct, const TArray<FString>& PropertyArray);
};
