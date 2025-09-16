// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/PawnExtensionComponentBase.h"
#include "PawnCombatComponent.generated.h"

class ACombatFlowWeaponBase;
/**
 * 
 */
UCLASS()
class COMBATFLOW_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintCallable, Category = "CombatFlow|Combat")
	void RegisterSpawnedWeapon(FGameplayTag InWeaponTagToRegister,ACombatFlowWeaponBase* InWeaponToRegister,bool bRegisterAsEquippedWeapon=false);

	UFUNCTION(BlueprintCallable, Category = "CombatFlow|Combat")
	ACombatFlowWeaponBase* GetCharacterCarriedWeaponByTag(FGameplayTag InWeaponTagToGet)const;

	UFUNCTION(BlueprintCallable, Category = "CombatFlow|Combat")
	ACombatFlowWeaponBase* GetCharacterCurrentEquippedWeapon()const;

	UPROPERTY(BlueprintReadWrite, Category = "CombatFlow|Combat")
	FGameplayTag CurrentEquippedWeaponTag;
	
private:
TMap<FGameplayTag,TObjectPtr<ACombatFlowWeaponBase>>CharacterCarriedWeaponMap;
};
