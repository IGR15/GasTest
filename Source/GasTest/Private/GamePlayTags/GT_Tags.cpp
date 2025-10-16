#include "GamePlayTags/GT_Tags.h"

namespace GTTags
{
	namespace GTAbilities
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Primary,"CCTags.CCAbilities.Primary","Tag For The Primary Ability")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Secondary,"CCTags.CCAbilities.Secondary","Tag For The Secondary Ability")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Tertiary,"CCTags.CCAbilities.Tertiary","Tag For The Tertiary Ability")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ActivateOnGiven,"CCTags.CCAbilities.ActivateOnGiven","Tag For The  Ability")
	}

	namespace Events
	{
		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact,"CCTags.Events.Enemy.HitReact","Tag For The  Hit React")
		}
	}
}
