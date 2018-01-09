#pragma once

#include "ItemRegistry.h"
#include "ItemRegistryContainer.generated.h"

UINTERFACE(BlueprintType)
class INVENTORY_API UItemRegistryContainer : public UInterface {
  GENERATED_UINTERFACE_BODY()
  };

class INVENTORY_API IItemRegistryContainer {
  GENERATED_IINTERFACE_BODY()
  public:
  UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = Inventory)
  UItemRegistry* GetItemRegistry();
};
