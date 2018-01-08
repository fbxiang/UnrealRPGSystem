#pragma once

#include "Object.h"
#include "Tuple.h"
#include "Styling/SlateBrush.h"
#include "Item.generated.h"

UCLASS(Blueprintable)
class UItem : public UObject {
  GENERATED_BODY()
  public:

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
  UTexture2D* HUDTexture;

  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Inventory)
  FName UniqueName;

  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Inventory)
  int32 MaxStackSize;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
  FText Description;

  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Inventory)
  int32 Width = 1;

  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Inventory)
  int32 Height = 1;

  FSlateBrush* GetTextureBrush();
 private:
  FSlateBrush TextureBrush;
};
