#include "SInventoryGrid.h"
#include "SInventorySlot.h"
#include "SlateOptMacros.h"
#include "Widgets/Layout/SUniformGridPanel.h"

#define LOCTEXT_NAMESPACE "SInventoryGrid"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInventoryGrid::Construct(const FArguments& InArgs)
{
  int32 rows = InArgs._Rows;
  int32 cols = InArgs._Columns;

  Style = InArgs._Style;

  TSharedPtr<class SUniformGridPanel> gridPanel = SNew(SUniformGridPanel);
  for (int32 i = 0; i < cols; ++i) {
    for (int32 j = 0; j < rows; ++j) {
      gridPanel->AddSlot(i, j)
      [
          SNew(SInventorySlot)
          .Style(Style)
       ];
    }
  }
  ItemCanvas = SNew(SCanvas);

  ChildSlot
  .VAlign(VAlign_Fill)
  .HAlign(HAlign_Fill)
  [
      SNew(SVerticalBox)
      +SVerticalBox::Slot()
      .VAlign(VAlign_Bottom)
      .HAlign(HAlign_Center)
      .Padding(0, 30)
      [
          SNew(SBox)
          .WidthOverride(cols * Style->SlotWidth)
          .HeightOverride(rows * Style->SlotHeight)
          [
              SNew(SOverlay)
              +SOverlay::Slot()
              .VAlign(VAlign_Fill)
              .HAlign(HAlign_Fill)
              [
                  gridPanel.ToSharedRef()
               ]
              +SOverlay::Slot()
              .VAlign(VAlign_Fill)
              .HAlign(HAlign_Fill)
              [
                  ItemCanvas.ToSharedRef()
               ]
           ]
       ]
   ];
}

void SInventoryGrid::ClearItemCanvas() {
  ItemCanvas->ClearChildren();
}

void SInventoryGrid::DisplayItemStack(int32 row, int32 col, UItemStack* itemStack) {
  if (!itemStack || !itemStack->Item) return;
  UItem* item = itemStack->Item;
  ItemCanvas->AddSlot()
  .Size(FVector2D(item->Width * Style->SlotWidth, item->Height * Style->SlotHeight))
  .Position(FVector2D(Style->SlotWidth * col, Style->SlotHeight * row))
  [
      SNew(SBox)
      .HAlign(HAlign_Fill)
      .VAlign(VAlign_Fill)
      [
          SNew(SImage).Image(item->GetTextureBrush())
       ]
   ];
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
#undef LOCTEXT_NAMESPACE
