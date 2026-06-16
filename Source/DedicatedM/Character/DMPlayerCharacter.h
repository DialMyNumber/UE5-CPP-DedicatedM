// DMPlayerCharacter.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DMPlayerCharacter.generated.h"

UCLASS()
class DEDICATEDM_API ADMPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ADMPlayerCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};