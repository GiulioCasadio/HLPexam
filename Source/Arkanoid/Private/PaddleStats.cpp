// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddleStats.h"
#include "ReflectionUtilsFunctionLibrary.h"

// Sets default values for this component's properties
UPaddleStats::UPaddleStats()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UPaddleStats::UpdateStats(const FString& StatName, float StatValue)
{

	FString Path = "This";
	Path += ".";
	Path += StatName;

	void* OutObject = nullptr;
	FProperty* StatProperty = UReflectionUtilsFunctionLibrary::RetrieveProperty(this, Path, OutObject);
	
	if (StatProperty != nullptr) {
		FFloatProperty* FloatProperty = CastField<FFloatProperty>(StatProperty);
		if (FloatProperty != nullptr) {
			float Value = FMath::Clamp(StatValue, 0.f, 1.f);

			FloatProperty->SetPropertyValue_InContainer(OutObject, Value);

			if (GEngine != nullptr) {
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Stats update"));
			}
		}
	}
}
