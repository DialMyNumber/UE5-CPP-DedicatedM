// InventoryComponent.cpp

#include "InventoryComponent.h"
#include "InventoryLog.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();

	if (!Owner)
	{
		return;
	}

	INVEN_NET_LOG(InventoryLog, Warning, Owner, "BeginPlay");
}