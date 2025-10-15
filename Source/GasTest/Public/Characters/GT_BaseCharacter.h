// CopyRight Omar W Switi

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "GT_BaseCharacter.generated.h"

class UGameplayAbility;
UCLASS(Abstract)
class GASTEST_API AGT_BaseCharacter : public ACharacter,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AGT_BaseCharacter();

virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
protected:
	void GiveStartUpAbilities();
private:
	UPROPERTY(EditDefaultsOnly,Category="GT|Abilities")
	TArray<TSubclassOf<UGameplayAbility>>StartUpAbilities;
};
