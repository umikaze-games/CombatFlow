// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatFlowBaseCharacter.h"
#include "CombatFlowHeroCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class COMBATFLOW_API ACombatFlowHeroCharacter : public ACombatFlowBaseCharacter
{
	GENERATED_BODY()
public:
	ACombatFlowHeroCharacter();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(visibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FollowCamera;
	
};
