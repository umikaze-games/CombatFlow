// Copyright Epic Games, Inc. All Rights Reserved.

#include "CombatFlowGameMode.h"
#include "CombatFlowCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACombatFlowGameMode::ACombatFlowGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
