#include "ItemRegistry.h"
#include "ItemRegistryContainer.h"
#include "ItemData.h"
#include "Item.h"

UItemRegistry::UItemRegistry(const FObjectInitializer& objectInitializer): Super(objectInitializer) {
  // if (!ItemDataTable) {
  //   UE_LOG(LogTemp, Warning, TEXT("Item Data Table not initialized"));
  //   return;
  // }
  // UE_LOG(LogTemp, Warning, TEXT("Item Data initialized"));

  // for (auto it : ItemDataTable->RowMap) {
  //   FName name = it.Key;
  //   FItemData* data = (FItemData*)it.Value;
  //   UItem* newItem = NewObject<UItem>(this);
  //   newItem->HUDTexture = data->Icon;
  //   newItem->UniqueName = name;
  //   newItem->MaxStackSize = data->MaxStackSize;
  //   // TODO: assert width and height
  //   newItem->Width = data->Width;
  //   newItem->Height = data->Height;
  // }
}

void UItemRegistry::RegisterItem(UItem* item) {
  if (!Name2Item.Find(item->UniqueName)) {
    Name2Item.Add(item->UniqueName, item);
  }
}

UItem* UItemRegistry::GetItemFromUniqueName(const FName& name) {
  UItem** item = Name2Item.Find(name);
  if (item) return *item;
  FItemData* data = ItemDataTable->FindRow<FItemData>(name, "");
  if (!data) return NULL;

  UItem* newItem = NewObject<UItem>(this);
  newItem->HUDTexture = data->Icon;
  newItem->Height = data->Height;
  newItem->Width = data->Width;
  newItem->MaxStackSize = data->MaxStackSize;
  newItem->UniqueName = name;
  RegisterItem(newItem);
  return newItem;
}

UItemRegistry* UItemRegistry::GetGlobalRegistry() {
  UItemRegistry* itemRegistry = NULL;
  if (GEngine->GameSingleton) {
    auto registry = Cast<IItemRegistryContainer>(GEngine->GameSingleton);
    // if the interface is implemented with C++
    if (registry) {
      GEngine->AddOnScreenDebugMessage(
          -1, 5, FColor::Green,
          TEXT("Item Registry Container is implemented with C++"));
      return registry->GetItemRegistry();
    }

    // if the interface is implemented in Blueprint
    if (GEngine->GameSingleton->GetClass()->ImplementsInterface(UItemRegistryContainer::StaticClass())) {
      GEngine->AddOnScreenDebugMessage(
          -1, 5, FColor::Green,
          TEXT("Item Registry Container is implemented with Blueprint"));
      return IItemRegistryContainer::Execute_GetItemRegistry(GEngine->GameSingleton);
    }
  }
  GEngine->AddOnScreenDebugMessage(
      -1, 5, FColor::Red,
      TEXT("Item Registry is not implemented in the GameSingleton."));
  return NULL;
}
