// CopyRight Omar W Switi


#include "UI/GT_WidgetComponent.h"

#include "AbilitySystem/GT_AbilitySystemComponent.h"
#include "AbilitySystem/GT_AttributeSet.h"
#include "Blueprint/WidgetTree.h"
#include "Characters/GT_BaseCharacter.h"
#include "UI/GT_AttributeWidget.h"


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
	for (const TTuple<FGameplayAttribute,FGameplayAttribute>& Pair : AttributeMap)
	{
		BindWidgetToAttributeChanges(GetUserWidgetObject(),Pair);// fof checking the owned Widget Object
		GetUserWidgetObject()->WidgetTree->ForEachWidget([this,&Pair](UWidget* ChildWidget)
		{
			BindWidgetToAttributeChanges(ChildWidget,Pair);
		});
	}
	
}
void UGT_WidgetComponent::BindWidgetToAttributeChanges(UWidget* WidgetObject,
	const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const
{
	UGT_AttributeWidget* AttributeWidget =Cast<UGT_AttributeWidget>(WidgetObject);
	if (!IsValid(AttributeWidget))return;
	if (!AttributeWidget->MatchesAttribute(Pair))return;

	AttributeWidget->OnAttributeChange(Pair,AttributeSet.Get());

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Key).AddLambda([this,AttributeWidget,&Pair](const FOnAttributeChangeData& AttributeChangeData)
	{
		AttributeWidget->OnAttributeChange(Pair,AttributeSet.Get());

	});
}




