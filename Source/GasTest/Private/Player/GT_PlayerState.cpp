// CopyRight Omar W Switi


#include "Player/GT_PlayerState.h"
#include "AbilitySystem/GT_AbilitySystemComponent.h"

AGT_PlayerState::AGT_PlayerState()
{
	SetNetUpdateFrequency(100.f);

	AbilitySystemComponent=CreateDefaultSubobject<UGT_AbilitySystemComponent>("AbilitySystemComponent");

	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	
}

UAbilitySystemComponent* AGT_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
