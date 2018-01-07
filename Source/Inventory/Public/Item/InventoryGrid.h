#pragma once

#include "Object.h"
#include "ItemStack.h"
#include "InventoryGrid.generated.h"

struct _ItemStackInfo {
  UItemStack* ItemStack;
  bool Primary;
};

UCLASS(EditInlineNew)
class INVENTORY_API UInventoryGrid : public UObject {
  GENERATED_BODY()
  public:
  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Inventory)
  int32 Width = 1;

  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Inventory)
  int32 Height = 1;

  /**
   * Call this function to initialize the inventory grid
   */
  UFUNCTION(BlueprintCallable, Category = Inventory)
  void Initialize();

  UFUNCTION(BlueprintCallable, Category = Inventory)
  bool IsValidIndex(int32 row, int32 Col);

  UFUNCTION(BlueprintCallable, Category = Inventory)
  UItemStack* GetItemStackAt(int32 row, int32 col);

  UFUNCTION(BlueprintCallable, Category = Inventory)
  UItemStack* RemoveItemStackAt(int32 row, int32 col);

  UFUNCTION(BlueprintCallable, Category = Inventory)
  bool CanPutItemStackAt(int32 row, int32 col, UItemStack* stack);

  UFUNCTION(BlueprintCallable, Category = Inventory)
  bool CanReplaceItemStackAt(int32 row, int32 col, UItemStack* stack);

  UFUNCTION(BlueprintCallable, Category = Inventory)
  bool CanMergeItemStackAt(int32 row, int32 col, UItemStack* stack);

  UFUNCTION(BlueprintCallable, Category = Inventory)
  UItemStack* PutItemStackAt(int32 row, int32 col, UItemStack* stack);

  UFUNCTION(BlueprintCallable, Category = Inventory)
  UItemStack* ReplaceItemStackAt(int32 row, int32 col, UItemStack* stack);

  UFUNCTION(BlueprintCallable, Category = Inventory)
  UItemStack* MergeItemStackAt(int32 row, int32 col, UItemStack* stack);

  UItemStack* GetPrimaryItemStackAt(int32 row, int32 col);

 private:
  TArray<_ItemStackInfo> ItemStackInfoArray;

  void SetItemStackAt(int32 row, int32 col, UItemStack* stack, bool primary);
};
