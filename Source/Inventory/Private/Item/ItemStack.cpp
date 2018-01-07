#include "ItemStack.h"
#include "ItemRegistry.h"

bool UItemStack::IsMergeable(UItemStack* other) {
  // compare the 2 stacks
  return this->Item == other->Item;
}

void UItemStack::MergeWith(UItemStack* other) {
  if (!IsMergeable(other))
    return;
  int32 total = this->StackSize + other->StackSize;
  if (total <= Item->MaxStackSize) {
    this->StackSize = total;
    other->StackSize = 0;
  } else {
    this->StackSize = Item->MaxStackSize;
    other->StackSize = total - Item->MaxStackSize;
  }
}

UItemStack* UItemStack::Create(FName itemName, int size, UObject* outer) {
  auto itemRegistry = UItemRegistry::GetGlobalRegistry();
  if (!itemRegistry) {
    GEngine->AddOnScreenDebugMessage(
        -1, 5, FColor::Red,
        TEXT("Item Registry is invalid. You need to implement the interface properly in GameSingleton"));
    return NULL;
  }
  GEngine->AddOnScreenDebugMessage(
      -1, 5, FColor::Yellow,
      TEXT("Item Registry is fine"));
  UItemStack* stack = NewObject<UItemStack>(outer);
  stack->Item = itemRegistry->GetItemFromUniqueName(itemName);
  stack->StackSize = size;
  if (!stack->Item) {
    GEngine->AddOnScreenDebugMessage(
        -1, 5, FColor::Red,
        TEXT("ItemStack with invalid Item is created"));
  }
  return stack;
}
