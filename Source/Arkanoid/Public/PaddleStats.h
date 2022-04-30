// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PaddleStats.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARKANOID_API UPaddleStats : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPaddleStats();

	void UpdateStats(const FString& StatName, float StatValue);

protected:
	
	UPROPERTY(EditAnywhere, Category = "Stats", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMAX = "1.0"))
	float Speed = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Stats", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMAX = "1.0"))
	float Size = 0.5f;
};
