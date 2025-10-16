// CopyRight Omar W Switi

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GT_AbilitySystemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GASTEST_API UGT_AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UGT_AbilitySystemComponent();

protected:
	virtual void BeginPlay() override;

};
