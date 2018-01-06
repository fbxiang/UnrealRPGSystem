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
