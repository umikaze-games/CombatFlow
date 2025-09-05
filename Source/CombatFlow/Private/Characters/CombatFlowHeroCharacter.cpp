// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CombatFlowHeroCharacter.h"

// Sets default values
ACombatFlowHeroCharacter::ACombatFlowHeroCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACombatFlowHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACombatFlowHeroCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACombatFlowHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

