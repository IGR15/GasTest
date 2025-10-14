// CopyRight Omar W Switi

#pragma once

#include "CoreMinimal.h"
#include "GT_BaseCharacter.h"
#include "GT_PlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class GASTEST_API AGT_PlayerCharacter : public AGT_BaseCharacter
{
	GENERATED_BODY()

public:
	AGT_PlayerCharacter();

private:
	UPROPERTY(VisibleAnywhere,Category="camera")
	TObjectPtr<USpringArmComponent> CameraBoom;

	UPROPERTY(VisibleAnywhere,Category="camera")
	TObjectPtr<UCameraComponent> FollowCamera;
	
};
