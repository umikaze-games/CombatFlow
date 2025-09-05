// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatFlowBaseCharacter.h"
#include "CombatFlowHeroCharacter.generated.h"

UCLASS()
class COMBATFLOW_API ACombatFlowHeroCharacter : public ACombatFlowBaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACombatFlowHeroCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
