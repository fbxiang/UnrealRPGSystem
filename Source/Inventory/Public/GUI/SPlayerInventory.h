#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "InventoryWidgetStyle.h"

class INVENTORY_API SPlayerInventory : public SCompoundWidget
{
 public:
	SLATE_BEGIN_ARGS(SPlayerInventory)
	{}
  SLATE_ARGUMENT(int32, Rows)
  SLATE_ARGUMENT(int32, Columns)
  SLATE_ARGUMENT(const FInventoryStyle*, Style)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
};
