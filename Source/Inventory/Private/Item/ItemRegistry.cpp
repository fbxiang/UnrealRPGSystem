#include "ItemRegistry.h"
#include "ItemData.h"
#include "Item.h"

UItemRegistry::UItemRegistry(const FObjectInitializer& objectInitializer): Super(objectInitializer) {
  if (!ItemDataTable)
    return;

  for (auto it : ItemDataTable->RowMap) {
    FName name = it.Key;
    FItemData* data = (FItemData*)it.Value;
    UItem* newItem = NewObject<UItem>(this);
    newItem->HUDTexture = data->Icon;
    newItem->UniqueName = name;
    newItem->MaxStackSize = data->MaxStackSize;
    // TODO: assert width and height
    newItem->Width = data->Width;
    newItem->Height = data->Height;
  }
}

void UItemRegistry::RegisterItem(UItem* item) {
  int32 id = ItemArray.Num();
  ItemArray.Add(item);
  UniqueName2IdMap[item->UniqueName] = id;
}

int32 UItemRegistry::GetIdFromUniqueName(const FName& name) {
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

UItem* UItemRegistry::GetItemFromUniqueName(const FName& name) {
  return GetItemFromId(GetIdFromUniqueName(name));
}
