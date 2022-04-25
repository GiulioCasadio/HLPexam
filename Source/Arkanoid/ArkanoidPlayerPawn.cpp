// Fill out your copyright notice in the Description page of Project Settings.


#include "ArkanoidPlayerPawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/Pawn.h"

#include "Components/StaticMeshComponent.h"

// Sets default values
AArkanoidPlayerPawn::AArkanoidPlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Pitcher = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pitcher"));
	RootComponent = Pitcher;

	Pitcher->SetEnableGravity(false);
	Pitcher->SetConstraintMode(EDOFMode::XZPlane);
	Pitcher->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Pitcher->SetCollisionProfileName(TEXT("PhysicsActor"));
	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement"));

}

// Called when the game starts or when spawned
void AArkanoidPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AArkanoidPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AArkanoidPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AArkanoidPlayerPawn::ArkanoidMovement(float AxisValue)
{
	AddMovementInput(FVector(AxisValue, 0.0f, 0.0f), 1.0f, false);
	Server_Movement(GetActorLocation());
}

void AArkanoidPlayerPawn::Launch()
{
	//ballRef->Destroy();
	Server_Launch();
}

void AArkanoidPlayerPawn::Server_Launch_Implementation()
{
	if (ballRef) {
		ballRef->Launch();
	}
}

void AArkanoidPlayerPawn::Server_Movement_Implementation(FVector newPosition)
{
	SetActorLocation(newPosition);
}