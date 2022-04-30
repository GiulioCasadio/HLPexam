// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ArkanoidGameState.generated.h"

/**
 * 
 */
UCLASS()
class ARKANOID_API AArkanoidGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	int remainingBalls;

	int numberOfBricks;

	UFUNCTION(BlueprintCallable, Category = "GameStats")
	int GetRemainingBalls();

	UFUNCTION(BlueprintCallable, Category = "GameStats")
	void SetRemainingBalls(int balls);

	UFUNCTION(BlueprintCallable, Category = "GameStats")
	void DecreaseBalls();

	UFUNCTION(BlueprintImplementableEvent)
	void Restart();
};
