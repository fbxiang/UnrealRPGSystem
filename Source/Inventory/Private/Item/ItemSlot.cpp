#include "ItemSlot.h"

UItemStack* UItemSlot::GetItemStack() {
  if (ItemStack) {
  }
  return ItemStack;
}

UItemStack* UItemSlot::PutItemStack(UItemStack* stack) {
  if (!GetItemStack()) {
    stack->Rename(NULL, this);
    ItemStack = stack;
    return NULL;
  }
  return stack;
}
