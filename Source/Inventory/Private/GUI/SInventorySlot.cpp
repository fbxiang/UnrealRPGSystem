#include "SInventorySlot.h"
#include "SlateOptMacros.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Colors/SColorBlock.h"

#define LOCTEXT_NAMESPACE "SInventorySlot"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInventorySlot::Construct(const FArguments& InArgs)
{
	ChildSlot
 	[
      SNew(SBox)
      .WidthOverride(100)
      .HeightOverride(100)
      [
          SNew(SImage)
          .Image(InArgs._Image)
       ]
	];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
