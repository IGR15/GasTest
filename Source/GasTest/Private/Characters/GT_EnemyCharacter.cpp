// CopyRight Omar W Switi


#include "Characters/GT_EnemyCharacter.h"

#include "AbilitySystemComponent.h"


AGT_EnemyCharacter::AGT_EnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	AbilitySystemComponent=CreateDefaultSubobject<UAbilitySystemComponent>("ability system component");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
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


