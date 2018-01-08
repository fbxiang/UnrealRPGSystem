#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "InventoryWidgetStyle.h"
#include "Widgets/SCanvas.h"
#include "ItemStack.h"
#include "Widgets/SCompoundWidget.h"

class INVENTORY_API SInventoryGrid : public SCompoundWidget
{
 public:
	SLATE_BEGIN_ARGS(SInventoryGrid)
	{}
  // SLATE_ARGUMENT(TWeakObjectPtr<class AHUD>, OwnerHUD)
  SLATE_ARGUMENT(int32, Rows)
  SLATE_ARGUMENT(int32, Columns)
  SLATE_ARGUMENT(const FInventoryStyle*, Style)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

  TSharedPtr<SCanvas> ItemCanvas;
  const FInventoryStyle* Style;

public:
  void ClearItemCanvas();
  void DisplayItemStack(int32 row, int32 col, UItemStack* ItemStack);

 private:
  // TWeakObjectPtr<class AHUD> OwnerHUD;
};
