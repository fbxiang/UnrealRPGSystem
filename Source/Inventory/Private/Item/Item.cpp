#include "Item.h"
#include "Brushes/SlateDynamicImageBrush.h"

FSlateBrush* UItem::GetTextureBrush(){
  if (!TextureBrush.GetResourceObject())
  {
    TextureBrush = FSlateDynamicImageBrush(HUDTexture,
                                           FVector2D(HUDTexture->GetSizeX(), HUDTexture->GetSizeY()),
                                           HUDTexture->GetFName());
  }
  return &TextureBrush;
}
