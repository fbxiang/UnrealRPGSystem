#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Widgets/SCompoundWidget.h"

class INVENTORY_API SInventoryGrid : public SCompoundWidget
{
 public:
	SLATE_BEGIN_ARGS(SInventoryGrid)
	{}
  // SLATE_ARGUMENT(TWeakObjectPtr<class AHUD>, OwnerHUD)
  SLATE_ARGUMENT(int32, Rows)
  SLATE_ARGUMENT(int32, Columns)
  SLATE_ARGUMENT(const FSlateBrush*, SlotImage)
  SLATE_ARGUMENT(const FSlateBrush*, HoveredSlotImage)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

 private:
  // TWeakObjectPtr<class AHUD> OwnerHUD;
};
