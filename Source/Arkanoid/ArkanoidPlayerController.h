// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

#include "ArkanoidPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API AArkanoidPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	AArkanoidPlayerController();
	virtual void SetupInputComponent() override;

protected:
	virtual void BeginPlay() override;

	void ArkanoidMovement(float AxisValue);

	void Fire();
};
