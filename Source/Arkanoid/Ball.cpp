// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"

#include "Components/StaticMeshComponent.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	RootComponent = BallMesh;
	BallMesh->SetSimulatePhysics(false);
	BallMesh->SetEnableGravity(false);
	BallMesh->SetConstraintMode(EDOFMode::XZPlane);
	BallMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABall::Launch()
{
	if (!ballLaunched) {
		ballLaunched = true;
		BallMesh->SetSimulatePhysics(true);
		BallMesh->AddImpulse(FVector(0, 0, 70000));
	}
}