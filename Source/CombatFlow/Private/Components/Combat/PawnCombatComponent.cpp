// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Combat/PawnCombatComponent.h"
#include "CombatFlowDebugHelper.h"
#include "Items/Weapons/CombatFlowWeaponBase.h"

void UPawnCombatComponent::RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister,
                                                 ACombatFlowWeaponBase* InWeaponToRegister, bool bRegisterAsEquippedWeapon)
{
	checkf(!CharacterCarriedWeaponMap.Contains(InWeaponTagToRegister),
		TEXT("A named named %s has already been added as carried weapon"),*InWeaponTagToRegister.ToString())
	check(InWeaponToRegister);
	CharacterCarriedWeaponMap.Emplace(InWeaponTagToRegister,InWeaponToRegister);
	if (bRegisterAsEquippedWeapon)
	{
		CurrentEquippedWeaponTag=InWeaponTagToRegister;
	}

	const FString WeaponString=FString::Printf(
		TEXT("A weapon named: %s has been registered using the tag %s"),
			*InWeaponToRegister->GetName(),
			*InWeaponTagToRegister.ToString()
			);

		Debug::Print(WeaponString);
		
}

ACombatFlowWeaponBase* UPawnCombatComponent::GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet) const
{
	if (CharacterCarriedWeaponMap.Contains(InWeaponTagToGet))
	{
		if (const TObjectPtr<ACombatFlowWeaponBase>* FoundWeapon = CharacterCarriedWeaponMap.Find(InWeaponTagToGet))
		{
			return *FoundWeapon;
		}
	}
	return nullptr;
}

ACombatFlowWeaponBase* UPawnCombatComponent::GetCharacterCurrentEquippedWeapon() const
{
	if (!CurrentEquippedWeaponTag.IsValid())
	{
		return nullptr;
	}
	return  GetCharacterCarriedWeaponByTag(CurrentEquippedWeaponTag);
}
