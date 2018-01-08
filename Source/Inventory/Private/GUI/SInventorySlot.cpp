#include "SInventorySlot.h"
#include "SlateOptMacros.h"
#include "Widgets/Images/SImage.h"
#include "Widgets/Colors/SColorBlock.h"

#define LOCTEXT_NAMESPACE "SInventorySlot"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInventorySlot::Construct(const FArguments& InArgs)
{
  TAttribute<const FSlateBrush*> ImageAttribute = TAttribute<const FSlateBrush*>::Create(
      TAttribute<const FSlateBrush*>::FGetter::CreateRaw(this, &SInventorySlot::GetImage));

  const FInventoryStyle* style = InArgs._Style;

  Image = &style->SlotImage;
  HoveredImage = &style->HoveredSlotImage;
  ImageWidget = SNew(SImage);
  ImageWidget->SetImage(ImageAttribute);

	ChildSlot
 	[
      SNew(SBox)
      .WidthOverride(style->SlotWidth)
      .HeightOverride(style->SlotHeight)
      [
          ImageWidget.ToSharedRef()
       ]
	];
}

const FSlateBrush* SInventorySlot::GetImage() const {
  if (ImageWidget->IsHovered()) {
    return HoveredImage;
  } else {
    return Image;
  }
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
