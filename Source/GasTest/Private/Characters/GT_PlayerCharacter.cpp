// CopyRight Omar W Switi


#include "GasTest/Public/Characters/GT_PlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/GT_PlayerState.h"


AGT_PlayerCharacter::AGT_PlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	GetCapsuleComponent()->InitCapsuleSize(42.f,96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement=true;
	GetCharacterMovement()->RotationRate=FRotator(0.f,540.f,0.f);
	GetCharacterMovement()->JumpZVelocity=500.f;
	GetCharacterMovement()->AirControl=0.35f;
	GetCharacterMovement()->MaxWalkSpeed=500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed=20.f;
	GetCharacterMovement()->BrakingDecelerationWalking=2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling=1500.f;

	CameraBoom=CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength=600.f;
	CameraBoom->bUsePawnControlRotation=true;

	FollowCamera=CreateDefaultSubobject<UCameraComponent>("FollowCamera");
	FollowCamera->SetupAttachment(CameraBoom,USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation=false;
}

UAbilitySystemComponent* AGT_PlayerCharacter::GetAbilitySystemComponent() const
{
	AGT_PlayerState* GTPlayerState=Cast<AGT_PlayerState>(GetPlayerState());
	if (!IsValid(GTPlayerState))return nullptr;

	return GTPlayerState->GetAbilitySystemComponent();
}

UAttributeSet* AGT_PlayerCharacter::GetAttributeSet() const
{
	AGT_PlayerState* GTPlayerState=Cast<AGT_PlayerState>(GetPlayerState());
	if (!IsValid(GTPlayerState))return nullptr;

	return GTPlayerState->GetAttributeSet();
}

void AGT_PlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!IsValid(GetAbilitySystemComponent())||!HasAuthority())return;

	GetAbilitySystemComponent()->InitAbilityActorInfo(GetPlayerState(),this);
	OnASCInitialized.Broadcast(GetAbilitySystemComponent(),GetAttributeSet());
	GiveStartUpAbilities();
	InitializeAttributes();

	
}

void AGT_PlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	if (!IsValid(GetAbilitySystemComponent()))return;

	GetAbilitySystemComponent()->InitAbilityActorInfo(GetPlayerState(),this);
	OnASCInitialized.Broadcast(GetAbilitySystemComponent(),GetAttributeSet());
}


