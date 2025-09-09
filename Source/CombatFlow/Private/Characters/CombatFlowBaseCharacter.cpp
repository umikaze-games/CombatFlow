// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CombatFlowBaseCharacter.h"

#include "AbilitySystem/CombatFlowAbilitySystemComponent.h"
#include "AbilitySystem/CombatFlowAttributeSet.h"

// Sets default values
ACombatFlowBaseCharacter::ACombatFlowBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled=false;
	GetMesh()->bReceivesDecals=false;

	CombatFlowAbilitySystemComponent=CreateDefaultSubobject<UCombatFlowAbilitySystemComponent>(TEXT("CombatFlowAbilitySystemComponent"));
	CombatFlowAttributeSet=CreateDefaultSubobject<UCombatFlowAttributeSet>(TEXT("CombatFlowAttributeSet"));
}

UAbilitySystemComponent* ACombatFlowBaseCharacter::GetAbilitySystemComponent() const
{
	return GetCombatFlowAbilitySystemComponent();
}

void ACombatFlowBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (CombatFlowAbilitySystemComponent)
	{
		CombatFlowAbilitySystemComponent->InitAbilityActorInfo(this,this);
	}
}

