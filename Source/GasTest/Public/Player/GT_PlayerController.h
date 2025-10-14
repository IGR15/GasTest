// CopyRight Omar W Switi

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GT_PlayerController.generated.h"

/**
 * 
 */
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class GASTEST_API AGT_PlayerController : public APlayerController
{
	GENERATED_BODY()
protected:
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditDefaultsOnly,Category="GT|Input")
	TArray<TObjectPtr<UInputMappingContext>> InputMappingContexts;

	UPROPERTY(EditDefaultsOnly,Category="GT|Input|Movement")
	TObjectPtr<UInputAction>JumpAction;

	UPROPERTY(EditDefaultsOnly,Category="GT|Input|Movement")
	TObjectPtr<UInputAction>MoveAction;

	UPROPERTY(EditDefaultsOnly,Category="GT|Input|Movement")
	TObjectPtr<UInputAction>LookAction;

	UPROPERTY(EditDefaultsOnly,Category="GT|Input|Abilities")
	TObjectPtr<UInputAction>PrimaryAction;

	

	void Jump();
	void StopJumping();
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Primary();
};
