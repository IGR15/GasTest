// CopyRight Omar W Switi

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/GT_GamePlayAbility.h"
#include "GT_HitReact.generated.h"

/**
 * 
 */
UCLASS()
class GASTEST_API UGT_HitReact : public UGT_GamePlayAbility
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "GT|Abilities")
	void CashHitDirectionVectors(AActor* Instigator);
	
	UPROPERTY(BlueprintReadOnly,Category="GT|Abilities")
	FVector AvatarForward;

	UPROPERTY(BlueprintReadOnly,Category="GT|Abilities")
	FVector ToInstigator;
};
