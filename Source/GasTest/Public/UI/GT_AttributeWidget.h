// CopyRight Omar W Switi

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/GT_AttributeSet.h"
#include "Blueprint/UserWidget.h"
#include "GT_AttributeWidget.generated.h"

/**
 * 
 */
UCLASS()
class GASTEST_API UGT_AttributeWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Crash|Attribute")
	FGameplayAttribute Attribute;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Crash|Attribute")
	FGameplayAttribute MaxAttribute;

	void OnAttributeChange(const TTuple<FGameplayAttribute,FGameplayAttribute>& Pair,UGT_AttributeSet* AttributeSet);

	bool MatchesAttribute(const TTuple<FGameplayAttribute,FGameplayAttribute>& Pair)const;

	UFUNCTION(BlueprintImplementableEvent,meta=(DisplayName="OnAttributeChange"))
	void BP_OnAttributeChange(float NewValue,float NewMaxValue);
	
};
