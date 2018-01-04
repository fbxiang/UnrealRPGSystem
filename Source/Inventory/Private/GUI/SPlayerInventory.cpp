#include "SPlayerInventory.h"
#include "SlateOptMacros.h"
#include "SInventoryGrid.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SPlayerInventory::Construct(const FArguments& InArgs) {
  int32 rows = InArgs._Rows;
  int32 cols = InArgs._Columns;
  const FInventoryStyle* style = InArgs._Style;
  const FSlateBrush* background = style ? &(style->BackgroundImage) : NULL;
  const FSlateBrush* slotImage = style ? &(style->SlotImage) : NULL;

  ChildSlot
  .VAlign(VAlign_Center)
  .HAlign(HAlign_Center)
  [
      SNew(SBox)
      .WidthOverride(800)
      .HeightOverride(1200)
      [
          SNew(SOverlay)
          +SOverlay::Slot()
          .HAlign(HAlign_Fill)
          .VAlign(VAlign_Fill)
          [
              SNew(SImage).Image(background)
           ]
          +SOverlay::Slot()
          [
              SNew(SInventoryGrid)
              .Rows(rows)
              .Columns(cols)
              .SlotImage(slotImage)
           ]
       ]
   ];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
