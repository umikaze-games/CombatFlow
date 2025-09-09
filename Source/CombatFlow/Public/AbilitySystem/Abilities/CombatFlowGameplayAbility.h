// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "CombatFlowGameplayAbility.generated.h"

UENUM(BlueprintType)
enum class ECombatFlowAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};
/**
 * 
 */
UCLASS()
class COMBATFLOW_API UCombatFlowGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
	protected:

	//~Begin UGameplayAbility Interface.
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec);
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled);
	//~End UGameplayAbility Interface.
	
	UPROPERTY(EditDefaultsOnly,Category="CombatFlowAbility")
	ECombatFlowAbilityActivationPolicy AbilityActivationPolicy=ECombatFlowAbilityActivationPolicy::OnTriggered;
};
