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

  TSharedPtr<class SUniformGridPanel> gridPanel = SNew(SUniformGridPanel);
  for (int32 i = 0; i < cols; ++i) {
    for (int32 j = 0; j < rows; ++j) {
      gridPanel->AddSlot(i, j)
      [
          SNew(SInventorySlot)
          .Image(InArgs._SlotImage)
       ];
    }
  }

  ChildSlot
  .VAlign(VAlign_Fill)
  .HAlign(HAlign_Fill)
  [
      SNew(SVerticalBox)
      +SVerticalBox::Slot()
      .VAlign(VAlign_Center)
      .HAlign(HAlign_Center)
      [
          gridPanel.ToSharedRef()
       ]
   ];
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
#undef LOCTEXT_NAMESPACE
