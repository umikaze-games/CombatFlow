// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CombatFlowBaseCharacter.h"

// Sets default values
ACombatFlowBaseCharacter::ACombatFlowBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled=false;
	GetMesh()->bReceivesDecals=false;
}

