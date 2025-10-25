// CopyRight Omar W Switi


#include "UI/GT_AttributeWidget.h"

void UGT_AttributeWidget::OnAttributeChange(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair,
	UGT_AttributeSet* AttributeSet)
{
	const float AttributeValue=Pair.Key.GetNumericValue(AttributeSet);
	const float MaxAttributeValue=Pair.Value.GetNumericValue(AttributeSet);

	BP_OnAttributeChange(AttributeValue,MaxAttributeValue);
}

bool UGT_AttributeWidget::MatchesAttribute(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair)const
{
	return Attribute==Pair.Key && MaxAttribute==Pair.Value;
}
