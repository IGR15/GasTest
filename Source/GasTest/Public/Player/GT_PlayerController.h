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

	UPROPERTY(EditDefaultsOnly,Category="GT|Input")
	TObjectPtr<UInputAction>JumpAction;

	UPROPERTY(EditDefaultsOnly,Category="GT|Input")
	TObjectPtr<UInputAction>MoveAction;

	UPROPERTY(EditDefaultsOnly,Category="GT|Input")
	TObjectPtr<UInputAction>LookAction;

	void Jump();
	void StopJumping();
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
};
