// Fill out your copyright notice in the Description page of Project Settings.


#include "ArkanoidGameState.h"
#include "ArkanoidPlayerState.h"

int AArkanoidGameState::GetRemainingBalls()
{
	return remainingBalls;
}

void AArkanoidGameState::SetRemainingBalls(int balls)
{
	remainingBalls = balls;
}

void AArkanoidGameState::DecreaseBalls()
{
	remainingBalls--;

	// Works only in single player
	/*if (remainingBalls <= 0) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("You lose"));
		Restart();
	}*/
}

void AArkanoidGameState::SetBricks(int bricks)
{
	numberOfBricks = bricks;
}

void AArkanoidGameState::DecreaseBricks()
{
	numberOfBricks--;
}

int AArkanoidGameState::GetBricks()
{
	return numberOfBricks;
}

void AArkanoidGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AArkanoidGameState, remainingBalls);
}