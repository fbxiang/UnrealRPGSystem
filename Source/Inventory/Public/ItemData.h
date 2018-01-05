#pragma once

#include "CoreMinimal.h"

UStruct(BlueprintType)
struct FItemData : public FTableRowBase {
  GENERATED_USTRUCT_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
  FString Name;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
  int32 Width;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
  int32 Height;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
  TSoftObjectPtr<UTexture> Icon;
}
