// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "InputAction.h"
#include "CombatFlow/CombatFlowCharacter.h"
#include "Engine/DataAsset.h"
#include "DataAsset_InputConfig.generated.h"

USTRUCT(BlueprintType)
struct FCombatFlowInputConfig
{
	GENERATED_BODY()
public:
UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,meta=(Categories="InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputAction> InputAction;
	
};

UCLASS()
class COMBATFLOW_API UDataAsset_InputConfig : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,meta=(TitleProperty="InputTag"))
	TArray<FCombatFlowInputConfig>NativeInputActions;

	UInputAction* FindNativeInputActionsByTag(const FGameplayTag& InInputTag);
};
