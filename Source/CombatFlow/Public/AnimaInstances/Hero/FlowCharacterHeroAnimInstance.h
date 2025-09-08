// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AnimaInstances/CombatFlowCharacterAnimInstance.h"
#include "FlowCharacterHeroAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class COMBATFLOW_API UFlowCharacterHeroAnimInstance : public UCombatFlowCharacterAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|Refrences")
	TObjectPtr<ACombatFlowHeroCharacter>OwningHeroCharacter;
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	bool bShouldEnterRelaxState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData|LocomotionData")
	float EnterRelaxStateThreshold=5.f;

	float IdleElpasedTime;
};
