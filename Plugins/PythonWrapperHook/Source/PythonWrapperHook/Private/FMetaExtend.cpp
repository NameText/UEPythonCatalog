#include "FMetaExtend.h"
#include "UObject/MetaData.h"


void FMetaExtend::AddBlueprintType()
{
	UStruct* Struct = FKShapeElem::StaticStruct();
	UMetaData* MetaData = Struct->GetOutermost()->GetMetaData();
	MetaData->SetValue(Struct, TEXT("BlueprintType"), TEXT("true"));

	Struct = FKSphereElem::StaticStruct();
	MetaData = Struct->GetOutermost()->GetMetaData();
	MetaData->SetValue(Struct, TEXT("BlueprintType"), TEXT("true"));

	Struct = FKBoxElem::StaticStruct();
	MetaData = Struct->GetOutermost()->GetMetaData();
	MetaData->SetValue(Struct, TEXT("BlueprintType"), TEXT("true"));

	Struct = FKConvexElem::StaticStruct();
	MetaData = Struct->GetOutermost()->GetMetaData();
	MetaData->SetValue(Struct, TEXT("BlueprintType"), TEXT("true"));

	Struct = FKSphylElem::StaticStruct();
	MetaData = Struct->GetOutermost()->GetMetaData();
	MetaData->SetValue(Struct, TEXT("BlueprintType"), TEXT("true"));

	Struct = FKTaperedCapsuleElem::StaticStruct();
	MetaData = Struct->GetOutermost()->GetMetaData();
	MetaData->SetValue(Struct, TEXT("BlueprintType"), TEXT("true"));

	Struct = FKAggregateGeom::StaticStruct();
	MetaData = Struct->GetOutermost()->GetMetaData();
	MetaData->SetValue(Struct, TEXT("BlueprintType"), TEXT("true"));
}

void FMetaExtend::SetPropertyBlueprintVisible()
{

	SetPropertyBlueprintVisible(UPhysicsAsset::StaticClass(), {TEXT("SkeletalBodySetups") });
	SetPropertyBlueprintVisible(UBodySetup::StaticClass(), {TEXT("BoneName"), TEXT("AggGeom") });
	SetPropertyBlueprintVisible(FKShapeElem::StaticStruct(), {TEXT("Name") });

	SetPropertyBlueprintVisible(FKAggregateGeom::StaticStruct(), {TEXT("SphereElems"), TEXT("SphylElems"), TEXT("BoxElems") });
	SetPropertyBlueprintVisible(FKSphereElem::StaticStruct(), {TEXT("Radius"), TEXT("Center") });
	SetPropertyBlueprintVisible(FKBoxElem::StaticStruct(), {TEXT("Center"), TEXT("Rotation"), TEXT("X"), TEXT("Y"), TEXT("Z") });
	SetPropertyBlueprintVisible(FKConvexElem::StaticStruct(), {TEXT("VertexData"), TEXT("IndexData"), TEXT("ElemBox") });
	SetPropertyBlueprintVisible(FKSphylElem::StaticStruct(), {TEXT("Center"), TEXT("Rotation"), TEXT("Radius") , TEXT("Length")});
	SetPropertyBlueprintVisible(FKTaperedCapsuleElem::StaticStruct(), {TEXT("Center"), TEXT("Rotation"), TEXT("Radius0") , TEXT("Radius1"), TEXT("Length")});

}


void FMetaExtend::SetPropertyBlueprintVisible(UStruct* Struct, const TArray<FString>& PropertyArray)
{
	 for (auto PropertyName : PropertyArray)
	 {
		if(FProperty* PropertyIns = Struct->FindPropertyByName(*PropertyName))
		{
			if(!PropertyIns->HasAnyPropertyFlags(CPF_BlueprintVisible))
			{
				PropertyIns->SetPropertyFlags(CPF_BlueprintVisible);
			}
		}
	}
	
}