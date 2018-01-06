#pragma once

#include "CoreMinimal.h"
#include "GUI/HUDComponentBase.h"
#include "SPlayerInventory.h"
#include "InventoryWidgetStyle.h"
#include "InventoryHUDComponent.generated.h"

UCLASS()
class INVENTORY_API UInventoryHUDComponent : public UHUDComponentBase
{
	GENERATED_BODY()
  public:

  virtual void Initialize() override;
  virtual void Open() override;
  virtual void Close() override;

  TSharedPtr<SPlayerInventory> PlayerInventory;

  UPROPERTY(Instanced, EditAnywhere, Category = Inventory)
  UInventoryWidgetStyle* InventoryStyle;
};
