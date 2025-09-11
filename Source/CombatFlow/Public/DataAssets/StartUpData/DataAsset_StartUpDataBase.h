// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UCombatFlowGameplayAbility;
class UCombatFlowAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class COMBATFLOW_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()
public:
	virtual  void GiveToAbilitySystemComponent(UCombatFlowAbilitySystemComponent* InCombatFlowASCToGive,int32 ApplyLevel=1);
	
protected:
	UPROPERTY(EditDefaultsOnly,Category="StartUpData")
	TArray<TSubclassOf<UCombatFlowGameplayAbility>>ActivateOnGivenAbiliies;

	UPROPERTY(EditDefaultsOnly,Category="StartUpData")
	TArray<TSubclassOf<UCombatFlowGameplayAbility>>ReactiveAbiliies;

	void GrantAbilities(const TArray<TSubclassOf<UCombatFlowGameplayAbility>>& InAbilitiesToGive,UCombatFlowAbilitySystemComponent* InCombatFlowASCToGive,int32 ApplyLevel=1);
};
