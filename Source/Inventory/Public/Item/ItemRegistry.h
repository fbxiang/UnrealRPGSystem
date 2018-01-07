#pragma once

#include "Object.h"
#include "Item.h"
#include "ItemStack.h"
#include "Containers/Map.h"
#include "Containers/Array.h"
#include "Engine/DataTable.h"
#include "ItemRegistry.generated.h"

UCLASS(EditInlineNew, DefaultToInstanced, Blueprintable)
class UItemRegistry : public UObject {
  GENERATED_BODY()

  UItemRegistry(const FObjectInitializer& objectInitializer);

  private:
  // generate 1 map and 1 table for mutual reference
  TMap<FName, UItem*> Name2Item;

 public:
  UFUNCTION(BlueprintCallable, Category = Inventory)
  static UItemRegistry* GetGlobalRegistry();

 public:
  UFUNCTION(BlueprintCallable, Category = Inventory)
  void RegisterItem(UItem* item);

  UFUNCTION(BlueprintCallable, Category = Inventory)
  UItem* GetItemFromUniqueName(const FName& name);
 public:
  /** Use a data table to initialize the item */
  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Inventory)
  UDataTable* ItemDataTable;
};
