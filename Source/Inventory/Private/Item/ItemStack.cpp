#include "ItemStack.h"

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
