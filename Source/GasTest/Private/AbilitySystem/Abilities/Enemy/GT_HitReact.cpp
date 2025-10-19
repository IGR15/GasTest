// CopyRight Omar W Switi


#include "AbilitySystem/Abilities/Enemy/GT_HitReact.h"

void UGT_HitReact::CashHitDirectionVectors(AActor* Instigator)
{
	AvatarForward=GetAvatarActorFromActorInfo()->GetActorForwardVector();
	const FVector AvatarLocation= GetAvatarActorFromActorInfo()->GetActorLocation();
	const FVector InstigatorLocation=Instigator->GetActorLocation();

	ToInstigator=InstigatorLocation-AvatarLocation;
	ToInstigator.Normalize();
}
