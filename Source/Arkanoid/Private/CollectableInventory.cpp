#include "CollectableInventory.h"

#include "PaddleStats.h"

#include "ArkanoidLogContext.h"
#include "Collectable.h"
#include "CollectableDataAsset.h"
#include "CollectableStatModifier.h"

UCollectableInventory::UCollectableInventory()
{
	PrimaryComponentTick.bCanEverTick = false;

	bWantsInitializeComponent = true;
}

void UCollectableInventory::InitializeComponent()
{
	Super::InitializeComponent();

	AActor* Owner = GetOwner();
	if (Owner != nullptr) {
		PaddleStats = Owner->FindComponentByClass<UPaddleStats>();
	}
}

void UCollectableInventory::UninitializeComponent()
{
	Super::UninitializeComponent();

	PaddleStats = nullptr;
}

void UCollectableInventory::AddItem(ACollectable* i_Collectable)
{
	if (PaddleStats == nullptr) 
	{
		UE_LOG(LogArkanoid, Warning, TEXT("Missing character stats"));
		return;
	}

	if (i_Collectable == nullptr)
	{
		UE_LOG(LogArkanoid, Warning, TEXT("Invalid collectable"));
		return;
	}

	UCollectableDataAsset* DataAsset = i_Collectable->ItemData;

	if (DataAsset == nullptr)
	{
		UE_LOG(LogArkanoid, Warning, TEXT("Invalid collectable data asset"));
		return;
	}

	UE_LOG(LogArkanoid, Log, TEXT("Added item %s"), *DataAsset->ItemName.ToString());

	UDataTable* Modifiers = DataAsset->StatsModifiers;

	if (Modifiers == nullptr)
	{
		UE_LOG(LogArkanoid, Warning, TEXT("Invalid collectable data table"));
		return;
	}

	static const FString ContextString(TEXT("UCollectableInventory::AddItem"));

	TArray<FCollectableStatModifier*> Rows;
	Modifiers->GetAllRows(ContextString, Rows);

	int NumRows = Rows.Num();

	for (size_t RowIndex = 0; RowIndex < NumRows; ++ RowIndex) {
		FCollectableStatModifier* Row = Rows[RowIndex];
		PaddleStats->UpdateStats(Row->StatName, Row->Value);
	}
}
