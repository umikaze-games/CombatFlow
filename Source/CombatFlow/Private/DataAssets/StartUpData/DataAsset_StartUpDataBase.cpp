// Fill out your copyright notice in the Description page of Project Settings.


#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"

#include "AbilitySystem/CombatFlowAbilitySystemComponent.h"
#include "AbilitySystem/Abilities/CombatFlowGameplayAbility.h"

void UDataAsset_StartUpDataBase::GiveToAbilitySystemComponent(UCombatFlowAbilitySystemComponent* InASCToGive,
                                                              int32 ApplyLevel)
{
	check(InASCToGive);
	GrantAbilities(ActivateOnGivenAbiliies,InASCToGive,ApplyLevel);
	GrantAbilities(ReactiveAbiliies,InASCToGive,ApplyLevel);
}

void UDataAsset_StartUpDataBase::GrantAbilities(
	const TArray<TSubclassOf<UCombatFlowGameplayAbility>>& InAbilitiesToGive,
	UCombatFlowAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	if (InAbilitiesToGive.IsEmpty())
	{
		return;;
	}
	for (const TSubclassOf<UCombatFlowGameplayAbility>& Ability : InAbilitiesToGive)
	{
		if (!Ability)continue;
		FGameplayAbilitySpec AbilitySpec(Ability);
		AbilitySpec.SourceObject = InASCToGive->GetAvatarActor();
		AbilitySpec.Level = ApplyLevel;
		InASCToGive->GiveAbility(AbilitySpec);
	}
}
