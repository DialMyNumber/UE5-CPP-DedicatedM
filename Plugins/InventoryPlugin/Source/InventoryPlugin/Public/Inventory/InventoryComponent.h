// InventoryComponent.h

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

USTRUCT()
struct FInventoryEntry
{
	GENERATED_BODY()

	UPROPERTY()
	TObjectPtr<class UItemDataAsset> Item;

	UPROPERTY()
	int32 CurrentStack;
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INVENTORYPLUGIN_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInventoryComponent();

	UFUNCTION(Server, Reliable)
	void Server_AddItem(FName ItemID, int32 Count);

	// 3. GetLifetimeReplicatedProps() 함수에 네트워크로 복제할 속성을 추가
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(Replicated)
	TArray<FInventoryEntry> Items;
};
