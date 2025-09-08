// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimaInstances/CombatFlowCharacterAnimInstance.h"

#include "GameFramework/CharacterMovementComponent.h"

void UCombatFlowCharacterAnimInstance::NativeInitializeAnimation()
{
	//Super::NativeInitializeAnimation();
	OwningCharacter=Cast<ACombatFlowBaseCharacter>(TryGetPawnOwner());
	if (OwningCharacter)
	{
		OwningMovementComponent=OwningCharacter->GetCharacterMovement();
	}
}

void UCombatFlowCharacterAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	//Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	if (!OwningCharacter||!OwningMovementComponent)	return;
	GroundSpeed= OwningCharacter->GetVelocity().Size2D();
	bHasAcceleration= OwningMovementComponent->GetCurrentAcceleration().SizeSquared2D()>0.f;
}
