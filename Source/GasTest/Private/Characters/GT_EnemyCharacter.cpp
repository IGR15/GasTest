// CopyRight Omar W Switi


#include "Characters/GT_EnemyCharacter.h"
#include "AbilitySystem/GT_AbilitySystemComponent.h"
#include "AbilitySystem/GT_AttributeSet.h"


AGT_EnemyCharacter::AGT_EnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	AbilitySystemComponent=CreateDefaultSubobject<UGT_AbilitySystemComponent>("ability system component");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet=CreateDefaultSubobject<UGT_AttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AGT_EnemyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AGT_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	if(!IsValid(GetAbilitySystemComponent()))return;

	GetAbilitySystemComponent()->InitAbilityActorInfo(this,this);

	if (!HasAuthority())return;

	GiveStartUpAbilities();
	
}


