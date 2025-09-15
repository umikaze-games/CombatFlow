// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatFlowBaseCharacter.h"
#include "CombatFlowHeroCharacter.generated.h"

class UHeroCombatComponent;
class UDataAsset_InputConfig;
class USpringArmComponent;
class UCameraComponent;
struct FInputActionValue;

UCLASS()
class COMBATFLOW_API ACombatFlowHeroCharacter : public ACombatFlowBaseCharacter
{
	GENERATED_BODY()
public:
	ACombatFlowHeroCharacter();

protected:
	//~Begin Apawn Interface.
	virtual void PossessedBy(AController* NewController)override;
	//~End Apawn Interface.
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void BeginPlay() override;
	
private:

#pragma region Components
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Combat, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UHeroCombatComponent>HeroCombatComponent;
	
	#pragma endregion

#pragma region Inputs
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = CharacterData, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UDataAsset_InputConfig> InputConfigDataAsset;

	void Input_Move(const FInputActionValue& InputActionValue);
	void Input_Look(const FInputActionValue& InputActionValue);
	
	#pragma endregion

	public:
	FORCEINLINE UHeroCombatComponent*  GetHeroCombatComponent()const{return HeroCombatComponent;}
};
