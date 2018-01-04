#include "InventoryGrid.h"

// TODO: This file needs to be thoroughly tested
bool UInventoryGrid::IsValidIndex(int row, int col) {
  return row >= 0 && row < Height && col >= 0 && col < Width;
}

void UInventoryGrid::Initialize() {
  ItemStackArray.SetNum(Width * Height);
}

UItemStack* UInventoryGrid::GetItemStackAt(int32 row, int32 col) {
  if (!IsValidIndex(row, col))
    return NULL;
  return ItemStackArray[row * Height + col];
}

void UInventoryGrid::SetItemStackAt(int32 row, int32 col, UItemStack* stack) {
  if (IsValidIndex(row, col))
    ItemStackArray[row * Height + col] = stack;
}

UItemStack* UInventoryGrid::RemoveItemStackAt(int32 row, int32 col) {
  UItemStack* stack = GetItemStackAt(row, col);
  if (!stack) return NULL;

  // remove the stack by iterating
  for (int32 i = 0; i < ItemStackArray.Num(); i++) {
    if (ItemStackArray[i] == stack) {
      ItemStackArray[i] = NULL;
    }
  }
  return stack;
}

bool UInventoryGrid::CanPutItemStackAt(int32 row, int32 col, UItemStack* stack) {
  int32 itemWidth = stack->Item->Width;
  int32 itemHeight = stack->Item->Height;

  for (int32 i = 0; i < itemHeight; ++i) {
    for (int32 j = 0; j < itemWidth; ++j) {
      int32 row_i = row + i;
      int32 col_j = col + j;
      if (!IsValidIndex(row_i, col_j) || GetItemStackAt(row_i, col_j) != NULL) {
        return false;
      }
    }
  }
  return true;
}

UItemStack* UInventoryGrid::PutItemStackAt(int32 row, int32 col, UItemStack* stack) {
  if (!CanPutItemStackAt(row, col, stack))
    return stack;

  int32 itemWidth = stack->Item->Width;
  int32 itemHeight = stack->Item->Height;
  for (int32 i = 0; i < itemHeight; ++i) {
    for (int32 j = 0; j < itemWidth; ++j) {
      SetItemStackAt(row + i, col + j, stack);
    }
  }
  return NULL;
}

bool UInventoryGrid::CanMergeItemStackAt(int32 row, int32 col, UItemStack* otherStack) {
  UItemStack* currentStack = GetItemStackAt(row, col);
  if (!currentStack) {
    return false;
  }
  return currentStack->IsMergeable(otherStack);
}

UItemStack* UInventoryGrid::MergeItemStackAt(int32 row, int32 col, UItemStack* otherStack) {
  if (!CanMergeItemStackAt(row, col, otherStack)) {
    return otherStack;
  }
  GetItemStackAt(row, col)->MergeWith(otherStack);
  return otherStack->StackSize > 0 ? otherStack : NULL;
}

bool UInventoryGrid::CanReplaceItemStackAt(int32 row, int32 col, UItemStack* otherStack) {
  int32 itemWidth = otherStack->Item->Width;
  int32 itemHeight = otherStack->Item->Height;

  UItemStack* currentStack = NULL;
  for (int32 i = 0; i < itemHeight; ++i) {
    for (int32 j = 0; j < itemWidth; ++j) {
      int32 row_i = row + i;
      int32 col_j = col + j;
      if (!IsValidIndex(row_i, col_j))
        return false;
      UItemStack* stack = GetItemStackAt(row_i, col_j);
      if (stack == NULL) {
        continue;
      }
      if (currentStack == NULL) {
        currentStack = stack;
        continue;
      }
      if (currentStack != stack)
        return false;
    }
  }
  return currentStack != NULL;
}

UItemStack* UInventoryGrid::ReplaceItemStackAt(int32 row, int32 col, UItemStack* otherStack) {
  int32 itemWidth = otherStack->Item->Width;
  int32 itemHeight = otherStack->Item->Height;

  UItemStack* currentStack = NULL;
  int32 currentRow;
  int32 currentCol;
  for (int32 i = 0; i < itemHeight; ++i) {
    for (int32 j = 0; j < itemWidth; ++j) {
      int32 row_i = row + i;
      int32 col_j = col + j;
      if (!IsValidIndex(row_i, col_j))
        return otherStack;
      UItemStack* stack = GetItemStackAt(row_i, col_j);
      if (stack == NULL) {
        continue;
      } else {
        currentRow = row_i;
        currentCol = col_j;
      }
      if (currentStack == NULL) {
        currentStack = stack;
        continue;
      }
      if (currentStack != stack)
        return otherStack;
    }
  }
  if (currentStack == NULL) {
    return otherStack;
  }
  UItemStack* removedStack = RemoveItemStackAt(currentRow, currentCol);
  PutItemStackAt(row, col, otherStack);
  return removedStack;
}
