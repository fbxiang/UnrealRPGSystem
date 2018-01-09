#pragma once

#include "Object.h"
#include "ItemStack.h"
#include "ItemSlot.generated.h"

UCLASS(EditInlineNew)
class UItemSlot : public UObject {
  GENERATED_BODY()
  public:
  // restriction class here

  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Size)
  int32 Width;

  UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Size)
  int32 Height;

 protected:
  UPROPERTY()
  UItemStack* ItemStack;

 public:
  UFUNCTION()
  UItemStack* GetItemStack();

  UFUNCTION()
  UItemStack* PutItemStack(UItemStack* stack);
};
