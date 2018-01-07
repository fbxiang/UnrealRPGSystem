#include "InventoryHUDComponent.h"
#include "Widgets/SWeakWidget.h"

void UInventoryHUDComponent::Initialize() {
  PlayerInventory = SNew(SPlayerInventory).Rows(4).Columns(10)
  .Style(InventoryStyle ? &InventoryStyle->WidgetStyle : NULL);
}

void UInventoryHUDComponent::Open() {
  GEngine->GameViewport->AddViewportWidgetContent(
      SNew(SWeakWidget).PossiblyNullContent(PlayerInventory.ToSharedRef()));
  PlayerInventory->SetVisibility(EVisibility::Visible);
}

void UInventoryHUDComponent::Close() {
  PlayerInventory->SetVisibility(EVisibility::Hidden);
}

void UInventoryHUDComponent::ConnectTo(UInventoryComponent* inventory) {
  InventoryModel = inventory;
  Update();
}

void UInventoryHUDComponent::Update() {
  if (!InventoryModel) return;
  UInventoryGrid* grid = InventoryModel->InventoryGrid;
  // TODO: Ensure width and height match first

  int32 s = 0;
  for (int32 row = 0; row < grid->Height; row++) {
    for (int32 col = 0; col < grid->Width; col++) {
      UItemStack* stack = grid->GetPrimaryItemStackAt(row, col);
      if (stack) {
        s++;
      }
    }
  }
  GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow, TEXT("Found ") + FString::FromInt(s) + TEXT(" items in inventory"));
}
