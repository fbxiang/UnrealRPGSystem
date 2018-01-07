#pragma once

#include "Object.h"
#include "Item.h"
#include "ItemStack.generated.h"

UCLASS(Blueprintable)
class UItemStack : public UObject {
  GENERATED_BODY()

  public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
  UItem* Item = NULL;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
  int32 StackSize = 1;

  UFUNCTION(BlueprintCallable, Category = Inventory)
  bool IsMergeable(UItemStack* other);

  UFUNCTION(BlueprintCallable, Category = Inventory)
  void MergeWith(UItemStack* other);

  UFUNCTION(BlueprintCallable, Category = Inventory)
  static UItemStack* Create(FName itemName, int size, UObject* outer);
};
