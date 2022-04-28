#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CollectableInventory.generated.h"

class UPaddleStats;

class ACollectable;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARKANOID_API UCollectableInventory : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCollectableInventory();

	virtual void InitializeComponent() override;
	virtual void UninitializeComponent() override;
	
	void AddItem(ACollectable* i_Collectable);

protected:
	UPROPERTY(Transient)
	UPaddleStats* PaddleStats = nullptr;
};
