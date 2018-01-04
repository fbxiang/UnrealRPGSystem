#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

class INVENTORY_API SInventorySlot : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SInventorySlot)
	{}
  SLATE_ARGUMENT(const FSlateBrush*, Image)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
};
