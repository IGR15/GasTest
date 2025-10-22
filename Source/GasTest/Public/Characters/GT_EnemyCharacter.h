// CopyRight Omar W Switi

#pragma once

#include "CoreMinimal.h"
#include "GT_BaseCharacter.h"
#include "GT_EnemyCharacter.generated.h"


class UAttributeSet;
class UAbilitySystemComponent;
UCLASS()
class GASTEST_API AGT_EnemyCharacter : public AGT_BaseCharacter
{
	GENERATED_BODY()

public:
	AGT_EnemyCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	virtual void BeginPlay() override;


private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet>AttributeSet;
};
