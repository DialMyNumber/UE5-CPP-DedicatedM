// DMPlayerCharacter.cpp

#include "DMPlayerCharacter.h"

ADMPlayerCharacter::ADMPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ADMPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADMPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADMPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}