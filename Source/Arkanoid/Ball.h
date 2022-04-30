// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"

#include "Ball.generated.h"

UCLASS()
class ARKANOID_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool ballLaunched = false;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
		UStaticMeshComponent* BallMesh;

public:	
	virtual void Launch();
};
