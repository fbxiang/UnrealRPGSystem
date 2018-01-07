#pragma once

#include "CoreMinimal.h"
#include "GUI/HUDComponentBase.h"
#include "SPlayerInventory.h"
#include "InventoryWidgetStyle.h"
#include "InventoryComponent.h"
#include "InventoryHUDComponent.generated.h"

UCLASS()
class INVENTORY_API UInventoryHUDComponent : public UHUDComponentBase
{
	GENERATED_BODY()
  public:

  virtual void Initialize() override;
  virtual void Open() override;
  virtual void Close() override;

  UPROPERTY(Instanced, EditAnywhere, Category = Inventory)
  UInventoryWidgetStyle* InventoryStyle;

  UFUNCTION(BlueprintCallable, Category = Inventory)
  void ConnectTo(UInventoryComponent* inventory);

private:
  void Update();

private:
  TSharedPtr<SPlayerInventory> PlayerInventory;
  UInventoryComponent* InventoryModel;
};
