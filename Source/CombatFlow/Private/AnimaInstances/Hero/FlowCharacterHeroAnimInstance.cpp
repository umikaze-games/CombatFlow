// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimaInstances/Hero/FlowCharacterHeroAnimInstance.h"

#include "Characters/CombatFlowHeroCharacter.h"

void UFlowCharacterHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	if (OwningCharacter)
	{
		OwningHeroCharacter=Cast<ACombatFlowHeroCharacter>(OwningHeroCharacter);
	}
}

void UFlowCharacterHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);
	if (bHasAcceleration)
	{
		IdleElpasedTime=0.f;
		bShouldEnterRelaxState=false;
	}
	else
	{
		IdleElpasedTime+=DeltaSeconds;
		bShouldEnterRelaxState=(IdleElpasedTime>=EnterRelaxStateThreshold);
	}
}
