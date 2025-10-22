// CopyRight Omar W Switi


#include "UI/GT_WidgetComponent.h"

#include "AbilitySystem/GT_AbilitySystemComponent.h"
#include "AbilitySystem/GT_AttributeSet.h"
#include "Characters/GT_BaseCharacter.h"


// Called when the game starts
void UGT_WidgetComponent::BeginPlay()
{
	Super::BeginPlay();

	InitAbilitySystemData();
	if (!IsASCInitialized())
	{
		BaseCharacter->OnASCInitialized.AddDynamic(this,&ThisClass::OnASCInitialized);
		return;
	}
	InitializeAttributesDelegate();
	
}

void UGT_WidgetComponent::InitAbilitySystemData()
{
	BaseCharacter=Cast<AGT_BaseCharacter>(GetOwner());
	AttributeSet=Cast<UGT_AttributeSet>(BaseCharacter->GetAttributeSet());

	AbilitySystemComponent=Cast<UGT_AbilitySystemComponent>(BaseCharacter->GetAbilitySystemComponent());
}

bool UGT_WidgetComponent::IsASCInitialized()const
{
	return AbilitySystemComponent.IsValid()&&AttributeSet.IsValid();
}

void UGT_WidgetComponent::InitializeAttributesDelegate()
{
	if (!AttributeSet->bAttributeInitialized)
	{
		AttributeSet->OnAttributeInitializedDelegate.AddDynamic(this,&ThisClass::BindToAttributeChanges);
	}
	else
	{
		BindToAttributeChanges();
	}
}

void UGT_WidgetComponent::OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	AbilitySystemComponent=Cast<UGT_AbilitySystemComponent>(ASC);
	AttributeSet=Cast<UGT_AttributeSet>(AS);

	if (!IsASCInitialized())return;
	
	InitializeAttributesDelegate();
}

void UGT_WidgetComponent::BindToAttributeChanges()
{
	
}




