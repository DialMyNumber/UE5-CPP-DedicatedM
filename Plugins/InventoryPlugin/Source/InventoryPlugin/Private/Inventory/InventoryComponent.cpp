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

	if (GetOwner()->GetLocalRole() != ROLE_AutonomousProxy)
	{
		return;
	}

	AActor* Owner = GetOwner();

	if (!Owner)
	{
		return;
	}

	INVEN_NET_LOG(InventoryLog, Warning, Owner, "BeginPlay");
}

void UInventoryComponent::Server_AddItem_Implementation(FName ItemID, int32 Count)
{
	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		return;
	}

	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	// 모든 Pawn 순회
	for (TActorIterator<APawn> It(GetWorld()); It; ++It)
	{
		APawn* Pawn = *It;
		if (!Pawn)
		{
			continue;
		}

		UInventoryComponent* Inv = Pawn->FindComponentByClass<UInventoryComponent>();
		if (!Inv)
		{
			continue;
		}

		// 아이템 추가
		FInventoryEntry NewEntry;
		NewEntry.Item = nullptr; // 지금은 테스트라 nullptr 가능
		NewEntry.CurrentStack = Count;

		Inv->Items.Add(NewEntry);
	}
}