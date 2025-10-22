// CopyRight Omar W Switi

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "GT_PlayerState.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
UCLASS()
class GASTEST_API AGT_PlayerState : public APlayerState,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AGT_PlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
private:
	UPROPERTY(VisibleAnywhere,Category="GT|Abilities")
	TObjectPtr<UAbilitySystemComponent>AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
