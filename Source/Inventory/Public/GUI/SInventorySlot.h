#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Images/SImage.h"

class INVENTORY_API SInventorySlot : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SInventorySlot)
	{}
  SLATE_ARGUMENT(const FSlateBrush*, Image)
  SLATE_ARGUMENT(const FSlateBrush*, HoveredImage)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

  const FSlateBrush* GetImage() const;

private:
  const FSlateBrush* Image;
  const FSlateBrush* HoveredImage;
  TSharedPtr<SImage> ImageWidget;
};
