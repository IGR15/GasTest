// CopyRight Omar W Switi


#include "GasTest/Public/Characters/GT_BaseCharacter.h"
#include "AbilitySystemComponent.h"


AGT_BaseCharacter::AGT_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	//tick and refresh bone transforms whether rendered or not - for bond update on a dedicated server 
	GetMesh()->VisibilityBasedAnimTickOption=EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
}

UAbilitySystemComponent* AGT_BaseCharacter::GetAbilitySystemComponent() const
{
	return nullptr;
}

void AGT_BaseCharacter::GiveStartUpAbilities()
{
	if (!IsValid(GetAbilitySystemComponent()))return;
	for (const auto& Ability:StartUpAbilities)
	{
		//FGamePlayAbilitySpec Are A light Wight Version of A GamePlayAbility
		FGameplayAbilitySpec AbilitySpec=FGameplayAbilitySpec(Ability);
		GetAbilitySystemComponent()->GiveAbility(AbilitySpec);
	}
}

void AGT_BaseCharacter::InitializeAttributes()
{
	checkf(IsValid(InitializeAttributeEffect),TEXT("InitializeAttributeEffect Not Set."));

	FGameplayEffectContextHandle Handle= GetAbilitySystemComponent()->MakeEffectContext();
	FGameplayEffectSpecHandle SpecHandle= GetAbilitySystemComponent()->MakeOutgoingSpec(InitializeAttributeEffect,1.f,Handle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
}




