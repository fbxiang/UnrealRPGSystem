#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SPlayerInventory.h"
#include "InventoryWidgetStyle.h"
#include "InventoryHUD.generated.h"

UCLASS()
class INVENTORY_API AInventoryHUD : public AHUD
{
	GENERATED_BODY()
  public:
  TSharedPtr<SPlayerInventory> PlayerInventory;
  virtual void BeginPlay() override;

  UPROPERTY(Instanced, EditDefaultsOnly, Category = Inventory)
  UInventoryWidgetStyle* InventoryStyle;
};
