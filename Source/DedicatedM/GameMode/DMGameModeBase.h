// DMGameModeBase.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DMGameModeBase.generated.h"

UCLASS()
class DEDICATEDM_API ADMGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADMGameModeBase();

	virtual void PreLogin(
		const FString& Options, 
		const FString& Address, 
		const FUniqueNetIdRepl& UniqueId, 
		FString& ErrorMessage) override;
	
};