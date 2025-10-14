// CopyRight Omar W Switi


#include "GasTest/Public/Characters/GT_BaseCharacter.h"


AGT_BaseCharacter::AGT_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	//tick and refresh bone transforms whether rendered or not - for bond update on a dedicated server 
	GetMesh()->VisibilityBasedAnimTickOption=EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
}




