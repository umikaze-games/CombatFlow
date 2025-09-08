// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimaInstances/CombatFlowBaseAnimInstance.h"
#include "Characters/CombatFlowBaseCharacter.h"
#include "CombatFlowCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class COMBATFLOW_API UCombatFlowCharacterAnimInstance : public UCombatFlowBaseAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

	protected:
	UPROPERTY()
	TObjectPtr<ACombatFlowBaseCharacter>OwningCharacter;
	
	UPROPERTY()
	TObjectPtr<UCharacterMovementComponent>OwningMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|LocomotionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category="AnimData|LocomotionData")
	bool bHasAcceleration;
};
