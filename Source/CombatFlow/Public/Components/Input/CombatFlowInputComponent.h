// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "CombatFlowInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class COMBATFLOW_API UCombatFlowInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()
	
public:
	
	template<class UserObject,typename CallbackFunc>
	void BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,
		const FGameplayTag& InInputTag,
		ETriggerEvent TriggerEvent,
		UserObject* ContextObject,
		CallbackFunc Func);
};

template <class UserObject, typename CallbackFunc>
void UCombatFlowInputComponent::BindNativeInputAction(const UDataAsset_InputConfig* InInputConfig,
	const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	checkf(InInputConfig,TEXT("Input Config data asset is null, can not proceed with binding"));
	if (UInputAction* FoundAction=InInputConfig->FindNativeInputActionsByTag(InInputTag))
	{

		BindAction(FoundAction,TriggerEvent,ContextObject,Func);
	}
}
