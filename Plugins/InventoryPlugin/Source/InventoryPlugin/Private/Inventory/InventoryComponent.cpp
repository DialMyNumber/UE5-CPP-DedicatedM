// InventoryComponent.cpp

#include "Inventory/InventoryComponent.h"
#include "InventoryLog.h"
#include "Net/UnrealNetwork.h"
#include "Item/ItemDataAsset.h"

#include "GameFramework/PlayerState.h"
#include "GameFramework/PlayerController.h"

#include "EngineUtils.h"						// Iterator 사용

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInventoryComponent::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// 3. DOREPLIFETIME 매크로를 사용해 복제할 속성을 명시
	// "Net/UnrealNetwork.h" 헤더파일 필요
	DOREPLIFETIME(ThisClass, Items);

	// 변수 중에서 변경될 여지가 있으면 Replication에 등록,
	// 변경될 여지 없이 고정 값이라면 Replication에 등록할 필요가 없음
}
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();

	if (!Owner)
	{
		return;
	}

	INVEN_NET_LOG(InventoryLog, Warning, Owner, "Begin Play");

	if (GetOwner()->GetLocalRole() != ROLE_AutonomousProxy)
	{
		return;
	}

	//----------------------------------------------
	// NetRole == ROLE_AutonomousProxy만 실행되는 구간

	INVEN_NET_LOG(InventoryLog, Warning, Owner, "Inventory Component Attached.");
}

void UInventoryComponent::Server_AddItem_Implementation(UItemDataAsset* Item, int32 Count)
{
	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		return;
	}

	if (!Item)
	{
		return;
	}

	// 1. 이미 같은 아이템 있는지 찾기
	for (FInventoryEntry& Entry : Items)
	{
		if (Entry.Item == Item)
		{
			Entry.CurrentStack += Count;
			return;
		}
	}

	// 2. 없으면 새로 추가
	FInventoryEntry NewEntry;
	NewEntry.Item = Item;
	NewEntry.CurrentStack = Count;

	Items.Add(NewEntry);
}

void UInventoryComponent::PrintAllItems()
{
	AActor* Owner = GetOwner();

	if (!Owner || !Owner->HasAuthority())
	{
		return; // 서버만 출력
	}

	INVEN_NET_LOG(InventoryLog, Warning, Owner, "Try Print All Items");

	for (const FInventoryEntry& Entry : Items)
	{
		if (!Entry.Item)
		{
			continue;
		}

		INVEN_NET_LOG(InventoryLog, Warning, Owner, "ItemID: %s | Name: %s | Stack: %d", 
			*Entry.Item->ItemID.ToString(),
			*Entry.Item->ItemName.ToString(),
			Entry.CurrentStack);
	}
}