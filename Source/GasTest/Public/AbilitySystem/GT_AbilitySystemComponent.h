// CopyRight Omar W Switi

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GT_AbilitySystemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GASTEST_API UGT_AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UGT_AbilitySystemComponent();

	virtual void OnGiveAbility(FGameplayAbilitySpec& AbilitySpec) override;

	virtual void OnRep_ActivateAbilities() override;

	UFUNCTION(BlueprintCallable,Category="GT|Abilities")
	void SetAbilityLevel(TSubclassOf<UGameplayAbility>AbilityClass,int32 Level);

	UFUNCTION(BlueprintCallable,Category="GT|Abilities")
	void AddToAbilityLevel(TSubclassOf<UGameplayAbility>AbilityClass,int32 Level=1);

private:
	void HandleAutoActivateAbilities(const FGameplayAbilitySpec& AbilitySpec);

};
