#pragma once

#include "Object.h"
#include "Item.h"
#include "Containers/Map.h"
#include "Containers/Array.h"
#include "ItemRegistry.generated.h"

UCLASS(Blueprintable)
class UItemRegistry : public UObject {
  GENERATED_BODY()

  private:
  // generate 1 map and 1 table for mutual reference
  TMap<FString, int32> UniqueName2IdMap;
  TArray<UItem*> ItemArray;

 public:
  UFUNCTION(BlueprintCallable, Category = Inventory)
  void RegisterItem(UItem* item);

  UFUNCTION(BlueprintCallable, Category = Inventory)
  int32 GetIdFromUniqueName(const FString& name);

  UFUNCTION(BlueprintCallable, Category = Inventory)
  UItem* GetItemFromId(int32 id);

  UFUNCTION(BlueprintCallable, Category = Inventory)
  UItem* GetItemFromUniqueName(const FString& name);
};
