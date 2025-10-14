// CopyRight Omar W Switi


#include "GasTest/Public/Player/GT_PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"

void AGT_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputLocalPlayerSubsystem* InputSubsystem=ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (!IsValid(InputSubsystem))return;
	for (UInputMappingContext* Context:InputMappingContexts)
	{
		InputSubsystem->AddMappingContext(Context,0);
	}
	UEnhancedInputComponent* EnhancedInputComponent=Cast<UEnhancedInputComponent>(InputComponent);
	if (!IsValid(EnhancedInputComponent))return;

	EnhancedInputComponent->BindAction(JumpAction,ETriggerEvent::Started,this,&AGT_PlayerController::Jump);
	EnhancedInputComponent->BindAction(JumpAction,ETriggerEvent::Completed,this,&AGT_PlayerController::StopJumping);

	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&AGT_PlayerController::Move);
	EnhancedInputComponent->BindAction(LookAction,ETriggerEvent::Triggered,this,&AGT_PlayerController::Look);
	EnhancedInputComponent->BindAction(PrimaryAction,ETriggerEvent::Started,this,&AGT_PlayerController::Primary);

	
}

void AGT_PlayerController::Jump()
{
	if (!IsValid(GetCharacter()))return;

	GetCharacter()->Jump();
}

void AGT_PlayerController::StopJumping()
{
	if (!IsValid(GetCharacter()))return;

	GetCharacter()->StopJumping();
}

void AGT_PlayerController::Move(const FInputActionValue& Value)
{
	if (!IsValid(GetPawn()))return;

	const FVector2D MovementVector=Value.Get<FVector2D>();

	//find which way is forward
	const FRotator YawRotation(0.f,GetControlRotation().Yaw,0.f);
	const FVector ForwardDirection=FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection=FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	GetPawn()->AddMovementInput(ForwardDirection,MovementVector.Y);
	GetPawn()->AddMovementInput(RightDirection,MovementVector.X);
	
	
	
}

void AGT_PlayerController::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector=Value.Get<FVector2D>();

	AddYawInput(LookAxisVector.X);
	AddPitchInput(LookAxisVector.Y);

}

void AGT_PlayerController::Primary()
{
	UE_LOG(LogTemp,Warning,TEXT("AGT_PlayerController::Primary"));
}
