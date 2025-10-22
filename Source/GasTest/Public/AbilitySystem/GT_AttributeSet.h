// CopyRight Omar W Switi

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GT_AttributeSet.generated.h"

/**
 * 
 */
#define ATTRIBUTE_ACCESSORS_BASIC(ClassName,PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
UCLASS()
class GASTEST_API UGT_AttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=onRep_Health)
	FGameplayAttributeData Health;

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_Mana)
	FGameplayAttributeData Mana;
	
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing=OnRep_MaxMana)
	FGameplayAttributeData MaxMana;
	
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldValue );

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldValue );
	
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldValue );
	
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldValue );
	
	ATTRIBUTE_ACCESSORS_BASIC(ThisClass,Health);
	ATTRIBUTE_ACCESSORS_BASIC(ThisClass,MaxHealth);
	ATTRIBUTE_ACCESSORS_BASIC(ThisClass,Mana);
	ATTRIBUTE_ACCESSORS_BASIC(ThisClass,MaxMana);
	
};
