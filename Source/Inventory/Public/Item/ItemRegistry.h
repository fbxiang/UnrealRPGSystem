#pragma once

#include "Object.h"
#include "Item.h"
#include "Containers/Map.h"
#include "Containers/Array.h"
#include "Engine/DataTable.h"
#include "ItemRegistry.generated.h"

UCLASS(Blueprintable)
class UItemRegistry : public UObject {
  GENERATED_BODY()

  UItemRegistry(const FObjectInitializer& objectInitializer);

  private:
  // generate 1 map and 1 table for mutual reference
  TMap<FName, int32> UniqueName2IdMap;
  TArray<UItem*> ItemArray;

 public:
  UFUNCTION(BlueprintCallable, Category = Inventory)
  void RegisterItem(UItem* item);

  UFUNCTION(BlueprintCallable, Category = Inventory)
  int32 GetIdFromUniqueName(const FName& name);

  UFUNCTION(BlueprintCallable, Category = Inventory)
  UItem* GetItemFromId(int32 id);

  UFUNCTION(BlueprintCallable, Category = Inventory)
  UItem* GetItemFromUniqueName(const FName& name);
 public:
  /** Use a data table to initialize the item */
  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Inventory)
  UDataTable* ItemDataTable;
};
