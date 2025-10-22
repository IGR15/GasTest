// CopyRight Omar W Switi


#include "Player/GT_PlayerState.h"
#include "AbilitySystem/GT_AbilitySystemComponent.h"
#include "AbilitySystem/GT_AttributeSet.h"

AGT_PlayerState::AGT_PlayerState()
{
	SetNetUpdateFrequency(100.f);

	AbilitySystemComponent=CreateDefaultSubobject<UGT_AbilitySystemComponent>("AbilitySystemComponent");

	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet=CreateDefaultSubobject<UGT_AttributeSet>("AttributeSet");

	
}

UAbilitySystemComponent* AGT_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
