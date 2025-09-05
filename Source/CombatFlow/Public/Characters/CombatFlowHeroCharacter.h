// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatFlowBaseCharacter.h"
#include "CombatFlowHeroCharacter.generated.h"

UCLASS()
class COMBATFLOW_API ACombatFlowHeroCharacter : public ACombatFlowBaseCharacter
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
};
