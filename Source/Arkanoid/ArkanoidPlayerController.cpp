// Fill out your copyright notice in the Description page of Project Settings.


#include "ArkanoidPlayerController.h"


#include "Camera/CameraActor.h"
#include "ArkanoidCamera.h"

#include "ArkanoidPlayerPawn.h"

AArkanoidPlayerController::AArkanoidPlayerController()
{

}

void AArkanoidPlayerController::BeginPlay()
{

}

void AArkanoidPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	EnableInput(this);

	InputComponent->BindAxis("Arkanoid_Movement", this, &AArkanoidPlayerController::ArkanoidMovement);
	InputComponent->BindAction("Arkanoid_Fire", IE_Pressed, this, &AArkanoidPlayerController::Fire);
}

void AArkanoidPlayerController::ArkanoidMovement(float AxisValue)
{
	auto PlayerPawn = Cast<AArkanoidPlayerPawn>(GetPawn());

	if (PlayerPawn) {
		PlayerPawn->ArkanoidMovement(AxisValue);
	}
}

void AArkanoidPlayerController::Fire() {
	auto PlayerPawn = Cast<AArkanoidPlayerPawn>(GetPawn());

	if (PlayerPawn) {
		PlayerPawn->Launch();
	}
}