// CopyRight Omar W Switi

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GT_GamePlayAbility.generated.h"

/**
 * 
 */
UCLASS()
class GASTEST_API UGT_GamePlayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	//virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="GT|Debug")
	bool bDrawDebugs=false;
};
