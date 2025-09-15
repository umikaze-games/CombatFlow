// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/CombatFlowHeroCharacter.h"
#include "CombatFlowDebugHelper.h"
#include "CombatFlowGameplayTags.h"
#include "EnhancedInputSubsystemInterface.h"
#include "EnhancedInputSubsystems.h"
#include "AbilitySystem/CombatFlowAbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/Combat/HeroCombatComponent.h"
#include "Components/Input/CombatFlowInputComponent.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

ACombatFlowHeroCharacter::ACombatFlowHeroCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42,96);
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	CameraBoom=CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 200.0f;
	CameraBoom->SocketOffset=FVector(0.0f,55.f,65.0f);
	CameraBoom->bUsePawnControlRotation=true;

	FollowCamera=CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom,USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation=false;

	GetCharacterMovement()->bOrientRotationToMovement=true;
	GetCharacterMovement()->RotationRate=FRotator(0.f,500.f,0.f);
	GetCharacterMovement()->MaxWalkSpeed=400.f;
	GetCharacterMovement()->BrakingDecelerationWalking=2000.f;

	HeroCombatComponent= CreateDefaultSubobject<UHeroCombatComponent>(TEXT("HeroCombatComponent"));
	
}

void ACombatFlowHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (!CharacterStartUpData.IsNull())
	{
		if (UDataAsset_StartUpDataBase* LoadData=CharacterStartUpData.LoadSynchronous())
		{
			LoadData->GiveToAbilitySystemComponent(CombatFlowAbilitySystemComponent);
		}
	}
}

// Called when the game starts or when spawned
void ACombatFlowHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
	Debug::Print(TEXT("Working"));
	
}

void ACombatFlowHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();
	UEnhancedInputLocalPlayerSubsystem* SubSystem=ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
	check(SubSystem);
	SubSystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext,0);
	UCombatFlowInputComponent*  CombatFlowInputComponent=CastChecked<UCombatFlowInputComponent>(PlayerInputComponent);
	CombatFlowInputComponent->BindNativeInputAction(InputConfigDataAsset,CombatFlowGameplayTags::InputTag_Move,ETriggerEvent::Triggered,this,&ThisClass::Input_Move);
	CombatFlowInputComponent->BindNativeInputAction(InputConfigDataAsset,CombatFlowGameplayTags::InputTag_Look,ETriggerEvent::Triggered,this,&ThisClass::Input_Look);
}

void ACombatFlowHeroCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementVector=InputActionValue.Get<FVector2D>();
	const FRotator MovementRotation(0,Controller->GetControlRotation().Yaw,0);
	if (MovementVector.Y!=0)
	{
		const FVector ForwardDirection=MovementRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardDirection,MovementVector.Y);
	}
	if (MovementVector.X!=0)
	{
		const FVector RightDirection=MovementRotation.RotateVector(FVector::RightVector);
		AddMovementInput(RightDirection,MovementVector.X);
	}
	
}

void ACombatFlowHeroCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector=InputActionValue.Get<FVector2D>();
	if (LookAxisVector.X!=0)
	{
		AddControllerYawInput(LookAxisVector.X);
	}
	if (LookAxisVector.Y!=0)
	{
		AddControllerPitchInput(LookAxisVector.Y);
	}
}
