// CopyRight Omar W Switi

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/GT_AttributeSet.h"
#include "Components/WidgetComponent.h"
#include "GT_WidgetComponent.generated.h"


class UGT_AttributeSet;
class UGT_AbilitySystemComponent;
class AGT_BaseCharacter;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GASTEST_API UGT_WidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


private:
	TWeakObjectPtr<AGT_BaseCharacter> BaseCharacter;
	TWeakObjectPtr<UGT_AbilitySystemComponent>AbilitySystemComponent;
	TWeakObjectPtr<UGT_AttributeSet> AttributeSet;

	void InitAbilitySystemData();
	bool IsASCInitialized()const;

	UFUNCTION()
	void OnASCInitialized(UAbilitySystemComponent* ASC,UAttributeSet* AS);
	
};
