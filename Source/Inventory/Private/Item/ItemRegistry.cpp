#include "ItemRegistry.h"

void UItemRegistry::RegisterItem(UItem* item) {
  int32 id = ItemArray.Num();
  ItemArray.Add(item);
  UniqueName2IdMap.Add(item->UniqueName, id);
}

int32 UItemRegistry::GetIdFromUniqueName(const FString& name) {
  int32* value = UniqueName2IdMap.Find(name);
  if (!value)
    return -1;
  return *value;
}

UItem* UItemRegistry::GetItemFromId(int32 id) {
  if (!ItemArray.IsValidIndex(id)) {
    return NULL;
  }
  return ItemArray[id];
}

UItem* UItemRegistry::GetItemFromUniqueName(const FString& name) {
  return GetItemFromId(GetIdFromUniqueName(name));
}
