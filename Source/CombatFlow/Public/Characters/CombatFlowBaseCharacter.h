// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "CombatFlowBaseCharacter.generated.h"

class UCombatFlowAbilitySystemComponent;
class UCombatFlowAttributeSet;
UCLASS()
class COMBATFLOW_API ACombatFlowBaseCharacter : public ACharacter ,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	ACombatFlowBaseCharacter();

	//~Begin IAbilitySystemInterface Interface.
	virtual UAbilitySystemComponent* GetAbilitySystemComponent()const;
	//~End IAbilitySystemInterface Interface.
	
	protected:
	//~Begin Apawn Interface.
	virtual void PossessedBy(AController* NewController)override;
	//~End Apawn Interface.
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<UCombatFlowAbilitySystemComponent>CombatFlowAbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	TObjectPtr<UCombatFlowAttributeSet>CombatFlowAttributeSet;

public:
	FORCEINLINE UCombatFlowAbilitySystemComponent* GetCombatFlowAbilitySystemComponent()const{return CombatFlowAbilitySystemComponent;}

	FORCEINLINE UCombatFlowAttributeSet* GetCombatFlowAttributeSet()const{return CombatFlowAttributeSet;}
};
