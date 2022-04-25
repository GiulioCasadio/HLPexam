// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Ball.h"

#include "ArkanoidPlayerPawn.generated.h"

class UFloatingPawnMovement;

UCLASS()
class ARKANOID_API AArkanoidPlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AArkanoidPlayerPawn();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ABall* ballRef;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//bool isAlive = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
		UStaticMeshComponent* Pitcher;
	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
		UFloatingPawnMovement* FloatingMovement;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void ArkanoidMovement(float AxisValue);

	void Launch();

private:
	UFUNCTION(Server, Reliable, Category = "ServerUpdateMovement")
	void Server_Launch();

	UFUNCTION(Server, Reliable, Category = "ServerUpdateMovement")
	void Server_Movement(FVector newPosition);
};
