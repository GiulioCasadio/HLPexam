// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CollectableDataAsset.generated.h"

class UDataTable;

UCLASS()
class ARKANOID_API UCollectableDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "Item Data")
	FName ItemName;

	UPROPERTY(EditAnywhere, Category = "Item Data")
	UDataTable* StatsModifiers;
};
