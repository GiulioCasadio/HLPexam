// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Ball.h"

#include "ArkanoidPlayerPawn.generated.h"

class UFloatingPawnMovement;
class UPaddleStats;
class UCollectableInventory;

UCLASS()
class ARKANOID_API AArkanoidPlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AArkanoidPlayerPawn();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ABall* ballRef;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
	UStaticMeshComponent* Pitcher;
	UPROPERTY(VisibleAnywhere, BlueprintReadonly)
	UFloatingPawnMovement* FloatingMovement;

	UPROPERTY(Category = Pawn, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPaddleStats* StatsComponent;

	UPROPERTY(Category = Pawn, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UCollectableInventory* InventoryComponent;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void ArkanoidMovement(float AxisValue);

	void Launch();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
