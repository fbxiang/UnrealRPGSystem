#pragma once

#include "Engine/DataTable.h"
#include "ItemData.generated.h"

USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase {
  GENERATED_USTRUCT_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
  int32 Width;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
  int32 Height;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
  int32 MaxStackSize;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
  UTexture2D* Icon;
};
