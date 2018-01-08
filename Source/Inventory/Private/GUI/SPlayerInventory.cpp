#include "SPlayerInventory.h"
#include "SlateOptMacros.h"
#include "SInventoryGrid.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SPlayerInventory::Construct(const FArguments& InArgs) {
  int32 rows = InArgs._Rows;
  int32 cols = InArgs._Columns;
  const FInventoryStyle* style = InArgs._Style;

  InventoryGrid = SNew(SInventoryGrid)
  .Rows(rows)
  .Columns(cols)
  .Style(style);

  ChildSlot
  .VAlign(VAlign_Center)
  .HAlign(HAlign_Center)
  [
      SNew(SBox)
      .WidthOverride(style->PanelWidth)
      .HeightOverride(style->PanelHeight)
      [
          SNew(SOverlay)
          +SOverlay::Slot()
          .HAlign(HAlign_Fill)
          .VAlign(VAlign_Fill)
          [
              SNew(SImage).Image(&style->BackgroundImage)
           ]
          +SOverlay::Slot()
          [
              InventoryGrid.ToSharedRef()
           ]
       ]
   ];
}

void SPlayerInventory::ClearDisplay() {
  if (InventoryGrid.IsValid())
    InventoryGrid->ClearItemCanvas();
}

void SPlayerInventory::DisplayItemStack(int32 row, int32 col, UItemStack* ItemStack) {
  if (InventoryGrid.IsValid())
    InventoryGrid->DisplayItemStack(row, col, ItemStack);
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
