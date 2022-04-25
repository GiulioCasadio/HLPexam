// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Net/UnrealNetwork.h"
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
	UPROPERTY(Replicated)
	int remainingBalls;

	UPROPERTY(Replicated)
	int numberOfBricks;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

	UFUNCTION(BlueprintCallable, Category = "GameStats")
	int GetRemainingBalls();

	UFUNCTION(BlueprintCallable, Category = "GameStats")
	void SetRemainingBalls(int balls);

	UFUNCTION(BlueprintCallable, Category = "GameStats")
	void DecreaseBalls();

	UFUNCTION(BlueprintCallable, Category = "GameStats")
	void SetBricks(int bricks);

	UFUNCTION(BlueprintCallable, Category = "GameStats")
	void DecreaseBricks();

	UFUNCTION(BlueprintCallable, Category = "GameStats")
	int GetBricks();

	UFUNCTION(BlueprintImplementableEvent, Category = "GameStats")
	void Restart();
};
