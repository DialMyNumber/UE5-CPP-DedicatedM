// ItemDataAsset.h

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemDataAsset.generated.h"

UCLASS()
class INVENTORYPLUGIN_API UItemDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly)
	FName ItemID;

	UPROPERTY(EditDefaultsOnly)
	FText ItemName;

	UPROPERTY(EditDefaultsOnly)
	FText ItemDescription;

	UPROPERTY(EditDefaultsOnly)
	FText ItemFlavorText;

	UPROPERTY(EditDefaultsOnly)
	int32 MaxStack;
};
