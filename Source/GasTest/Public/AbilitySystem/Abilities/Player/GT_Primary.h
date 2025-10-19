// CopyRight Omar W Switi

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/GT_GamePlayAbility.h"
#include "GT_Primary.generated.h"

/**
 * 
 */
UCLASS()
class GASTEST_API UGT_Primary : public UGT_GamePlayAbility
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable,Category="GT|Abilities")
	TArray<AActor*> HitBoxOverlapTest();

	UFUNCTION(BlueprintCallable,Category="GT|Abilities")
	void SendHitReactEventToActors(const TArray<AActor*>& ActorsHit);

private:

	void DrawHitBoxOverlapDebugs(const TArray<FOverlapResult>& OverlapResults,const FVector& HitBoxLocation)const ;
	UPROPERTY(EditDefaultsOnly,Category="GT|Abilities")
	float HitBoxRadius=100.f;

	UPROPERTY(EditDefaultsOnly,Category="GT|Abilities")
	float HitBoxForwardOffset=200.f;

	UPROPERTY(EditDefaultsOnly,Category="GT|Abilities")
	float HitBoxElevationOffset=20.f;

	
};
