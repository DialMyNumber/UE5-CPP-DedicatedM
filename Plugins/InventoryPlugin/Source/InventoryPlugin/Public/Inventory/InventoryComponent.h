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

	// 3. GetLifetimeReplicatedProps() 함수에 네트워크로 복제할 속성을 추가
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(Server, Reliable)
	void Server_AddItem(UItemDataAsset* Item, int32 Count);

	UFUNCTION(BlueprintCallable)
	void PrintAllItems();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(Replicated, EditAnywhere)
	TArray<FInventoryEntry> Items;
};
