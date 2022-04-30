// Fill out your copyright notice in the Description page of Project Settings.


#include "ArkanoidPlayerPawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/Pawn.h"

#include "Components/StaticMeshComponent.h"
#include "PaddleStats.h"
#include "CollectableInventory.h"
#include "Collectable.h"

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

	StatsComponent = CreateDefaultSubobject<UPaddleStats>(TEXT("Stats"));
	InventoryComponent = CreateDefaultSubobject<UCollectableInventory>(TEXT("Inventory"));
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

void AArkanoidPlayerPawn::ArkanoidMovement(float AxisValue)
{
	if (StatsComponent!=nullptr) {
		AddMovementInput(FVector(AxisValue, 0.0f, 0.0f), StatsComponent->GetSpeed());
		SetActorLocation(GetActorLocation());
	}
}

void AArkanoidPlayerPawn::Launch()
{
	if (ballRef) {
		ballRef->Launch();
	}
}

void AArkanoidPlayerPawn::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	if (OtherActor == nullptr) {
		return;
	}

	bool bIsAnItem = OtherActor->IsA<ACollectable>();

	if (bIsAnItem) {
		ACollectable* Item = Cast<ACollectable>(OtherActor);
		InventoryComponent->AddItem(Item);

		Item->Destroy();
	}
}
