// CopyRight Omar W Switi


#include "AbilitySystem/GT_AbilitySystemComponent.h"

#include "GamePlayTags/GT_Tags.h"


// Sets default values for this component's properties
UGT_AbilitySystemComponent::UGT_AbilitySystemComponent()
{

	PrimaryComponentTick.bCanEverTick = false;
	
}

void UGT_AbilitySystemComponent::OnGiveAbility(FGameplayAbilitySpec& AbilitySpec)
{
	Super::OnGiveAbility(AbilitySpec);

	if (!IsValid(AbilitySpec.Ability))return;
	HandleAutoActivateAbilities(AbilitySpec);
	
}

void UGT_AbilitySystemComponent::OnRep_ActivateAbilities()
{
	Super::OnRep_ActivateAbilities();

	FScopedAbilityListLock ActiveScopeLock(*this);
	for (const FGameplayAbilitySpec& AbilitySpec:GetActivatableAbilities())
	{
		HandleAutoActivateAbilities(AbilitySpec);
	}
}

void UGT_AbilitySystemComponent::SetAbilityLevel(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level)
{
	if (IsValid(GetAvatarActor())&&!GetAvatarActor()->HasAuthority())return;

	
	if (FGameplayAbilitySpec* AbilitySpec=FindAbilitySpecFromClass(AbilityClass))
	{
		AbilitySpec->Level=Level;
		MarkAbilitySpecDirty(*AbilitySpec);
	}
}

void UGT_AbilitySystemComponent::AddToAbilityLevel(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level)
{
	if (IsValid(GetAvatarActor())&&!GetAvatarActor()->HasAuthority())return;

	
	if (FGameplayAbilitySpec* AbilitySpec=FindAbilitySpecFromClass(AbilityClass))
	{
		AbilitySpec->Level+=Level;
		MarkAbilitySpecDirty(*AbilitySpec);
	}
}

void UGT_AbilitySystemComponent::HandleAutoActivateAbilities(const FGameplayAbilitySpec& AbilitySpec)
{
	
	for (const FGameplayTag& Tag: AbilitySpec.Ability->GetAssetTags())
	{
		if (Tag.MatchesTagExact(GTTags::GTAbilities::ActivateOnGiven))
		{
			TryActivateAbility(AbilitySpec.Handle);
			return;
		}
	}
}
	






