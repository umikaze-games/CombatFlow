// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CombatFlowHeroCharacter.h"
#include "CombatFlowDebugHelper.h"

// Called when the game starts or when spawned
void ACombatFlowHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
	Debug::Print(TEXT("Working"));
	
}
