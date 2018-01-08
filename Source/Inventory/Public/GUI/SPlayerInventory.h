#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "ItemStack.h"
#include "SInventoryGrid.h"
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

  void ClearDisplay();

  void DisplayItemStack(int32 row, int32 col, UItemStack* ItemStack);

private:
  TSharedPtr<SInventoryGrid> InventoryGrid;
};
